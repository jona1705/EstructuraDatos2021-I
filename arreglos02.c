#include <stdio.h>

/*
    21/08/2023
    Manejo de arreglos 1d (2da. Parte)
*/

int main(){

    int a[5] = {1, 2, 3, 4, 5};
    // Declaramos un apuntador a entero
    int * p = a;
    // Declaramos un apuntador a un arreglo de
    // enteros de 5 elementos
    int (*q)[5] = &a;
    // Imprimimos la dirección base de a usando p y q
    printf("\np=%p", p);
    printf("\nq=%p", q);
    // Nos deplazamos al siguiente elemento de a usando p y q
    p++;
    q++;
    // p se desplaza a la dirección de a, es decir, a[1]
    printf("\n\np=%p", p);
    // p se desplaza al siguiente bloque de memoria de 5 enteros
    printf("\nq=%p", q);
    
    return 0;
}