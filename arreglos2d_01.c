#include <stdio.h>

/*
    21/08/2023
    Manejo de arreglos 2d (1ra. Parte)
*/

int main(){
    // Un arreglo en 2 dimensiones es
    // un arreglo de arreglos
    int b[2][3] = {{1, 2, 3}, {4, 5, 6}};
    // El nombre del arreglo 2d es un arreglo 1d
    
    // Obteniendo la dirección base del arreglo b
    printf("\nb=%p", b);
    // Obteniendo la dirección del subarreglo 0
    // usando la notación de arreglo y notación de apuntadores
    printf("\nb=%p b[0]=%p *(b+0)=%p", b, b[0], *(b+0));
    // Obteniendo la dirección del elemento b[0][2]
    // usando la notación de arreglo y notación de apuntadores
    printf("\nb[0]+2 = %p, *(b+0)+2 = %p", b[0]+2, *(b+0)+2);
    // Obteniendo el valor del elemento b[0][2]
    // usando la notación de arreglo y notación de apuntadores
    printf("\n*(b[0]+2) = %d, *(*(b+0)+2) = %d", *(b[0]+2), *(*(b+0)+2));

    // Calculando las dimensiones del arreglo
    int m = sizeof(b)/sizeof(b[0]); // 2
    printf("\n\nm=%d", m);
    int n = sizeof(b[0])/sizeof(b[0][0]); // 3
    printf("\nn=%d", n);
    

    printf("\n\n");

}