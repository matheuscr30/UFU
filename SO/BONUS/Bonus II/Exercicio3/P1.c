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

int garfos[5];
sem_t mutex[5];

void *acao(void *p)
{
	//0 - comer
	//1 - pensar
	int *num = (int*)p;
	
	while(1)
	{
		int escolha = rand()%2;
		
		if(escolha == 0){
			
			int j = *num;
			sem_wait(&mutex[j]);
			printf("Filosofo %d pegou o garfo %d\n", j, j);
			sleep(1);
			sem_wait(&mutex[(j+1)%5]);
			printf("Filosofo %d pegou o garfo %d\n", j, j+1);
			int tempo = rand()%3;
			sleep(tempo);
			printf("Filosofo %d parou de comer\n", j);
			
			sem_post(&mutex[j]);
			sem_post(&mutex[(j+1)%5]);
		}
		else if(escolha == 1)
		{
			printf("Filosofo %d esta pensando\n", (*num));
			int tempo = rand()%3;
			sleep(tempo);
		}
	}
	
	pthread_exit(0);
}

main()
{
	int i;
	pthread_t filosofos[5];
	srand( (unsigned)time(NULL) );
	
	for(i = 0; i < 5; i++){
		garfos[i] = i;
		sem_init(&mutex[i], 0, 1); 
	}
	
	for(i = 0; i < 5; i++)
		pthread_create(&filosofos[i],NULL,acao,(void*)&garfos[i]);
	
	for(i = 0; i < 5; i++)
		pthread_join(filosofos[i], NULL);
	
	for(i = 0; i < 5; i++)
		sem_destroy(&mutex[i]);
	exit(0);
}
