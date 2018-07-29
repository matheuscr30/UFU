
/* -------------------------------------------------------------------------
 * This program - an extension of program ssq1.c - simulates a single-server
 * FIFO service node using Exponentially distributed interarrival times and
 * Uniformly distributed service times (i.e. a M/U/1 queue).
 *
 * Name              : ssq2.c  (Single Server Queue, version 2)
 * Author            : Steve Park & Dave Geyer
 * Language          : ANSI C
 * Latest Revision   : 9-11-98
 * -------------------------------------------------------------------------
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "rngs.h"

#define LAST         100000L                   /* number of jobs processed */
#define START        0.0                      /* initial time             */


   double Exponential(double m)
/* ---------------------------------------------------
 * generate an Exponential random variate, use m > 0.0
 * ---------------------------------------------------
 */
{
  return (-m * log(1.0 - Random()));
}

   double Uniform(double a, double b)
/* --------------------------------------------
 * generate a Uniform random variate, use a < b
 * --------------------------------------------
 */
{
  return (a + (b - a) * Random());
}

  int main(void)
{
    FILE* arq1 = fopen("media.txt", "w");
    FILE* arq2 = fopen("desvio.txt", "w");
    FILE* arq3 = fopen("vetor.txt", "w");

    double* vetor = calloc(sizeof(double), 5000);
    double acc_m = 0, acc_s = 0, erro = 10000;
    double anterior=100,media=0,desvio_pad=0;
    int i;

    for(i = 1; erro>0.0001; i++){
        vetor[i] = Exponential(17);
        fprintf(arq3, "%lf\n", vetor[i]);
        acc_m += vetor[i];
        acc_s += pow(vetor[i], 2);
        media = ((acc_m/(double)i));
        fprintf(arq1, "%lf\n", media);
        desvio_pad = sqrt(((acc_s/(double)i))- pow(media,2));
        erro = fabs((media - anterior)/media);
        anterior = media;
    }

    fclose(arq1);
    fclose(arq2);
    fclose(arq3);
    printf("\nConvergiu com erro inferior a 0.0001 em : %d\n",i);
    return (0);
}
