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

  ///####################################
  double max_delay=0;
  double delayed_proportion=0;
  int jobs_in_node =0;
  double in_time = 400;
  ///####################################

  while (!feof(fp)) {
    index++;
    arrival      = GetArrival(fp);
    if (arrival < departure) {
      delay      = departure - arrival;        /* delay in queue    */
///################################
      delayed_proportion+=1;
///################################
    }
    else {
      delay      = 0.0;
    }                       /* no delay          */
    service      = GetService(fp);
    wait         = delay + service;
    departure    = arrival + wait;             /* time of departure */

///###########################################
    if(delay > max_delay){
        max_delay = delay;
    }
///###########################################

///############################################
    if(arrival< in_time && departure> in_time){
        jobs_in_node++;
    }
///############################################

    sum.delay   += delay;
    sum.wait    += wait;
    sum.service += service;
  }
  sum.interarrival = arrival - START;

  printf("\nfor %ld jobs\n", index);
  printf("   average interarrival time = %.4f\n", sum.interarrival / index);
  printf("   average service time .... = %.4f\n", sum.service / index);
  printf("   average delay ........... = %.4f\n", sum.delay / index);
  printf("   average wait ............ = %.4f\n", sum.wait / index);

printf("\n\nRESOLUCAO 1.2.3:  ________________________________\n\n");
  printf("   max delay = %.4f\n",max_delay);
  printf("   delayed proportion = %.4f \n",delayed_proportion/index);
  printf("   number of jobs in the node int time %.3f = %d \n", in_time,jobs_in_node);

  printf("__________________________________________________\n\n");

  /// SÓ NÃO SOUBE EXPLICAR A RELAÇÃO DO TEOREMA 1.2.1 COM A RESPOSTA DA C, VOU PESQUISAR DIREITO DEPOIS
  /// Resposta A:  Alterações do código.
  /// Resposta B:  O delay maximo foi de 118.7610.
  /// Resposta C:  No tempo 400, temos 7 jobs dentro do nó de serviço.
  /// Resposta D:  A proporção de jobs que esperam na fila é 72.3%.
  ///            significando que o servidor está sobrecarregado, fazendo
  ///            com que 72.3% dos jobs espere para ser atendido.

  fclose(fp);
  return (0);
}
