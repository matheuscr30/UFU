#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void checkMC(int a, int m)
{
    int r, q;
    r = m%a;
    q = m/a;
    if(r<q)
        printf("%d eh MC %d", a, m);
    else
        printf("%d nao eh MC %d", a, m);
}

int main()
{
    int nums [] = {630360016, 742938285, 950706376, 1226874159, 62089911, 1343714438, -1};
    int m = pow(2,31)-1;
    int i = 0;

    while(nums[i] != -1){
        checkMC(nums[i], m);
        i++;
    }

    return 0;
}
