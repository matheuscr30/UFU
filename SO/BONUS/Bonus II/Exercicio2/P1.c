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

void *acao(void *p)
{
	//0 - comer
	//1 - pensar
	int *num = (int*)p;
	
	while(1)
	{
		int escolha = rand()%2;
		
		if(escolha == 0){
			
			printf("Filosofo %d esta comendo com os garfos %d e %d\n", (*num)+1, (*num)+1, (*num + 2)%5);
			int tempo = rand()%3;
			sleep(tempo);
			printf("Filosofo %d parou de comer\n", (*num)+1);
		}
		else if(escolha == 1)
		{
			printf("Filosofo %d esta pensando\n", (*num)+1);
			int tempo = rand()%3;
			sleep(tempo);
		}
	}
	
	pthread_exit(0);
}

main()
{
	srand( (unsigned)time(NULL) );
	int i;
	pthread_t filosofos[5];
	
	int f[5];
	for(i = 0; i < 5; i++)
		f[i] = i;
	
	for(i = 0; i < 5; i++)
		pthread_create(&filosofos[i],NULL,acao,(void*)&f[i]);
	
	for(i = 0; i < 5; i++)
		pthread_join(filosofos[i], NULL);
		
	exit(0);
}
