#ifndef _LISTALIGADA_H
#define _LISTALIGADA_H

typedef struct nodo{
	int dato;
	struct nodo * siguiente;
} Nodo;

Nodo * crearNodo(int);
void desplegar(Nodo *);
Nodo * insertar_inicio(Nodo *, int);
Nodo * insertar_final(Nodo *, int);
Nodo * borrar_inicio(Nodo *);
Nodo * borrar_final(Nodo *);
int contar_nodos(Nodo * cabecera);

#endif
