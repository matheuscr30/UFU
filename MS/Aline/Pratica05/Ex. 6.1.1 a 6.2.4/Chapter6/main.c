#include <stdio.h>
#include <stdlib.h>
#include "rvgs.h"
#include "rngs.h"
#include "rvms.h"
#include <string.h>
#include <math.h>


/** PARA FAZER
6.1.1
6.1.7
6.2.3
6.2.4
6.2.7
*/

///EXERCICIO 6.1.1
///Falta gerar as médias, desvio padrão e PDF dos dados, Comparar e comentar. Verificar como aplicar a formula de desvio padrão
double pdfDice(int x){
    int i, j;
    double acc=0;
    for(i=1;i<=6;i++){
        for(j=1;j<=6;j++){
            if(i+j==x){
                acc += pdfEquilikely(1,6,i) * pdfEquilikely(1,6,j);
            }
        }
    }
    return acc;
}

void gerar_pdf611(){
int i;
FILE*f ;

f=fopen("arquivos\\Exercicio6.1.1\\pdf.txt","w");

for(i=0;i<15;i++){
    fprintf(f,"%lf\n",pdfDice(i));
}
fclose(f);
}
int dice611(){
    return Equilikely(1,6);
}
void exercise611(){
    int i,j,*histogram,generated=0;
    FILE*f,*f2;
    for(j=0; j<5; j++)
    {
        histogram = calloc(sizeof(int),15);
        PutSeed(0);
        f=fopen("arquivos\\Exercicio6.1.1\\seed_.txt","w");

        for(i=0; i<360000; i++)
        {
            generated=dice611()+dice611();
            histogram[generated]++;
            fprintf(f,"%d\n",generated);
        }
        f2=fopen("arquivos\\Exercicio6.1.1\\histogram_.txt","w");
        for(i=0; i<15; i++)
        {
            fprintf(f2,"%d\n",histogram[i]);
        }

        fclose(f);
        fclose(f2);
        free(histogram);

    }

}


///EXERCICIO 6.2.3
double pdf623(int x){

    if( x == 4 || x == 5){
        if(x==4){
            return 1-pow(1.0/2.0,2);
        }

        else return pow(1.0/2.0,2);
    }
    else{
        return 0.0;
    }

}
int distribuition623(){
    double u=Random();
    return ceil(3.0+2.0*pow(u,2));
}
void exercise623(){
    /**
    Exercise 6.2.3 Find the pdf associated with the random variate generation algorithm
    u = Random();
    return Ceil(3.0 + 2.0 * u^2);
    */

    long *histogram = calloc(sizeof(long),10);
    FILE *f = fopen("arquivos\\Exercício6.2.3\\histogram623.txt","w");
    int i;

    for(i=0; i<10000000; i++)
    {
        histogram[distribuition623()]++;
    }

    for(i=0;i<10;i++){
        //printf("%ld\n",histogram[i]);
        fprintf(f,"%ld\n", histogram[i]);
    }
    free(f);
    f=fopen("arquivos\\Exercício6.2.3\\pdf623.txt","w");

        for(i=0;i<10;i++){
        //printf("%lf\n",pdf623(i));
        fprintf(f,"%lf\n",pdf623(i));
    }

}

///EXERCICIO 6.2.4
void exercise624(){

    /**
    Exercise 6.2.4 (a) Generate a Poisson(9) random variate sample of size 1 000 000 using
    the appropriate generator function in the library rvgs and form a histogram of the results.
    (b) Compare the resulting relative frequencies with the corresponding Poisson(9) pdf using
    the appropriate pdf function in the library rvms. (c) Comment on the value of this process
    as a test of correctness for the two functions used.
    */

    int i;
    FILE*f= fopen("arquivos\\Exercicio6.2.4\\histogram624.txt","w");
    long *histogram = calloc(sizeof(long),100);
    for(i=0; i<1000000; i++)
    {
        histogram[Poisson(9)]++;
    }

    for(i=0; i<100; i++)
    {
        fprintf(f,"%ld\n",histogram[i]);
    }


    fclose(f);
    fopen("arquivos\\Exercicio6.2.4\\pdf624.txt","w");
    for(i=0; i<30; i++)
    {
        fprintf(f,"%lf\n",pdfPoisson(9,i));

    }

    fclose(f);
    free(histogram);
}


///EXERCICIO 6.2.7
void exercise627(){
    /**
    Exercise 6.2.7 (a) Implement Algorithm 6.2.1 for a Poisson(¹) random variable and
    use Monte Carlo simulation to verify that the expected number of passes through the while
    loop is ¹. Use ¹ = 1; 5; 10; 15; 20; 25. (b) Repeat with Algorithm 6.2.2. (c) Comment. (Use
    the function cdfPoisson in the library rvms to generate the Poisson(¹) cdf values.)
    */


}
///EXERCICIO 6.1.7
void exercise617(){

}


int main(){
    //exercise623();
    exercise623();
    return 0;
}
