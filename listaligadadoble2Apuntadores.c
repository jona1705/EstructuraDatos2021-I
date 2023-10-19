#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct nodo{
	int dato;
	struct nodo * siguiente;
    struct nodo * anterior;
};

struct listaLigada{
    struct nodo * cabecera;
    struct nodo * final;
};

struct nodo * crearNodo(int);
struct listaLigada * crearLista();
void desplegarAdelante(struct listaLigada *);
void desplegarAtras(struct listaLigada *);
void insertar_inicio(struct listaLigada *, int);
void insertar_final(struct listaLigada *, int);
void insertar_intermedio(struct listaLigada *, int, int);
void borrar_inicio(struct listaLigada *);
void borrar_final(struct listaLigada *);
void borrar_intermedio(struct listaLigada *, int);
int contar_nodos(struct listaLigada * cabecera);
int frente(struct listaLigada *);
int ultimo(struct listaLigada *);

int main(){
	// Desplegando nodos en la lista
	struct listaLigada * l1 = crearLista(); // l1 es una instancia de Lista Ligada
	// Probando las funciones implementadas
	printf("\nOperaciones de insercion: \n\n");
	// Insertando nodos al principio
	insertar_inicio(l1, 23);
	insertar_inicio(l1, 12);
	insertar_inicio(l1, 76);
	insertar_inicio(l1, 93);
	insertar_inicio(l1, 8);
	desplegarAdelante(l1);
    desplegarAtras(l1);
    if(frente(l1) != INT_MIN){
        printf("Primer nodo de la lista: %d\n", frente(l1));
    }
    if(ultimo(l1) != INT_MIN){
        printf("Ultimo nodo de la lista: %d\n", ultimo(l1));
    } 
	printf("Numero de Nodos en la Lista: %d\n", contar_nodos(l1));
	// Insertando nodos al final
	insertar_final(l1, 9);
	insertar_final(l1, 7);
	insertar_final(l1, -5);
	insertar_final(l1, 16);
	desplegarAdelante(l1);
    desplegarAtras(l1);
    if(frente(l1) != INT_MIN){
        printf("Primer nodo de la lista: %d\n", frente(l1));
    }
    if(ultimo(l1) != INT_MIN){
        printf("Ultimo nodo de la lista: %d\n", ultimo(l1));
    }  
	printf("Numero de Nodos en la Lista: %d\n", contar_nodos(l1));
	// Insertando nodos en una posicion intermedia
	insertar_intermedio(l1, 0, 14);
	insertar_intermedio(l1, 5, 25);
	insertar_intermedio(l1, 2, 17);
    insertar_intermedio(l1, 12, 89);
	desplegarAdelante(l1);
    desplegarAtras(l1);
    if(frente(l1) != INT_MIN){
        printf("Primer nodo de la lista: %d\n", frente(l1));
    }
    if(ultimo(l1) != INT_MIN){
        printf("Ultimo nodo de la lista: %d\n", ultimo(l1));
    }  
	printf("Numero de Nodos en la Lista: %d\n", contar_nodos(l1));
	
	printf("\n\nOperaciones de borrado: \n\n");
	// Borrando nodos al principio
    borrar_inicio(l1);
	borrar_inicio(l1);
	borrar_inicio(l1);
	desplegarAdelante(l1);
    desplegarAtras(l1);
    if(frente(l1) != INT_MIN){
        printf("Primer nodo de la lista: %d\n", frente(l1));
    }
    if(ultimo(l1) != INT_MIN){
        printf("Ultimo nodo de la lista: %d\n", ultimo(l1));
    } 
	printf("Numero de Nodos en la Lista: %d\n", contar_nodos(l1));
	// Borrando nodos al final
	borrar_final(l1);
	borrar_final(l1);
    borrar_final(l1);
	borrar_final(l1);
    borrar_final(l1);
	borrar_final(l1);
    insertar_final(l1, -4);
	desplegarAdelante(l1);
    desplegarAtras(l1);
    if(frente(l1) != INT_MIN){
        printf("Primer nodo de la lista: %d\n", frente(l1));
    }
    if(ultimo(l1) != INT_MIN){
        printf("Ultimo nodo de la lista: %d\n", ultimo(l1));
    } 
	printf("Numero de Nodos en la Lista: %d\n", contar_nodos(l1));
	// Borrando nodos en una posicion intermedia
    borrar_intermedio(l1, 0);
    borrar_intermedio(l1, 4);
	borrar_intermedio(l1, 1);
    borrar_intermedio(l1, 2);
    borrar_intermedio(l1, 0);
    borrar_intermedio(l1, 1);
    borrar_intermedio(l1, 0);
    insertar_inicio(l1, 1);
    borrar_intermedio(l1, 0);
	desplegarAdelante(l1);
    desplegarAtras(l1);
    if(frente(l1) != INT_MIN){
        printf("Primer nodo de la lista: %d\n", frente(l1));
    }
    if(ultimo(l1) != INT_MIN){
        printf("Ultimo nodo de la lista: %d\n", ultimo(l1));
    } 
    printf("Numero de Nodos en la Lista: %d\n", contar_nodos(l1));
	
	return 0;
}

