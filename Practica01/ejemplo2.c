
#include <stdio.h>

int main(){
    // Declaramos un arreglo de enteros
    int arr[5] = {1, 2, 3, 4, 5};
    int n; // Capturamos el tamaño del arreglo
    int i; // Sirve como índice del arreglo
    // Imprimiendo la dirección de arr
    printf("\ndir(arr)= %p", arr);
    // Imprimiendo la dirección del primer elemento del arreglo
    printf("\ndir(arr[0])= %p", &arr[0]);
    // Obteniendo el número de elementos del arreglo
    n = sizeof(arr)/sizeof(arr[0]);
    // Imprimiendo los valores del arreglo
    printf("\nValores del arreglo: ");
    for(i=0; i<n; i++){
        printf("\narr[%d]= %d", i, arr[i]);
    }

    // Imprimiendo las direcciones de los elementos del arreglo
    printf("\nDirecciones del arreglo: ");
    for(i=0; i<n; i++){
        printf("\ndir(arr[%d])= %p", i, &arr[i]);
    }

    return 0;
}


