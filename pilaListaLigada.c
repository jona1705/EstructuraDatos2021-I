#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct nodo{
	int dato;
	struct nodo * siguiente;
} Nodo;


typedef struct pila{
    // La cabecera representaría el tope
    Nodo * tope;
} Pila;

Pila * init();
// Una pila sigue la metodología LIFO 
void push(Pila *, int); // push() representaría la funcion insertar_inicio en una lista ligada
void pop(Pila *); // pop() representaría la funcion borrar_inicio en una lista ligada
int peak(Pila *); // peak() imprime valor en el tope
void desplegar(Pila *);
int contar_nodos(Pila *);

int main(){
    Pila * p1 = init();
    // Insertando elementos en la Pila
    printf("\nInsertando elementos en la pila: ");
    push(p1, 5);
    push(p1, 8);
    push(p1, 9);
    push(p1, -2);
    push(p1, 7);
    desplegar(p1);
    if(peak(p1) != INT_MIN){
        printf("Nodo en el tope de la pila: %d\n", peak(p1));
    }
    printf("Numero de Nodos en la pila: %d\n", contar_nodos(p1));
    printf("\nBorrando elementos en la pila: ");
    pop(p1);
    pop(p1);
    pop(p1);
    desplegar(p1);
    if(peak(p1) != INT_MIN){
        printf("Nodo en el tope de la pila: %d\n", peak(p1));
    }
    printf("Numero de Nodos en la pila: %d\n\n", contar_nodos(p1));

    return 0;
}

Nodo * crearNodo(int x){
	Nodo * nuevo = NULL;
	nuevo = (Nodo *) malloc(sizeof(Nodo));
	if(nuevo == NULL) exit(0);
	nuevo->dato = x;
	nuevo->siguiente = NULL;
	return nuevo;
}

Pila * init(){
    Pila * nuevaPila = NULL;
    nuevaPila = (Pila *) malloc(sizeof(Pila));
    if(nuevaPila == NULL) return NULL;
    nuevaPila->tope = NULL;
    return nuevaPila;
}

void push(Pila * p, int x){
	Nodo * n = crearNodo(x);
	if(p->tope == NULL){
		p->tope = n;
	} else{
		n->siguiente = p->tope;
		p->tope = n;
	}
}

void pop(Pila * p){
	if(p->tope == NULL){
		printf("\nLista Vacia");
	} else{
		Nodo * aux = p->tope;
		p->tope = p->tope->siguiente;
		free(aux);
	}
}

int peak(Pila * p){
    if(p->tope == NULL){
        return INT_MIN;
    } else{
        return p->tope->dato;
    }
}

int contar_nodos(Pila * p){
	if(p->tope == NULL){
		return 0;
	} else{
		int cont = 0;
		struct nodo * temp = p->tope;
		while(temp != NULL){
			cont++;
			temp = temp->siguiente;
		}
		return cont;
	}
}

void desplegar(Pila * p){
	Nodo * temp = p->tope;
	if(temp == NULL){
		printf("Lista Vacia");
	} else{
		while(temp != NULL){
			printf("%d->",temp->dato);
			temp = temp->siguiente;
		}
		printf("NULL\n");
	}
}