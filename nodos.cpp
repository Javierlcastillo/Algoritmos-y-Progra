#include <iostream>

using namespace std;

class Nodo {
public:
    int valor;
    Nodo* siguiente;
 
    Nodo(int dataValue) {
        valor = dataValue;
        siguiente = nullptr;

    }
};

class ListaLigada {
    Nodo *cabeza;
public:
    ListaLigada() {
        cabeza = nullptr;
    }
    void crear(int valor) {
        if (cabeza == nullptr) {
            cabeza = new Nodo(valor);
        
        }
        else{
            Nodo* current = cabeza;
            while(current->siguiente!=nullptr){
                current = current->siguiente;
            }
            Nodo *nuevo = new Nodo(valor);
            current->siguiente = nuevo;
     

        
        }
    
    }
    void imprimeLista() {
        Nodo* nodoActual = cabeza;
        while (nodoActual != nullptr) {
            cout << nodoActual->valor<< " ";
            nodoActual = nodoActual->siguiente;
        }
        cout << endl;

    
    
    }
    ~ListaLigada() {
        Nodo* nodoActual = cabeza;
        while (nodoActual) {
            cout << "Borrando: " << nodoActual->valor << " ";
            cout << endl;
            Nodo* temp = nodoActual;
            nodoActual = nodoActual->siguiente;
            delete temp;
        }

    }
};

int main()
{
    ListaLigada lista;
    lista.crear(5);
    lista.imprimeLista();
    lista.crear(6);
    lista.imprimeLista();
    lista.crear(7);
    lista.imprimeLista();
    lista.crear(8);
    lista.imprimeLista();
    lista.crear(9);
    lista.imprimeLista();
 
    ListaLigada* lista2 = new ListaLigada;
    lista2->crear(2);
    lista2->crear(3);
    lista2->imprimeLista();
    delete lista2;

}