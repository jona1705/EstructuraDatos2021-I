#ifndef __COMPLEJO_H_
#define __COMPLEJO_H_

// Definimos la interfaz del número complejo

typedef struct complejo {
	double real;
	double img;
} Complejo;

Complejo init(double a, double b);
Complejo suma(Complejo c1, Complejo c2);
Complejo resta(Complejo c1, Complejo c2);
Complejo multiplicacion(Complejo c1, Complejo c2);
Complejo division(Complejo c1, Complejo c2);
void imprimir(Complejo c);
double modulo(Complejo c);
void formaPolar(Complejo c);


#endif
