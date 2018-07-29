#include <stdio.h>

#define FILENAME   "ac.dat"                  /* input data file */
#define OUTPUT     "output_services.dat"
#define START      0.0

/* =========================== */
double GetArrival(FILE *fp)                 /* read an arrival time */
/* =========================== */
{
    double a;

    fscanf(fp, "%lf", &a);
    return (a);
}

/* =========================== */
double GetDeparture(FILE *fp)                 /* read a service time */
/* =========================== */
{
    double s;

    fscanf(fp, "%lf\n", &s);
    return (s);
}

/* ============== */
int main(void)
/* ============== */
{



    FILE   *fp;                                  /* input data file      */
    FILE   *output = fopen(OUTPUT,"w");
    long   index     = 0;                        /* job index            */
    double arrival   = START;                    /* arrival time         */
    double delay;                                /* delay in queue       */
    double service;                              /* service time         */
    double wait;                                 /* delay + service      */
    double departure = START;                    /* departure time       */

    struct                                       /* sum of ...           */
    {
        double delay;                              /*   delay times        */
        double wait;                               /*   wait times         */
        double service;                            /*   service times      */
        double interarrival;                       /*   interarrival times */
    } sum = {0.0, 0.0, 0.0};

    fp = fopen(FILENAME, "r");
    if (fp == NULL)
    {
        fprintf(stderr, "Cannot open input file %s\n", FILENAME);
        return (1);
    }

    while (!feof(fp))
    {
        index++;
        arrival      = GetArrival(fp);
        if (arrival < departure)
        {
            delay      = departure - arrival;        /* delay in queue    */
        }
        else
        {
            delay      = 0.0;
        }                       /* no delay          */
        departure   = GetDeparture(fp);           /* time of departure */
        wait= departure - arrival;
        service= wait-delay;

        fprintf(output,"%lf\n",service);

        sum.delay   += delay;
        sum.wait    += wait;
        sum.service += service;
    }
    sum.interarrival = arrival - START;

    printf("\nfor %ld jobs\n", index);
    printf("   average interarrival time = %.4f\n", sum.interarrival / index);
    printf("   average service time .... = %.4f\n", (sum.service / index));
    printf("   average delay ........... = %.4f\n", sum.delay / index);
    printf("   average wait ............ = %.4f\n", sum.wait / index);
    printf("   server utilization ...... = %.4f\n", (index/departure)*(sum.service / index));
    printf("   traffic intensity ....... = %.4f\n", (sum.service / index)* (sum.interarrival / index));

    fclose(fp);
    fclose(output);
    return (0);
}
