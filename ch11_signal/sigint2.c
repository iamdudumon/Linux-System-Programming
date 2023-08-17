#include <stdio.h>
#include <signal.h>

struct sigaction newact;
struct sigaction oldact;

void sigint_handler(int signo);

int main(void){
	newact.sa_handler = sigint_handler;
	sigfillset(&newact.sa_mask);

	sigaction(SIGINT, &newact, &oldact);

	while(1){
		printf("Ctrl-C를 눌러보셈\n");
		sleep(1);
	}
}

void sigint_handler(int signo){
	printf("%d번 시그널 처리!\n", signo);
	printf("또 눌러보셈 ㅋㅋ\n");
	sigaction(SIGINT, &oldact, NULL);
}
