#include <stdio.h>
#include <math.h>
 
int main()
{
    int m;
    printf("type the m: ");
    scanf("%d", &m);
 
    int i, j;
    for(i = m-1; i >= 1; i--){
 
        int flag = 0;
        for(j = 2; j < i; j++)
        {
            if(i%j == 0){
                printf("not prime %d %d\n", i, j);
                flag = 1;
                break;
            }
        }
 
        if(!flag){
            printf("largest prime in range: %d", i);
            break;
        }
    }
    return 0;
}