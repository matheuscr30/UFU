#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    pid_t pids[50];

    int i, flag = 0;
    for(i = 0 ; i < 50; i++){
        pids[i] = fork();

        if(pids[i] == 0){
            printf("Pid Pai: %d  Pid Atual: %d\n", getppid(), getpid());      
            break;
        }
        else if(pids[i] > 0)
            flag = 1;  
    }

    int j;
    if(flag == 1){
        for(i = 0; i < 50; i++)
            wait(&j);
        getchar();
    }

    return 0;
}
