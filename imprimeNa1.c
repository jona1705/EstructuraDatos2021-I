#include <stdio.h>

void X(int n){
	int i;
	for(i=n; i>=1; i--){
		printf("%d ", i);
	}
}

// Imprime de n a 1 recursivamente
void X_rec(int n){
	if(n==0) return;
	printf("%d ", n);
	X_rec(n-1);			
}

int main(){
	printf("Imprime de n a 1 iterativo: ");
	X(10);
	printf("\n\nImprime de n a 1 recursivo: ");
	X_rec(10);
}
