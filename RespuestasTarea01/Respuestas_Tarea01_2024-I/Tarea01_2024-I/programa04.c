#include <stdio.h>
#include <stdlib.h>
#define dim01 3
#define dim02 4
#define dim03 2
#define dim04 3

int main(){
	int **** ptr = NULL;
	int i, j, k, l;
	// Creando un arreglo de dim01 elementos de triples apuntadores
	ptr = (int ****) malloc (dim01 * sizeof(int ***));
	if(ptr == NULL) exit(0);

	for(i=0; i<dim01; i++){
		// Cada elemento del arreglo de triple apuntador apunta 
		// a un arreglo de dim02 elementos de dobles apuntadores
		ptr[i] = (int ***) malloc(dim02 * sizeof(int **));
		if(ptr[i] == NULL) exit(0);
		for(j=0; j<dim02; j++){
			// Cada elemento de los arreglos de doble apuntador apunta 
			// a un arreglo de dim03 elementos de apuntadores
			ptr[i][j] = (int **) malloc(dim03 * sizeof(int *));
			if(ptr[i][j] == NULL) exit(0);
			for(k=0; k<dim03; k++){
				// Cada elemento de los arreglos de apuntador apunta 
				// a un arreglo de dim04 elementos de enteros
				ptr[i][j][k] = (int *) malloc(dim04 * sizeof(int));
				if(ptr[i][j][k] == NULL) exit(0);	
			}
		}
	}
	
	// Llenando el arreglo 4D
	for(i=0; i<dim01; i++){
		for(j=0; j<dim02; j++){
			for(k=0; k<dim03; k++){
				for(l=0; l<dim04; l++){
					ptr[i][j][k][l] = i+j+k+l;
				}
			}
		}
	}
	
	// Imprimiendo el arreglo 4D
	for(i=0; i<dim01; i++){
		for(j=0; j<dim02; j++){
			for(k=0; k<dim03; k++){
				for(l=0; l<dim04; l++){
					printf("%d ", ptr[i][j][k][l]);
				}
				printf("\n");
			}
			printf("\n");
		}
		printf("\n");
	}
	
	// Liberando memoria
	for(i=0; i<dim01; i++){
		for(j=0; j<dim02; j++){
			for(k=0; k<dim03; k++){
				free(ptr[i][j][k]);
			}
			free(ptr[i][j]);
		}
		free(ptr[i]);	
	}
	
	free(ptr);
}
