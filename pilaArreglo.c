#include <stdio.h>
#include <stdbool.h>
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

int main(){
    // Inicializando la variable pila
    Pila p1 = init();
    // Insertando elementos
    p1 = push(p1, 3.4);
    p1 = push(p1, 9.1);
    p1 = push(p1, 12.4);
    p1 = push(p1, 8.5);
    p1 = push(p1, -3.7);
    p1 = push(p1, 6.5);
    printf("\nElementos en la pila p1 despues de insertar: \n");
    desplegar(p1);
    printf("\nElemento en el tope de la pila: %.2lf", peak(p1));

    // Borrando elementos
    p1 = pop(p1);
    p1 = pop(p1);
    p1 = pop(p1);
    printf("\nElementos en la pila p1 despues de borrar: \n");
    desplegar(p1);
    printf("\nElemento en el tope de la pila p1: %.2lf", peak(p1));

    return 0;
}

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
