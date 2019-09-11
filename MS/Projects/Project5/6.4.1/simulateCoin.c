#include <stdio.h>
#include "rvgs.h"

int main()
{
    long N = 1000;
    long i, j, heads;
    long seed = 123456;
    long cont[15] = {0};

    FILE *f1 = fopen("data.txt","w");
    FILE *f2 = fopen("probabilities.txt","w");

    for(i = 0; i < 1000; i++)
    {
        PutSeed(seed);
        seed += 135234;

        heads = 0;
        for(j = 0; j < 10; j++)
        {
            long coin = Bernoulli(0.5);
            if(coin)
                heads++;
        }

        fprintf(f1, "%ld\n", heads);
        cont[heads]++;
    }

    for(i = 0; i <= 10; i++){
        double probs = (double)cont[i]/1000.0;
        fprintf(f2, "%.5f\n", probs);
    }

    fclose(f1);
    fclose(f2);

    return 0;
}
