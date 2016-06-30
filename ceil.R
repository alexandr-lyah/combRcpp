
library(Rcpp)
Rcpp::cppFunction("double ceil_any(double x, double prec) { 
  if (fabs(prec / x) < DBL_MIN)
    return x;
    
  double r = fmod(fabs(x), prec);
  if (r == 0)
    return x;
  return (x > 0) ? x + prec - r : x + r;
}")

ceil_any(9.9, 2)
ceil_any(10, 2)
ceil_any(10.1, 2)

ceil_any(-9.9, 2)
ceil_any(-10, 2)
ceil_any(-10.1, 2)