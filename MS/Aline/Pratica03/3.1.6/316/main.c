#include <stdio.h>
#include "../rng.h"

#define MAXIMUM  80                        /* 'S' inventory policy parameter */
#define sqr(x)   ((x) * (x))


long Equilikely(long a, long b)
{
    return (a + (long) ((b - a + 1) * Random()));
}


long GetDemand(void)
{
    return (Equilikely(10, 50));
}

void Sis2(int N, FILE *arq, int seed)
{
    int i;
    int MINIMUM = 15;

    printf("Seed: %d\n", seed);
    printf("N = %d\n\n", N);

    for(i=15; i<=35; i++)
    {
        long index = 0, indexAux = 0;            /* time interval index     */
        long inventory = MAXIMUM;                /* current inventory level */
        long demand;                             /* amount of demand        */
        long order;                              /* amount of order         */

        struct                                   /* sum of ...              */
        {
            double setup;                          /*   setup instances       */
            double holding;                        /*   inventory held (+)    */
            double shortage;                       /*   inventory short (-)   */
            double order;                          /*   orders                */
            double demand;                         /*   demands               */
        } sum = {0.0, 0.0, 0.0, 0.0, 0.0};

        PutSeed(seed);


        while (index < N)
        {
            indexAux++;
            index++;
            if (inventory < MINIMUM)               /* place an order */
            {
                order         = MAXIMUM - inventory;
                sum.setup++;
                sum.order    += order;
            }
            else                                   /* no order       */
                order         = 0;
            inventory      += order;               /* there is no delivery lag */
            demand          = GetDemand();
            sum.demand     += demand;
            if (inventory > demand)
                sum.holding  += (inventory - 0.5 * demand);
            else
            {
                sum.holding  += sqr(inventory) / (2.0 * demand);
                sum.shortage += sqr(demand - inventory) / (2.0 * demand);
            }
            inventory -= demand;
            if(indexAux == 5)
                indexAux = 0;
        }

        if (inventory < MAXIMUM)                 /* force the final inventory to */
        {
            order      = MAXIMUM - inventory;    /* match the initial inventory  */
            sum.setup++;
            sum.order += order;
            inventory += order;
        }

        double dependentCost = (sum.setup/index)*1000  + (sum.holding/index)*25 + (sum.shortage/index)*700;

        fprintf(arq, "%.2f,%d\n", dependentCost, MINIMUM);

        MINIMUM++;
    }
}

int main(void)
{
    FILE *arq;


    int seed;
    PutSeed(-1);
    GetSeed(&seed);

    // Os paramaetros passados para Sis2 modificado são N, o arquivo de gravação dos dados, a semente q se repetira, e a formatação do aqruivo de saida
    arq = fopen("n 100.txt", "w");
    Sis2(1000, arq, seed);
    fclose(arq);

    arq = fopen("n 10000.txt", "w");
    Sis2(10000, arq, seed);
    fclose(arq);

    return (0);
}
