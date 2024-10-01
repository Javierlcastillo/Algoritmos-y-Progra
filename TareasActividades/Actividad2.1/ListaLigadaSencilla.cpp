/**
 * Codigo que disena e implementa un ADT que represente una estructura 
 * de datos lineal para lista ligada sencilla con sus metodos CRUDE.
 * Autor: Javier Luis Castillo Solórzano 
 * Matrícula: A01658415
 * Creado: {23-09-2024}
 */

#include <iostream>
using namespace std;

/**
 * clase Nodo que establece el ADT con las variables de 'valor,
 * que es un int y 'siguiente', un puntero que hace referencia al
 * objeto siguiente. Se establece el constructor.
 */
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

class ListaLigada {
    Nodo *cabeza;
    Nodo *finLista;
public:
    ListaLigada() {
        cabeza = nullptr;
    }
/**
 * Funcion que crea un nuevo Nodo y actualiza los valores de siguiente y anterior
 * @param valor de tipo int que ingresa el valor que tendra el nodo
 * Complejidad de Tiempo: O(1)
 * Complejidad de espacio: O(1)
 */    
    void crear (int valor) {
        if (cabeza == nullptr) {
            cabeza = new Nodo(valor);
            finLista = cabeza;
        } else {
            Nodo *nuevo = new Nodo(valor);
            finLista->siguiente = nuevo;
            //finLista->anterior = finLista;
            finLista = nuevo; 
        }
    }
/**
 * Funcion que imprime todos los elementos de la lista
 * Complejidad de Tiempo: O(n)
 * Complejidad de espacio: O(1)
 */
    void imprimeLista() {
        Nodo *nodoActual = cabeza;
        while (nodoActual != nullptr) {
            cout << nodoActual->valor<< " ";
            nodoActual = nodoActual->siguiente;
        }
        cout << endl;   
    };
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
    // intento de eliminar un elemento especifico.
    /* void elimNodo (int indice) {
        Nodo* tmp = getElemento(indice);
        Nodo* anterior = tmp->anterior;
        Nodo* siguiente =  tmp->siguiente;
        if (anterior == nullptr) { //el nodo no es la cabeza
            cabeza = siguiente;
        } else if (siguiente == nullptr) { //el nodo es el ultimo
            finLista = anterior;
        } else {
            anterior->siguiente = siguiente;
            siguiente->anterior = anterior;
        }
        delete tmp;
    } */
/**
 * Funcion de tipo void que cambia el valor de un elemento Nodo
 * Complejidad de Tiemp: O(1)
 * Complejidad de Espacio: O(1)
 */
    void updateNodo (int indice, int valorNuevo) {
        Nodo* tmp = getElemento(indice);
        tmp->valor = valorNuevo;
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

int main() {
    cout << ">> Lista Sencilla Ligada << " << endl;
    cout << "-----------------------------" << endl;
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
    lista.updateNodo(2,0);
    lista.imprimeLista();

    return 0;
}