#include <bits/stdc++.h>
#include "rng.hpp"

using namespace std;

double Uniform(double a, double b)
{
    return (a + (b - a) * Random());
}

main()
{
    vector<double> vet;
    vet.push_back(0);
    for(int i = 1; i < 2000; i++)
    {
        double x = Uniform(0, 5000);
        vet.push_back(x);
    }

    sort(vet.begin(), vet.end());

    for(int i = 1; i < vet.size(); i++)
    {
        cout << vet[i] - vet[i-1] << endl;
    }
}
