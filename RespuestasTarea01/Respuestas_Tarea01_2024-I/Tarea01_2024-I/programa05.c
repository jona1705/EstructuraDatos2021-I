#include <stdio.h>
#include <stdlib.h>

int contar(int * arr, int n){
	int i, cont = 0;
	for(i=0; i<n; i++){
		if(arr[i]%2 == 0) cont++;
	}
	return cont;
}

int * noImpares(int * arr, int n, int * nNuevo){
	int i;
	int noPares = contar(arr, n);
	*nNuevo = noPares;
	int * nuevoArr = (int *) calloc(noPares, sizeof(int));
	if(nuevoArr == NULL) exit(0);
	int nuevoIndex = 0;
	for(i=0; i< n; i++){
		if(arr[i]%2 == 0){
			nuevoArr[nuevoIndex] = arr[i];
			nuevoIndex++;
		} 
	}
	return nuevoArr;
}

void desplegar(int * arr, int n){
	int i;
	printf("\n[ ");
	for(i=0; i<n; i++){
		printf("%d ", arr[i]);
	}
	printf("]");
}

void limpiarMemoria(int * ptr){
	free(ptr);
}

int main(){
	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
	int n = sizeof(arr)/sizeof(arr[0]);
	int nNuevo;
	// Operando el primer arreglo
	int * nuevoArr = noImpares(arr, n, &nNuevo);
	desplegar(nuevoArr, nNuevo);
	// Liberar memoria para el arreglo 1
	limpiarMemoria(nuevoArr);
	
	// Operando el segundo arreglo
	int arr2[] = {43, 65, 23, 89, 53, 9, 6};
	nuevoArr = NULL; // Reseteando el apuntador
	int n2 = sizeof(arr2)/sizeof(arr2[0]);
	nuevoArr = noImpares(arr2, n2, &nNuevo);
	desplegar(nuevoArr, nNuevo);
	// Liberar memoria para el arreglo 2
	limpiarMemoria(nuevoArr);
	
	// Operando el tercer arreglo
	int arr3[] = {718, 991, 449, 644, 380, 440};
	nuevoArr = NULL; // Reseteando el apuntador
	int n3 = sizeof(arr3)/sizeof(arr3[0]);
	nuevoArr = noImpares(arr3, n3, &nNuevo);
	desplegar(nuevoArr, nNuevo);
	// Liberar memoria para el arreglo 3
	limpiarMemoria(nuevoArr);
}
