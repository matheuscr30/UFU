#include <stdio.h>
#include <windows.h>
#include "../rngs.h"

int seed=4554;

int flip()
{
    return Equilikely(0,1);
}

int toss10times()
{
    PutSeed(seed);
    seed++;

    int toss;
    int heads = 0;
    int tails = 0;

    for (toss = 1; toss <= 10; toss++ )
    {
        if (flip() == 0)
            heads++;

        else
            tails++;
    }

    return heads;
}

int main( void )
{
    FILE *arq = fopen("data.dat","w");
    int i=0;
    int heads=0;

    for(i=0; i<100000; i++)
        heads+=toss10times();
//        fprintf(arq, "%d\n", toss());

    fclose(arq);

    printf("\tFrequencia relativa - %f\n\n", (double)heads/1000000);
    printf("\tBinomal pdf - %f\n\n", pdfBinomial(10, 0.5, 0));

    return 0;
}
