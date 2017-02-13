// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <RcppArmadillo.h>
#include <Rcpp.h>

using namespace Rcpp;

// baseHaz_cpp
List baseHaz_cpp(const NumericVector& alltimes, const IntegerVector& status, const NumericVector& eXb, const IntegerVector& strata, bool se, arma::mat data, int nVar, const std::vector<double>& predtimes, const NumericVector& emaxtimes, int nPatients, int nStrata, int cause, bool Efron);
RcppExport SEXP riskRegression_baseHaz_cpp(SEXP alltimesSEXP, SEXP statusSEXP, SEXP eXbSEXP, SEXP strataSEXP, SEXP seSEXP, SEXP dataSEXP, SEXP nVarSEXP, SEXP predtimesSEXP, SEXP emaxtimesSEXP, SEXP nPatientsSEXP, SEXP nStrataSEXP, SEXP causeSEXP, SEXP EfronSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const NumericVector& >::type alltimes(alltimesSEXP);
    Rcpp::traits::input_parameter< const IntegerVector& >::type status(statusSEXP);
    Rcpp::traits::input_parameter< const NumericVector& >::type eXb(eXbSEXP);
    Rcpp::traits::input_parameter< const IntegerVector& >::type strata(strataSEXP);
    Rcpp::traits::input_parameter< bool >::type se(seSEXP);
    Rcpp::traits::input_parameter< arma::mat >::type data(dataSEXP);
    Rcpp::traits::input_parameter< int >::type nVar(nVarSEXP);
    Rcpp::traits::input_parameter< const std::vector<double>& >::type predtimes(predtimesSEXP);
    Rcpp::traits::input_parameter< const NumericVector& >::type emaxtimes(emaxtimesSEXP);
    Rcpp::traits::input_parameter< int >::type nPatients(nPatientsSEXP);
    Rcpp::traits::input_parameter< int >::type nStrata(nStrataSEXP);
    Rcpp::traits::input_parameter< int >::type cause(causeSEXP);
    Rcpp::traits::input_parameter< bool >::type Efron(EfronSEXP);
    rcpp_result_gen = Rcpp::wrap(baseHaz_cpp(alltimes, status, eXb, strata, se, data, nVar, predtimes, emaxtimes, nPatients, nStrata, cause, Efron));
    return rcpp_result_gen;
END_RCPP
}
// baseHazEfron_survival_cpp
NumericVector baseHazEfron_survival_cpp(int ntimes, IntegerVector ndead, NumericVector risk, NumericVector riskDead);
RcppExport SEXP riskRegression_baseHazEfron_survival_cpp(SEXP ntimesSEXP, SEXP ndeadSEXP, SEXP riskSEXP, SEXP riskDeadSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< int >::type ntimes(ntimesSEXP);
    Rcpp::traits::input_parameter< IntegerVector >::type ndead(ndeadSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type risk(riskSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type riskDead(riskDeadSEXP);
    rcpp_result_gen = Rcpp::wrap(baseHazEfron_survival_cpp(ntimes, ndead, risk, riskDead));
    return rcpp_result_gen;
END_RCPP
}
// colCumSum
NumericMatrix colCumSum(NumericMatrix x);
RcppExport SEXP riskRegression_colCumSum(SEXP xSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< NumericMatrix >::type x(xSEXP);
    rcpp_result_gen = Rcpp::wrap(colCumSum(x));
    return rcpp_result_gen;
END_RCPP
}
// colSumsCrossprod
NumericMatrix colSumsCrossprod(NumericMatrix X, NumericMatrix Y, bool transposeY);
RcppExport SEXP riskRegression_colSumsCrossprod(SEXP XSEXP, SEXP YSEXP, SEXP transposeYSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< NumericMatrix >::type X(XSEXP);
    Rcpp::traits::input_parameter< NumericMatrix >::type Y(YSEXP);
    Rcpp::traits::input_parameter< bool >::type transposeY(transposeYSEXP);
    rcpp_result_gen = Rcpp::wrap(colSumsCrossprod(X, Y, transposeY));
    return rcpp_result_gen;
END_RCPP
}
// calcE_cpp
List calcE_cpp(const NumericVector& eventtime, const NumericVector& status, const NumericVector& eXb, const arma::mat& X, int p, bool add0);
RcppExport SEXP riskRegression_calcE_cpp(SEXP eventtimeSEXP, SEXP statusSEXP, SEXP eXbSEXP, SEXP XSEXP, SEXP pSEXP, SEXP add0SEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const NumericVector& >::type eventtime(eventtimeSEXP);
    Rcpp::traits::input_parameter< const NumericVector& >::type status(statusSEXP);
    Rcpp::traits::input_parameter< const NumericVector& >::type eXb(eXbSEXP);
    Rcpp::traits::input_parameter< const arma::mat& >::type X(XSEXP);
    Rcpp::traits::input_parameter< int >::type p(pSEXP);
    Rcpp::traits::input_parameter< bool >::type add0(add0SEXP);
    rcpp_result_gen = Rcpp::wrap(calcE_cpp(eventtime, status, eXb, X, p, add0));
    return rcpp_result_gen;
END_RCPP
}
// ICbeta_cpp
arma::mat ICbeta_cpp(const NumericVector& newT, const NumericVector& neweXb, const arma::mat& newX, const NumericVector& newStatus, const IntegerVector& newIndexJump, const NumericVector& S01, const arma::mat& E1, const NumericVector& time1, const arma::mat& iInfo, int p);
RcppExport SEXP riskRegression_ICbeta_cpp(SEXP newTSEXP, SEXP neweXbSEXP, SEXP newXSEXP, SEXP newStatusSEXP, SEXP newIndexJumpSEXP, SEXP S01SEXP, SEXP E1SEXP, SEXP time1SEXP, SEXP iInfoSEXP, SEXP pSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const NumericVector& >::type newT(newTSEXP);
    Rcpp::traits::input_parameter< const NumericVector& >::type neweXb(neweXbSEXP);
    Rcpp::traits::input_parameter< const arma::mat& >::type newX(newXSEXP);
    Rcpp::traits::input_parameter< const NumericVector& >::type newStatus(newStatusSEXP);
    Rcpp::traits::input_parameter< const IntegerVector& >::type newIndexJump(newIndexJumpSEXP);
    Rcpp::traits::input_parameter< const NumericVector& >::type S01(S01SEXP);
    Rcpp::traits::input_parameter< const arma::mat& >::type E1(E1SEXP);
    Rcpp::traits::input_parameter< const NumericVector& >::type time1(time1SEXP);
    Rcpp::traits::input_parameter< const arma::mat& >::type iInfo(iInfoSEXP);
    Rcpp::traits::input_parameter< int >::type p(pSEXP);
    rcpp_result_gen = Rcpp::wrap(ICbeta_cpp(newT, neweXb, newX, newStatus, newIndexJump, S01, E1, time1, iInfo, p));
    return rcpp_result_gen;
END_RCPP
}
// IClambda0_cpp
arma::mat IClambda0_cpp(const NumericVector& tau, const arma::mat& ICbeta, const NumericVector& newT, const NumericVector& neweXb, const NumericVector& newStatus, const IntegerVector& newStrata, const IntegerVector& newIndexJump, const NumericVector& S01, const arma::mat& E1, const NumericVector& time1, const NumericVector& lambda0, int p, int strata);
RcppExport SEXP riskRegression_IClambda0_cpp(SEXP tauSEXP, SEXP ICbetaSEXP, SEXP newTSEXP, SEXP neweXbSEXP, SEXP newStatusSEXP, SEXP newStrataSEXP, SEXP newIndexJumpSEXP, SEXP S01SEXP, SEXP E1SEXP, SEXP time1SEXP, SEXP lambda0SEXP, SEXP pSEXP, SEXP strataSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const NumericVector& >::type tau(tauSEXP);
    Rcpp::traits::input_parameter< const arma::mat& >::type ICbeta(ICbetaSEXP);
    Rcpp::traits::input_parameter< const NumericVector& >::type newT(newTSEXP);
    Rcpp::traits::input_parameter< const NumericVector& >::type neweXb(neweXbSEXP);
    Rcpp::traits::input_parameter< const NumericVector& >::type newStatus(newStatusSEXP);
    Rcpp::traits::input_parameter< const IntegerVector& >::type newStrata(newStrataSEXP);
    Rcpp::traits::input_parameter< const IntegerVector& >::type newIndexJump(newIndexJumpSEXP);
    Rcpp::traits::input_parameter< const NumericVector& >::type S01(S01SEXP);
    Rcpp::traits::input_parameter< const arma::mat& >::type E1(E1SEXP);
    Rcpp::traits::input_parameter< const NumericVector& >::type time1(time1SEXP);
    Rcpp::traits::input_parameter< const NumericVector& >::type lambda0(lambda0SEXP);
    Rcpp::traits::input_parameter< int >::type p(pSEXP);
    Rcpp::traits::input_parameter< int >::type strata(strataSEXP);
    rcpp_result_gen = Rcpp::wrap(IClambda0_cpp(tau, ICbeta, newT, neweXb, newStatus, newStrata, newIndexJump, S01, E1, time1, lambda0, p, strata));
    return rcpp_result_gen;
END_RCPP
}
// predictCIF_cpp
arma::mat predictCIF_cpp(const std::vector<arma::mat>& hazard, const std::vector<arma::mat>& cumhazard, const arma::mat& eXb_h, const arma::mat& eXb_cumH, const arma::mat& strata, const std::vector<double>& newtimes, const std::vector<double>& etimes, const std::vector<double>& etimeMax, double t0, int nEventTimes, int nNewTimes, int nData, int cause, int nCause);
RcppExport SEXP riskRegression_predictCIF_cpp(SEXP hazardSEXP, SEXP cumhazardSEXP, SEXP eXb_hSEXP, SEXP eXb_cumHSEXP, SEXP strataSEXP, SEXP newtimesSEXP, SEXP etimesSEXP, SEXP etimeMaxSEXP, SEXP t0SEXP, SEXP nEventTimesSEXP, SEXP nNewTimesSEXP, SEXP nDataSEXP, SEXP causeSEXP, SEXP nCauseSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const std::vector<arma::mat>& >::type hazard(hazardSEXP);
    Rcpp::traits::input_parameter< const std::vector<arma::mat>& >::type cumhazard(cumhazardSEXP);
    Rcpp::traits::input_parameter< const arma::mat& >::type eXb_h(eXb_hSEXP);
    Rcpp::traits::input_parameter< const arma::mat& >::type eXb_cumH(eXb_cumHSEXP);
    Rcpp::traits::input_parameter< const arma::mat& >::type strata(strataSEXP);
    Rcpp::traits::input_parameter< const std::vector<double>& >::type newtimes(newtimesSEXP);
    Rcpp::traits::input_parameter< const std::vector<double>& >::type etimes(etimesSEXP);
    Rcpp::traits::input_parameter< const std::vector<double>& >::type etimeMax(etimeMaxSEXP);
    Rcpp::traits::input_parameter< double >::type t0(t0SEXP);
    Rcpp::traits::input_parameter< int >::type nEventTimes(nEventTimesSEXP);
    Rcpp::traits::input_parameter< int >::type nNewTimes(nNewTimesSEXP);
    Rcpp::traits::input_parameter< int >::type nData(nDataSEXP);
    Rcpp::traits::input_parameter< int >::type cause(causeSEXP);
    Rcpp::traits::input_parameter< int >::type nCause(nCauseSEXP);
    rcpp_result_gen = Rcpp::wrap(predictCIF_cpp(hazard, cumhazard, eXb_h, eXb_cumH, strata, newtimes, etimes, etimeMax, t0, nEventTimes, nNewTimes, nData, cause, nCause));
    return rcpp_result_gen;
END_RCPP
}
// rowCumSum
NumericMatrix rowCumSum(NumericMatrix x);
RcppExport SEXP riskRegression_rowCumSum(SEXP xSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< NumericMatrix >::type x(xSEXP);
    rcpp_result_gen = Rcpp::wrap(rowCumSum(x));
    return rcpp_result_gen;
END_RCPP
}
// rowSumsCrossprod
NumericMatrix rowSumsCrossprod(NumericMatrix X, NumericMatrix Y, bool transposeY);
RcppExport SEXP riskRegression_rowSumsCrossprod(SEXP XSEXP, SEXP YSEXP, SEXP transposeYSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< NumericMatrix >::type X(XSEXP);
    Rcpp::traits::input_parameter< NumericMatrix >::type Y(YSEXP);
    Rcpp::traits::input_parameter< bool >::type transposeY(transposeYSEXP);
    rcpp_result_gen = Rcpp::wrap(rowSumsCrossprod(X, Y, transposeY));
    return rcpp_result_gen;
END_RCPP
}
// colCenter_cpp
arma::mat colCenter_cpp(arma::mat X, arma::colvec& center);
RcppExport SEXP riskRegression_colCenter_cpp(SEXP XSEXP, SEXP centerSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::mat >::type X(XSEXP);
    Rcpp::traits::input_parameter< arma::colvec& >::type center(centerSEXP);
    rcpp_result_gen = Rcpp::wrap(colCenter_cpp(X, center));
    return rcpp_result_gen;
END_RCPP
}
// rowCenter_cpp
arma::mat rowCenter_cpp(arma::mat X, arma::rowvec& center);
RcppExport SEXP riskRegression_rowCenter_cpp(SEXP XSEXP, SEXP centerSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::mat >::type X(XSEXP);
    Rcpp::traits::input_parameter< arma::rowvec& >::type center(centerSEXP);
    rcpp_result_gen = Rcpp::wrap(rowCenter_cpp(X, center));
    return rcpp_result_gen;
END_RCPP
}
// colScale_cpp
arma::mat colScale_cpp(arma::mat X, arma::colvec& scale);
RcppExport SEXP riskRegression_colScale_cpp(SEXP XSEXP, SEXP scaleSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::mat >::type X(XSEXP);
    Rcpp::traits::input_parameter< arma::colvec& >::type scale(scaleSEXP);
    rcpp_result_gen = Rcpp::wrap(colScale_cpp(X, scale));
    return rcpp_result_gen;
END_RCPP
}
// rowScale_cpp
arma::mat rowScale_cpp(arma::mat X, arma::rowvec& scale);
RcppExport SEXP riskRegression_rowScale_cpp(SEXP XSEXP, SEXP scaleSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::mat >::type X(XSEXP);
    Rcpp::traits::input_parameter< arma::rowvec& >::type scale(scaleSEXP);
    rcpp_result_gen = Rcpp::wrap(rowScale_cpp(X, scale));
    return rcpp_result_gen;
END_RCPP
}
// colMultiply_cpp
arma::mat colMultiply_cpp(arma::mat X, arma::colvec& scale);
RcppExport SEXP riskRegression_colMultiply_cpp(SEXP XSEXP, SEXP scaleSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::mat >::type X(XSEXP);
    Rcpp::traits::input_parameter< arma::colvec& >::type scale(scaleSEXP);
    rcpp_result_gen = Rcpp::wrap(colMultiply_cpp(X, scale));
    return rcpp_result_gen;
END_RCPP
}
// rowMultiply_cpp
arma::mat rowMultiply_cpp(arma::mat X, arma::rowvec& scale);
RcppExport SEXP riskRegression_rowMultiply_cpp(SEXP XSEXP, SEXP scaleSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::mat >::type X(XSEXP);
    Rcpp::traits::input_parameter< arma::rowvec& >::type scale(scaleSEXP);
    rcpp_result_gen = Rcpp::wrap(rowMultiply_cpp(X, scale));
    return rcpp_result_gen;
END_RCPP
}
