#ifndef FRACCION_H
#define FRACCION_H

typedef struct fraccion{
	int numerador;
	int denominador;
} Fraccion;

Fraccion init(int a, int b);
Fraccion suma(Fraccion f1, Fraccion f2);
Fraccion resta(Fraccion f1, Fraccion f2);
Fraccion multiplicacion(Fraccion f1, Fraccion f2);
Fraccion division(Fraccion f1, Fraccion f2);
int getNumerador(Fraccion f);
int getDenominador(Fraccion f);
void imprimir(Fraccion f);

#endif
