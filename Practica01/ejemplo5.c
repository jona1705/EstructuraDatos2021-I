#include <stdio.h>

int main(){
    // Declaramos un arreglo de enteros
    double arr[10] = {3.45, 6.34, 7.29, 5.21, -4.67, 8.12, 43.25, -12.56, 15.73};
    int n; // Capturamos el tamaño del arreglo
    int i; // Sirve como índice del arreglo
    // Imprimiendo la dirección de arr
    printf("\ndir(arr)= %p", arr);
    // Imprimiendo la dirección del primer elemento del arreglo
    printf("\ndir(arr[0])= %p", &arr[0]);
    // Obteniendo el número de elementos del arreglo
    n = sizeof(arr)/sizeof(arr[0]);
    // Imprimiendo los valores del arreglo (Notación de apuntadores)
    printf("\nValores del arreglo: ");
    for(i=0; i<n; i++){
        printf("\n*(arr + %d)= %.2lf", i, *(arr + i));
    }

    // Imprimiendo las direcciones de los elementos del arreglo
    printf("\nDirecciones del arreglo: ");
    for(i=0; i<n; i++){
        printf("\ndir(*(arr + %d))= %p", i, arr + i);
    }

    return 0;
}