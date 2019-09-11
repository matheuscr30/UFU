#include <bits/stdc++.h>
#include <fstream>
#include "rvgs.hpp"
#include "rvms.hpp"

using namespace std;

main(){
    long N = 1000000;
    long count[30] = {0};
    double p[30] = {0.0};
    long x;

    ofstream f1;
    f1.open("data.txt");
    for(int i = 0; i < N; i++)
    {
        x = Poisson(9);
        f1 << x << endl;
        count[x]++;
    }
    f1.close();

    for (x = 0; x < 30; x++)
        p[x] = (double) count[x] / N;

    ofstream f2;
    f2.open("probabilities.txt");
    for (x = 0; x < 30; x++)
        f2 << fixed << setprecision(5) << p[x] << endl;
    f2.close();

    ofstream f3;
    f3.open("pdf.txt");
    for (x = 0; x < 30; x++)
        f3 << fixed << setprecision(5) << pdfPoisson(9, x) << endl;
    f3.close();
}
