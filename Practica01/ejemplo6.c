#include <stdio.h>
#include <string.h>

int main(){
    // Declaramoss un arreglo de cadenas
    char * vegetales[] = {
        "Brocoli", "Zanahoria", "Betabel", "Espinaca", "Papa", "Jitomate"
    };

    // 1) Usando la función sizeof obtenga el número de elementos del arreglo vegetales
    int MAX = sizeof(vegetales)/sizeof(vegetales[0]);

    // Imprimiendo las direcciones base de cada elemento del arreglo
    int i;
    printf("\nDirecciones base de cada elemento del arreglo: ");
    for(i=0; i<MAX; i++){
        printf("\ndir(vegetales[%d]) = %p", i, &vegetales[i]);
    }

    // Imprimiendo el contenido de las cadenas del arreglo
    printf("\nValores del arreglo vegetales: ");
    for(i=0; i<MAX; i++){
        printf("\nvegetales[%d] = %s", i, vegetales[i]);
    }

    // Modifique el código anterior para que además imprima el número de caracteres 
    // que contiene cada cadena del arreglo
    printf("\nNúmero de caracteres de cada valor del arreglo vegetales: ");
    for(i=0; i<MAX; i++){
        printf("\nlen(%s) = %lu", vegetales[i], strlen(vegetales[i]));
    }

    return 0;
}