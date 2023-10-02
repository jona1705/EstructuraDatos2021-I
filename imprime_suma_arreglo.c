#include <stdio.h>

int suma(int arr[], int n){
	int i, cont = 0;
	for(i=0; i<n; i++){
		cont = cont + arr[i];
	}
	return cont;
}

// Sumar los elementos del arreglo de forma recursiva
int suma_rec(int arr[], int n){
	if(n==1) return arr[0];
	else return suma(arr, n-1) + arr[n-1];
}

int main(){
	int arreglo[] = {1,3,5,7,9,11,13,15,18};
	int n = sizeof(arreglo)/sizeof(arreglo[0]);
	
	printf("Suma iterativo: ");
	printf("\nLa suma es: %d", suma(arreglo, n));
	printf("\n\nSuma recursivo: ");
	suma_rec(arreglo, n);
	printf("\nLa suma es: %d", suma_rec(arreglo, n));
}
