#include <stdio.h>

void intercambiar(int * a, int * b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void burbuja(int * arr, int n){
    int i, j, temp;
    int bandera;
    // El bucle externo maneja el número de pasos
    // El bucle interno maneja el número de iteraciones
    for(int i=0; i<n-1; i++){
        bandera = 0;
        for(int j=0; j<n-i-1; j++){
            if(arr[j]>arr[j+1]){
                bandera = 1; 
                intercambiar(&arr[j], &arr[j+1]);
            }    
        }
        // Si despues de ejecutar cierta iteracion no se realizo
        // ningun intercambio la lista esta ordenada
        if(bandera == 0) break;
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
    burbuja(arr, n);
    desplegar(arr, n);
}