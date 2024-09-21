#include <iostream>

using namespace std;

class Nodo {
public:
    int valor;
    Nodo* siguiente;
    Nodo *anterior;
 
    Nodo(int dataValue) {
        valor = dataValue;
        siguiente = nullptr;

    }
};

class ListaLigada {
    Nodo *cabeza;
    Nodo *finLista;
    int tamanio;
public:
    ListaLigada() {
        cabeza = nullptr;
    }
    void crear(int valor) {
        if (cabeza == nullptr) {
            cabeza = new Nodo(valor);
            finLista = cabeza;
        }
        else{
            Nodo *nuevo = new Nodo(valor);
            nuevo->anterior = finLista;
            finLista->siguiente = nuevo;
            finLista = nuevo;
        }
        tamanio++;
    
    }
    void imprimeLista() {
        Nodo* nodoActual = cabeza;
        while (nodoActual != nullptr) {
            cout << nodoActual->valor<< " ";
            nodoActual = nodoActual->siguiente;
        }
        cout << endl;
    }

    int getElemento(int indice){
        Nodo* nodoActual = cabeza;
        int contador = 0;
        for (int i = 0; i < indice-1; i++){
            if (nodoActual != nullptr){
                nodoActual = nodoActual-> siguiente;
                contador++;
            }
        }
        if(contador == indice-1){
            return nodoActual->valor;
        } else{
            return -1;
        }

    }
    int dameTamano(){
        return tamanio;
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
    cout << lista.getElemento(2) << endl;

    ListaLigada* lista2 = new ListaLigada;
    lista2->crear(2);
    lista2->crear(3);
    lista2->imprimeLista();
    delete lista2;

}