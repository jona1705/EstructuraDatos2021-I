#include <stdio.h>
#include "fraccion.h"

Fraccion init(int a, int b){
	Fraccion f;
	f.numerador = a;
	f.denominador = b;
	return f;
}

Fraccion suma(Fraccion f1, Fraccion f2){
	Fraccion f;
	f.numerador = (f1.numerador * f2.denominador) + (f2.numerador * f1.denominador);
	f.denominador = f1.denominador * f2.denominador;
	return f;
}

Fraccion resta(Fraccion f1, Fraccion f2){
	Fraccion f;
	f.numerador = (f1.numerador * f2.denominador) - (f2.numerador * f1.denominador);
	f.denominador = f1.denominador * f2.denominador;
	return f;
}

Fraccion multiplicacion(Fraccion f1, Fraccion f2){
	Fraccion f;
	f.numerador = f1.numerador * f2.numerador;
	f.denominador = f1.denominador * f2.denominador;
	return f;
}

Fraccion division(Fraccion f1, Fraccion f2){
	Fraccion f;
	f.numerador = f1.numerador * f2.denominador;
	f.denominador = f1.denominador * f2.numerador;
	return f;
}

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

void imprimir(Fraccion f){
	int m = MCD(f.numerador, f.denominador); 
	if((f.denominador/m)==1) printf("%d", f.numerador/m);
	else printf("%d/%d", f.numerador/m, f.denominador/m);
}

int getNumerador(Fraccion f){
	return f.numerador;
}

int getDenominador(Fraccion f){
	return f.denominador;
}