struct nodo * crearNodo(int x){
	struct nodo * nuevo = NULL;
	nuevo = (struct nodo *) malloc(sizeof(struct nodo));
	if(nuevo == NULL) exit(0);
	nuevo->dato = x;
	nuevo->siguiente = NULL;
    nuevo->anterior = NULL;
	return nuevo;
}

struct listaLigada * crearLista(){
    struct listaLigada * nuevaLista = NULL;
    nuevaLista = (struct listaLigada *) malloc(sizeof(struct listaLigada));
    if(nuevaLista == NULL) return NULL;
    nuevaLista->cabecera = NULL;
    nuevaLista->final = NULL;
    return nuevaLista;
}

void insertar_inicio(struct listaLigada * lista, int x){
	struct nodo * nuevo = crearNodo(x);
	if(lista->cabecera == NULL){
        // Insertamos el primer nodo
		lista->cabecera = lista->final = nuevo;
	} else{
		nuevo->siguiente = lista->cabecera;
        lista->cabecera->anterior = nuevo;
		lista->cabecera = nuevo;
	}
}

void insertar_final(struct listaLigada * lista, int x){
	struct nodo * nuevo = crearNodo(x);
	if(lista->cabecera == NULL){
        // Insertamos el primer nodo
		lista->cabecera = lista->final = nuevo;
	} else{
        lista->final->siguiente = nuevo;
        nuevo->anterior = lista->final;
        lista->final = nuevo;
	}
}

void borrar_inicio(struct listaLigada * lista){
	if(lista->cabecera == NULL){
        // Si la lista esta vacia no borrramos nada
		printf("\nLista Vacia");
	} else{
		struct nodo * temp = lista->cabecera;
        if(lista->cabecera == lista->final){
            // Solo queda un nodo en la lista
            lista->cabecera = lista->final = NULL;
        } else{
            lista->cabecera = lista->cabecera->siguiente;
            lista->cabecera->anterior = NULL;
        }
		free(temp);
	}
}

void borrar_final(struct listaLigada * lista){
	if(lista->cabecera == NULL){
        // Si la lista esta vacia no borrramos nada
		printf("\nLista Vacia");
	} else{
		struct nodo * temp = lista->cabecera;
        if(lista->cabecera == lista->final){
            // Solo queda un nodo en la lista
            lista->cabecera = lista->final = NULL;
            free(temp);
        } else{
            while(temp->siguiente != lista->final){
                // Recorremos la lista hasta el penultimo nodo
			    temp = temp->siguiente;
		    }
            lista->final->anterior = NULL;
            free(lista->final);
            lista->final = temp;
            lista->final->siguiente = NULL;    
        }
	}
}

int contar_nodos(struct listaLigada * lista){
	if(lista->cabecera == NULL){
		return 0;
	} else{
		int cont = 0;
		struct nodo * temp = lista->cabecera;
		while(temp != NULL){
			cont++;
			temp = temp->siguiente;
		}
		return cont;
	}
}

