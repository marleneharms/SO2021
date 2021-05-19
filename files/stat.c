#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Room 1
// Linda Nayeli Abundis López
// Francisco Javier Ramos Velasco
// Marlene Rodríguez Harms 

int main(int argnum, char **argv){
    char *oldP = argv[1];
    char *newP = argv[2];
    
	// renombrar Si arch1.txt exista y arch2.txt no existe lo va a renombrar
	struct stat sb;
    if(stat(oldP,&sb) == -1){
        printf("Hay un error en el archivo\n");
        return -1;
    }

    struct stat sbn;
    if(stat(newP,&sbn) == -1){
        link(oldP,newP);
        unlink(oldP);
    }

	// Si arch2.txt existe me manda un mensaje de error
    if(S_ISREG(sbn.st_mode)){
        printf("El archivo2 ya es existente \n");
        return -1;
    }

	// Si dir2 existe y es un directorio mueve arch1.txt dentro de dir2
    if(S_ISDIR(sbn.st_mode)){
        char newD[100];
        strcpy(newD, newP);
        strcat(newD, "/");
        strcat(newD,oldP);
        printf("%s \n",newD);
        link(oldP,newD);
        unlink(oldP);
    }

    return 0;
}
