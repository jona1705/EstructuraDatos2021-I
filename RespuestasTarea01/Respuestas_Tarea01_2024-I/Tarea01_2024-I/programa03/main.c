#include <stdio.h>
#include <stdlib.h>
#include "fraccion.h"

int main() {
	Fraccion f1 = init(1, 2);
	Fraccion f2 = init(1, 3);
	// Numerador de f1 y f2
	printf("Num(f1)=%d", getNumerador(f1));
	printf("\nNum(f2)=%d", getNumerador(f2));
	// Denominador de f1 y f2
	printf("\nDenom(f1)=%d", getDenominador(f1));
	printf("\nDenom(f2)=%d", getDenominador(f2));
	// Imprimiendo resultados de suma
	Fraccion s = suma(f1, f2);
	printf("\nLa suma es: ");
	imprimir(s);
	// Imprimiendo resultados de resta
	Fraccion r = resta(f1, f2);
	printf("\nLa resta es: ");
	imprimir(r);
	// Imprimiendo resultados de multiplicacion
	Fraccion m = multiplicacion(f1, f2);
	printf("\nLa multiplicacion es: ");
	imprimir(m);
	// Imprimiendo resultados de division
	Fraccion div = division(f1, f2);
	printf("\nLa division es: ");
	imprimir(div);
	
	// Simplificacion de fracciones
	Fraccion f3 = init(12, 4);
	printf("\n");
	imprimir(f3);
	
	return 0;
}
