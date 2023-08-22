#include <stdio.h>

/*
    18/08/2023
    Almacenamiento de variables, apuntadores
    y aritmética de apuntadores
*/

int main(){
    int a = 5; // 4 bytes
    float b = 3.45; // 4 bytes
    int * p = &a; // 8 bytes

    printf("\np=%p", p);

    // Aritmetica de apuntadores
    p= p+1; // Se desplaza 4 bytes a la derecha
    printf("\np=%p", p);

    p = p-1; // Se desplaza 4 bytes a la izquierda
    printf("\np=%p", p);

    return 0;
}
