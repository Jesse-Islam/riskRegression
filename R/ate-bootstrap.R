### ate-bootstrap.R --- 
##----------------------------------------------------------------------
## Author: Brice Ozenne
## Created: apr 11 2018 (17:05) 
## Version: 
## Last-Updated: Oct 29 2019 (06:59) 
##           By: Thomas Alexander Gerds
##     Update #: 268
##----------------------------------------------------------------------
## 
### Commentary: 
## 
### Change Log:
##----------------------------------------------------------------------
## 
### Code:

## * calcBootATE
## generate a boot object for the ate function that will be used to compute CI and p.values
calcBootATE <- function(args, name.estimate, estimator.boot, n.obs, fct.pointEstimate,
                        handler, B, seed, mc.cores, cl,
                        verbose){
    n.estimate <- length(name.estimate)
                                        # {{{ prepare arguments
    
    ## hard copy of the dataset before bootstrap
    ls.data <- list(object.event = NULL,
                    object.treatment = NULL,
                    object.censor = NULL)
    ls.package <- list(object.event = NULL,
                       object.treatment = NULL,
                       object.censor = NULL)
    for(iModel in c("object.event","object.treatment","object.censor")){ ## iModel <- "object.event"

        if(inherits(args[[iModel]]$call$data,"name")){
            data.tempo <- eval(args[[iModel]]$call$data)
            if(inherits(data.tempo,"function")){
                stop("The dataset in argument \'",iModel,"\' has the same name has an existing R function \n",
                     "This creates confusion - please rename the dataset \n")
            }else{
                ls.data[[iModel]] <- data.table::as.data.table(data.tempo)
            }
        }else{
            ls.data[[iModel]] <- args[[iModel]]$call$data
        }
        
        if(inherits(args[[iModel]]$call$formula,"name")){
            formula.tempo <- eval(args[[iModel]]$call$formula)
            if(inherits(formula.tempo,"function")){
                stop("The formula in argument \'",iModel,"\' has the same name has an existing R function \n",
                     "This creates confusion - please rename the formula \n")
            }else{
                args[[iModel]]$call$formula <- formula.tempo
            }
        }

        ## package to be exported to cluster
        if(inherits(args[[iModel]]$call[[1]],"name")){
            iSource <- utils::find(deparse(args[[iModel]]$call[[1]]))
            iFound <- grepl("package:",iSource)
            if(any(iFound)){
                ls.package[[iModel]] <- gsub("package:","",iSource[iFound])
            }else{
                NULL
            }
        }else{
            ls.package[[iModel]] <- utils::packageName(environment(args[[iModel]]$call[[1]]))
        }
    }

    ## packages and functions to be exported to the cluster
    add.Package <- unique(c("riskRegression","prodlim","data.table","parallel","survival",unlist(ls.package)))
    add.Fct <- c("SurvResponseVar","predictRisk.coxphTD","predictRisk.CSCTD")
    
    ## if cluster already defined by the user
    no.cl <- is.null(cl)
    if( (no.cl[[1]] == FALSE) && (mc.cores[[1]] == 1) ){ ## i.e. the user has not initialized the number of cores
        mc.cores <- length(cl)
    }
    
    ## seed
    if (!missing(seed)){
        set.seed(seed)
    }
    bootseeds <- sample(1:1000000,size=B,replace=FALSE)
    ## allArgs <- c("warperBootATE","data","n.obs","fct.pointEstimate",
    ## "object","treatment","contrasts","times","cause","landmark",
    ## "n.contrasts","levels","TD","name.estimate","formula","dots")

                                        # }}}

                                        # {{{ warper
    warperBootATE <- function(index, args, estimator.boot, fct.pointEstimate, name.estimate, n.estimate){
        ## models for the conditional mean
        for(iModel in c("object.event","object.treatment","object.censor")){
            if(!is.null(args[[iModel]])){
                args[[iModel]]$call$data <- ls.data[[iModel]][index] ## resample dataset
                args[[iModel]] <- try(eval(args[[iModel]]$call),silent=TRUE) ## refit  model
                if ("try-error" %in% class(args[[iModel]])){
                    iBoot <- paste0("Failed to fit model ",iModel," on the bootstrap sample", sep = "")
                    class(iBoot) <- "try-error"
                    return(iBoot)
                }
            }
        }
        ## compute ate
        iBoot <- try(do.call(fct.pointEstimate, args), silent = TRUE)
        ## export
        if(inherits(iBoot,"try-error")){ ## error handling
            out <- setNames(rep(NA, n.estimate), name.estimate)
            attr(out,"error") <- iBoot
            return(out)        
        }else{
            ls.estimate <- lapply(1:length(estimator.boot), function(iE){
                return(c(iBoot$meanRisk[[paste0("meanRisk.",estimator.boot[iE])]],
                         iBoot$riskComparison[[paste0("diff.",estimator.boot[iE])]],
                         iBoot$riskComparison[[paste0("ratio.",estimator.boot[iE])]]))
                
            })
            return(setNames(do.call("c", ls.estimate), name.estimate))
        }
    }

                                        # }}}
    ## bootstrap
    if(handler %in% c("snow","multicore")) {
                                        # {{{ use boot package
        if(handler=="snow" && no.cl[[1]]==TRUE){ 
            ## initialize CPU
            cl <- parallel::makeCluster(mc.cores)
            ## load packages
            parallel::clusterCall(cl, function(x){sapply(x, library, character.only = TRUE)}, add.Package)
            ## set seeds
            parallel::clusterApply(cl, bootseeds, function(x){set.seed(x)})
            ## check
            ## clusterCall(cl, function(x){rnorm(5)})
        }else{
            ## set seeds
            bootseeds <- sum(bootseeds)
            set.seed(bootseeds)
        }
        ## run bootstrap
        boot.object <- boot::boot(data = args$mydata,
                                  R = B,
                                  sim = "ordinary",
                                  stpe = "indices",
                                  strata = rep(1, n.obs),
                                  parallel = handler,
                                  ncpus = mc.cores,
                                  cl = cl,
                                  statistic = function(data, index, ...){
                                      warperBootATE(index = index,
                                                    args = args,
                                                    fct.pointEstimate = fct.pointEstimate,
                                                    estimator.boot = estimator.boot,
                                                    name.estimate = name.estimate,
                                                    n.estimate = n.estimate)                                      
                                  })
                                        # }}}
    }else{

        if (handler=="foreach"){ # [@TAG: removed mc.cores > 1]
                                        # {{{ foreach
            if(no.cl){
                if(verbose>0){
                    cl <- parallel::makeCluster(mc.cores, outfile = "")
                }else{
                    cl <- parallel::makeCluster(mc.cores)
                }                
            }           
            doParallel::registerDoParallel(cl)
            ## progress bar 
            if(verbose){pb <- txtProgressBar(max = B, style = 3,width=30)}
            b <- NULL ## [:forCRANcheck:] foreach

            boots <- foreach::`%dopar%`(foreach::foreach(b = 1:B, .packages = add.Package, .export = add.Fct), { ## b <- 1
                if(verbose>0){setTxtProgressBar(pb, b)}
                set.seed(bootseeds[[b]])
                warperBootATE(index = sample(1:n.obs, size = n.obs, replace = TRUE),
                              args = args,
                              fct.pointEstimate = fct.pointEstimate,
                              estimator.boot = estimator.boot,
                              name.estimate = name.estimate,
                              n.estimate = n.estimate)                                      
            })            
            if(verbose>0){close(pb)}
            if(no.cl){parallel::stopCluster(cl)}
                                        # }}}
        }else if(handler=="mclapply"){
                                        # {{{ mclapply
            boots <- parallel::mclapply(1:B, mc.cores = mc.cores, FUN = function(b){
                set.seed(bootseeds[[b]])
                warperBootATE(index = sample(1:n.obs, size = n.obs, replace = TRUE),
                              args = args,
                              fct.pointEstimate = fct.pointEstimate,
                              estimator.boot = estimator.boot,
                              name.estimate = name.estimate,
                              n.estimate = n.estimate)                                      
            })
                                        # }}}
        }
                                        # {{{ convert to boot object
        M.bootEstimate <- do.call(rbind,boots)
        
        if(all(is.na(M.bootEstimate))){
            stop(paste0("Error in all bootstrap samples: ", attr(boots[[1]],"error")[1]))
        }
        colnames(M.bootEstimate) <- name.estimate
                                        # }}}
    }
                                    
    ## output
    return(list(boot = M.bootEstimate,
                bootseeds = bootseeds))
}

######################################################################
### ate-bootstrap.R ends here
