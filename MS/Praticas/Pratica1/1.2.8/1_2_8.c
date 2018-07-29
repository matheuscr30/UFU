
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

#define FILENAME   "ssq1.dat"                  /* input data file */
#define START      0.0

double constantService = 10.486;

/* =========================== */
   double GetArrival(FILE *fp)                 /* read an arrival time */
/* =========================== */
{
  double a;

  fscanf(fp, "%lf", &a);
  return (a);
}

/* =========================== */
   double GetService(FILE *fp)                 /* read a service time */
/* =========================== */
{
  double s;

  fscanf(fp, "%lf\n", &s);
  s = constantService;
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

  double arrivals[1005];
  double services[1005];

  while (!feof(fp)) {
    index++;
    arrivals[index] = GetArrival(fp);
    services[index] = GetService(fp);
  }

  int i, j;
  double traffic[] = {0.6, 0.7, 0.8, 0.9, 1.0, 1.1, 1.2};
  for(j = 0; j < 7; j++){
    arrival = START;
    departure = START;
    sum.delay = sum.wait = sum.service = sum.interarrival = 0;

    for(i = 1; i <= 1000; i++){
      arrival = arrivals[i];

      if (arrival < departure)
        delay      = departure - arrival;      /* delay in queue    */
      else                                     /* no delay          */
        delay      = 0.0;

      service      = services[i] * traffic[j];
      wait         = delay + service;
      departure    = arrival + wait;             /* time of departure */
      sum.delay   += delay;
      sum.wait    += wait;
      sum.service += service;
    }
    sum.interarrival = arrival - START;

    printf("\n\n\nfor %ld jobs\n", index);
    printf("  using traffic %6.2f\n", traffic[j]);
    printf("  r - average interarrival time....... = %6.2f\n", sum.interarrival / index);
    printf("  s - average service time ........... = %6.2f\n", sum.service / index);
    printf("  d - average delay .................. = %6.2f\n", sum.delay / index);
    printf("  w - average wait ................... = %6.2f\n", sum.wait / index);
    printf("  q - average jobs in the queue....... = %6.2f\n", sum.delay / departure);
    printf("  x - average jobs in the service..... = %6.2f\n", sum.service / departure);
    printf("  l - average jobs in the service node = %6.2f\n", (sum.delay/departure) + (sum.service/departure));
  }

  fclose(fp);
  return (0);
}
