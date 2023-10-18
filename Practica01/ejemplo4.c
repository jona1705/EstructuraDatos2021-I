#include <stdio.h>

int main(){
    // MAX es un valor constante con el número de elementos del arreglo
    const int MAX = 6;
    // Declaramoss un arreglo de cadenas
    char * vegetales[] = {
        "Brocoli", "Zanahoria", "Betabel", "Espinaca", "Papa", "Jitomate"
    };

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

    return 0;
}