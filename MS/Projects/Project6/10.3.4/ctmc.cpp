#include "rvgs.h"
#include "rngs.h"
#include <bits/stdc++.h>
#define FINAL_TIME 10000.0
#define INITIAL_STATE 1

using namespace std;

double P[4][4] = {
    {0.0, 0.3, 0.9, 1.0},
    {0.0, 0.0, 0.6, 1.0},
    {0.0, 0.3, 0.3, 1.0},
    {0.4, 0.4, 1.0, 1.0}
};

int next_state(int x) {
    int _x = 0;
    do {
        double u = Random();
        
        while(P[x][_x] <=  u) {
            _x++;
        }
    } while(x == _x);
    return _x;
}

int main () {

    PutSeed(12345);

    double mi[4] = {1.0, 1.5, 2.0, 0.5};

    double counter[4] = {0, 0, 0, 0};
    int state = INITIAL_STATE; //sets initial state as the problem asks
    double t = 0;
    double x_barra = 0.0;

    while(t < FINAL_TIME) {
        double still = Exponential(mi[state]);

        t += still;
        counter[state] += still;
        x_barra += state*still;

        state = next_state(state);              
    }

    int i = 0;
    for(i=0; i<4;i++) {
        counter[i] /= t;
    }

    x_barra /= FINAL_TIME;

    printf("     state :   0      1      2      3\n");
    printf("proportion : %.3lf  %.3lf  %.3lf  %.3lf\n", counter[0],counter[1],counter[2],counter[3]);
    printf("  x(barra) : %.3lf\n",x_barra);

}