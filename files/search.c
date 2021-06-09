#include "student.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char* itoa(int val, int base){
	static char buf[32] = {0};
	int i = 30;
	for(; val && i ; --i, val /= base) buf[i] = "0123456789abcdef"[val % base];
	return &buf[i+1];
}


int main(int argc, char **argv) {
  
	// arvg
  char *word = argv[3];
  char *fn = argv[1];
  char *atributo = argv[2];
  
  
  STUDENT nS;
  FILE *forigen;
  forigen = fopen(fn, "rb");

    while(fread(&nS, sizeof(nS), 1, forigen)){ 
		
        if(strcmp(atributo, "name") == 0){
            if(strcmp(word,nS.name) == 0){ printf("%s %s %d %d \n",nS.name,nS.lastname,nS.id,nS.semestre);}
        }else if(strcmp(atributo, "lastname") == 0){
            if(strcmp(word, nS.lastname) == 0){printf("%s %s %d %d \n", nS.name, nS.lastname, nS.id,nS.semestre);}
        }else if(strcmp(atributo,"id") == 0){
            char* id = itoa(nS.id, 10);
            if(strcmp(word,id) == 0) {printf("%s %s %d %d \n",nS.name,nS.lastname,nS.id,nS.semestre);}
        }else if(strcmp(atributo, "semestre") == 0){
            char* sem = itoa(nS.semestre, 10);
            if(strcmp(word, sem) == 0) { printf("%s %s %d %d \n", nS.name, nS.lastname, nS.id,nS.semestre);}    
        }
    }
    fclose(forigen);
}