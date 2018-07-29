#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int isPrime(int n){
    int i;

    if(n%2 == 0 && n>2)
        return 0;

    for(i=3; i<=floor(sqrt(n)); i+=2){
        if(n%i == 0)
            return 0;
    }
    return 1;
}

int findLargestPrime(int n){
    int i;

    for(i=n; i>1; i--){
        if(i%2!=0){
            if(isPrime(i) == 1)
                return i;
        }
    }
    return;
}

int gcd (int n1, int n2){
    while(n1!=n2)
    {
        if(n1 > n2)
            n1 -= n2;
        else
            n2 -= n1;
    }
    return n1;
}

int isFPM(int a, int m){
    int p=1;
    int x=a;

    while(x != 1){
        p++;
        x=(a*x)%m;
    }
    if(p == m-1)
        return 1;
    else
        return 0;
}

void findPrimeFactors(int *primeFactors, int num){
    int i;
    int j=0;

    for(i=2; i<=num; i++){
        if(num%i==0){
            if(isPrime(i)==1){
                primeFactors[j]=i;
                j++;
            }
        }
    }
    primeFactors[j] = -1;
}

int howManyFPMs(int m){
    m--;
    int *primeFactors = (int*)malloc(100*(sizeof(int)));
    findPrimeFactors(primeFactors, m);
    int j=0;
    int x = 1;
    int y = 1;

    while(primeFactors[j] != -1){
        x *= (primeFactors[j]-1);
        y *= primeFactors[j];
        j++;
    }
    double result = m;
    result *= x;
    result /= y;
    return ceil(result);
}

int *findFPMs(int m){
    int a = findFirstFPM(m);
    //int qtde = (howManyFPMs(m)+1);
    //int *FPMs = (int*)malloc(qtde*sizeof(int));
    int x = a;
    int i = 1;
    //int j=0;

    while(x != 1){
        if (gcd(i, m-1) == 1)
            i++;
        x = (a*x)%m;
        printf("%d ", x);
        //FPMs[j] = x;
        //j++;
    }
    //return FPMs;
}

int findFirstFPM(int m){
    int i;

    for(i=1; i<m-1; i++){
        if(isFPM(i, m))
            return i;
    }
    return;
}

int main()
{
    printf("%d\n", findFPMs(13));

    return 0;
}
