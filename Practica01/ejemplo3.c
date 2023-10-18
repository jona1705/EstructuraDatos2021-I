#include <stdio.h>

int main(){
    // Declaramos un arreglo de apuntadores a doble
    double * arr[3];
    // Declaramos valores de tipo doble
    double p = 42.3, q = 37.91, r = 29.8;
    // Asignamos valores al arreglo
    arr[0] = &p;
    arr[1] = &q;
    arr[2] = &r;

    // Imprimiendo los valores del arreglo
    int i;
    printf("\nValores del arreglo arr: ");
    for(i=0; i<3; i++){
        printf("\narr[%d] = %p", i, arr[i]);
    }
    // Imprimiendo el contenido de los elementos a los que apuntan
    printf("\nValores a los que apuntan los elementos del arreglo arr: ");
    for(i=0; i<3; i++){
        printf("\narr[%d] = %.2lf", i, *arr[i]);
    }

    return 0;
}