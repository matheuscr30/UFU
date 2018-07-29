#include <stdio.h>
#include <stdlib.h>

int main(){
    int a, x, m, p;
    printf("type the m: ");
    scanf("%d", &m);

    int i;
    for(i = 1; i < m; i++)
    {
        p = 1;
        x = i;
        while(x != 1){
            p++;
            x = (i * x) % m;
        }

        if(p == m-1){
            printf("%d is the first full period\n", i);
            break;
        }
        else
            printf("%d is not a full period\n", i);
    }

    return 0;
}
