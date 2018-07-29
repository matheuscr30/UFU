#include <stdio.h>
#include "rvgs.h"

int main () {

    FILE *f = fopen("data.txt", "w");
    int i;
    for(i=0;i<1000; i++) {
        fprintf(f, "%lf\n", Exponential(7));
    }

    fclose(f);
}