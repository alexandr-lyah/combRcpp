#include <stdio.h>
#include <math.h>

#define  PI  4*atan(1)


double PHI (double u) {
// Standard Normal Probability Function
  return (1.0/sqrt(2.0 * PI))*exp(-0.5*u*u);
}

double NORMAL (double P) {
// Inverse Standard Normal Function
  double chimax,chisqval,epsilon,minchisq,maxchisq;
  epsilon = 1e-6;
  chimax = 1e6;
  minchisq = 0.0;
  maxchisq = chimax;
  if (P <= 0.0)
    return maxchisq;
  else
    if (P >= 1.0) return 0.0;
  chisqval = 0.5;
  while (fabs(maxchisq - minchisq) > epsilon) {
    if (PHI(chisqval) < P)
      maxchisq = chisqval;
    else
      minchisq = chisqval;
    chisqval = (maxchisq + minchisq) * 0.5;
  }
  return chisqval;
}


void main() {

  double P, X, Y;
  printf("\n Value of variable: "); scanf("%lf", &X);
  P = PHI(X);
  printf("\n Probability = %f\n\n", P);
  printf(" Verify:\n");
  Y = NORMAL(P);
  printf("   X = %f\n\n", Y);

}

// end of file normal.cpp