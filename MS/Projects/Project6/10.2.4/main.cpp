#include <bits/stdc++.h>
#include "rvgs.hpp"
#include "rngs.hpp"

#define limit 1000.0
#define lambda 3.0
#define v 4.0

using namespace std;

double lambda_func(long x){
    if(x == 0)
        return 1.0/lambda;
    else
        return 1.0/(lambda + v);
}

double probability_func(long x){
    if(x == 0)
        return 1.0;
    else
        return (lambda/(lambda + v));
}

struct taxes{
     long birthrate = 0;
     long deathrate = 0;
 };
taxes vet[50];

main() {
    PutSeed(12345676);

    taxes aux;
    aux.birthrate = 0;
    aux.deathrate = 0;
    for(int i = 0; i < 50; i++)
        vet[i] = aux;

    double t;
    long x, index, sum;

    t = 0.0;
    x = index = sum = 0;

    ofstream f1;
    f1.open("data.txt");

    while(t < limit){
        index++;
        t += Exponential(lambda_func(x));
        long ber = Bernoulli(probability_func(x));
        if (ber == 0)
            vet[x].deathrate++;
        else
            vet[x].birthrate++;

        x += 2 * ber - 1;
        sum += x;
        f1 << t << " --- "<< x << endl;
    }

    f1.close();

    for(int i = 1; i < 20; i++){
        cout << i << " ";
        cout << (double)vet[i].birthrate/vet[i].deathrate << endl;
    }

    cout << endl << "average number in the node:  " << (double)sum/index << endl;
    cout << "quantity of changes in the node:  " << index << endl;
}
