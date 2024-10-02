/**
 * Codigo que disena e implementa un ADT que represente una estructura 
 * de datos lineal para lista ligada, lista doblemente ligada y 
 * lista circular doblemente ligada.
 * Autor: Javier Luis Castillo Solórzano 
 * Matrícula: A01658415
 * Creado: {29-09-2024}
 */

#include <iostream>
using namespace std;

template <class T>
class Nodo {
public:
    T data;
    int priority;
    Nodo<T>* siguiente;
    Nodo(T valor, int prioridad) {
        data = valor;
        priority = prioridad; //El valor de prioridad es de 1-3 donde el 1 es de menor prioridad y el 3 de mayor prioridad.
        siguiente = nullptr;
    }
    ~Nodo() {
        cout << "Eliminando Nodo -> " << data << endl;
    }
};

template <class T>
class FilaDePrioridad{
    Nodo<T>* primero; //es el primero en la lista
    Nodo<T>* ultimo; //el ultimo nodo de la lista
    int size = 0;
public:
    FilaDePrioridad() {
        primero = nullptr;
        size = 0;
    }
    ~FilaDePrioridad() {
        while (primero != nullptr) {
            Nodo<T>* temp = primero;
            primero = primero->siguiente;
            delete temp;
            imprimeLista();
        }
    }
/**
 * Funcion que elimina el primer elemento de la lista
 * No tiene entradas ni devuelve nada
 * Complejidad de Timpo: O(1)
 * Complejidad de Espacio: O(1)
 */
    void pop() {
        cout << "Eliminando primero en la lista: " << primero->data << endl;
        cout << "Prioridad: " << primero->priority << endl;
        Nodo<T>* tmp = primero;
        primero = primero->siguiente;
        delete tmp;
    }
    /**
 * Funcion que imprime cada elemento de la lista.
 * No tiene entradas ni devuelve nada
 * Complejidad de Timpo: O(N)
 * Complejidad de Espacio: O(1)
 */
    void imprimeLista() {
        Nodo<T>* nodoActual = primero;
        while (nodoActual != nullptr) {
            cout << nodoActual->data<< " ";
            nodoActual = nodoActual->siguiente;
        }
        cout << endl;
    }
    int isEmpty() {
        if (primero == nullptr)
            return 1;
        return 0;
    }
/**
 * Funcionq que agrega un elemento a la lista de acuerdo su prioridad
 * @param dataValue de tipo T que es el valor que tendra el nodo y
 * @param priority que es la prioridad que tendra el nodo
 * Complejidad de Espacio: O(1)
 * Complejida de Tiempo: O(N)
 */
    void push(T dataValue, int priority) {
        size++;
        Nodo<T>* current = primero;
        Nodo<T>* nuevo = new Nodo(dataValue, priority);
        if(isEmpty() || primero->priority < priority) { //por si no hay elementos o es mas grande que la cabeza
            //nuevo->siguiente = primero;
            nuevo->siguiente = primero;
            primero = nuevo;
        } else {
            while(current->siguiente != nullptr && current->siguiente->priority >= priority) {
                current = current->siguiente;
            }
            nuevo->siguiente = current->siguiente;
            current->siguiente = nuevo;
        }
    }
/**
 * Funcion que obteien el elemento de la lista en el indice ingresado
 * @param indice
 * @return nodoActual que es un puntero de Nodo o nullptr en caso de que el indice ingresado no exista
 * Complejida de Espacio: O(1)
 * Complejida de Tiempo: O(n)
 */
    Nodo<T>* getElemento(int indice){
        Nodo<T>* nodoActual = primero;
        int contador = 0;
        for (int i = 0; i < indice-1; i++){
            if (nodoActual != nullptr){
                nodoActual = nodoActual->siguiente;
                contador++;
            }
        }
        if(contador == indice-1){
            return nodoActual;
        } else{
            cout << "No hay nodo en ese indice" << endl;
            return nullptr;
        }

    }
/**
 * Funcion que cambia el nombre de un elemento dado utilizando la funcion getElemento() pero no devuelve nada
 * @param indice 
 * @param valorNuevo
 * 
 */
    void updateNombre(int indice, T valorNuevo) {
        Nodo<T>* tmp = getElemento(indice);
        tmp->data = valorNuevo;
    }
/**
 * funcion que actualiza la priorida de un elemento si esta es de mayor prioridad que en la que esta actualmente y no devuelve nada. 
 * @param indice
 * @param prioridad que es la nueva prioridad a asignar
 * 
 */
    void updatePrioridad(int indice, int prioridad) {
        Nodo<T>* tmp = getElemento(indice);
        if (tmp->priority < prioridad)
        {
            tmp->priority = prioridad;

            // RECORREMOS TODA LA LISTA PERO PRIMERO IDENTIFICAMOS EL ELEMENTO ANTES DE ESTE.
            Nodo<T> *current = primero;
            if (primero != tmp)
            {
                Nodo<T> *anterior = getElemento(indice - 1);
                anterior->siguiente = tmp->siguiente;
            }
            if (isEmpty() || primero->priority < tmp->priority)
            { // por si no hay elementos o es mas grande que la cabeza
                tmp->siguiente = primero;
                primero = tmp;
            }
            else
            {
                while (current->siguiente != nullptr && current->siguiente->priority >= tmp->priority)
                {
                    current = current->siguiente;
                }
                tmp->siguiente = current->siguiente;
                current->siguiente = tmp;
            }
        }
    }
};

