#include <stdio.h>
#include <string.h>


int main(){
    // Declarar e inicializar un arreglo de cadenas
    char cadenas[5][20]; // 5 cadenas de 20 caracteres cada uno

    // Inicializar las cadenas
    strcpy(cadenas[0], "CDMX");
    strcpy(cadenas[1], "Veracruz");
    strcpy(cadenas[2], "Monterrey");
    strcpy(cadenas[3], "Jalisco");
    strcpy(cadenas[4], "Campeche");

    // Imprimir los arreglos
    printf("\n\nLas cadenas son: \n");
    size_t n = sizeof(cadenas)/sizeof(cadenas[0]);
    for(int i=0; i<n; i++){
        printf("Cadena %d: %s\n", i+1, cadenas[i]);
    }
    printf("\n");

    return 0;
}
