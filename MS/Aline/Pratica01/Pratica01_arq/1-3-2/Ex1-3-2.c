#include <stdio.h>

#define FILENAME  "sis1.dat"            /* input data file                */
#define MINIMUM   20                    /* 's' inventory policy parameter */
#define MAXIMUM   80                    /* 'S' inventory policy parameter */
#define sqr(x)    ((x) * (x))

#define ORDER_COST 8000
#define SETUP_COST 1000
#define HOLDING_COST 25
#define SHORTAGE_CUST 700

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
    /* amount of order         */

    struct                                   /* sum of ...              */
    {
        double setup;                          /*   setup instances       */
        double holding;                        /*   inventory held (+)    */
        double shortage;                       /*   inventory short (-)   */
        double order;                          /*   orders                */
        double demand;                         /*   demands               */
    } sum = { 0.0, 0.0, 0.0, 0.0, 0.0 };

    /// ///////////////////////
    int i;
    FILE*fileSetup = fopen("setup_cost.txt","w");
    FILE*fileHolding = fopen("holding_cost.txt","w");
    FILE*fileShortage = fopen("shortage_cost.txt","w");
    FILE*fileDependent = fopen("dependent_cost.txt","w");
    for(i=1; i<=40; i++)
    {
        sum.demand=0;
        sum.shortage=0;
        sum.holding=0;
        sum.setup=0;
        long index     = 0;                      /* time interval index     */
        long inventory = MAXIMUM;                /* current inventory level */
        FILE *fp;                                /* input data file         */
        long demand;                             /* amount of demand        */
        long order;
        fp = fopen(FILENAME, "r");
        if (fp == NULL)
        {
            fprintf(stderr, "Cannot open input file %s\n", FILENAME);
            return (1);
        }
        /// ///////////////////////
        while (!feof(fp))
        {
            index++;
            if (inventory < i)               /* place an order          */
            {
                order         = MAXIMUM - inventory;

                sum.setup++;
                sum.order    += order;
            }
            else                                   /* no order                 */
                order         = 0;
            inventory      += order;               /* there is no delivery lag */


            demand          = GetDemand(fp);
            sum.demand     += demand;
            if (inventory > demand)
            {
                sum.holding  += (inventory - 0.5 * demand);
            }
            else
            {
                sum.holding  += sqr(inventory) / (2.0 * demand);
                sum.shortage += sqr(demand - inventory) / (2.0 * demand);

            }
            inventory      -= demand;

        }
        if (inventory < MAXIMUM)                 /* force the final inventory to */
        {
            order           = MAXIMUM - inventory; /* match the initial inventory  */
            sum.setup++;
            sum.order      += order;
            inventory      += order;
        }

          printf("\nfor %ld time intervals ", index);
          printf("with an average demand of %6.2f\n", sum.demand / index);
          printf("and policy parameters (s, S) = (%d, %d)\n\n", MINIMUM, MAXIMUM);
          printf("   average order ............ = %6.2f\n", sum.order / index);
          printf("   setup frequency .......... = %6.2f\n", sum.setup / index);
          printf("   average holding level .... = %6.2f\n", sum.holding / index);
          printf("   average shortage level ... = %6.2f\n", sum.shortage / index);

          /// //////////////////////////////////////////////////////////////////////////
        printf("\n\nResposta 1.3.2:\n\n");
          printf("   average order cost per week.... = %6.2f\n", ORDER_COST* (sum.order / index));
          printf("   average setup cost per week.... = %6.2f\n", SETUP_COST * (sum.setup / index));
          printf("   average holding cost per week.... = %6.2f\n", HOLDING_COST * (sum.holding / index));
          printf("   average shortage cost per week.... = %6.2f\n", SHORTAGE_CUST * (sum.shortage / index));


        fprintf(fileSetup,"%f\n", SETUP_COST * (sum.setup / index));
        fprintf(fileHolding,"%f\n", HOLDING_COST * (sum.holding / index));
        fprintf(fileShortage,"%f\n", SHORTAGE_CUST * (sum.shortage / index));
        fprintf(fileDependent,"%f\n",((SETUP_COST * (sum.setup / index)) +
                                      (HOLDING_COST * (sum.holding / index)) +  (SHORTAGE_CUST * (sum.shortage / index))));
        /// ///////////////////////////////////////////////////////////////////////////

        /**
        Letra A: Modificações no código.
        Letra B: Sim, por caracteristicas de arredondamento ou truncamento da máquina,por exemplo.
        Letra C: Para o valor S=80, temos uma otimização do sistema com s=22, pela soma de valores de gastos
        ser a menor possivel com $1549,28.
        Letra D: Essa otimização é baseada em uma aproximação, pois como o valor de s se trata de um inteiro, não
        é possivel calcular curvas de aproximação, ou outros metodos mais exatos.
        */
        fclose(fp);
    }
    fclose(fileSetup);
    fclose(fileHolding);
    fclose(fileShortage);
    fclose(fileDependent);
    return (0);
}

