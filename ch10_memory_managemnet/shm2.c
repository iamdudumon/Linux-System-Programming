#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(){
	int shmid;
	key_t key;
	char *shmaddr;

	key = ftok("hi", 1);
	shmid = shmget(key, 1024, 0);
	if(shmid == -1){
		perror("shmget");
		exit(1);
	}

	printf("shmid: %d\n", shmid);
	shmaddr = (char *)shmat(2, NULL, 0);
	printf("%s\n", shmaddr);
}
