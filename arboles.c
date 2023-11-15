#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

#define NODO malloc(sizeof(Nodo))
#define ARBOL malloc(sizeof(Arbol))

typedef struct nodo{
    int dato;
    struct nodo * hi; // Hijo izquierdo
    struct nodo * hd; // Hijo derecho
} Nodo;

typedef struct arbol{
    struct nodo * raiz;
} Arbol;

static Nodo * crearNodo(int el){
    Nodo * temp = NODO;
    assert(temp!=NULL);
    temp->dato = el;
    temp->hi = NULL;
    temp->hd = NULL;
    return temp;
}

Arbol * crearArbol(){
    Arbol * temp = ARBOL;
    assert(temp!=NULL);
    temp->raiz = NULL;
    return temp;
}

static Nodo * insertar(Nodo * en, int el){
    if(!en) return crearNodo(el);
    else{
        if(el < en->dato) en->hi = insertar(en->hi, el);
        else en->hd = insertar(en->hd, el);
    }
    return en;
}

void insertar_en_arbol(Arbol * a, int el){
    a->raiz = insertar(a->raiz, el);
}

// Recorridos

static void preorden(Nodo * en){
    if(en){
        printf("%d ", en->dato);
        preorden(en->hi);
        preorden(en->hd);
    }
}

void recorrer_preorden(Arbol * a){
    preorden(a->raiz);
}

static void inorden(Nodo * en){
    if(en){
        inorden(en->hi);
        printf("%d ", en->dato);
        inorden(en->hd);
    }
}

void recorrer_inorden(Arbol * a){
    inorden(a->raiz);
}

static void postorden(Nodo * en){
    if(en){
        postorden(en->hi);
        postorden(en->hd);
        printf("%d ", en->dato);
    }
}

void recorrer_postorden(Arbol * a){
    postorden(a->raiz);
}

// Contar Nodos
int no_nodos(Nodo * en){
    if(!en) return 0;
    else return (1 + no_nodos(en->hi) + no_nodos(en->hd));
}

int no_nodos_arbol(Arbol * a){
    return no_nodos(a->raiz);
}

// Altura del arbol
int altura(Nodo * en){
    if(en == NULL) return 0;
    else{
        int nodo_i, nodo_d;
        nodo_i = altura(en->hi);
        nodo_d = altura(en->hd);
        if(nodo_i > nodo_d) return (1 + nodo_i);
        else return (1 + nodo_d);
    }
}

int altura_arbol(Arbol * a){
    return altura(a->raiz);
}

// Obtener nivel de un nodo
int obtenerNivel(Nodo * en, int el, int nivel){
    if(!en) return 0;
    if(en->dato == el) return nivel;
    int nivel_abajo = obtenerNivel(en->hi, el, nivel+1);
    if(nivel_abajo != 0) return nivel_abajo;
    nivel_abajo = obtenerNivel(en->hd, el, nivel+1);
    return nivel_abajo;
}

int nivel_nodo_arbol(Arbol * a, int el){
    return obtenerNivel(a->raiz, el, 1);
}

// Encontrar el nodo con menor valor
Nodo * valorMenor(Nodo * en){
    if(!en) return en;
    else if(!(en->hi)) return en;
    return valorMenor(en->hi);
}

int nodo_menor_arbol(Arbol * a){
    Nodo * min = valorMenor(a->raiz);
    return min->dato;
}

// Encontrar el nodo con mayor valor
Nodo * valorMayor(Nodo * en){
    if(!en) return en;
    else if(!(en->hd)) return en;
    return valorMayor(en->hd);
}

int nodo_mayor_arbol(Arbol * a){
    Nodo * max = valorMayor(a->raiz);
    return max->dato;
}

Nodo * borrar(Nodo * en, int el);

// Borrar Nodos del ·rbol
Nodo * borrar_nodo(Nodo * en){
    Nodo * temp;
    // Caso 1: No tiene hijo el Nodo
    if(!(en->hi) && !(en->hd)){
        free(en);
        return NULL;
    }
        // Caso 2: El nodo solo tiene el hijo derecho
    else if(!(en->hi) && en->hd){
        temp = en->hd;
        free(en);
        return temp;
    }
        // Caso 3: El nodo solo tiene el hijo izquierdo
    else if(en->hi && !(en->hd)){
        temp = en->hi;
        free(en);
        return temp;
    }
        // Caso 4: El nodo tiene dos hijos
    else{
        Nodo * sucesor = valorMenor(en->hd);
        // Duplicamos el nodo
        int valorSucesivo = sucesor->dato;
        en = borrar(en, valorSucesivo);
        en->dato = valorSucesivo;
        return en;
    }
}

Nodo * borrar(Nodo * en, int el){
    if(!en) return NULL;
    if(el == en->dato) en = borrar_nodo(en);
    else if(el < en->dato) en->hi = borrar(en->hi, el);
    else en->hd = borrar(en->hd, el);
    return en;
}

void borrar_en_arbol(Arbol * a, int el){
    a->raiz = borrar(a->raiz, el);
}

// Encontrar un elemento en el arbol
Nodo * buscar(Nodo * en, int el){
    if(!en) return NULL;
    else if(el == en->dato) return en;
    else if(el < en->dato) return buscar(en->hi, el);
    else return buscar(en->hd, el);
}

void buscar_arbol(Arbol * a, int el){
    if(buscar(a->raiz, el)) printf("\nEl valor %d esta en el arbol", el);
    else printf("\nEl valor %d NO esta en el arbol", el);
}

int main(int argc, char *argv[]) {
    Arbol * arbol1 = crearArbol();
    insertar_en_arbol(arbol1, 30);
    insertar_en_arbol(arbol1, 25);
    insertar_en_arbol(arbol1, 45);
    insertar_en_arbol(arbol1, 10);
    insertar_en_arbol(arbol1, 27);
    insertar_en_arbol(arbol1, 38);
    insertar_en_arbol(arbol1, 47);
    printf("\nPreorden: ");
    recorrer_preorden(arbol1);
    printf("\nInorden: ");
    recorrer_inorden(arbol1);
    printf("\nPostorden: ");
    recorrer_postorden(arbol1);
    printf("\nNumero de Nodos en el arbol: %d", no_nodos_arbol(arbol1));
    printf("\nLa altura del arbol es: %d", altura_arbol(arbol1));
    printf("\nEl nivel del nodo 38 es: %d", nivel_nodo_arbol(arbol1, 38));
    printf("\nNodo de menor valor: %d", nodo_menor_arbol(arbol1));
    printf("\nNodo de mayor valor: %d", nodo_mayor_arbol(arbol1));
    buscar_arbol(arbol1, 12);
    buscar_arbol(arbol1, 27);
    borrar_en_arbol(arbol1, 45);
    borrar_en_arbol(arbol1, 30);
    printf("\nInorden: ");
    recorrer_inorden(arbol1);
    return 0;
}