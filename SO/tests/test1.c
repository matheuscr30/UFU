#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    pid_t pids[5];
    int i;
    for(i = 0; i < 5; i++){
        pids[i] = fork();
        if(pids[i] > 0)
			break;
    }
    getchar();
    return 0;
}
