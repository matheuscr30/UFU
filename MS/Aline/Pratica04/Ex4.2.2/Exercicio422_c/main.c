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
int n_boxes = 1000;
int n_balls = 10000;
FILE *f = fopen("hist.txt","w");

long *boxes = calloc(sizeof(long),n_boxes), *histogram ;
int i,choose,max=0, size_histogram=0;
double acc;
PutSeed(SEED);


for(i=0;i<n_balls;i++){
        choose= Equilikely(0,n_boxes-1);
        if(choose<0 || choose >=n_boxes){
            printf("\n\nERRROOO\n\n");
            exit(1);
        }
        if(boxes[choose]> max){
            max = boxes[choose];
        }
        boxes[choose]++;
}

size_histogram=max+1;
histogram=calloc(sizeof(long),size_histogram);

for(i=0,acc=0;i<n_boxes;i++){
    histogram[boxes[i]]++;
    acc+= boxes[i];
}

for(i=0,acc=0;i<size_histogram;i++){
        fprintf(f,"%lf\n", ((double) histogram[i]) / ((double)n_boxes)  );
}


free(f);
return 0;
}


