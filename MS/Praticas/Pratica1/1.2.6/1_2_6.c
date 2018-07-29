
/* -------------------------------------------------------------------------
 * This program simulates a single-server FIFO service node using arrival
 * times and service times read from a text file.  The server is assumed
 * to be idle when the first job arrives.  All jobs are processed completely
 * so that the server is again idle at the end of the simulation.   The
 * output statistics are the average interarrival time, average service
 * time, the average delay in the queue, and the average wait in the service 
 * node. 
 *
 * Name              : ssq1.c  (Single Server Queue, version 1)
 * Authors           : Steve Park & Dave Geyer
 * Language          : ANSI C
 * Latest Revision   : 9-01-98
 * Compile with      : gcc ssq1.c 
 * ------------------------------------------------------------------------- 
 */

#include <stdio.h>                              

#define FILENAME   "ac.dat"                  /* input data file */
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
  long   index     = 0;                        /* job index            */
  double arrival   = START;                    /* arrival time         */
  double delay;                                /* delay in queue       */
  double service;                              /* service time         */
  double wait;                                 /* delay + service      */
  double departure = START;                    /* departure time       */
  struct {                                     /* sum of ...           */
    double delay;                              /*   delay times        */
    double wait;                               /*   wait times         */
    double service;                            /*   service times      */
    double interarrival;                       /*   interarrival times */
  } sum = {0.0, 0.0, 0.0};

  fp = fopen(FILENAME, "r");
  if (fp == NULL) {
    fprintf(stderr, "Cannot open input file %s\n", FILENAME);
    return (1);
  }
  
  double last_arrival, last_departure;
  while (!feof(fp)) {
    index++;
    arrival      = GetArrival(fp);
    // if (arrival < departure) 
    //   wait       = departure - arrival;        /* delay in queue    */
    // else 
    //   delay      = 0.0;                        /* no delay          */
    departure    = GetDeparture(fp);
    wait         = departure - arrival;

    if (index == 1) {
        service      = departure - arrival;
        delay        = 0.0;
    } else {
        if (arrival < last_departure)
            delay    = last_departure - arrival;
        else
            delay = 0.0;

        service = departure - arrival - delay;      
    }

    sum.delay   += delay;
    sum.wait    += wait;
    sum.service += service;

    last_arrival = arrival;
    last_departure = departure;
  }
  sum.interarrival = arrival - START;

  printf("\nfor %ld jobs\n", index);
  printf("   average service time .... = %6.2f\n", sum.service / index);
  printf("   server utilization....... = %6.2f\n", sum.service / last_departure);
  printf("   traffic intensity ....... = %6.2f\n", (departure/arrival) * (sum.service / last_departure));

  fclose(fp);
  return (0);
}
