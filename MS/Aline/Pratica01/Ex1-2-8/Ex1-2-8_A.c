
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
   double Gets(FILE *fp)                 /* read a s time */
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
    s      = Gets(fp);
    w         = d + s;
    c    = a + w;             /* time of c */
    sum.d   += d;
    sum.w    += w;
    sum.s += s;
  }
  sum.intera = a - START;

  printf("\nfor %ld jobs\n", index);
  printf("   average r time = %.2f\n", sum.intera / index); //interarrive time
  printf("   average s time .... = %.2f\n", sum.s);
  printf("   average d ........... = %.2f\n", sum.d / index);
  printf("   average w ............ = %.2f\n", sum.w / index);
  printf("   average q ............ = %.8f\n", sum.d / c);
  printf("   average x ............ = %.8f\n", sum.s / c);
  printf("   average l ............ = %.8f\n", sum.w / c);
  printf("   sum q + x ............ = %.8f\n", ((sum.d/c)+(sum.s/c)));
  printf("   a ............ = %6.8f\n", a);
  printf("   c ............ = %6.8f\n", c);
  printf("%.4f\n", c/index);

  fclose(fp);
  return (0);
}
