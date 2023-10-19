#include <stdio.h>
#include <math.h>

double media(double * arr, int n){
	int i;
	double cont = 0.0;
	for(i=0; i<n; i++){
		cont += arr[i];
	}
	double prom = cont/(double)n;
	return prom;
}

double desviacion_tipica(double * arr, double m, int n) {
	int i;
	double cont = 0.0;
	for(i=0; i<n; i++){
		cont += ((arr[i] + m) * (arr[i] + m));
	}
	double prom = cont/(double)n;
	double dt = sqrt(prom);
	
	return dt;
}

double media_cuadratica(double * arr, int n) {
	int i;
	double cont = 0.0;
	for(i=0; i<n; i++){
		cont += ((arr[i] * arr[i]));
	}
	double prom = cont/(double)n;
	double mc = sqrt(prom);
	
	return mc;
}

double media_armonica(double * arr, int n) {
	int i;
	double cont = 0.0;
	for(i=0; i<n; i++){
		cont += ((double)1/arr[i]);
	}
	double ma = (double)n / cont;
	
	return ma;
}

int main(){
	double arr[] = {3.45, 12.78, 28.45, 12.56, 
	45.6, 48.3, 29.4, 56.7, 94.3, 67.45};
	// Calculando numero de elementos
	int n = sizeof(arr)/sizeof(arr[0]);
	// Calculando la media
	double m = media(arr, n);
	printf("\nMedia = %.2lf", m);
	// Calculando desviacion tipica
	double dt = desviacion_tipica(arr, m, n);
	printf("\nDesviacion Tipica = %.2lf", dt);
	// Calculando media cuadratica
	double mc = media_cuadratica(arr, n);
	printf("\nMedia Cuadratica = %.2lf", mc);
	// Calculando media armonica
	double ma = media_armonica(arr, n);
	printf("\nMedia Armonica = %.2lf", ma);
}
