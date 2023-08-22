#include <stdio.h>

/*
    21/08/2023
    Manejo de arreglos 1d (1ra. Parte)
*/

int main(){

    int a[5] = {1, 2, 3, 4, 5};
    // Imprimiendo la dirección base de a
    printf("a=%p", a);

    // a++; No podemos cambiar la referencia de un arreglo

    // Apuntador apuntando a la dirección base de a
    int * p = a;
    // Imprimiendo la dirección base de a usando p
    printf("\np=%p", p);
    // Nos desplazamos al siguiente elemento de a usando p
    p++;
    // Imprimiendo la dirección a[1] usando p
    printf("\np=%p", p);
    
    return 0;
}