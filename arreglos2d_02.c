#include <stdio.h>

/*
    21/08/2023
    Manejo de arreglos 2d (2da. Parte)
    Uso de un doble apuntador (apuntador a apuntador)
    y un arreglo de apuntadores para acceder a los
    elementos de un arreglo 2d
*/

void testing(int ** dp, int m, int n){
    int i, j;
    for(i=0; i<m; i++){
        for(j=0; j<n; j++){
            printf("b[%d][%d] = %d", i, j, dp[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int b[2][3] = {{1, 2, 3}, {4, 5, 6}};
    // Calcular m y n
    int m = sizeof(b)/sizeof(b[0]); // 2
    int n = sizeof(b[0])/sizeof(b[0][0]); // 3

    // Arreglo de apuntadores
    int *p[m]; // m representa las filas

    int i;
    for(i=0; i<m; i++){
        p[i] = b[i];
    }

    // El doble apuntador apunta al
    // arreglo de apuntadores
    int **dp = p;

    testing(dp, m, n); 

    
}