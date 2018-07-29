
/* -------------------------------------------------------------------------
 * This program simulates a single-server FIFO s node using a
 * times and s times read from a text file.  The server is assumed
 * to be idle when the first job arrives.  All jobs are processed completely
 * so that the server is again idle at the end of the simulation.   The
 * output statistics are the average intera time, average s
 * time, the average d in the queue, and the average w in the s
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
   double Geta(FILE *fp)                 /* read an a time */
/* =========================== */
{
  double a;

  fscanf(fp, "%lf", &a);
  return (a);
}

/* =========================== */
   double Gets(FILE *fp, double n)                 /* read a s time */
/* =========================== */
{
  double s;

  fscanf(fp, "%lf\n", &s);
  return (n * s);
}

/* ============== */
   int main(void)
/* ============== */
{
  FILE   *fp;                           /* input data file      */
  double ti = 0.6;                      //traffic intensity

  printf("Average r time using the data file = 9.87\n"); //interarrive time
  printf("Average s time using the data file = 7.12\n");
  printf("Traffic intensity using the data file(s/r) = 0.721\n");


  while(ti <= 1.2){
            long   index     = 0;                        /* job index            */
          double a   = START;                    /* a time         */
          double d;                                /* d in queue       */
          double s;                              /* s time         */
          double w;                                 /* d + s      */
          double c = START;                    /* c time       */
          struct {                                     /* sum of ...           */
            double d;                              /*   d times        */
            double w;                               /*   w times         */
            double s;                            /*   s times      */
            double intera;                       /*   intera times */
          } sum = {0.0, 0.0, 0.0};

        int esperando = 0;
        int semEspera = 0;
          fp = fopen(FILENAME, "r");
          if (fp == NULL) {
            fprintf(stderr, "Cannot open input file %s\n", FILENAME);
            return (1);
          }

          while (!feof(fp)) {

            index++;
            a      = Geta(fp);
            if (a < c){
                esperando++;
                d      = c - a;        /* d in queue    */
            }else {
                semEspera++;
                d      = 0.0;                        /* no d          */
            }
            s      = Gets(fp, ti/0.721);
            w         = d + s;
            c    = a + w;             /* time of c */
            sum.d   += d;
            sum.w    += w;
            sum.s += s;
          }
          sum.intera = a - START;

          printf("\nFor traffic intensity %.3f\n", ti);
          printf("Average x ............ = %.3f\n", sum.s / c);
          printf("Average q ............ = %.3f\n", sum.d / c);
          printf("Average l ............ = %.3f\n", sum.w / c);
          printf("Intensidade de tráfego = %.1f\n", sum.s / sum.intera);
          ti = ti + 0.1;
  }

  fclose(fp);
  return (0);
}
