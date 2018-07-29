#include <bits/stdc++.h>

#define lambda 30.0
#define v 2.0

using namespace std;

void calculate(long c)
{
    double q, l, d, w, p;
    double sum, t;
    long s;

    p = lambda / ((double)c * v);

    if (p >= 1){
        cout << "for c = " << c << endl;
        cout << "Don't exist steady-state statistics because p >= 1" << endl;
        return;
    }

    sum = 0.0;
    t = 1.0;
    s = 0;

    while(s < c){
        sum += t;
        s++;
        t *= ((double)c * p / s);
    }

    sum += t / (1.0 - p);
    q = t * p / ((1.0 - p) * (1.0 - p) * sum);
    l = q + (c * p);
    d = q / lambda;
    w = l / lambda;

    cout << endl << "for c = " << c << " and p = " << p << endl;
    cout << "E[Q] / average number in the queue  = " << q << endl;
    cout << "E[L] / average number in the node   = " << l << endl;
    cout << "E[D] / average delay in the queue   = " << d << endl;
    cout << "E[W] / average wait in the node     = " << w << endl;
}

main()
{
    long cs[6] = {15, 16, 17, 18, 19, 20};
    for (int i = 0; i < 6; i++)
        calculate(cs[i]);
}
