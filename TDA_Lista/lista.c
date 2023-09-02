#include <stdio.h>
#include "lista.h"

Lista inicializar(){
	Lista l;
	int i;
	for(i=0; i<MAX; i++){
		l.arr[i] = 0.0;
	}
	l.len = 0;
}

void desplegar(Lista l){
	int i;
	for(i=0; i<l.len; i++){
		printf("%.2lf ", l.arr[i]);
	}
	printf("\n");
}

Lista insertar(Lista l, double x){
	l.arr[l.len] = x;
	l.len++;
	return l;
}

Lista insertar_en(Lista l, int pos, double x){
	int i;
	for(i=l.len; i>=pos; i--){
		l.arr[i+1] = l.arr[i];
	}
	l.arr[pos] = x;
	l.len++;
	return l;
}
