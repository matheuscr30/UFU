
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
#include <math.h>
#include "../rng.h"
#include <windows.h>

#define LAST         10000                   /* number of jobs processed */
#define START        0.0                      /* initial time             */


double Exponential(double m)
{
    return (-m * log(1.0 - Random()));
}


double Uniform(double a, double b)
{
    return (a + (b - a) * Random());
}


static double arrival1 = START;

double GetArrival(void)
{
    arrival1 += Exponential(2.0);

    return (arrival1);
}

long Geometric(double p) /* use 0.0 < p < 1.0 */
{
    return ((long) (log(1.0 - Random()) / log(p)));
}


double GetService(void)
{
    long k;
    double sum = 0.0;
    long tasks = 1 + Geometric(0.9);
    for (k = 0; k < tasks; k++)
        sum += Uniform(0.1, 0.2);
    return (sum);
}

int main(void)
{
    int j;
    for(j=500; j<=500; j+=2)
    {
        double s1 = 0.0;
        double s2 = 0.0;
        double s3 = 0.0;
        double s4 = 0.0;
        double s5 = 0.0;
        double s6 = 0.0;
        double s7 = 0.0;

        int i;

        for (i=0; i<=j; i++)
        {
            long   index     = 0;                         /* job index            */
            double arrival   = START;                     /* time of arrival      */
            double delay;                                 /* delay in queue       */
            double service;                               /* service time         */
            double wait;                                  /* delay + service      */
            double departure = START;                     /* time of departure    */
            struct                                        /* sum of ...           */
            {
                double delay;                               /*   delay times        */
                double wait;                                /*   wait times         */
                double service;                             /*   service times      */
                double interarrival;                        /*   interarrival times */
            } sum = {0.0, 0.0, 0.0};

            PutSeed(-1);

            while (index < LAST)
            {
                index++;
                arrival      = GetArrival();

                if (arrival < departure)
                    delay      = departure - arrival;         /* delay in queue    */
                else
                    delay      = 0.0;                         /* no delay          */
                service      = GetService();
                wait         = delay + service;
                departure    = arrival + wait;              /* time of departure */
                sum.delay   += delay;
                sum.wait    += wait;
                sum.service += service;
            }

            sum.interarrival = arrival - START;

            s1 += (sum.interarrival / index);
            s2 += (sum.wait / index);
            s3 += (sum.delay / index);
            s4 += (sum.service / index);
            s5 += (sum.wait / departure);
            s6 += (sum.delay / departure);
            s7 += (sum.service / departure);

            arrival1 = START;
            Sleep(1100);
        }

//    printf("Executing the modified ssq2 %d times and taking the means of the outputs the results are,", i);
//    printf("\nfor %ld jobs\n", LAST);
//    printf("   average interarrival time = %6.2f\n", s1/i);
//    printf("   average wait ............ = %6.2f\n", s2/i);
//    printf("   average delay ........... = %6.2f\n", s3/i);
//    printf("   average service time .... = %6.2f\n", s4/i);
//    printf("   average # in the node ... = %6.2f\n", s5/i);
//    printf("   average # in the queue .. = %6.2f\n", s6/i);
//    printf("   utilization ............. = %6.2f\n", s7/i);

        FILE *arq = fopen("averageDelay.txt", "a");

        fprintf(arq,"%f,%d\n", (s3/i), j);

        fclose(arq);
    }

    return (0);
}
