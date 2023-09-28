#include <stdio.h>
#include <limits.h>

/* 
	Clase: 18/09/2023
	Algoritmo de busqueda Lineal (recursivo)
	para encontrar un elemento
	en un arreglo
*/

int busquedaLineal(int arreglo[], int inicio, int fin, int buscado){
	if(inicio > fin) return INT_MIN;
	
	// Comprueba si el elemento en el índice 'inicio' es igual al 
	//valor buscado.
	if(arreglo[inicio] == buscado) return inicio;

	// Llamada recursiva para buscar en el resto del arreglo.
    return busquedaLineal(arreglo, inicio + 1, fin, buscado);
}

int main(){
	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int n = sizeof(arr)/sizeof(arr[0]);
	int buscado = 7;
	int indice = busquedaLineal(arr, 0, n-1, buscado);
	if(indice == INT_MIN){
		printf("\nEl valor buscado no se encuentra en el arreglo");
	} else{
		printf("\nEl valor buscado se encuentra en el indice: %d", indice);
	}
	
	return 0;
}
