#include <stdio.h>

int main()
{
	int sec = 0;
	alarm(5);
	printf("무한 루프 \n");
	while(1){
		sleep(1);
		printf("%d 초 경과 \n", ++sec);
	}
	printf("결코 실행 ㄴㄴ");
}
