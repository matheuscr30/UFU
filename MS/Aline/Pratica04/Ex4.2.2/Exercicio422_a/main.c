#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "rng.h"

double Exponential(double m){
    return (-m * log(1.0 - Random()));
}
double Uniform(double a, double b){
  return (a + (b - a) * Random());
}
long Equilikely(long a, long b){
    return (a + (long) ((b - a + 1) * Random()));
}

int main(){
int SEED = 12345;
int i, N = 1000;
int *boxes = calloc(sizeof(int),N);
double *histograma;
FILE *f = fopen("hist.txt","w");
int choosed;
int max=0;
PutSeed(SEED);

/// Colocando bola nas caixas
for(i=0; i< (10*N);i++){
       choosed= Equilikely(0,N);
    boxes[choosed]++;
    if(max<boxes[choosed])
        max=boxes[choosed];
}
histograma = calloc(sizeof(double),max);
///Extraindo o histograma
for(i=0;i<N;i++){
    histograma[boxes[i]]+= 1.0/((double)N);
}

///Gravando histograma em arquivo;
double acc;
for(i=0;i<=max;i++){
    printf("%d---> %lf  ",i,histograma[i]);
    fprintf(f,"%lf\n",histograma[i]);
    acc += (double) i *(histograma[i]/(double)N);
}

printf("\nMedia: %lf",acc);
return 0;
}


