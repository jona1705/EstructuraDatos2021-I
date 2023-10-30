#include <stdio.h>
#include <stdlib.h>

/* Jagged Arrays (Arreglo de arreglos) */

int main() {
    int filas = 4; // Número de filas en el arreglo irregular
    int * arreglo[filas]; // Declaración del jagged array
    size_t sizes[filas]; // Arreglo para almacenar el tamaño de los arreglos

    int arreglo01[] = {1};
    int arreglo02[] = {3, 4, 5};
    int arreglo03[] = {6, 7, 8, 9};
    int arreglo04[] = {10, 11};

    // Capturando los tamaños de los arreglos
    sizes[0] = sizeof(arreglo01)/sizeof(int);
    sizes[1] = sizeof(arreglo02)/sizeof(int);
    sizes[2] = sizeof(arreglo03)/sizeof(int);
    sizes[3] = sizeof(arreglo04)/sizeof(int); 

    // Llenando arreglo irregular
    arreglo[0] = arreglo01;
    arreglo[1] = arreglo02;
    arreglo[2] = arreglo03;
    arreglo[3] = arreglo04;

    // Acceso a elementos individuales del arreglo irregular
    printf("\nImprimiendo elementos individuales del arreglo: \n");
    printf("arreglo[0][1]: %d\n", arreglo[0][1]);
    printf("arreglo[1][2]: %d\n", arreglo[1][2]);
    printf("arreglo[2][3]: %d\n", arreglo[2][3]);

    // Acceso a todos los arreglos arreglo irregular
    printf("\nImprimiendo todos los arreglos: ");
    int tam = sizeof(arreglo)/sizeof(arreglo[0]);
    for(int i=0; i<tam; i++){
        int * arregloActual = arreglo[i];
        printf("\nArreglo %d: ", i+1);
        for(int j=0; j<sizes[i]; j++){
            printf("%d ", arregloActual[j]);
        }
    }
    printf("\n\n");


    return 0;
}