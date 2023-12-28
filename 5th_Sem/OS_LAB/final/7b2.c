#include<stdio.h>
#include<string.h>
#include<sys/shm.h>
#include<unistd.h>

int main()
{
	int i=0 ;
	void * shared_memory ;
	char buff[100];
	int shmid ;

	shmid = shmget((key_t)2345,1024,0666 | IPC_CREAT);
	printf("Shared memory kEY :- %d",shmid);

	shared_memory = shmat(shmid,NULL,0);
	printf("Process attached at %p\n",shared_memory);
	printf("Enter some data to shared memory ");
	while(ch[i] !='\n')
	{
		scanf("%c",&buff[i]);
		i++;
	}

	strncpy(shared_memory,buff,strlen(buff));

	shmdt(shared_memory);

	return 0;


}