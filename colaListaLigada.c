#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
	int dato;
	struct nodo * siguiente;
} Nodo;

typedef struct cola{
    Nodo * frente;
    Nodo * final;
} Cola;

Nodo * crearNodo(int);
Cola * init();
void encolar(Cola *, int);
void desencolar(Cola *);
int frente(Cola *);
int final(Cola *);
void desplegar(Cola *);
int contar_nodos(Cola *);

int main(){
    Cola * c1 = init();
    // Insertando elementos en la Cola
    printf("\nInsertando elementos en la cola: ");
    encolar(c1, 5);
    encolar(c1, 8);
    encolar(c1, 9);
    encolar(c1, -2);
    encolar(c1, 7);
    desplegar(c1);
    if(frente(c1) != 0){
        printf("Nodo al frente de la cola: %d\n", frente(c1));
    }
    if(final(c1) != 0){
        printf("Nodo al final de la cola: %d\n", final(c1));
    } 
    printf("Numero de Nodos en la cola: %d\n", contar_nodos(c1));
	
    printf("\nBorrando elementos en la pila: ");
    desencolar(c1);
    desencolar(c1);
    desencolar(c1);
    desplegar(c1);
    if(frente(c1) != 0){
        printf("Nodo al frente de la cola: %d\n", frente(c1));
    }
    if(final(c1) != 0){
        printf("Nodo al final de la cola: %d\n", final(c1));
    } 
    printf("Numero de Nodos en la cola: %d\n\n", contar_nodos(c1));

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

Cola * init(){
    Cola * nuevaCola = NULL;
    nuevaCola = (Cola  *) malloc(sizeof(Cola));
    if(nuevaCola == NULL) return NULL;
    nuevaCola->frente = NULL;
    nuevaCola->final = NULL;
    return nuevaCola;
}

void encolar(Cola * c, int x){
	Nodo * n = crearNodo(x);
	if(c->frente == NULL){
		c->frente = c->final = n;
	} else{
        c->final->siguiente = n;
        c->final = n;
	}
}

void desencolar(Cola * c){
	if(c->frente == NULL){
		printf("\nLista Vacia");
	} else{
		Nodo * temp = c->frente;
        if(c->frente == c->final){
            // Solo queda un nodo en la lista
            c->frente = c->final = NULL;
        } else{
            c->frente = c->frente->siguiente;
        }
		free(temp);
	}
}

int frente(Cola * c){
    if(c->frente == NULL){
        return 0;
    } else{
        return c->frente->dato;
    }
}

int final(Cola * c){
    if(c->frente == NULL){
        return 0;
    } else{
        return c->final->dato;
    }    
}

int contar_nodos(Cola * c){
	if(c->frente == NULL){
		return 0;
	} else{
		int cont = 0;
		Nodo * temp = c->frente;
		while(temp != NULL){
			cont++;
			temp = temp->siguiente;
		}
		return cont;
	}
}

void desplegar(Cola * c){
	Nodo * temp = c->frente;
	if(temp == NULL){
		printf("Lista Vacia\n");
	} else{
		while(temp != NULL){
			printf("%d->",temp->dato);
			temp = temp->siguiente;
		}
		printf("NULL\n");
	}
}