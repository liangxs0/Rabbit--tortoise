/*************************************************************************
    > File Name: src/run.c
    > Author: L-Rmos
    > .....
    > Created Time: 2017年10月06日 星期五 09时59分22秒
 ************************************************************************/

#include "run.h"
int R = 0;
int T = 0;
void run(void)
{
	int i = 0;
	pid_t pid;
	pid = fork();
	if(pid == 0){
		for(i = 6;i < 65;i++){
			printf("\033[11;%dH\033[31m%s\033[0m\n",i,"T");
			sleep(rand() % 7);
			printf("\033[11;%dH\033[31m%s\033[0m\n",i," ");
			T++;
		}
	}else{
		for(i = 6;i < 65;i++){
			printf("\033[9;%dH\033[31m%s\033[0m\n",i,"R");
			sleep(rand() % 6);
			printf("\033[9;%dH\033[31m%s\033[0m\n",i," ");
			R++;
		}
	}
	if(T == 59 || R == 59){
		write(STDOUT_FILENO,"Game over",9);
	}
}


