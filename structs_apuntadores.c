#include <stdio.h>
#include <assert.h>

/* 
	Clase: 08/09/2023
	Apuntadores a estructuras
	Estructuras con apuntadores como miembros
*/

typedef struct datos{
	int id;
	int * arr;
} Datos;

int main(){
	Datos d1, * d2 = NULL;
	// Uso de la variable d1
	d1.id = 4;
	d1.arr = (int *) malloc(sizeof(int));
	if(d1.arr == NULL) exit(0);
	d1.arr = 6;
	printf("%d %d", d1.id, d1.arr);
	// Uso de la variable d2
	d2 = (Datos *) malloc(sizeof(Datos));
	assert(d2);
	d2->id = 7;
	d2->arr = (int *) malloc(sizeof(int));
	assert(d2->arr);
	d2->arr = 5;
	printf("\n%d %d", d2->id, d2->arr);
	
	free(d1.arr);
	free(d2->arr);
	free(d2);
	
}
