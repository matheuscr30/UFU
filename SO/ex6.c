#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <unistd.h>     /* Symbolic Constants */
#include <semaphore.h>  /* Semaphore */
#include <pthread.h>    /* POSIX Threads */
#include <signal.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/wait.h>

main()
{
	int canal1[2], canal2[2], i, j;
	pid_t pid1, pid2;
	
	if ( pipe(canal1) == -1 ){ printf("Erro pipe()"); exit(0); }
	if ( pipe(canal2) == -1 ){ printf("Erro pipe()"); exit(0); }
	
	pid1 = fork();
	
	if(pid1 == 0)
	{
		for(i = 0; i <= 100; i+=2)
			write(canal1[1], &i, sizeof(int));
		close(canal1[1]);
		
		int num;
		for(i = 0; i < 50; i++){
			read(canal1[0], &num, sizeof(int));
			printf("P2 recebeu %d\n", num);
		}
		close(canal1[0]);
	}
	else if(pid1 > 0){
		
		pid2 = fork();
		
		if(pid2 == 0)
		{
			for(i = 1; i <= 100; i+=2)
				write(canal2[1], &i, sizeof(int));
			close(canal2[1]);
			
			int num;
			for(i = 0; i < 50; i++){
				read(canal2[0], &num, sizeof(int));
				printf("P3 recebeu %d\n", num);
			}
			close(canal2[0]);
		}
	}
	
	getchar();
	exit(0);
}

