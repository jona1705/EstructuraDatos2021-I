#include <iostream>
using namespace std;

// Numero máximo de elementos en la pila
const int MAX = 100; 

class Pila {
	private:
    	double arr[MAX]; 
    	int tope; 

	public:
    	// Constructor to initialize an empty stack
    	Pila() {
        	tope = -1;
    	}
    	
    	// Funcion que verifica si la pila esta vacia
    	bool esVacia() {
        	return tope == -1;
    	}
    	
    	// Funcion que verifica si la pila esta vacia
    	bool esLlena() {
        	return tope == MAX-1;
    	}

    	// Funcion para ingresar un elemento en la pila
    	void push(double x) {
        	if (esLlena()) {
            	cout << "Pila Llena ..." << endl;
            	return;
        	}
        	arr[++tope] = x;
    	}

    	// Funcion para remover un elemento en la pila
    	void pop() {
        	if (esVacia()) {
            	cout << "Pila Vacia ..." << endl;
            	return;
        	}
        	--tope;
    	}

    	// Function to get the top element of the stack
    	double peek() {
	        if (esVacia()) {
	            cout << "Pila Vacia ..." << endl;
	            // Retornamos un valor sentinela para indicar que la pila 
				//esta vacia
	            return -1;  
	        }
	        return arr[tope];
    	}	
    	
    	void desplegar(){
    		if(esVacia()) {
	            cout << "Pila Vacia ..." << endl;
	            return;
	    	} 
    		for(int i=tope; i>=0; i--){
    			cout << arr[i] << " ";
			}
			cout << endl;
		}

    	// Retorna el numero de elementos actualmente
    	// en la pila
    	int size() {
        	return tope + 1;
    	}
};

int main() {
    Pila p1 = Pila();
	// Insertando elementos en la Pila
	cout << "Elementos en la Pila: " << endl;
    p1.push(3.4);
    p1.push(9.1);
    p1.push(12.4);
    p1.push(8.5);
    p1.push(-3.7);
    p1.push(6.5);
    p1.desplegar();

    cout << "Valor en el Tope: " << p1.peek() << endl;
    cout << "No. Elementos en la Pila: " << p1.size() << endl;
    cout << endl;
	// 	Borrando elementos en la Pila
	cout << "Elementos en la Pila: " << endl;
    p1.pop();
    p1.pop();
    p1.pop();
    p1.desplegar();
	cout << "Valor en el Tope: " << p1.peek() << endl;
    cout << "No. Elementos en la Pila: " << p1.size() << endl;

    return 0;
}

