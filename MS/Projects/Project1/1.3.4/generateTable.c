
/* -------------------------------------------------------------------------
 * This program simulates a simple (s,S) inventory system using demand read
 * from a text file.  Backlogging is permitted and there is no delivery lag.
 * The output statistics are the average demand and order per time interval
 * (they should be equal), the relative frequency of setup and the time
 * averaged held (+) and short (-) inventory levels.
 *
 * NOTE: use 0 <= MINIMUM < MAXIMUM, i.e., 0 <= s < S.
 *
 * Name              : sis1.c  (Simple Inventory System, version 1)
 * Authors           : Steve Park & Dave Geyer
 * Language          : ANSI C
 * Latest Revision   : 8-20-97
 * Compile with      : gcc sis1.c
 * -------------------------------------------------------------------------
*/

#include <stdio.h>

#define FILENAME  "sis1.dat"            /* input data file                */
#define MAXIMUM   100                    /* 'S' inventory policy parameter */
#define sqr(x)    ((x) * (x))

int MINIMUM = 20;

/* ======================== */
   long GetDemand(FILE *fp)
/* ======================== */
{
  long d;

  fscanf(fp, "%ld\n", &d);
  return (d);
}

/* ============== */
   int main(void)
/* ============== */
{
  FILE *fp;                                /* input data file         */
  long index     = 0;                      /* time interval index     */
  long inventory = MAXIMUM;                /* current inventory level */
  long demand;                             /* amount of demand        */
  long order;                              /* amount of order         */
  struct {                                 /* sum of ...              */
    double setup;                          /*   setup instances       */
    double holding;                        /*   inventory held (+)    */
    double shortage;                       /*   inventory short (-)   */
    double order;                          /*   orders                */
    double demand;                         /*   demands               */
  } sum = { 0.0, 0.0, 0.0, 0.0, 0.0 };

  fp = fopen(FILENAME, "r");
  if (fp == NULL) {
    fprintf(stderr, "Cannot open input file %s\n", FILENAME);
    return (1);
  }

  long demands[1005];

  while(!feof(fp)){
      index++;
      demands[index] = GetDemand(fp);
  }

  int i, j;

  for(i = 0; i <= MAXIMUM; i++){
      MINIMUM = i;
      sum.setup = sum.holding = sum.shortage = 0;
      sum.order = sum.demand = 0;

      for (j = 1; j <= 1000; j++) {
        if (inventory < MINIMUM) {             /* place an order          */
          order         = MAXIMUM - inventory;
          sum.setup++;
          sum.order    += order;
        }
        else                                   /* no order                 */
          order         = 0;
        inventory      += order;               /* there is no delivery lag */
        demand          = demands[j];
        sum.demand     += demand;
        if (inventory > demand)
          sum.holding  += (inventory - 0.5 * demand);
        else {
          sum.holding  += sqr(inventory) / (2.0 * demand);
          sum.shortage += sqr(demand - inventory) / (2.0 * demand);
        }
        inventory      -= demand;
      }

      if (inventory < MAXIMUM) {               /* force the final inventory to */
        order           = MAXIMUM - inventory; /* match the initial inventory  */
        sum.setup++;
        sum.order      += order;
        inventory      += order;
      }

      double itemCost = 8000 * (sum.order / index);
      double setupCost = 1000 * (sum.setup / index);
      double holdingCost = 25 * (sum.holding / index);
      double shortageCost = 700 * (sum.shortage / index);
      double totalCost = itemCost + setupCost + holdingCost + shortageCost;

      printf("\n\nfor %ld time intervals ", index);
      printf("with an average demand of %6.2f\n", sum.demand / index);
      printf("and policy parameters (s, S) = (%d, %d)\n\n", MINIMUM, MAXIMUM);
      printf("   average order ............ = %6.2f\n", sum.order / index);
      printf("   setup frequency .......... = %6.2f\n", sum.setup / index);
      printf("   average holding level .... = %6.2f\n", sum.holding / index);
      printf("   average shortage level ... = %6.2f\n", sum.shortage / index);

      // PRINT COSTS
      printf("   total item cost .......... = %6.2f\n", itemCost);
      printf("   total setup cost ......... = %6.2f\n", setupCost);
      printf("   total holding cost ....... = %6.2f\n", holdingCost);
      printf("   total shortage cost ...... = %6.2f\n", shortageCost);
      printf("   total cost per week ...... = %6.2f\n", totalCost);
  }

  fclose(fp);
  return (0);
}
