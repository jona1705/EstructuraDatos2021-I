#include <stdio.h>

/* 
	Clase: 18/09/2023
	Algoritmo de la Burbuja (recursivo)
	para ordenaci�n de numeros
*/

void intercambiar(int * a, int * b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

// Se realizan (n-1)*(n-1) comparaciones
// aunque la lista ya este ordenada
void burbuja(int arreglo[], int n){
	// Caso base: la longitud de la lista es 1
	if(n==1) return; 
	
	int i;
	for(i=0; i<n-1; i++){
		if(arreglo[i] > arreglo[i+1]){
			intercambiar(&arreglo[i], &arreglo[i+1]);
		}	
	}
	// Caso recursivo: llamamos a burbuja() para procesar
	// las sublistas faltantes
	burbuja(arreglo, n-1);
}

void desplegar(int arreglo[], int n){
	int i;
	for(i=0; i<n; i++){
		printf("%d ", arreglo[i]);
	}
	printf("\n");
}

int main(){
	int arr[] = {9, 6, -2, 8, 5, -1, 3, 4};
	int n = sizeof(arr)/sizeof(arr[0]);
	printf("\nArreglo antes de ordenar: \n");
	desplegar(arr, n);
	printf("\nArreglo despues de ordenar: \n");
	burbuja(arr, n);
	desplegar(arr, n);
	
	return 0;
}
