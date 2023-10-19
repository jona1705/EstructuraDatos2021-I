#include <stdio.h>
#include <stdbool.h>

// Funcion para calcular el MCD 
// usando el algoritmo de Euclides
int MCD(int a, int b) {
    int temp;
    while (b != 0) {
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

bool esMiniSudoku(int arr[3][3]) {
	// Creamos un array para marcar el número de ocurrencias (1-9)
    int numOcurrencias[10] = {0}; 

   	// Empezamos a verificar la matriz
   	int i, j;
    for (i=0; i<3; i++) {
        for (j=0; j<3; j++) {
            int num = arr[i][j];

            // Verificar si el número esta dentro del rango
            if (num<1 || num>9) return false;
			// Verifica si el valor ya existe en la matriz
            if (numOcurrencias[num] > 0) return false;
            // Marcamos la ocurrencia de un valor
            numOcurrencias[num]++;
        }
    }

    // Verificamos si cada numero ocurre una vez
    int num;
    for (num = 1; num <= 9; num++) {
        if (numOcurrencias[num] != 1) return false;
    }

    // Si se cumple todas las condiciones el cuadrado es valid
    return true;
}


int main(){
	//int arr[3][3] = {{1, 3, 2}, {9, 7, 8}, {4, 5, 6}}; // true
	//int arr[3][3] = {{1, 1, 3}, {6, 5, 4}, {8, 7, 9}}; // false
	//int arr[3][3] = {{0, 1, 2}, {6, 4, 5}, {9, 8, 7}}; // false
	int arr[3][3] = {{8, 9, 2}, {5, 6, 1}, {3, 7, 4}}; // true
	if(esMiniSudoku(arr)) printf("\nEl cuadrado es Mini-Sudoku");
	else printf("\nEl cuadrado no es Mini-Sudoku");
	
	return 0;
}
