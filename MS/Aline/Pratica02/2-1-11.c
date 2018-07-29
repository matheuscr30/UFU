#include <stdio.h>
#include <stdlib.h>

int gcd ( int a, int b )
{
    int r;
    r = a % b;
    while (r > 0)
    {
        a = b;
        b = r;
        r = a % b;
    }
    return b;
}

int tyr(int m )
{
    int i, x, a = 2, p;
    while(a < m)
    {
        p = 1;
        x = a;
        while (x != 1)
        {
            p++;
            x = (a * x) % m;
        }
        if (p == m - 1)
        {
            return a;
        }
        a++;
    }
}

int caos(int m, int a)
{
    int i, x,valores = 0;
    i = 1;
    x = a;
    while (x != 1)
    {
        if (gcd(i, m - 1) == 1){
            valores++;
        }
        i++;
        x = (a * x) % m;
    }
    printf("\t%d           \t%d                    \t%d\n", m,valores,a );
}

int main()
{
    int i,m[10] = {17,19,23,29,31,37,41,43,47,53};
    printf("  Valor de m | Full period multipliers | Menor full period multiplier\n");
    for(i = 0; i < 10 ; i++)
    {
        caos(m[i],tyr(m[i]));
    }

    return 0;
}
