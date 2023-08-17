#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(){
	int shmid;
	char *shmp1, *shmp2;

	shmid = shmget(IPC_PRIVATE, 10*sizeof(char), IPC_CREAT|0666);
	if(shmid == -1){
		perror("shmget failed\n");
		exit(0);
	}

	if(fork() == 0){
		shmp1 = (char *) shmat(shmid, NULL, 0);
		for(int i = 0; i < 10; i++)
			shmp1[i] = i * 10;
		shmdt(shmp1);
		exit(0);
	}
	else{
		wait(NULL);
		shmp2 = (char *)shmat(shmid, NULL, 0);
		for(int i = 0; i < 10; i++)
			printf("%d ", shmp2[i]);
		printf("\n");
		shmdt(shmp2);

		if(shmctl(shmid, IPC_RMID, NULL) == -1)
			printf("shmctl falied\n");
	}
}
