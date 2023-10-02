#include <stdio.h>

// Imprime Hola Mundo n veces de Forma Iterativa
void imprime_iterativo(int n){
	int i;
	for(i=0; i<n; i++){
		printf("\nHola Mundo");	
	}	
}

// Imprime Hola Mundo n veces de Forma Recursiva
void imprime_recursivo(int n){
	if(n==0) return;
	printf("\nHola Mundo");	
	imprime_recursivo(n-1);		
}

int main(){	
	printf("Imprime iterativo: ");
	imprime_iterativo(10);
	printf("\n\nImprime recursivo: ");
	imprime_recursivo(10);
}
