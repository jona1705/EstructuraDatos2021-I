#ifndef PILA_H
#define PILA_H
#define MAX 100

struct pila{
    double A[MAX];
    int tope;
};

typedef struct pila Pila;

Pila init();
Pila push(Pila p, double x);
Pila pop(Pila p);
double peak(Pila p);
void desplegar(Pila p);
// MODIFICACION ACTIVIDAD 3
bool sonIguales(Pila p1, Pila p2);
// MODIFICACION ACTIVIDAD 4
double promedio(Pila p);
double maximo(Pila p);
double minimo(Pila p);

#endif  
