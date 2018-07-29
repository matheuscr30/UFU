#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "rvgs.h"

void generate_ball(int n) {
    int *f = malloc(sizeof(int) * n * 2);
    int *f_numbers = malloc(sizeof(int) * 25);
    int i;
    for(i=0;i<n;i++) {
        f[i] = 0;
    }
    for(i=0;i<25;i++) {
        f_numbers[i] = 0;
    }


    for(i=0;i<2*n;i++) {
        int k = Equilikely(1, n);
        f[k]++;
    }

    for(i=0;i<n;i++) {
        f_numbers[ f[i] ]++;
    }

    FILE *file = fopen("data.txt", "w");

    for(i=0;i<25;i++)
        fprintf(file, "%d %d\n", i, f_numbers[i]);

    fclose(file);

}

int main () {

    generate_ball(1000);

}