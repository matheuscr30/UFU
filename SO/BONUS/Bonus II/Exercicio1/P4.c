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

int numeros[11], cont, flag, canal1[2], canal2[2], contP5, contP6;
sem_t *mutex;

struct shared_area{	
	int num;
	int vet[15];
};

struct shared_area2{	
	int num;
	int wait;
	int vet[15];
};

struct shared_area *shared_area_ptrF1;
struct shared_area2 *shared_area_ptrF2;

void handler();
void *thread1(void *p);
void *thread2(void *p);
void insereF2(int num, int opt);

void configF1()
{
	key_t key=1234;
	void *shared_memory = (void *)0;
	int shmid;
	shmid = shmget(key,MEM_SZ,0666|IPC_CREAT);
	if ( shmid == -1 ){
		printf("shmget falhou\n");
		exit(-1);
	}
	printf("shmid=%d\n",shmid);
	
	shared_memory = shmat(shmid,(void*)0,0);
	
	if (shared_memory == (void *) -1 ){
		printf("shmat falhou\n");
		exit(-1);
	}

	shared_area_ptrF1 = (struct shared_area *) shared_memory;
}

void configF2()
{
	key_t key=5678;
	void *shared_memory = (void *)0;
	int shmid, i;
	shmid = shmget(key,MEM_SZ,0666|IPC_CREAT);
	if ( shmid == -1 ){
		printf("shmget falhou\n");
		exit(-1);
	}
	printf("shmid=%d\n",shmid);
	
	shared_memory = shmat(shmid,(void*)0,0);
	
	if (shared_memory == (void *) -1 ){
		printf("shmat falhou\n");
		exit(-1);
	}
	
	shared_area_ptrF2 = (struct shared_area2 *) shared_memory;
	shared_area_ptrF2->num=0;
	shared_area_ptrF2->wait = 0;
}

main()
{
  	signal(SIGUSR1, handler);
  	key_t key=1234;

	mutex = sem_open("semaphore1", O_RDWR); 
	
	if ( pipe(canal1) == -1 ){ printf("Erro pipe()"); exit(0); }
	if ( pipe(canal2) == -1 ){ printf("Erro pipe()"); exit(0); }
	
	cont = 0;
	flag = 0;
	
	configF1();
	configF2();
	
	while(1){ }

	sem_close(mutex);	
		
    exit(0);
}

void handler()
{
	int i, j;
	sem_wait(mutex);
	
	printf("%d ", cont);
	cont++;
	for(i=0;i<10;i++)
	{	
		numeros[i] = shared_area_ptrF1->vet[i];
		printf("%d ", numeros[i]);
	}
	
	printf("\n");
	shared_area_ptrF1->num = 0;
	
	pthread_t t1, t2;
	pthread_create(&t1,NULL,thread1,NULL);
	pthread_create(&t2,NULL,thread2,NULL);
	
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	
	if(cont == 1000){
		printf("Parou\n");
		while (1){ }
	}
	//sleep(2);
	sem_post(mutex);
}

void * thread1(void *p)
{
	pid_t pid;
	int i;
	
	for(i = 0; i < 5; i++)
		write(canal1[1], &numeros[i], sizeof(int));
		
	pid=fork();
   	
   	if ( pid == 0 )
	{	
		for(i = 0; i < 5; i++){
			int num;
			read(canal1[0], &num, sizeof(int));
			
			//Insere na F2
			while(1){
				if(shared_area_ptrF2->wait == 0)
				{	
					if(shared_area_ptrF2->num >= 10){
						shared_area_ptrF2->wait = 2;
						break;
					}
				
					shared_area_ptrF2->vet[shared_area_ptrF2->num] = num;
					shared_area_ptrF2->num = shared_area_ptrF2->num + 1;
						
					if(shared_area_ptrF2->num >= 10){
						shared_area_ptrF2->wait = 2;
						break;
					}
				
					shared_area_ptrF2->wait = (shared_area_ptrF2->wait + 1)%3;
					break;
				}
			}
		}
		
		fflush(stdout);
		exit(0);
	}

	wait(&pid);
	pthread_exit(0);
}

void * thread2(void *p)
{
	pid_t pid;
	int i;
		
	for(i = 5; i < 10; i++)
		write(canal2[1], &numeros[i], sizeof(int));
	
	pid=fork();
   
	if ( pid == 0 )
	{
		for(i = 5; i < 10; i++){
			int num;
			read(canal2[0], &num, sizeof(int));
			
			//Insere na F2
			while(1){
				if(shared_area_ptrF2->wait == 1)
				{	
					if(shared_area_ptrF2->num >= 10){
						shared_area_ptrF2->wait = 2;
						break;
					}
						
					shared_area_ptrF2->vet[shared_area_ptrF2->num] = num;
					shared_area_ptrF2->num = shared_area_ptrF2->num + 1;
						
					if(shared_area_ptrF2->num >= 10){
						shared_area_ptrF2->wait = 2;
						break;
					}
					
					shared_area_ptrF2->wait = (shared_area_ptrF2->wait + 1)%3;
					break;
				}
			}
		}
	
		fflush(stdout);
		exit(0);
	}
	
	wait(&pid);
	pthread_exit(0);
}
