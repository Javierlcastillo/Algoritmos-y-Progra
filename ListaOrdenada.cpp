/**
 * Codigo que disena e implementa un ADT que represente una estructura 
 * de datos lineal para lista ligada sencilla con sus metodos CRUDE.
 * Autor: Javier Luis Castillo Solórzano 
 * Matrícula: A01658415
 * Creado: {24-09-2024}
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
        Nodo* current = cabeza;
        if (cabeza == nullptr) {
            cabeza = new Nodo(valor);
            finLista = cabeza;
        } else {
            while(valor > current->valor){
                Nodo* elemento = current->siguiente;
                if(valor <= elemento->valor){
                    Nodo* nuevo = new Nodo(valor);
                    Nodo* tmp = current->siguiente; //creo  un nodo temporal para guardar el valor de el siguiente nodo
                    current->siguiente = nuevo;
                    nuevo->siguiente = tmp;
                }
            }
            Nodo *nuevo = new Nodo(valor);
            finLista->siguiente = nuevo;
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
    }
/*     Nodo* findMitad(){
        Nodo* current = cabeza;
        int tamanio;
        while(cabeza->siguiente){
            tamanio++;
        }
        for (int i = 0; i < tamanio/2; i++){
            current = current->siguiente
        }
    } */
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
    //lista.updateNodo(2,0);
    lista.imprimeLista();

    return 0;
}