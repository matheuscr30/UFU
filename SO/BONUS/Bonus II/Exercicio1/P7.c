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

struct shared_area2{	
	int num;
	int wait;
	int vet[15];
};

int cont, res[1005], min, max;
struct shared_area2 *shared_area_ptrF2; 

void *tira_f2(void * p)
{
	int i;
	int *opt = (int*)p;
	
	while(1)
	{
		if(cont == 10000)
			break;
		if(shared_area_ptrF2->wait == *opt)
		{
			if(shared_area_ptrF2->num == 0){
				shared_area_ptrF2->wait = (shared_area_ptrF2->wait + 1)%6 ;
			}
			else{
			
				int num = shared_area_ptrF2->vet[0];
		
				res[num]++;
				if(num > max) max = num;
				else if(num < min) min = num;
				if(*opt)
					
				for(i = 0 ; i < shared_area_ptrF2->num; i++)
					shared_area_ptrF2->vet[i] = shared_area_ptrF2->vet[i+1];
			
				shared_area_ptrF2->num--;
				cont++;
				printf("Recebendo numero %d:  %d\n", cont, num);
				shared_area_ptrF2->wait = (shared_area_ptrF2->wait + 1)%6 ;
			}
		}
	}
	
	pthread_exit(0);
}

main()
{
  	time_t inicio, fim;
	inicio = time(NULL);
  	
  	int i;
	key_t key=5678;
	pthread_t th1, th2, th3;
	void *shared_memory = (void *)0;
	int shmid;
	
	cont = 0;
	min = 1005;
	max = 0;
	memset(res, 0, sizeof(res));

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
		
	printf("Memoria compartilhada no endereco=%x\n",(int)shared_memory);

	shared_area_ptrF2 = (struct shared_area2 *) shared_memory;

	int t1 = 3, t2 = 4, t3 = 5;
	pthread_create(&th1, NULL, tira_f2,(void*)&t1);	
	pthread_create(&th2, NULL, tira_f2,(void*)&t2);
	pthread_create(&th3, NULL, tira_f2,(void*)&t3);	
	
	char aux[5];
	while(1)
	{
		if(cont == 10000)
			break;
		
		if(shared_area_ptrF2->wait == 2 && shared_area_ptrF2->num > 0)
			shared_area_ptrF2->wait = shared_area_ptrF2->wait + 1;
	}

	int indice, best = 0;
	for(i = 1; i <= 1000; i++){
		if(res[i] > best){
			best = res[i];
			indice = i;
		}
	}
	
	fim = time(NULL);
	printf("Tempo total de execucao do programa: %f\n", difftime(fim, inicio));
	printf("Quantidade de valores processados por P5: %d\n", 5000);
	printf("Quantidade de valores processados por P6: %d\n", 5000);
	printf("Moda: %d\n", indice);
	printf("Maior valor: %d\n", max);
	printf("Menor Valor: %d\n", min);
	
    exit(0);
}
