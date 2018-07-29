
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
#define T          400

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

  double data[1005][2];
  double maximum_delay = 0.0;
  int jobs_delayed = 0;
  int jobs_at_time = 0;

  while (!feof(fp)) {
    index++;
    arrival      = GetArrival(fp);

    if (arrival < T && T < departure) {
      jobs_at_time++;
    }

    if (arrival < departure) { 
      delay      = departure - arrival;        /* delay in queue    */
      jobs_delayed++;
    }
    else { 
      delay      = 0.0;                        /* no delay          */
    }
    service      = GetService(fp);

    maximum_delay = delay > maximum_delay? delay : maximum_delay; //Computa o maior delay

    wait         = delay + service;
    departure    = arrival + wait;             /* time of departure */
    sum.delay   += delay;
    sum.wait    += wait;
    sum.service += service;
  }
  sum.interarrival = arrival - START;

  printf("\nfor %ld jobs\n", index);
  printf("   average interarrival time = %6.2f\n", sum.interarrival / index);
  printf("   average service time .... = %6.2f\n", sum.service / index);
  printf("   average delay ........... = %6.2f\n", sum.delay / index);
  printf("   average wait ............ = %6.2f\n", sum.wait / index);

  //Prints para responder ao item (a)
  printf("   maximum delay ........... = %6.2f\n", maximum_delay);
  printf("   jobs at time %d ........ = %6d\n", T, jobs_at_time);
  printf("   proportion of jobs delayed= %6.2f\n", (double)jobs_delayed/(double)index);

  fclose(fp);
  return (0);
}
