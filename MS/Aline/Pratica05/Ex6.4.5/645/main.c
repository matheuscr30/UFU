#include "../../rvms.h"

double pdfBinomialRecursiva (int n, double p, int x)
{
    double aux = 0.0;
    double aux2 = 0.0;

    if(x == 0)
        return pow(1-p, n);

    else
    {
        aux = (n - x + 1);
        aux *= p;
        aux2 = x*(1-p);
        aux /= aux2;
        return (aux * pdfBinomialRecursiva(n,p,(x-1)));
    }
}

double pdfPoissonRecursiva (double mu, double x)
{

    if(x == 0)
        return 0.367880;

    else
        return ((mu/x) * pdfPoissonRecursiva(mu,(x-1)));

}

int main()
{
    printf("Utilizando as funcoes pdf's apropriadas da biblioteca rvms: \n\n");

    int x = 0;

    printf("-----------------------------------\n");
    printf("|x|  pdfBinomial  |   pdfPoisson  |\n");
    printf("-----------------------------------\n");

    for(x=0; x<10; x++)
    {
        printf("-----------------------------------\n");
        printf("|%d| \t %f | \t %f |\n", x, pdfBinomial(25, 0.04, x), pdfPoisson(1, x));
    }
    printf("-----------------------------------\n");

    printf("Utilizando as equacoes recursivas: \n\n");


    printf("-----------------------------------\n");
    printf("|x|  pdfBinomial  |   pdfPoisson  |\n");
    printf("-----------------------------------\n");

    for(x=0; x<10; x++)
    {
        printf("-----------------------------------\n");
        printf("|%d| \t %f | \t %f |\n", x, pdfBinomialRecursiva(25, 0.04, x), pdfPoissonRecursiva(1.0, (double)x));
    }
    printf("-----------------------------------\n");



    return 0;
}
