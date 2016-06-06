//[The Kaplan–Meier estimator, also known as the product limit estimator, is a non-parametric statistic used to estimate the survival function from lifetime data. In medical research, it is often used to measure the fraction of patients living for a certain amount of time after treatment. In other fields, Kaplan–Meier estimators may be used to measure the length of time people remain unemployed after a job loss, the time-to-failure of machine parts, or how long fleshy fruits remain on plants before they are removed by frugivores. The estimator is named after Edward L. Kaplan and Paul Meier, who each submitted similar manuscripts to the Journal of the American Statistical Association. The journal editor, John Tukey, convinced them to combine their work into one paper, which has been cited about 34,000 times since its publication.] Wikipedia

library(Rcpp)
cppFunction('
double kpMeier(NumericVector x, NumericVector y, NumericVector z) {
  
    int n = x.size(), d = y.size(), t = z.size();
    double st = 0, var = 0;
	
	if ( n == d && n == t) {
		
		double st0;
		
		for(int i = 0; i < n; ++i) {
	        
			#if ( z[i-1] < z[i] ){}
			//The Kaplan–Meier estimator is the nonparametric maximum likelihood estimate of S(t), where the maximum is taken over the set of all piecewise constant survival curves with breakpoints at the event times ti. It is a product of the form
			st0 = x[i] - y[i];
	        st  =  st  + st0 / x[i];
						
			//Kaplan–Meier
			var =  var + y[i] / ( x[i] * ( x[i] -  y[i] ));
		}
		  var = pow( st, 2) * var;
		   
	}else{ perror (" Matrix dimension error occured  n <> m ");	}
 
  return var;
}
')
