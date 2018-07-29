#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "rngs.h"

/**
Exercise 4.1.11 Calculate ¹x and s by hand using the 2-pass algorithm, the 1-pass
algorithm, and Welford's algorithm in the following two cases. (a) The data based on
n = 3 observations: x1 = 1, x2 = 6, and x3 = 2. (b) The sample path x(t) = 3 for
0 < t · 2, and x(t) = 8 for 2 < t · 5, over the time interval 0 < t · 5.
*/

/**
        3, 0<=t<=2
x(t) =  8, 2<t<= 5

No intervalo: [1,2,3,4,5]
*/

double x( int t){
    if(0<t && t<= 2)
        return 3;
    if(2<t && t<=5)
        return 8;
    else return -1;
}
double Exponential(double m){
    return (-m * log(1.0 - Random()));
}
double Uniform(double a, double b){
  return (a + (b - a) * Random());
}
long Equilikely(long a, long b){
    return (a + (long) ((b - a + 1) * Random()));
}

void mean(double *v,int n){
int i;
double average,acc_m;

for(i=0,acc_m=0; i<n;i++){
acc_m+=v[i];
}
average = acc_m/n;
printf("\nAverage: %f",average);
}
void twoPassS(double *v, int n){
int i;
double average,acc_s,acc_m,deviation;

for(i=0,acc_m=0;i<n;i++){
    acc_m+=v[i];
}

average= acc_m/((double) n);

for (i=0, acc_s=0;i<n;i++){
    acc_s += pow((v[i]- average),2);
}

deviation = sqrt( acc_s/ ((double)n));


printf("\nTwo Pass Algorithm: %lf", deviation);

}
void onePassS(double *v, int n){
int i;
double acc_s=0, deviation=0, acc_m=0, average;

for(i=0, acc_s=0,acc_m=0; i< n ; i++){
    acc_s += (v[i] *v[i]);
    acc_m += v[i];

}
average = acc_m/(double)n;


deviation=sqrt(acc_s/((double) n) - (average*average));


printf("\nOne Pass Algorithm: %lf", deviation);

}
void welfordS(double *vetor, int size){
int n;
double mean=0, v=0, x=0, d=0,s=0;

for(n=0;n<size;){
    x = vetor[n];
    n++;
    d = x -mean;
    v = v + d*d * (double)((double)(n-1))/((double) n);
    mean= mean + d/((double)n);
}
    s=sqrt(v/((double)n));

    printf("\nWelford One pass Algorithm: %lf\n", s);
}


int main()
{


int n=3,i;
double *v=calloc(sizeof(double),n);

v[0]=1;
v[1]=6;
v[2]=2;
/// Vetor ///////////////

printf("----------------------------------------------------\nLETRA (A):\n\n");
mean(v,n);
twoPassS(v,n);
onePassS(v,n);
welfordS(v,n);

free(v);


n=5;
v= calloc(sizeof(double),n);
for(i=0;i<n;i++){
    v[i]= x(i+1);
    printf("%lf  ",v[i]);
}
printf("\n\n----------------------------------------------------\nLETRA (B):\n\n");
mean(v,n);
twoPassS(v,n);
onePassS(v,n);
welfordS(v,n);
printf("\n----------------------------------------------------\n");
free(v);
return 0;
}
