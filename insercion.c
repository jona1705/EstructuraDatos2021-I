#include <stdio.h>

void intercambiar(int * a, int * b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insercion(int * arr, int n){
    int i, j;
    for(int i=1; i<n; i++){
        j = i;
        while((j>0) && (arr[j-1]>arr[j])){
            intercambiar(&arr[j-1],&arr[j]);
            j = j-1;
        }
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