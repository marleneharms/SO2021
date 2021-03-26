#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

void signalHandler(int sig){
	int pidHijoTermino = wait(NULL);
	prinf("Mi hijo termino %d \n", pidHijoTermino);
}

int main(){
	signal(17, signalHandler);
	int pid = fork();
	int pidHijoTermino;
	if(pid == 0){
		//Proceso hilo
		prinf("Soy el proceso hijo\n");
	} else{
		prinf("Soy el proceso padre y mi hijo es %d\n", pid);
		while(1){
			prinf("Trabajando \n");
			sleep(1);
		}
	}
	prinf("Terminado\n");
	return 0;
}

