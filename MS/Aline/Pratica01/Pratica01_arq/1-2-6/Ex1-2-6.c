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

  while (!feof(fp)) {
    index++;
    arrival      = GetArrival(fp);
    if (arrival < departure) {
      delay      = departure - arrival;        /* delay in queue    */
    }
    else {
      delay      = 0.0;
    }                       /* no delay          */
    departure   = GetDeparture(fp);           /* time of departure */
    wait = departure - arrival;
    service = wait - delay;

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

  /// Resposta A:   O tempo medio de serviço: 3.0319, a utilização do serviço é 0.7396
  ///            e a intensidade de trafego é 12.3695

  /// Resposta B:   O tempo de serviço (s) se relaciona da seguinte forma:
  ///            s = wait - delay
  ///            s = (departure (i) - arrival (i) )-delay
  ///            s = (C(i) - A(i)) - (departure (i-1) - arrival(i))
  ///            s = (C(i) - A(i)) - (C(i-1) - A(i))
  ///            s = (C(i) - C(i-1) - 2*A(i))
  ///ESSES i, E i-1 Q TÁ DENTRO DE PARENTENTESES NA B TEM Q COLOCAR SUBESCRITO NO RELATORIO
  fclose(fp);
  return (0);
}
