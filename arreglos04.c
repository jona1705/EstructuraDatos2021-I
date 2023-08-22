#include <stdio.h>

/*
    21/08/2023
    Manejo de arreglos 1d (4ta. Parte)
*/

// void testing(int a[]);

void testing(int * p){
    printf("\np=%p", p);
    p++;
    printf("\np=%p", p);
    p[3] = 7;
}

int main(){
    // Inicializamos los elementos del arreglo en 0
    int a[10] = {0};
    // pasar el arreglo a la funcion
    printf("\na=%p", a);
    // Imprimir los valores del arreglo antes de llamar a la
    // función testing()
    int i;
    printf("\n");
    for(i=0; i<5; i++){
        printf("%d ", a[i]);
    }
    printf("\n");

    // Llamando a la función testing
    testing(a);

    // Imprimir los valores del arreglo desspués de llamar a la
    // función testing()
    printf("\n");
    for(i=0; i<5; i++){
        printf("%d ", a[i]);
    }

    return 0;
}