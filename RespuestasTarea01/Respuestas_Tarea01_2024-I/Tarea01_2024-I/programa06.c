#include <stdio.h>

// Esta funcion actualiza el arreglo 
// sin necesidad de crear un nuevo arreglo
// auxiliar (no se toma memoria auxiliar)
void actualizar(int arr[], int n){
	int i, anterior, siguiente, actual;
	anterior = arr[0];
	siguiente = arr[1];
	if(n==2){
		arr[0] = arr[1] = anterior * siguiente; 
	} else if(n>2){
		arr[0] = anterior * siguiente;	
		for(i=1; i<n; i++){
			if(i==1){
				siguiente = arr[i+1];
				actual = arr[i];
				arr[i] = anterior * siguiente;
			} else if(i==n-1){
				anterior = actual;
				siguiente = arr[n-1];
				arr[i] = anterior * siguiente;
			} else{
				anterior = actual;
				siguiente = arr[i+1];
				actual = arr[i];
				arr[i] = anterior * siguiente;
			}		
		}
	} 
}

void desplegar(int * arr, int n){
	int i;
	printf("\n[ ");
	for(i=0; i<n; i++){
		printf("%d ", arr[i]);
	}
	printf("]");
}

int main(){
	int arr[] = {1, 2, 3, 4, 5, 6};
	int n = sizeof(arr)/sizeof(int);
	printf("\nArreglo Actual: ");
	desplegar(arr, n);
	printf("\nArreglo Actualizado: ");
	actualizar(arr, n);
	desplegar(arr, n);
}
