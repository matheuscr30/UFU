#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int a=1,aux=0;
    int modulo;
    printf("Informe o módulo: ");
    scanf("%d", &modulo);

    while(a!=(modulo-1)){
        int p = 1, x;
        x=a;
        while(x != 1){
            p++;
            x=(a*x)%modulo;
        }
        if(p==(modulo-1)){
            printf("%5d ", a);
            aux++;
            if(aux % 12 == 0){
                printf("\n");
            }
        }
        a++;
    }
    printf("\n\nTemos o total de %d multiplicadores full-período.\n\n", aux);

    return 0;
}
