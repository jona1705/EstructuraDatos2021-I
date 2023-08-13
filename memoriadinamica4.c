#include <stdio.h>
#include <stdlib.h>
#define N 10

/* Re-asignación de memoria para un arreglo
	con realloc */
	
int main(){
    int * p = NULL;
    int i;

    p = malloc(N * sizeof(int)); 
    if(p == NULL){
        exit(0);
    }
    
    // Asignamos valores al arreglo de N elementos
    for(i=0; i<N; i++){
        p[i] = i+1;
    }

	// Imprimimos los N valores
	printf("\nArreglo original ...");
    for(i=0; i<N; i++){
        printf("\np[%d]=%d", i, p[i]);
    }

	// Agregamos 10 valores más a los N valores que ya tenía el arreglo
	int n = N+5;
    p = realloc(p, n * sizeof(int));
    if(p == NULL){
        exit(0);
    }

    printf("\nArreglo reasignado ...");
    for(i=0; i<n; i++){
        printf("\np[%d]=%d", i, p[i]);
    }
    
    // Liberar la memoria
    free(p);
	
	return 0;
}
