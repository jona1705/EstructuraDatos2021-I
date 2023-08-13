#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Declaración y uso de structs (registros) en C */

struct agenda{
    char nombre[50];
    char telefono[20];
};

int main(){
	// Declaración de una variable de tipo struct agenda
    struct agenda a1;

    printf("\n");

	// strcpy(): sirve para copiar el contenido de una cadena a otra
    strcpy(a1.nombre, "Juan");
    strcpy(a1.telefono, "5512345678");

	// Accedemos a los miembros del struct con el operador punto (.)
    printf("\nNombre: %s", a1.nombre);
    printf("\nTelefono: %s", a1.telefono);

	// Declaración de una variable de tipo apuntador a struct agenda
	// En este ejemplo se le asigna memoria con malloc
    struct agenda * a2 = malloc(sizeof(struct agenda));
    if(a2 == NULL){
        exit(0);
    }

    printf("\n");

	// Accedemos a los miembros del struct con el operador flecha (->)
    strcpy(a2->nombre, "Mateo");
    strcpy(a2->telefono, "5512445678");

    printf("\nNombre: %s", a2->nombre);
    printf("\nTelefono: %s", a2->telefono);

	// Liberar la memoria
    free(a2);

  	return 0;
}
