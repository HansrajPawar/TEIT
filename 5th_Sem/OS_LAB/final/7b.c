#include<stdio.h>
#include<string.h>
#include<sys/shm.h>
#include<unistd.h>

int main()
{
	int i ;
	void * shared_memory ;
	char buff[100];
	int shmid ;

	shmid = shmget((key_t)2345,1024,0666);
	printf("Shared memory kEY :- %d",shmid);

	shared_memory = shmat(shmid,NULL,0);

	printf("Process attache at %p",shared_memory);
	printf("Data read from shared memory is %s \n",(char *)shared_memory);

	shmdt(shared_memory);

	return 0;
	
}