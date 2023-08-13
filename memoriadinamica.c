#include <stdio.h>
#include <stdlib.h>

/* Asignación de memoria para una variable 
	con malloc */

int main(){
    int * p = NULL;

    p = malloc(sizeof(int)); 
    if(p == NULL){
        exit(0);
    }
    
    *p = 10;

    printf("p=%d", *p);

	// Liberar la memoria
    free(p);

	return 0;
}
