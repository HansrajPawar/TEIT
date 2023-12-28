#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<windows.h>
#include<semaphore.h>
#include<pthread.h>

void * writer_thr (void * temp );
void * reader_thr (void * temp );
sem_t mutex ;
semt_t wrt ;
int readcount = 0 , nrd =5 ,nwr = 5 ;

int main ()
{
	int i ;
	sem_init(&mutex,0,1);
	sem_init(&wrt,0,1);

	pthread_t writer[100] , reader[100];

	//take input for the nrd and nwr 

	for (int i = 0; i < nrw; i++)
	{
		int * writer_id = malloc(sizeof(int));
		writer_id = i;
		pthread_create(&writer[i],NULL,writer_thr,(void *)writer_id);
	}

	for (int i = 0; i < nrw; i++)
	{
		int * reader_id = malloc(sizeof(int));
		reader_id = i;
		pthread_create(&reader[i],NULL,writer_thr,(void *)reader_id);
	}
	
	for (int i = 0; i < nrw; i++)
	{
		pthread_join(&writer[i],NULL);
	}

		
	for (int i = 0; i < nrw; i++)
	{
		pthread_join(&reader[i],NULL);
	}
	

	sem_destroy(&mutex);
	sem_destroy(&wrt);

	pthread_exit(NULL);
	
	return 0;
}
void * writer_thr (void * temp )
{
	int * idptr = (int *) temp;
	int id  = *idptr ;
	free(idptr);

	printf("Reader %d trying to read " , id);
	sem_wait(&wait);
	readcount++;

	if(readcount==1)
		sem_wait(&wrt);
	sem_post(&mutex);


	printf("\nReader %d reading " , id);
	sem_wait(&wait);
	readcount++;

	if(readcount==0)
		sem_post(&wrt);
	sem_post(&mutex);

	printf("\nReader %d leaving " , id);
	sleep(3);
	pthread_exit(NULL);

}
void * reader_thr (void * temp )
{
	
	int * idptr = (int *) temp;
	int id  = *idptr ;
	free(idptr);

	printf("Reader %d trying to read " , id);
	sem_wait(&wrt);

	printf("\nWriter %d is writing a data ",id);
	sleep(3);

	printf("\n writer %d leaving ",id);
	sem_post(&wrt)

	pthread_exit(NULL);
}