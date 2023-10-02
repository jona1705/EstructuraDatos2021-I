#include <stdio.h>

// Imprime de 1 a n Iterativamente
void X(int n){
	int i;
	for(i=0; i<n; i++){
		printf("%d ", i+1);	
	}	
}

// Imprime de 1 a n recursivamente
void X_rec(int n){
	if(n==0) return;
	X_rec(n-1);
	printf("%d ", n);			
}

int main(){
	printf("Imprime de 1 a n iterativo: ");
	X(10);
	printf("\n\nImprime de 1 a n recursivo: ");
	X_rec(10);
}

