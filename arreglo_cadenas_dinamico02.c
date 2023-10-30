#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Funcion para anadir una cadena a un arreglo
void anadirCadena(char *** arreglo, int * tam, const char * nuevaCadena) {
    (*tam)++;
    *arreglo = (char **)realloc(*arreglo, (*tam) * sizeof(char *));

    if (*arreglo == NULL) {
        fprintf(stderr, "Fallo asignacion de memoria.\n");
        exit(1);
    }

    
    (*arreglo)[*tam - 1] = (char *) malloc(strlen(nuevaCadena) + 1);
    if ((*arreglo)[*tam - 1] == NULL) {
        fprintf(stderr, "Fallo duplicacion de cadena.\n");
        exit(1);
    }
    strcpy((*arreglo)[*tam - 1], nuevaCadena);

    // Alternativamente podemos usar
    /* (*arreglo)[*tam - 1] = strdup(nuevaCadena);
    if ((*arreglo)[*tam - 1] == NULL) {
        fprintf(stderr, "Fallo duplicacion de cadena.\n");
        exit(1);
    } */
}

// Function to free the dynamic array of strings
void liberarArregloCadena(char ** arreglo, int tam) {
    for (int i = 0; i < tam; i++) {
        free(arreglo[i]);
    }
    free(arreglo);
}

int main() {
    char ** arregloCadenas = NULL;
    int tam = 0;

    anadirCadena(&arregloCadenas, &tam, "CDMX");
    anadirCadena(&arregloCadenas, &tam, "Veracruz");
    anadirCadena(&arregloCadenas, &tam, "Monterrey");
    anadirCadena(&arregloCadenas, &tam, "Jalisco");
    anadirCadena(&arregloCadenas, &tam, "Campeche");

    // Imprimir los arreglos
    printf("\n\nLas cadenas son: \n");
    for (int i = 0; i < tam; i++) {
        printf("%d: %s\n", i+1, arregloCadenas[i]);
    }

    liberarArregloCadena(arregloCadenas, tam);

    return 0;
}
