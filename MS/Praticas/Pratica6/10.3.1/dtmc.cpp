#include "rng.h"
#include <bits/stdc++.h>
#define FINAL_TIME 100000
#define INITIAL_STATE 1

using namespace std;

double P[4][4] = {
    {0.3, 0.5, 0.9, 1.0},
    {0.0, 0.5, 0.8, 1.0},
    {0.0, 0.4, 0.4, 1.0},
    {0.4, 0.4, 0.9, 1.0}
};

int next_state(int x) {
    double u = Random();
    int _x = 0;
    while(P[x][_x] <= u) {
        _x++;
    }
    return _x;
}

int main () {

    double counter[4] = {0, 0, 0, 0};
    int state = INITIAL_STATE; //sets initial state as the problem asks
    int t = 0;
    double x_barra = 0.0;

    while(t < FINAL_TIME) {
        t++;
        counter[state]++;
        x_barra += state;
        state = next_state(state);        
    }

    int i = 0;
    for(i=0; i<4;i++) {
        counter[i] /= FINAL_TIME;
    }

    x_barra /= FINAL_TIME;

    printf("     state :   0      1      2      3\n");
    printf("proportion : %.3lf  %.3lf  %.3lf  %.3lf\n", counter[0],counter[1],counter[2],counter[3]);
    printf("  x(barra) : %.3lf\n",x_barra);

}