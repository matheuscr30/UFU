#include <stdio.h>
#include <math.h>                                             
#include "rng.h"

double Exponential(double m)                 
{                                       
  return (-m * log(1.0 - Random()));     
}

int main(){
	FILE *arq;
	arq = fopen("expo.txt","w+");
	int n = 0;
	double x = 0.0;
	double xb = 0.0;
	double v = 0.0;
	double d = 0.0;
	double s = 0.0;	
  	double  min;
  	double  max;
	
	PutSeed(12345);
		
	min = Exponential(7.0);
	max = Exponential(7.0);

	while ( n<1000 ) {
		x = Exponential(7.0);
		fprintf(arq,"%f\n",x);
		n++;
		d = x - xb; /* temporary variable */
		v = v + d * d * (n - 1) / n;
		xb = xb + d / n;
		if (x > max)
      			max = x;
    		else if (x < min)
      			min = x;
	}

	s = sqrt(v / n);
	//return n, xb, s;
	printf("\nfor a sample of size %d\n", n);
	printf("xb ................. = %7.3f\n", xb);
    	printf("s  ................. = %7.3f\n", s);
	printf("minimum ............ = %7.3f\n", min);
    	printf("maximum ............ = %7.3f\n", max);
}	
