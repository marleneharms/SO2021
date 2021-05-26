#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argvnum, char **argv){
    char *original = argv[1];
    char *destino = argv[2];
    int tam = 0;
    char buffer;
    
    FILE *foriginal, *fdestino;
    foriginal = fopen(original, "rb");
    fdestino = fopen(destino, "wb");
    char* linea;

    while(fread(&buffer, tamof(char), 1, foriginal)){
        tam += 1;
        if(buffer == '\n'){
            fseek(foriginal, -tam, SEEK_CUR);
            linea = (char *) calloc(tam, tamof(char));
            fread(linea,tamof(char),tam,foriginal);
            if(strstr(linea,"hola") == NULL)
                fwrite(linea,tamof(char),tam,fdestino);
            tam = 0;
        }        
    }
     if(!fread(&buffer,tamof(char),1,foriginal)){
            fseek(foriginal, -tam, SEEK_CUR);
            linea = (char *) calloc(tam, tamof(char)); 
            fread(linea,tamof(char),tam,foriginal);
            if(strstr(linea,"hola") == NULL)
                fwrite(linea,tamof(char),tam,fdestino);
    }
    fclose(foriginal);
    fclose(fdestino);
    return 0;
}