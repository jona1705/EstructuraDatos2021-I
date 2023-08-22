#include <stdio.h>

/*
    21/08/2023
    Manejo de arreglos 1d (3ra. Parte)
*/

int main(){
    // Declaramos 3 enteros
    // NOTA: Estos valores no se guardan necesariamente
    // contiguos en memoria
    int a = 5, b = 6, c = 7;
    // Declarar un arreglo de apuntadores
    int *p[3];
    // Asignar los valores de a, b y c al arreglo de apuntadores
    p[0] = &a;
    p[1] = &b;
    p[2] = &c;
    // Imprimir las direcciones de a, b, c
    printf("\n%p %p %p", &a, &b, &c);
    // Imprimir las direcciones de a, b, c
    // con el arreglo de apuntadores
    printf("\n%p %p %p", p[0], p[1], p[2]);

    return 0;
}