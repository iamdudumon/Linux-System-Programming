#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void alarmHandler();

int main(){
	int sec;
	signal(SIGALRM, alarmHandler);
	alarm(5);

	printf("무한 루프\n");
	while(1){
		sleep(1);
		printf("%d 초 경과\n", ++sec);
	}
	printf("실행 ㄴㄴ\n");
}

void alarmHandler(int signo){
	printf("일어나세요\n");
	exit(0);
}
