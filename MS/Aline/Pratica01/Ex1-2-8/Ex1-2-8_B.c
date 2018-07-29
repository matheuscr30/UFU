
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
  int it = 6;

  while(it <= 12){
      long   index     = 0;                        /* job index            */
      double a   = START;                    /* a time         */
      double d;                                /* d in queue       */
      double s;                              /* s time         */
      double temp;
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
       temp      = Gets(fp);
        if(it == 6){
            s = 5.9232;
        }else if (it == 7){
            s = 6.9104;
        }else if(it == 8){
            s = 7.8976;
        }else if(it == 9){
            s = 8.8848;
        }else if(it == 10){
            s = 9.8720;
        }else if(it == 11){
            s = 10.8592;
        }else if(it ==12){
            s = 11.8464;
        }
        w         = d + s;
        c    = a + w;             /* time of c */
        sum.d   += d;
        sum.w    += w;
        sum.s += s;
      }
      sum.intera = a - START;
      it++;

    //  printf("\nfor %ld jobs\n", index);
      printf("\n   average r time = %.2f and average s time .... = %.2f\n", sum.intera / index, sum.s / index); //interarrive time
      printf("   Trafic intensity (s/r)...... = %.1f\n", (sum.s / index)/(sum.intera / index));
    //  printf("   average d ........... = %.2f\n", sum.d / index);
     // printf("   average w ............ = %.2f\n", sum.w / index);
      printf("   average q ............ = %.8f\n", sum.d / c);
      printf("   average x ............ = %.8f\n", sum.s / c);
      printf("   average l (q+x)............ = %.8f\n", sum.w / c);

  }


  /*
  printf("   a ............ = %6.8f\n", a);
  printf("   c ............ = %6.8f\n\n", c);

  printf("\n   Valor do tempo medio de servico para trafego de intensidade 0.6: %.4f\n", (0.6*sum.intera / index));
  printf("   Valor do tempo medio de servico para trafego de intensidade 0.7: %.4f\n", (0.7*sum.intera / index));
  printf("   Valor do tempo medio de servico para trafego de intensidade 0.8: %.4f\n", (0.8*sum.intera / index));
  printf("   Valor do tempo medio de servico para trafego de intensidade 0.9: %.4f\n", (0.9*sum.intera / index));
  printf("   Valor do tempo medio de servico para trafego de intensidade 1.0: %.4f\n", (1.0*sum.intera / index));
  printf("   Valor do tempo medio de servico para trafego de intensidade 1.1: %.4f\n", (1.1*sum.intera / index));
  printf("   Valor do tempo medio de servico para trafego de intensidade 1.2: %.4f\n", (1.2*sum.intera / index));
  */

  fclose(fp);
  return (0);
}
