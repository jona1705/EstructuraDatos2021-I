#include <stdio.h>

void intercambiar(int * a, int * b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void seleccion(int arr[], int n) {
    int i, j, minIndex;
    for (i = 0; i < n - 1; i++) {
        minIndex = i;
        // Buscamos el indice del elemento minimo en la parte no ordenada
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // Intercambiamos el elemento minimo con el primer elemento de la lista
        // no ordenada
        intercambiar(&arr[i], &arr[minIndex]);
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
    seleccion(arr, n);
    desplegar(arr, n);
}