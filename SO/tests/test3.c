#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    int i, j;
    pid_t pid1, pid2;

    pid1 = fork();
    
    if(pid1 > 0){
        
        pid2 = fork();
        
        if(pid2 > 0){
            wait(&i);
            wait(&j);        
        }        
        else if(pid2 == 0)
            for(i = 1; i <= 1000; i = i + 2)
                printf("%d\n", i);
        else
            printf("Erro no fork\n");
    }
    else if(pid1 == 0)
        for(i = 2; i <= 1000; i = i + 2)
            printf("%d\n", i);
    else
        printf("Erro no fork\n");

    return 0;
}
