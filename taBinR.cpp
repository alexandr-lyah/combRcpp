library(Rcpp)
#Biggest value in the column
cppFunction('
double bigVal(NumericVector x) {
  
  int n = x.size(), index = 0;
  
  for(int i = 0; i < n; ++i) {
				if(x[index] < x[i]){ index=i;}
  }
  return x[index];
}
')
#Smallest value in the column
cppFunction('
double smallVal(NumericVector x) {
  
  int n = x.size(), index = 0;
  
  for(int i = 0; i < n; ++i) { 
				if(x[index] > x[i]){ index=i;}
  }
  return x[index];
}
')
