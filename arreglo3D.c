#include <stdio.h>
#define P 2 // Número de páginas
#define M 3 // Número de filas
#define N 3 // Número de columnas

/* 
	Clase: 25/08/2023
	Imprimiendo un arreglo 3D
*/

int main(){
	
	// Un arreglo 3D es un arreglo de arreglos 2D	
	int a[P][M][N] = {{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}, 
		              {{10, 11, 12}, {13, 14, 15}, {16, 17, 18}}};
	 
	// Imprimiendo un arreglo tridimensional
	int i, j, k;
	for(i=0; i<P; i++){
		for(j=0; j<M; j++){
			for(k=0; k<N; k++){
				printf("%d ", a[i][j][k]);
			}
			printf("\n");
		}
		printf("\n");
	}
	
	return 0;
}
