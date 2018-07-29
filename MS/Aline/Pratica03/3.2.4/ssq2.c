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
#include "rngs.h"
#include "rngs.c"

#define LAST         10000L                   /* number of jobs processed */
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


double GetArrival(int *j)
/* ------------------------------
 * generate the next arrival time
 * ------------------------------
 */
{
//  static double arrival = START;
//
//  arrival += Exponential(2.0);
//  return (arrival);
    const double mean[2] = {4.0, 6.0};
    static double arrival[2] = {START, START};
    static int init = 1;
    double temp;
    if (init)   /* initialize the arrival array */
    {
        SelectStream(0);
        arrival[0] += Exponential(mean[0]);
        SelectStream(1);
        arrival[1] += Exponential(mean[1]);
        init = 0;
    }
    if (arrival[0] <= arrival[1])
        *j = 0; /* next arrival is job type 0 */
    else
        *j = 1; /* next arrival is job type 1 */
    temp = arrival[*j]; /* next arrival time */
    SelectStream(*j); /* use stream j for job type j */
    arrival[*j] += Exponential(mean[*j]);
    return (temp);
}


double GetService(int j)
/* ------------------------------
 * generate the next service time
 * ------------------------------
 */
{
//    return (Uniform(1.0, 2.0));
    const double min[2] = {1.0, 0.0};
    const double max[2] = {3.0, 4.0};
    SelectStream(j + 2); /* use stream j + 2 for job type j */
    return (Uniform(min[j], max[j]));

}


int main(void)
{
    int j, indexA, indexB;
    long   index     = 0;                         /* job index            */
    double arrival   = START;                     /* time of arrival      */
    double delay;                                 /* delay in queue       */
    double service;                               /* service time         */
    double wait;                                  /* delay + service      */
    double departure = START;                     /* time of departure    */
    struct                                        /* sum of ...           */
    {
        double delay[2];                               /*   delay times        */
        double wait[2];                                /*   wait times         */
        double service[2];                             /*   service times      */
        double interarrival[2];                        /*   interarrival times */
    } sum = {{0.0, 0.0, 0.0},{0.0, 0.0, 0.0}};

    PlantSeeds(123456789);

    while (index < LAST)
    {
        index++;
        arrival      = GetArrival(&j);
        if(j == 0)
            indexA++;
        else if(j ==1)
            indexB++;
        if (arrival < departure)
            delay      = departure - arrival;         /* delay in queue    */
        else
            delay      = 0.0;                         /* no delay          */
        service      = GetService(j);
        wait         = delay + service;
        departure    = arrival + wait;              /* time of departure */
        sum.delay[j]   += delay;
        sum.wait[j]    += wait;
        sum.service[j] += service;
    }

    sum.interarrival[0] = arrival - START;

    sum.interarrival[1] = arrival - START;

    int i, auxIndex[2]={indexA,indexB};

    for(i=0; i<2; i++)
    {
        printf("\nfor %ld jobs\n", auxIndex[i]);
        printf("   average interarrival time = %6.2f\n", sum.interarrival[i] / auxIndex[i]);
        printf("   average wait ............ = %6.2f\n", sum.wait[i] / auxIndex[i]);
        printf("   average delay ........... = %6.2f\n", sum.delay[i] / auxIndex[i]);
        printf("   average service time .... = %6.2f\n", sum.service[i] / auxIndex[i]);
        printf("   average # in the node ... = %6.2f\n", sum.wait[i] / departure);
        printf("   average # in the queue .. = %6.2f\n", sum.delay[i] / departure);
        printf("   utilization ............. = %6.2f\n", sum.service[i] / departure);
    }
    return (0);
}