template <class T>
class Deque {
    Nodo<T>* primero; //es el primero en la lista
    Nodo<T>* ultimo; //el ultimo nodo de la lista
    int size = 0;
public: 
    Deque() {
        primero = nullptr;
        ultimo = nullptr;
        size = 0;
    }
    ~Deque() {
        while (primero != nullptr) {
            Nodo<T>* temp = primero;
            primero = primero->siguiente;
            delete temp;
            imprimeLista();
        }
    }
/**
 * funcionq eu imprime cada delemento de la lista, no tienen entrada ni devuelve nada
 * Complejidad de Espacio: O(1)
 * Complejida de Tiempo: O(n)
 */
    void imprimeLista() {
        Nodo<T>* nodoActual = primero;
        while (nodoActual != nullptr) {
            cout << nodoActual->data<< " ";
            nodoActual = nodoActual->siguiente;
        }
        cout << endl;
    }
    int isEmpty() {
        if (primero == nullptr)
            return 1;
        return 0;
    }
    /**
 * Funcion que obteien el elemento de la lista en el indice ingresado
 * @param indice
 * @return nodoActual que es un puntero de Nodo o nullptr en caso de que el indice ingresado no exista
 * Complejida de Espacio: O(1)
 * Complejida de Tiempo: O(n)
 */
    Nodo<T>* getElemento(int indice){
        Nodo<T>* nodoActual = primero;
        int contador = 0;
        for (int i = 0; i < indice-1; i++){
            if (nodoActual != nullptr){
                nodoActual = nodoActual->siguiente;
                contador++;
            }
        }
        if(contador == indice-1){
            return nodoActual;
        } else{
            cout << "No hay nodo en ese indice" << endl;
            return nullptr;
        }

    }
/**
 * Funcion que agrega un elemento hasta en frente de la lista 
 * @param valorDato
 * Complejida de Espacio: O(1)
 * Complejidad de Tiempo: O(1)
 */
    void pushFront(
        T valorDato) {
        Nodo<T>* nuevo = new Nodo(valorDato, 0);
        Nodo<T>* current = primero;
        if(isEmpty()) {
            primero = nuevo;
            ultimo = primero; 
        } else {
            primero = nuevo;
            primero->siguiente = current;
            while(current->siguiente != nullptr) {
                current = current->siguiente;
            }
        }
    }
    void getUltimo() {
        cout << ultimo->data << " ELemento Utlimo" << endl;
    }
/** 
 * Funcion que agrega un elemento hasta el final de la lista
 * @param valorDato
 * Complejida de Espacio:O(1)
 * Complejidad de Tiempo: O(1)
 */
    void pushBack(T valorDato) {
        Nodo<T>* nuevo = new Nodo(valorDato, 0);
        if(isEmpty()) {
            primero = nuevo; 
            ultimo = primero;
        } else {
            ultimo->siguiente = nuevo;
            ultimo = nuevo;
        }
    }
/** 
 * Funcion que elemina el primer elemento de la lista
 * Complejidad de espacio: O(1)
 * Complejidad de Tiempo: O(1)
 */
    void popFront() {
        cout << "Eliminando primero en la lista: " << primero->data << endl;
        Nodo<T>* tmp = primero;
        primero = primero->siguiente;
        delete tmp;
    }
/*     void popBack() {
        cout << "Eliminando ultimo en la lista: " << ultimo->data << endl;
        Nodo<T>* current = primero;
        while(current->siguiente != nullptr) {
            if(current->siguiente == ultimo) {
                Nodo<T>* tmp = ultimo;
                ultimo = current;
                current = ultimo;
                delete tmp;
            }
        }
    } */
/**
 * Funcion que cambia el nombre de un elemento dado utilizando la funcion getElemento() pero no devuelve nada
 * @param indice 
 * @param valorNuevo
 * 
 */
    void updateNombre(int indice, T valorNuevo) {
        Nodo<T>* tmp = getElemento(indice);
        tmp->data = valorNuevo;
    }
};

int main() {
    cout << "<<Fila de Prioridad>>" << endl;
    cout << "---------------------" << endl;
    FilaDePrioridad <string>lista;
    lista.push("CARLOS",1);
    lista.push("ANDREA",3);
    lista.push("FELIPE",2);
    lista.push("ANDRES",2);
    lista.push("RENATO", 3);
    lista.push("MARCELA", 1);
    lista.push("SILVANA",2);
    lista.imprimeLista();
    Nodo<string>* elemento = lista.getElemento(4);
    cout  << "El elemento es: " << elemento->data << endl;
    lista.updateNombre(4, "NombreUpdateado");
    lista.imprimeLista();
    lista.updatePrioridad(4,3);
    lista.imprimeLista();
    cout << "Implementacion de pop" << endl;
    lista.pop();

    cout << "<<      Deque      >>" << endl;
    cout << "---------------------" << endl;
    Deque<string> deque; 
    deque.pushFront("ANDRES");
    deque.imprimeLista();
    deque.pushFront("CARLOS");
    deque.imprimeLista();
    deque.pushBack("RONALDO");
    deque.imprimeLista();
    deque.popFront();
    deque.imprimeLista();
    //deque.popBack();
    //deque.imprimeLista();
}

