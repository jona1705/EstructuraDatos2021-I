#include <stdio.h>

/* 
	Clase: 18/09/2023
	Arreglos vs apuntadores
*/

int main(){
	int arreglo01[20] = {1, 2, 3, 4};
	printf("%lu", sizeof(arreglo01)); // 80
	
	// Podemos omitir la dimension en un arreglo 1D
	int arreglo02[] = {1, 2, 3, 4};
	printf("\n%lu", sizeof(arreglo02)); // 16
	// arreglo++; // No podemos cambiar la referencia de un arreglo
	int * p = arreglo02 + 1;
	// nombre_del_arreglo vs apuntador
	printf("\n%d %d", arreglo02[1], p[1]);
}