void insertar_intermedio(struct listaLigada * lista, int pos, int x){
    struct nodo * nuevo = crearNodo(x);
    // Se toma el 0 como posicion valida
    int noNodos = contar_nodos(lista);
    if(pos<-1 || pos>noNodos+1){
        // Rango valido de pos: [0, pos+1]
        printf("Posicion invalida\n");
    } else if(pos == 0){
        if(lista->cabecera == NULL) {
            // Apenas vamos a insertar el primer nodo
            lista->cabecera = lista->final = nuevo;
        }  else{
            // El nuevo nodo será el primero
            nuevo->siguiente = lista->cabecera;
            lista->cabecera->anterior = nuevo;
            lista->cabecera = nuevo;
        }     
    } else if(pos == noNodos){
        // Si el valor de pos es igual al numero de nodos
        // el nuevo nodo será el último de la lista
        lista->final->siguiente = nuevo;
        nuevo->anterior = lista->final;
        lista->final = nuevo;
    }else{
        // Insertamos un nodo en cualquier posición
        // que no sea la primera y la última
        struct nodo * temp = lista->cabecera;
        int i=0;
        while(i<pos-1){ // <-- Linea corregida
            temp = temp->siguiente; // (pos-1)-th nodo
            i++;
        }
        nuevo->siguiente = temp->siguiente;
        nuevo->siguiente->anterior = nuevo;
        temp->siguiente = nuevo;
        nuevo->anterior = temp;
    }
}

void borrar_intermedio(struct listaLigada * lista, int pos){
    if(lista->cabecera == NULL) {
        printf("Lista Vacia!!\n");
        return;
    } else {
        // Se toma el 0 como posicion valida
        int noNodos = contar_nodos(lista);
        if(pos<-1 || pos>=noNodos){
            // Rango valido de pos: [0, pos]
            printf("Posicion invalida\n");
        } else {
            struct nodo * temp = NULL;
            if(pos == 0){
                temp = lista->cabecera;
                if(lista->cabecera == lista->final){
                    // Si solo queda un nodo en la lista
                    lista->cabecera = lista->final = NULL;
                } else{
                    // Si todavía hay más nodos
                    lista->cabecera = lista->cabecera->siguiente;
                    lista->cabecera->anterior = NULL;
                }
                free(temp);
            } else{
                int i=0;
                struct nodo * temp = lista->cabecera;
                while(i<pos-1){ // <-- Linea corregida
                    // Recorremos la lista hasta el nodo previo a borrar
                    temp = temp->siguiente; // (pos-1)-th nodo
                    i++;
                }
                // Nos desplazamos al nodo a borrar
                struct nodo * borrado = temp->siguiente; // (pos)-th nodo
                if(borrado == lista->final){
                    borrado->anterior = NULL;
                    lista->final = temp;
                    temp->siguiente = NULL;

                } else{
                    // Si el nodo a borrar no es el último
                    temp->siguiente = borrado->siguiente; // (pos+1)-th nodo
                    if(temp->siguiente == NULL){
                        lista->final = temp;
                    } 
                }
                free(borrado); 
            }
        }
    }
}

int frente(struct listaLigada * lista){
    if(lista->cabecera == NULL){
        return INT_MIN;
    } else{
        return lista->cabecera->dato;
    }
}

int ultimo(struct listaLigada * lista){
    if(lista->cabecera == NULL){
        return INT_MIN;
    } else{
        return lista->final->dato;
    }    
}

void desplegarAdelante(struct listaLigada * lista){
	struct nodo * temp = lista->cabecera;
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

void desplegarAtras(struct listaLigada * lista){
	struct nodo * temp = lista->final;
	if(temp == NULL){
		printf("Lista Vacia\n");
	} else{
		while(temp != NULL){
			printf("%d->",temp->dato);
			temp = temp->anterior;
		}
		printf("NULL\n");
	}
}
