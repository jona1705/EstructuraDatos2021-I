#include <stdio.h>

/*
    21/08/2023
	Introducción a los arreglo bidimensionales

*/

int main(){
	// Declaración de un arreglo 2d
    double a[3][3];

    // Imprimiendo las direcciones de cada elemento de a
    printf("\n\nDirecciones de a: ");
    int i, j;
    for(i = 0; i<3; i++){
        for(j = 0; j<3; j++){
            printf("\n%p", &a[i][j]);
        }    
    }

	// Imprimiendo la dirección base del subarreglo [0]
    printf("\n\n%p", &a[0]);
    // Imprimiendo la dirección base del subarreglo [1]
    printf("\n%p", &a[1]);
    // Imprimiendo la dirección base del subarreglo [2]
    printf("\n%p", &a[2]);

    // Recorremos el arreglo usando la formula de direccionamiento
    // a[i][j] = i * (Numero_de_Columnas) + j
    printf("\n\n\nImprimiendo los valores en el arreglo 2d a: ");
    // Nota al no asignarle valores al arreglo a
    // su contenido imprime algunos valores basura
    double * p = a;
    for(i = 0; i<3; i++){
        for(j = 0; j<3; j++){
            printf("\n%d", *(p + i*3 + j));
        }    
    }

	return 0;
}
