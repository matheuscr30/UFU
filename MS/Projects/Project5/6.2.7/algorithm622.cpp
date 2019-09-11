#include <bits/stdc++.h>
#include <fstream>
#include "rng.hpp"
#include "rvms.hpp"

using namespace std;

main(){
    int means[6] = {1, 5, 10, 15, 20, 25};
    double x, u;
    int cont;

    for(int i = 0; i < 6; i++)
    {
        cont = 0;
        x = means[i];
        u = Random();

        if(cdfPoisson(means[i], x) <= u)
            while(cdfPoisson(means[i], x) <= u)
                x++, cont++;
        else if(cdfPoisson(means[i], 0) <= u)
            while(cdfPoisson(means[i], x-1) > u)
                x--, cont++;
        else
            x = 0, cont++;

        cout << "u = " << means[i] << endl;
        cout << "x = " << x << endl;
        cout << "number of passes =  " << cont << endl;
        cout << endl;
    }
}
