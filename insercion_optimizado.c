#include <stdio.h>

void insercion(int * arr, int n){
    int i, j;
    int elementoActual;
    for(int i=1; i<n; i++){
        elementoActual = arr[i];
        j = i;
        while((j>0) && (arr[j-1]>elementoActual)){
            arr[j] = arr[j-1];
            j = j-1;
        }
        arr[j] = elementoActual;
    }
}

void desplegar(int arr[], int n){
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
}

int main(){
    int arr[] = {7, 3, 9, 0, 1, -3, 6, 8, 9};
    int n = sizeof(arr)/sizeof(int);
    printf("\nLista antes de ordenar: \n");
    desplegar(arr, n);
    printf("\n\nLista despues de ordenar: \n");
    insercion(arr, n);
    desplegar(arr, n);
}