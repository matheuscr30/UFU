#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "rngs.h"

/**
(a) Generate an Exponential(9) random variate sample of size n = 100
and compute the proportion of points in the sample that fall within the intervals ¹x § 2s
and ¹x § 3s. Do this for 10 di®erent rngs streams. (b) In each case, compare the results
with Chebyshev's inequality. (c) Comment.

RESPOSTA:

(a)
*/
double Exponential(double m,int stream)
{
    SelectStream(stream);
    return (-m * log(1.0 - Random()));
}

int main()
{

    int i,k,j;
    double aux;
    int acc;
    /**
    Média -> 9
    S -> 9
    */
    double expected_mean = 9;
    double expected_s = 9;
    printf("For 100 elements: \n");
    for(k=2; k<=3; k++)
    {
        for(j=0; j<10; j++)
        {
            acc=0;
            for(i=0; i<100; i++)
            {
                aux = Exponential(9,j);
                if( aux > (expected_mean-(2*expected_s)) && aux < (expected_mean+(2*expected_s)))
                {
                    acc+=1;
                }
            }

            printf("%d: Number of elements in inteviel [x-%d *s,x+%d *s] = %d \n",j,k,k,acc );

        }
        printf("\n");
    }

    return 0;
}
