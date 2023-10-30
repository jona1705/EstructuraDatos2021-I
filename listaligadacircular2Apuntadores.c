#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct nodo{
    int dato;
    struct nodo * siguiente;
};

struct listaCircular{
    struct nodo * cabecera;
    struct nodo * final;
};

struct nodo * crearNodo(int);
struct listaCircular * listaCircular();
void insertar_inicio(struct listaCircular *, int);
void insertar_final(struct listaCircular *, int);
int contar_nodos(struct listaCircular *);
void insertar_intermedio(struct listaCircular *, int, int);
void borrar_inicio(struct listaCircular *);
void borrar_final(struct listaCircular *);
void borrar_intermedio(struct listaCircular *, int); 
void desplegar(struct listaCircular *);
int frente(struct listaCircular *);
int ultimo(struct listaCircular *);

int main(){
    // Declaramos múltiples instancias de lista
    struct listaCircular * l1 = listaCircular();
    // Probando las funciones implementadas
	printf("\nOperaciones de insercion: \n\n");
	// Insertando nodos al principio
	insertar_inicio(l1, 23);
	insertar_inicio(l1, 12);
	insertar_inicio(l1, 76);
	insertar_inicio(l1, 93);
	insertar_inicio(l1, 8);
	desplegar(l1);
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
	desplegar(l1);
    if(frente(l1) != INT_MIN){
        printf("Primer nodo de la lista: %d\n", frente(l1));
    }
    if(ultimo(l1) != INT_MIN){
        printf("Ultimo nodo de la lista: %d\n", ultimo(l1));
    }
    printf("Numero de Nodos en la Lista: %d\n", contar_nodos(l1));
    // Insertando nodos en una posicion intermedia
	insertar_intermedio(l1, 0, 14);
	insertar_intermedio(l1, 3, 25);
	insertar_intermedio(l1, 1, 17);
	desplegar(l1);
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
	desplegar(l1);
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
	desplegar(l1);
    if(frente(l1) != INT_MIN){
        printf("Primer nodo de la lista: %d\n", frente(l1));
    }
    if(ultimo(l1) != INT_MIN){
        printf("Ultimo nodo de la lista: %d\n", ultimo(l1));
    }
    printf("Numero de Nodos en la Lista: %d\n", contar_nodos(l1));
    // Borrando nodos en una posicion intermedia
    borrar_intermedio(l1, 1);
	borrar_intermedio(l1, 4);
	borrar_intermedio(l1, 0);
    borrar_intermedio(l1, 3);
    borrar_intermedio(l1, 1);
    borrar_intermedio(l1, 1);
	desplegar(l1);
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
    if(nuevo == NULL) return NULL;
    nuevo->dato = x;
    nuevo->siguiente = NULL;

    return nuevo;
}

struct listaCircular * listaCircular(){
    // Inicializamos la lista en NULL
    struct listaCircular * lista = NULL;
    // Asignamos memoria para la lista
    lista = (struct listaCircular *) malloc(sizeof(struct listaCircular));
    if(lista == NULL) return NULL; // En caso de que no se le pueda asignar memoria
    lista->cabecera = NULL; // Asignamos valores
    lista->final = NULL; // Asignamos valores

    return lista;
}

void insertar_inicio(struct listaCircular * lista, int dato){
    struct nodo * nuevo = crearNodo(dato);
    if(lista->cabecera == NULL){
        // Insertamos el primer nodo en la lista
        nuevo->siguiente = nuevo;
        lista->cabecera = lista->final = nuevo;
    } else{
        nuevo->siguiente = lista->cabecera;
        lista->final->siguiente = nuevo;
        lista->cabecera = nuevo;
    }
}

void insertar_final(struct listaCircular * lista, int dato){
    struct nodo * nuevo = crearNodo(dato);
    if(lista->cabecera == NULL){
        // Insertamos el primer nodo en la lista
        nuevo->siguiente = nuevo;
        lista->cabecera = lista->final = nuevo;
    } else{
        lista->final->siguiente = nuevo;
        nuevo->siguiente = lista->cabecera;
        lista->final = nuevo;
    }
}

int contar_nodos(struct listaCircular * lista){
    if(lista->cabecera == NULL){
        return 0;
    } else{
        struct nodo * temp = lista->cabecera;
        int cont = 0;
        do {
            temp = temp->siguiente;
            cont++;
        } while(temp != lista->cabecera);
        return cont;
    }
}

