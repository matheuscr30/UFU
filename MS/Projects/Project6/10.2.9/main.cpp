#include <bits/stdc++.h>
#include "rvgs.hpp"
#include "rngs.hpp"

#define limit 1000.0
#define lambda 8.0
#define v 2.0
#define k 10.0
#define c 4.0

using namespace std;

double lambda_func(long x){
    if(x == 0)
        return 1.0/lambda;
    else if(x == k)
        return 1.0/v;
    else
        return 1.0/(lambda + v);
}

double probability_func(long x){
    if(x == 0)
        return 1.0;
    else if(x == k)
        return 0.0;
    else
        return (lambda/(lambda + v));
}

double fat(double num){
    if(num == 0 || num == 1)
        return 1;
    else
        return num*fat(num-1);
}

main() {
    PutSeed(12345676);

    double t, probs[15] = {0.0};
    long x, index, sum, count[15] = {0};

    t = 0.0;
    x = index = sum = 0;

    ofstream f1;
    f1.open("data.txt");

    while(t < limit){
        index++;
        t += Exponential(lambda_func(x));
        x += 2 * Bernoulli(probability_func(x)) - 1;
        count[x]++;
        sum += x;
        f1 << t << " --- "<< x << endl;
    }

    f1.close();

    for(int i = 0; i <= k; i++)
        probs[i] = (double)count[i]/index;

    cout << endl << "average number in the node:  " << (double)sum/index << endl;
    cout << "quantity of changes in the node:  " << index << endl;
    cout << endl << "steady-state probabilities: " << endl;
    for(int i = 0; i <= k; i++)
        cout << i << "  -  " << probs[i] << endl;

    cout << endl << "steady-state probabilities formula: " << endl;

    double sum_aux = 0.0;
    for(long h = 0; h <= c-1; h++)
        sum_aux += (pow(c, h)/fat(h));

    double res0 = pow((pow(c, c)/fat(c)) * (k-c+1) + sum_aux, -1);
    cout << '0' << "  -  " << res0 << endl;

    for(int i = 1; i <= k; i++){
        double res;

        if(i <= c-1)
            res = pow(c, i)/fat(i)*res0;
        else
            res = pow(c, c)/fat(c)*res0;
        cout << i << "  -  " << res << endl;
    }
}
