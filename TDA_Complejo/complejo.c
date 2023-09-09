#include <stdio.h>
#include <float.h>
#include <math.h>
#include "complejo.h"

Complejo init(double a, double b){
	Complejo c;
	c.real = a;
	c.img = b;
	return c;
}

// (a+bi) + (c+di) = (a+c) + (b+d)i
Complejo suma(Complejo c1, Complejo c2){
	Complejo c;
	c.real = c1.real + c2.real;
	c.img  = c1.img + c2.img;
	return c;
}

// (a+bi) - (c+di) = (a-c) + (b-d)i
Complejo resta(Complejo c1, Complejo c2){
	Complejo c;
	c.real = c1.real - c2.real;
	c.img  = c1.img - c2.img;
	return c;
}

// (a+bi) * (c+di) = (ac-bd) + (ad-bc)i
Complejo multiplicacion(Complejo c1, Complejo c2){
	Complejo c;
	c.real = ((c1.real * c2.real) - (c1.img * c2.img));
	c.img  = ((c1.real * c2.img) + (c1.img * c2.real));
	return c;
}


// (a+bi) / (c+di) = ((ac+bd) / (c^2 + d^2))+ ((bc-ad) / (c^2 + d^2))i
Complejo division(Complejo c1, Complejo c2){
	Complejo c;
	double denominador = ((c2.real + c2.real) + (c2.img + c2.img));
	if(denominador == 0.0){
		c.real = DBL_MIN;
		c.img = DBL_MIN;
	} else{
		c.real = ((c1.real * c2.real) + (c1.img * c2.img)) / denominador;
	c.img  = ((c1.img * c2.real) + (c1.real * c2.img)) / denominador;
	}

	return c;
}

double modulo(Complejo c){
	double mod = sqrt((c.real * c.real) + (c.img * c.img));
	return mod;
}

static void conversion(Complejo c, double * magnitud, double * angulo){
	*magnitud = modulo(c);
	*angulo = atan2(c.img, c.real);
}

void formaPolar(Complejo c){
	double magnitud, angulo;
	conversion(c, &magnitud, &angulo);
	printf("\nForma Polar: %.2lf * ((cos(%.2lf) + i*sin(%.2lf))", magnitud, angulo, angulo);
}

void imprimir(Complejo c){
	// Imprimiendo los números complejos
	// Tener cuidado de prevenir la division entre cero
	if(c.real == DBL_MIN || c.img == DBL_MIN) printf("(ERROR) Division entre cero");
	else if(c.real == 0 && c.img == 0) printf("0 + 0i");
	else if(c.real == 0) printf("%.2lf", c.img);
	else if(c.img == 0) printf("%.2fl", c.real);
	else if(c.img < 0) printf("%.2fl - %.2lf", c.real, (-1) * c.img);
	else printf("%.2fl + %.2lf", c.real, c.img);
}


