/**
 * Codigo que disena e implementa un ADT que represente una estructura 
 * de datos lineal para lista ligada, lista doblemente ligada y 
 * lista circular doblemente ligada.
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
    void imprimeLista() {
        Nodo *nodoActual = cabeza;
        while (nodoActual != nullptr) {
            cout << nodoActual->valor<< " ";
            nodoActual = nodoActual->siguiente;
        }
        cout << endl;   
    };
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

class ListaDoblementeLigada {
    Nodo* cabeza;
    Nodo* finLista;
public: 
    ListaDoblementeLigada() {
        cabeza =  nullptr;
    }
    void crear (int valor) {
        if (cabeza == nullptr) {
            cabeza = new Nodo(valor);
            finLista = cabeza;
        } else {
            Nodo *nuevo = new Nodo(valor);
            finLista->siguiente = nuevo;
            finLista->anterior = finLista;
            finLista = nuevo; 
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
    void updateNodo (int indice, int valorNuevo) {
        Nodo* tmp = getElemento(indice);
        tmp->valor = valorNuevo;
    }
    ~ListaDoblementeLigada() {
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

class ListaLigadaCircular {
    Nodo* cabeza;
    Nodo* finLista;
    int tamanio;
    
public:
    ListaLigadaCircular() {
        cabeza = nullptr;
    }
    void crear(int valor) {
        if (cabeza == nullptr) {
            cabeza = new Nodo(valor);
            finLista = cabeza;
            cabeza->siguiente = cabeza;
            //cabeza->anterior = cabeza;
        } else{
                Nodo* nuevo = new Nodo(valor);
                nuevo->siguiente = cabeza;
                finLista->siguiente = nuevo;
                finLista = nuevo;
        }
        tamanio++;
    }
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
            cout << i << endl;
            i--;
        }
    }
};
int main(){
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

    cout << ">> Lista Doblemente Ligada << " << endl;
    cout << "-----------------------------" << endl;
    ListaDoblementeLigada lista2;
    lista2.crear(10);
    lista2.imprimeLista();
    lista2.crear(11);
    lista2.imprimeLista();
    lista2.crear(12);
    lista2.imprimeLista();
    lista2.crear(13);
    lista2.imprimeLista();
    lista2.crear(14);
    lista2.imprimeLista();
    lista2.updateNodo(4,0);
    lista2.imprimeLista();

    cout << ">> Lista  Ligada  Circular << " << endl;
    cout << "-----------------------------" << endl;
    ListaLigadaCircular lista3;
    lista3.crear(15);
    lista3.imprimeLista();
    /* lista3.crear(16);
    lista3.imprimeLista();
    lista3.crear(17);
    lista3.imprimeLista();
    lista3.crear(18);
    lista3.imprimeLista();
    lista3.crear(19);
    lista3.imprimeLista();
    lista3.updateNodo(3,0);
    lista3.imprimeLista(); */
    return 0;
}