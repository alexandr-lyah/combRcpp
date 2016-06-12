#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]
IntegerVector LengthStrata( DataFrame dataset ) {
  Rcpp::CharacterVector strata = dataset["strata2013"];
  int n = strata.size();
  std::map<SEXP, int> counts;
  for (int i = 0; i < n; ++i) {
    ++counts[ strata[i] ];
  }
  return wrap(counts);
}//v

//sourceCpp("icppR.cpp")
//DF <- data.frame(x=1:10, strata2013=sample(letters[1:8], 10, TRUE))
//LengthStrata(DF)


// [[Rcpp::export]]
IntegerVector LengthStrata2( DataFrame dataset ) {
  Rcpp::CharacterVector strata = dataset["strata2013"];
  return table(strata);
}