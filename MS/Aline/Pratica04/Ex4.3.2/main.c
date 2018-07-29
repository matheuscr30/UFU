#include <stdio.h>
#include <stdlib.h>
#include "rng.h"
#include "rng.c"

void selecao (double *v, int n)
{
    int fim, i, maior;
    double aux;
    for (fim=n-1; fim>0; fim--)
    {
        maior = 0;
        for(i=1; i<=fim; i++)
            if (v[i]>v[maior])
                maior =i;
        aux=v[fim];
        v[fim]=v[maior];
        v[maior]=aux;
    }
}
double Uniform(double a, double b)
{
    return (a + (b - a) * Random());
}

int main()
{
    FILE *arq;
    arq = fopen("teste.txt","w+");
    double vetor[2000];
    double x;
    int i;
    vetor[0]=0;
    fprintf(arq,"%7.3lf\n",vetor[0]);
    for(i = 1; i<2000 ; i++)
    {
        x = Uniform(0,5000);
        vetor[i]=x;
    }

    selecao(vetor,2000);

    for(i = 1; i<2000 ; i++)
    {
        fprintf(arq,"%7.3lf\n",vetor[i]-vetor[i-1]);
    }
    fclose(arq);
    return 0;
}
