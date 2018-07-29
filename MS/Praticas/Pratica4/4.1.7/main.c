#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
#define n 100
#define st 10
#include "rngs.h"

double Exponential(double m)
{
  return ((-m) * log(1.0 - Random()));
}

double sampleMean(double *sample)
{
    int i;
    double mean = 0;

    for(i=0; i<n; i++) {
        mean+= sample[i];
    }

    return (mean/n);
}

double sampleStandartDeviation(double *sample, double mean)
{
    int i;
    double variance = 0;

    for(i=0; i<n; i++) {
        variance+= pow(sample[i] - mean, 2);
    }

    variance = variance/n;

    return sqrt(variance);
}

int main()
{

    int i, aux = 0, count2s = 0, count3s = 0;
    double sample[n], mean, variance;


    printf("Proporção de amostras em: \ntype \tmédia+-2*s \tmédia+-3*s \n");

    while(aux < 10)
    {
        SelectStream(aux);
        for(i=0; i<n; i++)
        {
            sample[i] = Exponential(9);
        }

        mean = sampleMean(sample);
        variance = sampleStandartDeviation(sample, mean);

        for(i=0; i<n; i++)
        {
            if(sample[i] >= (mean - 2*variance) && sample[i] <= (mean + 2*variance))
                count2s++;
            if(sample[i] >= (mean - 3*variance) && sample[i] <= (mean + 3*variance))
                count3s++;
        }

        printf("%d \t%.2f \t\t%.2f \n", aux, (double)count2s/n, (double)count3s/n);
        count2s = 0;
        count3s = 0;
	aux++;
    }

    printf("\n\nChebyshev's inequality para k=2: pk >= %.2f, 1.0-1.0/4.0);
    printf("\nChebyshev's inequality para k=3: pk >= %.2f\n", 1.0-1.0/9.0);

    return 0;
}
