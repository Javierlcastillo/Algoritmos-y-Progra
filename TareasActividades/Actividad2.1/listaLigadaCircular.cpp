/**
 * Codigo que disena e implementa un ADT que represente una estructura 
 * de datos lineal para lista circular doblemente ligada con sus metodos CRUDE.
 * 
 * Autor: Javier Luis Castillo Solórzano 
 * Matrícula: A01658415
 * Creado: {23-09-2024}
 */
#include <iostream>
using namespace std;

class Nodo {
public:
    int valor;
    Nodo* siguiente;
    Nodo* anterior;
 
    Nodo(int dataValue) {
        valor = dataValue;
        siguiente = nullptr;
        anterior = nullptr;
    }
};

class ListaLigadaCircular {
    Nodo* cabeza;
    Nodo* finLista;
    int tamanio;
    
public:
    ListaLigadaCircular() {
        cabeza = nullptr;
    }
/**
 * Funcion que crea un nuevo Nodo y actualiza los valores de siguiente y anterior
 * @param valor de tipo int que ingresa el valor que tendra el nodo
 * Complejidad de Tiempo: O(1)
 * Complejidad de espacio: O(1)
 */
    void crear(int valor) {
        if (cabeza == nullptr) {
            cabeza = new Nodo(valor);
            finLista = cabeza;
            cabeza->siguiente = cabeza;
            cabeza->anterior = cabeza;
        } else{
                Nodo* nuevo = new Nodo(valor);
                nuevo->siguiente = cabeza;
                cabeza->anterior = nuevo;
                finLista->siguiente = nuevo;
                nuevo->anterior = finLista;
                finLista = nuevo;
        }
        tamanio++;
    }
/**
 * Funcion que imprime todos los elementos de la lista
 * Complejidad de Tiempo: O(n)
 * Complejidad de espacio: O(1)
 */
    void imprimeLista() {
        Nodo* nodoActual = cabeza;
        int i = tamanio;
        while (i != 0) {
            cout << nodoActual->valor<< " ";
            nodoActual = nodoActual->siguiente;
            i--;
        }
        cout << endl;
    }
/** 
 * Funcion de tipo Nodo que obtiene el elemento de la posicion (comenzando en el 1)
 * en la lista ligada.
 * @param indice de tipo int que es el elemento a obtener
 * @returns nodoActual o nullptr
 * Complejidad de Tiempo: O(n)
 * Complejidad de Espacio: O(1)
 */
    Nodo* getElemento(int indice) {
        Nodo *nodoActual = cabeza;
        int contador = 0;
        for (int i = 0; i < indice-1; i++){
            if (nodoActual != nullptr){
                nodoActual = nodoActual-> siguiente;
                contador++;
            }
        }
        if(contador == indice-1){
            return nodoActual;
        } else {
            cout << "No existe el elemento en la posicion " << indice << endl;
            return nullptr;    
        }
    }
/**
 * Funcion de tipo void que cambia el valor de un elemento Nodo
 * Complejidad de Tiemp: O(1)
 * Complejidad de Espacio: O(1)
 */
    void updateNodo (int indice, int valorNuevo) {
        Nodo* tmp = getElemento(indice);
        tmp->valor = valorNuevo;
    }
    ~ListaLigadaCircular() {
        Nodo* nodoActual = cabeza;
        int i = tamanio;
        while(i > 0) {
            cout << "Borrando: " << nodoActual->valor << " ";
            cout << endl;
            Nodo* temp = nodoActual;
            nodoActual = nodoActual->siguiente;
            delete temp;
            i--;
        }
    }
};
int main() {
cout << ">> Lista  Ligada  Circular << " << endl;
    cout << "-----------------------------" << endl;
    ListaLigadaCircular lista3;
    lista3.crear(15);
    lista3.imprimeLista();
    lista3.crear(16);
    lista3.imprimeLista();
    lista3.crear(17);
    lista3.imprimeLista();
    lista3.crear(18);
    lista3.imprimeLista();
    lista3.crear(19);
    lista3.imprimeLista();
    lista3.updateNodo(3,0);
    lista3.imprimeLista();
}