#include <stdio.h>

/*
    Clase: 23/08/2023
    Tercera forma de pasar un arreglo bidimensional
    a una funcion
*/

/* FORMA 3 : Usando un apuntador a un arreglo */
void imprimir(int m, int n, int (*p)[n]){
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

    /* FORMA 3 */
    int (*p)[3] = a;
    // Llamamos a la función y pasamos el apuntador a arreglo
    imprimir(2, 3, p);
    
    return 0;
}