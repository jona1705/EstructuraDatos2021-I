#ifndef LISTA_H
#define LISTA_H
#define MAX 100

typedef struct lista{
	double arr[MAX];
	int len;
} Lista;

Lista inicializar();
void desplegar(Lista l);
Lista insertar(Lista l, double x);
Lista insertar_en(Lista l, int pos, double x);

#endif
