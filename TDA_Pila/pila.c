#include <stdio.h>
#include <stdbool.h>
#include <float.h>
#include "pila.h"

Pila init(){
    Pila p;
    int i;
    for(i=0; i<MAX; i++){
        p.A[i] = 0.0;
    }
    p.tope = -1;
    return p;
}

// Operaciones auxiliares
static bool esLlena(Pila p){
    return p.tope == MAX-1;
}

static bool esVacia(Pila p){
    return p.tope == -1;
}

Pila push(Pila p, double x){
    if(esLlena(p)){
        printf("\n[] Pila Llena ...\n");
    } else{
        p.A[++p.tope] = x;
    }
    return p;
}

Pila pop(Pila p){
    if(esVacia(p)){
        printf("\n[] Pila Vacia ...\n");
    } else{
        p.tope--;
    }
    return p;
}

double peak(Pila p){
    if(!esVacia(p)){
        return p.A[p.tope];
    } 
    return -1.0;
}

void desplegar(Pila p){
    if(esVacia(p)){
        printf("\n[] Pila Vacia ...\n");
    } else{
        int i;
        for(i=p.tope; i>=0; i--){
            printf("%.2lf ", p.A[i]);
        }
    }
}

// MODIFICACION ACTIVIDAD 3
bool sonIguales(Pila p1, Pila p2){
    if(p1.tope != p2.tope) return false;
    int i;
    for(i=p1.tope; i>=0; i--){
        if(p1.A[i] != p2.A[i]) return false;
    }
    return true;
}

// MODIFICACION ACTIVIDAD 4
double promedio(Pila p){
    int i;
    double cont = 0.0, media;    
    for(i=p.tope; i>=0; i--){
        cont += p.A[i];
    }
    media = cont/(double)(p.tope+1);
    return media;    
}

// MODIFICACION ACTIVIDAD 4
double maximo(Pila p){
    int i;
    double max = DBL_MIN;
    for(i=p.tope; i>=0; i--){
        if(p.A[i] > max){
            max = p.A[i];
        }
    }
    return (double)max;
}

// MODIFICACION ACTIVIDAD 4
double minimo(Pila p){
    int i;
    double min = DBL_MAX;
    for(i=p.tope; i>=0; i--){
        if(p.A[i] < min){
            min = p.A[i];
        }
    }
    return (double)min;
}
