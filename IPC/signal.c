#include <signal.h>
#include <stdio.h>
#include <unistd.h>

int varGlobal = 0;

void signalHandler(int sig){
	printf("recibi signal %d\n", sig);
	varGlobal = 1;
}

int main(){
	signal(2, signalHandler);
	signal(15, signalHandler);
	while(1){
		printf("Trabajando\n");
		if(varGlobal == 1){
			break;
		}
		sleep(1);
	}
	printf("Ya voy a terminar \n");
	return 0;
}