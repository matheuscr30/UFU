#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    int j;
    pid_t pid;

    pid = fork();

    if(pid > 0){
        wait(&j);
    }
    else if(pid == 0)
    {
        int i;
        for(i = 2; i <= 1000; i = i+2){
            printf("%d\n", i);         
        }
    }
    else{
        printf("Erro no Fork\n");    
    }

    return 0;
}
