#include <unistd.h>
#include <ctype.h>
#include <stdio.h>

// 0 = stddin
// 1 = stdout

int main(){
    char minC;
    char mayC;
    int cont = 0;
    while(read(0,&minC,1)){
        mayC =toupper(minC);
        write(1,&mayC,1);
        if( minC == '\n'){
            cont++;
        }
    }
    printf ("\nSaltos de linea: %d\n",cont);

    return 0;
}