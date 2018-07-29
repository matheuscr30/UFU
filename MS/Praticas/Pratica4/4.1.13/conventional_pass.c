#include <stdio.h>
#include <math.h>

int main () {
    int i = 0;
    double data;
    double mean = 0.0;
    double acc = 0.0;
    double deviation;
    double variance;

    while(!feof(stdin)) {
        scanf("%lf\n",&data);
        mean += data; //xbarra ^ 2
        acc += (data * data); // x(i) ^ 2
        i++;
    }

    mean = (mean/i);
    variance = (acc / i) - (mean*mean);
    deviation = sqrt(variance);
    printf("\nfor a sample of size %ld\n", i);
    printf("mean ................. = %7.7lf\n", mean);
    printf("standard deviation ... = %7.7lf\n", deviation);
}