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

#define MEM_SZ 100
#define BUFF_SZ MEM_SZ-sizeof(int)

struct shared_area{	
	int num;
	int vet[15];
};

main(int argc, char *argv[])
{
	int pidP4 = atoi(argv[1]);
  	int i, j;
	key_t key=1234;
	srand( (unsigned)time(NULL) );
	struct shared_area *shared_area_ptr;
	void *shared_memory = (void *)0;
	int shmid;

	sem_t *mutex = sem_open("semaphore1", O_RDWR);
	
	shmid = shmget(key,MEM_SZ,0666|IPC_CREAT);
	if ( shmid == -1 )
	{
		printf("shmget falhou\n");
		exit(-1);
	}
	
	printf("shmid=%d\n",shmid);
	
	shared_memory = shmat(shmid,(void*)0,0);
	
	if (shared_memory == (void *) -1 )
	{
		printf("shmat falhou\n");
		exit(-1);
	}
		
	printf("Memoria compartilhada no endereco=%x\n",(int) shared_memory);

	shared_area_ptr = (struct shared_area *) shared_memory;
	
	int h;
	while(1)
	{
		sem_wait(mutex); 				// ABRE
		if ( shared_area_ptr->num < 10 )
		{
			int numAleatorio = rand()%1000 + 1;
			printf("Numero Aleatorio %d\n", numAleatorio);
			
			shared_area_ptr->vet[shared_area_ptr->num] = numAleatorio;
			shared_area_ptr->num++;
		}
		
		if( shared_area_ptr->num == 10 )
		{
			//Pid do processo 4
			sem_post(mutex);              // FECHA
			kill(pidP4, SIGUSR1);
		}	
		else
			sem_post(mutex);              // FECHA
	}
	
	sem_close(mutex);
    exit(0);
}
