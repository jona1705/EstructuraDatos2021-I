#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Declaración y uso de structs (registros) en C */

struct agenda{
    char nombre[50];
    char telefono[20];
};

int main(){
	// Declaración de un arreglo de elementos de  tipo struct agenda
    struct agenda a1[2];
 
    // Accedemos a los miembros del struct a partir de un índice
    // y el operador (.)
    strcpy(a1[0].nombre, "Juan");
    strcpy(a1[0].telefono, "5512345678");

    printf("\nNombre: %s", a1[0].nombre);
    printf("\nTelefono: %s", a1[0].telefono);

    printf("\n");
    
    strcpy(a1[1].nombre, "Paco");
    strcpy(a1[1].telefono, "551232778");

    printf("\nNombre: %s", a1[1].nombre);
    printf("\nTelefono: %s", a1[1].telefono);

    return 0;
}
