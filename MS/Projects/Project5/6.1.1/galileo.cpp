#include <bits/stdc++.h>
#include <fstream>
#include "rng.hpp"

using namespace std;

#define  sqr(x)  ((x) * (x))

long Equilikely(long a, long b)
{
    return (a + (long) ((b - a + 1) * Random()));
}

main()
{
    long sizes[5] = {360, 3600, 36000, 360000};
    long seeds[5] = {12345, 124564, 242453, 98786465, 3413124};
    long   count[15];                 /* histogram              */
    double p[15];               /* probability estimates  */
    long x, N;

    for(int i = 0; i < 4; i++)
    {
        for(int k = 0; k < 5; k++)
        {
            long sum = 0;

            memset(count, 0, sizeof(count));
            memset(p, 0, sizeof(count));
            PutSeed(seeds[k]);
            N = sizes[i];

            ofstream f1;
            string aux = to_string(sizes[i]) + "/values" + to_string(N) + "_" + to_string(seeds[k]) + ".txt";
            f1.open(aux);
            for (int j = 0; j < N; j++) {
                x = Equilikely(1, 6) + Equilikely(1, 6);
                f1 << x << endl;
                sum += x;
                count[x]++;
            }
            f1.close();

            for (x = 2; x <= 12; x++)                /* estimate probabilities */
                p[x] = (double) count[x] / N;

            double mean = sum / N;
            double stdev, sumsqr = 0;

            for (x = 2; x <= 12; x++)
                sumsqr += sqr(x - mean) * count[x];
            stdev = sqrt(sumsqr / N);

            ofstream f2;
            aux = to_string(sizes[i]) + "/probabilities" + to_string(N) + "_" + to_string(seeds[k]) + ".txt";
            f2.open(aux);

            f2 << "probabilities:" << endl;
            for (x = 2; x <= 12; x++)
                f2 << p[x] << endl;

            f2 << endl;
            f2 << "mean " << mean << endl;
            f2 << "stdev " << stdev << endl;
            f2.close();
        }
    }
}
