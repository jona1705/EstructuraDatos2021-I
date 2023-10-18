#include <stdio.h>
#include <stdbool.h>
#include <float.h>
#include "cola.h"

Cola init(){
    Cola c;
    int i;
    for(i=0; i<MAX; i++){
        c.arr[i] = 0.0; 
    }
    c.frente = -1;
    c.final = -1;
    c.len = 0;
    return c;
}

// Operaciones auxiliares
static bool esLlena(Cola c){
    if(c.final == MAX-1) return true;
    else return false;
}

static bool esVacia(Cola c){
    if((c.final < 0) || (c.frente > c.final)) return true;
    else return false;
}

Cola encolar(Cola c, double x){
    if(esLlena(c)){
        printf("\nCola Llena ...");
    } else{
        if(esVacia(c)){
            c.frente = 0;
            c.final = 0;
        } else{
            c.final++;
        }
        c.arr[c.final] = x;
        c.len++;
    }
    return c;
}

Cola desencolar(Cola c){
    if(esVacia(c)){
        printf("\nCola Vacia ...");
    } else{
        if(c.frente > c.final){
            c.frente = -1;
            c.final = -1;
            c.len = 0;
        } else{
            c.frente++;
            c.len--;
        }
    }
    return c;
}

void desplegar(Cola c){
    if(esVacia(c)){
        printf("\nCola Vacia ...");
    } else{
        int i;
        for(i=c.frente; i<=c.final; i++){
            printf("%.2lf ", c.arr[i]);
        }
        printf("\n");
    }
}

double frente(Cola c){
    if(c.frente == -1) return DBL_MIN;
    else return c.arr[c.frente];
}

double final(Cola c){
    if(c.final == -1) return DBL_MIN;
    else return c.arr[c.final];
}

int size(Cola c){
    return c.len;
}

// MODIFICACION ACTIVIDAD 3
double suma(Cola c){
    if(esVacia(c)){
        return 0;
    } else{
        int i;
        double cont = 0.0;
        for(i=c.frente; i<=c.final; i++){
            cont += c.arr[i];
        }
        return (double)cont;
    }
}

// MODIFICACION ACTIVIDAD 4
double promedio(Cola c){
    int i;
    double cont = 0.0, media;    
    for(i=c.frente; i<=c.final; i++){
        cont += c.arr[i];
    }
    media = cont/(double)(c.len);
    return media;    
}

// MODIFICACION ACTIVIDAD 4
double maximo(Cola c){
    int i;
    double max = DBL_MIN;
    for(i=c.frente; i<=c.final; i++){
        if(c.arr[i] > max){
            max = c.arr[i];
        }
    }
    return (double)max;
}

// MODIFICACION ACTIVIDAD 4
double minimo(Cola c){
    int i;
    double min = DBL_MAX;
    for(i=c.frente; i<=c.final; i++){
        if(c.arr[i] < min){
            min = c.arr[i];
        }
    }
    return (double)min;
}
