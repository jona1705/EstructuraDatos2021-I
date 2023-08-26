#include <stdio.h>

/*
    Clase: 23/08/2023
    Segunda forma de pasar un arreglo bidimensional
    a una funcion
*/

/* FORMA 2 : Usando un apuntador como parámetro */
void imprimir(int m, int n, int * p){
    int i, j;
    for(i=0; i<m; i++){
        for(j=0; j<n; j++){
            // Usando la formula de direccionamiento
            printf("%d ", *(p + i*n + j));
        }
        printf("\n");
    }
}

int main(){

    int a[2][3] = {1, 2, 3, 4, 5, 6};
    printf("\n");
    
    // Forma 2
    // &a[0][0] = a = a[0]
    // Llamamos a al función y pasamos la dirección base del arreglo
    imprimir(2, 3, &a[0][0]); 

    return 0;
}