
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

  double data[1005][2];

  while (!feof(fp)) {
    index++;
    arrival      = GetArrival(fp);
    if (arrival < departure) 
      delay      = departure - arrival;        /* delay in queue    */
    else 
      delay      = 0.0;                        /* no delay          */
    service      = GetService(fp);

    //Salva dados para calcular tabela do item (b)
    data[index][0] = arrival;
    data[index][1] = service;


    wait         = delay + service;
    departure    = arrival + wait;             /* time of departure */
    sum.delay   += delay;
    sum.wait    += wait;
    sum.service += service;
  }
  sum.interarrival = arrival - START;

  //Calculos necessarios para o item (a)

  double qbarra = (sum.delay/index) * (index/departure);
  double xbarra = (sum.service/index) * (index/departure);
  double lbarra = (sum.wait/index) * (index/departure);

  printf("\nfor %ld jobs\n", index);
  printf("   average interarrival time = %6.2f\n", sum.interarrival / index);
  printf("   average service time .... = %6.2f\n", sum.service / index);
  printf("   average delay ........... = %6.2f\n", sum.delay / index);
  printf("   average wait ............ = %6.2f\n", sum.wait / index);

  //Calculos para o item (a)
  printf("   time averaged in queue .. = %6.2f\n", qbarra);
  printf("   time averaged in service  = %6.2f\n", xbarra);
  printf("   time averaged in node ... = %6.2f\n", lbarra);


  //Gerar a tabela do item (b)
  double multiplier = 0.6;
  
  printf("\n\nMultiplier |     q    |     x     |      l     \n");
  printf("-----------------------------------------------------\n");
  while (multiplier < 1.3) {
      sum.delay = 0.0;
      sum.service = 0.0;
      sum.wait = 0.0;
      arrival = START;
      departure = START;
      
      int i;
      for (i = 1; i<= 1000; i++) {
        arrival      = data[i][0];
        if (arrival < departure) 
          delay      = departure - arrival;        /* delay in queue    */
        else 
          delay      = 0.0;                        /* no delay          */
        service      = data[i][1] * multiplier;

        wait         = delay + service;
        departure    = arrival + wait;             /* time of departure */
        sum.delay   += delay;
        sum.wait    += wait;
        sum.service += service;
      }
    qbarra = (sum.delay/index) * (index/departure);
    xbarra = (sum.service/index) * (index/departure);
    lbarra = (sum.wait/index) * (index/departure);

    printf("%11.2f|%10.2f|%11.2f|%10.2f\n",multiplier,qbarra,xbarra,lbarra);
    multiplier += 0.1;
  }
  printf("-----------------------------------------------------\n");

  //Resposta do item (c)

  /*
    As estatisticas baseadas em tempo q, x e l dependem pesadamente da intensidade do tráfego.

    Isso porque aumentar o tráfego através de um multiplicador no tempo de serviço, representa uma demora maior
    no tempo de cada serviço. Essa demora maior no tempo de serviço representa um possível aumento no numero de pessoas na fila
    num dado instante t. Essa função é q(t) e qbarra é basicamente a integral de q(t) num intervalo de tempo dividido pelo tempo.

    Aumentando o tráfego, aumentamos q (numero medio de pessoas na fila por tempo). Alem disso, aumentamos também a utilização média
    do nó de serviço (xbarra). O aumento desses dois fatores, implica diretamente no aumento  de lbarra, que é basicamente o numero medio
    de trabalhos para o nó de serviço.

  */

  //Simulação para calculo do item (d)

  multiplier = 1.0;
  qbarra = 0.0;

  while (qbarra < 5.0) {
    multiplier += 0.01;
    sum.delay = 0.0;
    sum.service = 0.0;
    sum.wait = 0.0;
    arrival = START;
    departure = START;
    
    int i;
    for (i = 1; i<= 1000; i++) {
      arrival      = data[i][0];
      if (arrival < departure) 
        delay      = departure - arrival;        /* delay in queue    */
      else 
        delay      = 0.0;                        /* no delay          */
      service      = data[i][1] * multiplier;

      wait         = delay + service;
      departure    = arrival + wait;             /* time of departure */
      sum.delay   += delay;
      sum.wait    += wait;
      sum.service += service;
    }

    qbarra = (sum.delay/index) * (index/departure);
  }

  printf("\n\n The maximum increase in service for a q less than 5.0 is %.2f\n\n", multiplier-0.01);

  fclose(fp);
  return (0);
}
