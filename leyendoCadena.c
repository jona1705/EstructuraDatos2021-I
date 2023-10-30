#include <stdio.h>


void leyendoCadena(char str[]){
    char * cad = str;
    while(*cad != '\0'){
        printf("%c", *cad);
        cad++; // Desplazo al siguiente caracter
    }
}

int main(){
    char cadena[] = "FES Acatlan";
    leyendoCadena(cadena);

    return 0;
}