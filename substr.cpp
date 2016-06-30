#include <Rcpp.h>
using namespace Rcpp;

inline SEXP subset_element(SEXP x, int i) {
  size_t n = Rf_length(x);

  if (i < 0 || i >= n || i == NA_INTEGER)
    stop("Invalid subscript");

  return VECTOR_ELT(x, i);
}

inline SEXP subset_element(SEXP x, double i) {
  if (ISNAN(i))
    stop("Invalid subscript");

  return subset_element(x, (int) i);
}

inline SEXP subset_element(List x, SEXP i) {
  if (!x.hasAttribute("names"))
    stop("To subset with character, input must have names");

  SEXP names = x.attr("names");
  int n = Rf_length(names);

  size_t index = -1;

  const char* name = Rf_translateChar(i);
  for (size_t j = 0; j < n; j++) {
    if (STRING_ELT(names, j) == NA_STRING)
      continue;

    const char* name_j = Rf_translateChar(STRING_ELT(names, j));
    if (strcmp(name, name_j) == 0) {
      index = j;
      break;
    }
  }

  if (index == -1)
    stop("Unknown name");

  return subset_element(x, (int) index);
}


// [[Rcpp::export]]
SEXP subset2(List x, SEXP i) {
  if (Rf_length(i) > 1)
    stop("Must subset with vector of length 1");

  switch(TYPEOF(i)) {
  case INTSXP:
    return subset_element(x, INTEGER(i)[0] - 1);
  case REALSXP:
    return subset_element(x, REAL(i)[0] - 1);
    break;
  case STRSXP:
    return subset_element(x, STRING_ELT(i, 0));
  default:
    stop("Must subset with integer, numeric, or character vector.");
  }

  return R_NilValue;
}

/***R
library(microbenchmark)
microbenchmark(
  mtcars$carb,
  .subset2(mtcars, "carb"),
  subset2(mtcars, "carb"),
  mtcars[[1]],
  .subset2(mtcars, 1),
  subset2(mtcars, 1)
)
# Considerably slower probably because of slow .Call/Rcpp overheads  
*/