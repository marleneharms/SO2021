#include "student.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char* itoa(int v, int b){
	static char buf[32] = {0};
	int i = 30;
	for(; v && i ; --i, v /= b){
		buf[i] = "0123456789abcdef"[v % b];	
	}
	return &buf[i+1];
}


int main(int argc, char **argv) {
  char *nV = argv[4];
  char *filename = argv[1];
  char *atributo = argv[2];
  char *word = argv[3];

  STUDENT nS;
	
  FILE *forigen;
  forigen = fopen(filename,"r+b");

  while(fread(&nS,sizeof(nS), 1, forigen)){
	
	if(strcmp(atributo, "name")==0)
		if(strcmp(word, nS.name) == 0){
			strcpy(nS.name, nV);
			fseek(forigen, -1 * sizeof(nS), SEEK_CUR);
			fwrite(&nS, sizeof(nS), 1, forigen);
			fread(&nS, sizeof(nS), 1, forigen);
		}

	if(strcmp(atributo, "lastname")==0)
		if(strcmp(word, nS.lastname) == 0){
			strcpy(nS. lastname, nV);
			fseek(forigen, -1 * sizeof(nS), SEEK_CUR);
			fwrite(&nS, sizeof(nS), 1, forigen);
			fread(&nS, sizeof(nS), 1, forigen);
		}

	if(strcmp(atributo, "id")==0){
		char* id = itoa(nS.id, 10);
		if(strcmp(word, id) == 0){
			nS.id = atoi(nV);
			fseek(forigen,-1 * sizeof(nS), SEEK_CUR);
			fwrite(&nS, sizeof(nS), 1, forigen);
			fread(&nS, sizeof(nS), 1, forigen);
		}
	}

	if(strcmp(atributo, "semestre")==0){
		char* sem = itoa(nS.semestre, 10);
		if(strcmp(word, sem) == 0){
			nS.semestre = atoi(nV);
			fseek(forigen, -1*sizeof(nS), SEEK_CUR);
			fwrite(&nS, sizeof(nS), 1, forigen);
			fread(&nS, sizeof(nS), 1, forigen);
		}
	}
	  
  }
  fclose(forigen);
} 