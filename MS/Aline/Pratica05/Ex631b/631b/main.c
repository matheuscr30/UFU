#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "rvms.h"
#include "rng.h"
#include "rng.c"
#include "rvms.c"

double Uniform(double a, double b)
{
  return (a + (b - a) * Random());
}

long inverse_truncated() {
				double a = cdfBinomial(100, 0.1, 4 - 1);// (seria o 4 - 1 )
				double b = 1 - cdfBinomial(100, 0.1, 16); // b (16)
				double u = Uniform(a, 1 - b);
				return idfBinomial(100, 0.1, u);
}
int main()
{
    FILE *arq;
    arq = fopen("arquivo.txt","w+");
    int i;
    for (i=0;i<10000;i++){
        fprintf(arq,"%ld\n",inverse_truncated());
    }
    fclose(arq);
    return 0;
}