void insertar_intermedio(struct listaCircular * lista, int pos, int dato){
    struct nodo * nuevo = crearNodo(dato);
    // Se toma el 0 como posición válida
    int noNodos = contar_nodos(lista);
    if(pos<0 || pos>noNodos){
        // Rango: [0, noNodos]
        printf("Posición inválida\n");
        return;
    } else if(pos == 0){
        if(lista->cabecera == NULL) {
            // Si la lista esta vacia
            // insertamos el primer nodo
            nuevo->siguiente = nuevo;
            lista->cabecera = lista->final = nuevo;
        } else{
            // Hay mas nodos en la lista
            // Unimos el ultimo nodo con el primero
            nuevo->siguiente = lista->cabecera;
            lista->final->siguiente = nuevo;
            lista->cabecera = nuevo;
        }
    } else{
        // Si la posicion es distinta de cero
        struct nodo * temp = lista->cabecera;
        int i=0;
        while(i<pos-1){
            temp = temp->siguiente; // (pos-1)-th nodo
            i++;
        }
        if(temp->siguiente == lista->cabecera){
            // Si temp es el ultimo nodo de la lista
            temp->siguiente = nuevo;
            nuevo->siguiente = lista->cabecera;
            lista->final = temp;
        } else{
            // Si temp no es el ultimo de la lista
            nuevo->siguiente = temp->siguiente;
            temp->siguiente = nuevo;
        }
    }
}

void borrar_inicio(struct listaCircular * lista){
    if(lista->cabecera == NULL){
        printf("Lista Vacía!!\n");
        return;
    } else{
        // Recorriendo la lista hasta el final
        struct nodo * temp = lista->cabecera;
        if (lista->final == lista->cabecera) {
            // Si solo queda un nodo en la lista
            lista->cabecera = lista->final = NULL;
            free(temp);
        } else{
            // Si hay mas nodos en la lista ligada
            struct nodo * ultimo = lista->cabecera;
            lista->final->siguiente = lista->cabecera->siguiente;
            lista->cabecera = lista->cabecera->siguiente;
            free(ultimo);
        }    
    }
}

void borrar_final(struct listaCircular * lista) {
    struct nodo *temp; // Nodo a borrar
    struct nodo *prev; // Nodo previo al ultimo (penultimo)
    if (lista->cabecera == NULL) {
        printf("Lista Vacía!!\n");
    } else {
        temp = lista->cabecera;
        // Recorremos hasta el último nodo de la Lista
        while (temp->siguiente != lista->cabecera) {
            prev = temp;
            temp = temp->siguiente;
        }
        if (temp == lista->cabecera) {
            // Solo queda un nodo en la lista
            lista->cabecera = lista->final = NULL;
        } else {
            /* Desconectar el enlace */
            prev->siguiente = lista->cabecera;
            lista->final = prev;
        }
        free(temp); // Borramos el último
    }
}

void borrar_intermedio(struct listaCircular * lista, int pos){
    if(lista->cabecera == NULL) {
        printf("Lista Vacía!!\n");
        return;
    } else {
        // Se toma el 0 como posición válida
        int noNodos = contar_nodos(lista);
        if(pos<0 || pos>noNodos-1){
            // Rango: [0, noNodos-1]
            printf("Posición inválida\n");
            return;
        } else {
            struct nodo * temp = NULL;
            if(pos == 0){
                // Recorriendo la lista hasta el final
                struct nodo * temp = lista->cabecera;
                if (lista->final == lista->cabecera) {
                    // Si solo queda un nodo en la lista
                    lista->cabecera = lista->final = NULL;
                } else{
                    lista->final->siguiente = lista->cabecera->siguiente;
                    lista->cabecera = lista->cabecera->siguiente;
                }
                free(temp);
            } else{
                int i=0;
                temp = lista->cabecera;
                while(i<pos-1){
                    temp = temp->siguiente; // (pos-1)-th nodo
                    i++;
                }
                struct nodo * borrado = temp->siguiente; // (pos)-th nodo
                if(borrado->siguiente == lista->cabecera){
                    // Borrado es el ultimo nodo en la lista
                    temp->siguiente = lista->cabecera;
                    lista->final = temp;
                } else{
                    temp->siguiente = borrado->siguiente; // (pos+1)-th nodo
                }
                free(borrado); // Borramos el nodo
            }
        }
    }
}


void desplegar(struct listaCircular * lista){
    struct nodo * temp = lista->cabecera;
    if(temp == NULL){
        printf("Lista Vacía!!\n");
        return;
    }
    int i=0;
    do{
        printf("%d->", temp->dato);
        temp = temp->siguiente;
        i++;
    } while (temp != lista->cabecera);
    printf("NULL\n");
}

int frente(struct listaCircular * lista){
    if(lista->cabecera == NULL){
        return INT_MIN;
    } else{
        return lista->cabecera->dato;
    }
}

int ultimo(struct listaCircular * lista){
    if(lista->final == NULL){
        return INT_MIN;
    } else{
        return lista->final->dato;
    }
}
