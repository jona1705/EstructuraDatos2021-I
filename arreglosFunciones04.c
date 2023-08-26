#include <stdio.h>

/*
    Clase: 23/08/2023
    Cuarta forma de pasar un arreglo bidimensional
    a una funcion
*/

/* FORMA 4 : Usando como parámetro un arreglo de apuntadores */
void imprimir(int m, int n, int *p[n]){
    int i, j;
    for(i=0; i<m; i++){
        for(j=0; j<n; j++){
            printf("%d ", p[i][j]);
        }
        printf("\n");
    }
} 

int main(){

    int a[2][3] = {1, 2, 3, 4, 5, 6};

    /* FORMA 4 */
    int * p[2]; // m = 2 (Número de filas)
    int i;
    for(i=0; i<2; i++){
        // Cada elemento del arreglo p apunta 
        // a la dirección base de cada subarreglo
        p[i] = a[i];
    }
    // Llamamos a la función y pasamos el arreglo de apuntadores
    imprimir(2, 3, p);
    
    return 0;
}


