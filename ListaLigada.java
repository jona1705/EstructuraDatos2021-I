public class ListaLigada{
    private Nodo cabecera;

    private static class Nodo{
        int dato;
        Nodo siguiente;
    
        // Constructor
        public Nodo(int dato){
            this.dato = dato;
            this.siguiente = null;
        }
    }

    // Constructor para crear una Lista Ligada Vacia
    public ListaLigada(){
        cabecera = null;
    }
    
    public void insertar_inicio(int x){
        Nodo nuevo = new Nodo(x);
        if(cabecera == null){
            cabecera = nuevo;
        } else{
            nuevo.siguiente = cabecera;
            cabecera = nuevo;
        }
    }
    
    public void insertar_final(int x){
        Nodo nuevo = new Nodo(x);
        if(cabecera == null){
            cabecera = nuevo;
        } else{
            Nodo temp = cabecera;
            while(temp.siguiente != null){
                temp = temp.siguiente;
            }
            temp.siguiente = nuevo;
        }
    }

    public void insertar_intermedio(int pos, int x){
        Nodo nuevo = new Nodo(x);
        // Se toma el 0 como posicion valida
        int noNodos = contar_nodos();
        if(pos<-1 || pos>noNodos+1){
            System.out.println("Posicion invalida\n");
        } else if(cabecera == null) {
            cabecera = nuevo;
        } else if(pos == 0){
            nuevo.siguiente = cabecera;
            cabecera = nuevo;
        } else{
            Nodo temp = cabecera;
            int i=0;
            while(i<pos-1){ // <-- Linea corregida
                temp = temp.siguiente; // (pos-1)-th nodo
                i++;
            }
            nuevo.siguiente = temp.siguiente;
            temp.siguiente = nuevo;
        }
    }

    public void borrar_inicio(){
        if(cabecera == null){
            System.out.println("Lista Vacia");
            return;
        } else{
            Nodo aux = cabecera;
            cabecera = cabecera.siguiente;
            aux = null;
        }
    }

    public void borrar_final(){
        Nodo temp = null, prev = null;
	    if(cabecera == null){
		    System.out.println("Lista Vacia");
	    } else{
		    temp = cabecera;
            while(temp.siguiente != null){
                prev = temp;
                temp = temp.siguiente;
            }
            if(temp == cabecera){
                // Si solo queda un nodo en la lista
                cabecera = null;
            } else{
                prev.siguiente = null;
            }
		    temp = null;
	    }
    }

    public void borrar_intermedio(int pos){
        if(cabecera == null) {
            System.out.println("Lista Vacia");
        } else {
            // Se toma el 0 como posicion valida
            int noNodos = contar_nodos();
            if(pos<-1 || pos>noNodos){
                System.out.println("Posicion invalida\n");
            } else {
                Nodo temp = null;
                if(pos == 0){
                    temp = cabecera;
                    cabecera = cabecera.siguiente;
                    temp = null;
                } else{
                    int i=0;
                    temp = cabecera;
                    while(i<pos-1){ // <-- Linea corregida
                        temp = temp.siguiente; // (pos-1)-th nodo
                        i++;
                    }
                    Nodo borrado = temp.siguiente; // (pos)-th nodo
                    temp.siguiente = borrado.siguiente; // (pos+1)-th nodo
                    borrado = null;
                }
            }
        }
    }
    
    int contar_nodos(){
        if(cabecera == null){
            return 0;
        } else{
            int cont = 0;
            Nodo temp = cabecera;
            while(temp != null){
                cont++;
                temp = temp.siguiente;
            }
            return cont;
        }
    }
    
    public void desplegar(){
        Nodo temp = cabecera;
        if(temp == null){
            System.out.println("Lista Vacia");
        } else{
            while(temp != null){
                System.out.print(temp.dato + "->");
                temp = temp.siguiente;
            }
            System.out.print("NULL\n");
        }
    }
    
    public static void main(String[] args){
        ListaLigada l1 = new ListaLigada();
        System.out.println("\nOperaciones de insercion: ");
        // Insertando nodos al principio
        l1.insertar_inicio(23);
        l1.insertar_inicio(12);
        l1.insertar_inicio(76);
        l1.insertar_inicio(93);
        l1.insertar_inicio(8);
        l1.desplegar();
        System.out.println("Numero de Nodos en la Lista: " + l1.contar_nodos());
        // Insertando nodos al final
        l1.insertar_final(9);
        l1.insertar_final(7);
        l1.insertar_final(-5);
        l1.insertar_final(16);
        l1.desplegar();
        System.out.println("Numero de Nodos en la Lista: " + l1.contar_nodos());
        // Insertando nodos en una posicion intermedia
	    l1.insertar_intermedio(0, 14);
	    l1.insertar_intermedio(5, 25);
	    l1.insertar_intermedio(2, 17);
	    l1.desplegar();
	    System.out.println("Numero de Nodos en la Lista: " + l1.contar_nodos());

        System.out.println("\n\nOperaciones de borrado: ");
	    // Borrando nodos al principio
	    l1.borrar_inicio();
	    l1.borrar_inicio();
	    l1.borrar_inicio();
	    l1.desplegar();
        System.out.println("Numero de Nodos en la Lista: " + l1.contar_nodos());
        // Borrando nodos al final
	    l1.borrar_final();
	    l1.borrar_final();
        l1.desplegar();
        System.out.println("Numero de Nodos en la Lista: " + l1.contar_nodos());
        // Borrando nodos en una posicion intermedia
	    l1.borrar_intermedio(1);
	    l1.borrar_intermedio(4);
	    l1.borrar_intermedio(0);
	    l1.desplegar();
        System.out.println("Numero de Nodos en la Lista: " + l1.contar_nodos() + "\n");
    }
}




    
    
