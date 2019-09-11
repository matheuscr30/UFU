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
#define N 5
#define LEFT (i+N-1)%N
#define RIGHT (i+1)%N
#define NOTHING 0
#define HUNGRY 1
#define EATING 2

int state[N];
sem_t mutex;
sem_t s[N];

void test(int i)
{
	if (state[i] == HUNGRY && state[RIGHT] != EATING && state[LEFT] != EATING)
	{
		state[i] = EATING;
		sem_post(&s[i]);
	}
}

void take_forks(int i)
{
	sem_wait(&mutex);
	state[i] = HUNGRY;
	test(i);
	sem_post(&mutex);
	sem_wait(&s[i]);
}

void put_forks(int i)
{
	sem_wait(&mutex);
	state[i] = NOTHING;
	test(LEFT);
	test(RIGHT);
	sem_post(&mutex);
}

void *acao(void *p)
{
	//0 - comer
	//1 - pensar
	int *num = (int*)p;
	int tempo;
	
	while(1)
	{
		take_forks(*num);
		tempo = rand()%3;
		printf("Filosofo %d esta comendo\n", (*num));
		sleep(tempo);
		put_forks(*num);
	
		printf("Filosofo %d esta pensando\n", (*num));
		tempo = rand()%3;
		sleep(tempo);
	}
	
	pthread_exit(0);
}

main()
{
	int i ,f[5];
	pthread_t filosofos[5];
	srand( (unsigned)time(NULL) );
	sem_init(&mutex, 0, 1);
	
	for(i = 0; i < 5; i++){
		sem_init(&s[i], 0, 1);
		f[i] = i;
	} 
	
	for(i = 0; i < 5; i++)
		pthread_create(&filosofos[i],NULL,acao,(void*)&f[i]);
	
	for(i = 0; i < 5; i++)
		pthread_join(filosofos[i], NULL);
	
	for(i = 0; i < 5; i++)
		sem_destroy(&s[i]);
	sem_destroy(&mutex);
	exit(0);
}
