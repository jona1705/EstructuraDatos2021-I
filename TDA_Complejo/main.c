#include <stdio.h>
#include "complejo.h"

int main() {
	// Numero complejo 1
	double a = 2.5;
	double b = 3.7;
	// Numero complejo 2
	double c = -4.5;
	double d = -6.3;
	
	// Creando números complejos
	Complejo c1 = init(a, b);
	Complejo c2 = init(c, d);
	
	Complejo s = suma(c1, c2);
	printf("La suma es: ");
	imprimir(s);

	Complejo r = resta(c1, c2);
	printf("\nLa resta es: ");
	imprimir(r);
	
	Complejo m = multiplicacion(c1, c2);
	printf("\nLa multiplicacion es: ");
	imprimir(m);
	
	Complejo dv = division(c1, c2);
	printf("\nLa division es: ");
	imprimir(dv);
	
	// Probando la division entre cero
	Complejo c3 = init(0, 0);
	Complejo c4 = init(0, 0);
	Complejo dvz = division(c3, c4);
	printf("\nLa division es: ");
	imprimir(dvz);
	
	// Probando la funcion modulo
	double mod = modulo(c1);
	printf("\nEl modulo de c1 es: %.2lf", mod);
	
	// Probando la función formaPolar
	printf("\nLa forma Polar de c1 es: ");
	formaPolar(c1);
	
	return 0;
}
