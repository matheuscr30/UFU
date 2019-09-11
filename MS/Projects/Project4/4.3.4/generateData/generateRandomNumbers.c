#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "rng.h"

#define N 10000

int main(void)
{
    int i;
    double x;
    for (i = 0; i < N; i++)
    {
        x = Random() + Random();
        printf("%lf\n", x);
    }
    return (0);
}
