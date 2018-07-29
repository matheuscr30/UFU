#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
#include "rngs.h"
#include "rngs.c"

double Exponential(double m)
{
    return (-m * log(1.0 - Random()));
}

double sampleMean(double *sample, int j)
{
    int i;
    double mean = 0;

    for(i=0; i<j; i++) 
    {
        mean+= sample[i];
    }

    return (mean/j);
}

double sampleStandartDeviation(double *sample, double mean, int j)
{
    int i;
    double variance = 0;

    for(i=0; i<j; i++) 
    {
        variance+= pow(sample[i] - mean, 2);
    }

    variance = variance/j;

    return sqrt(variance);
}

int main()
{
    FILE *f;
    f = fopen("file.txt", "w");

    int n = 0;
    double mean = 0, v = 0.0, s, x, d;

    PlantSeeds(11111);

    while(n <= 100)
    {
        x = Exponential(17);
        n++;
        d = x - mean;
        v = v + d * d * (n-1)/n;
        mean += d/n;
        fprintf(f, "%d %.2lf %.2lf %.2lf\n", n, x, mean, sqrt(v/n));
    }

    s = sqrt(v / n);

    fclose(f);

    return 0;
}
