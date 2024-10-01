#include <iostream>
using namespace std;

template <class T>
class Nodo {
public:
    T data;
    int priority;
    Nodo<T>* siguiente;
    Nodo<T>* anterior; 
    Nodo(T valor, int prioridad) {
        data = valor;
        priority = prioridad; //El valor de prioridad es de 1-3 donde el 1 es de menor prioridad y el 3 de mayor prioridad.
        siguiente = nullptr;
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
        }
    }
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
    void push(T dataValue, int priority) {
        size++;
        Nodo<T>* nuevo = new Nodo(dataValue, priority);
        if (isEmpty()) {
            primero = nuevo;
            ultimo =  primero;
        }
        Nodo<T>* current = ultimo;
        while(current != nullptr && current->priority < nuevo->priority) {
            cout << "ocurrencia" << endl;
            current->anterior = current;
        }
        if(current == nullptr) {
                primero -> siguiente = nuevo->siguiente;
                nuevo ->anterior = primero -> anterior;
                primero = nuevo;
         } else {
                current -> siguiente = nuevo -> siguiente;
                nuevo -> anterior = current -> anterior;
                
        }
        
    }
};
int main() {
    FilaDePrioridad <string>lista;
    lista.push("CARLOS",1);
    lista.imprimeLista();
    lista.push("ANDREA",2);
    lista.imprimeLista();
    lista.push("OKWE",1);
    lista.imprimeLista();
    lista.push("FUCKME",2);
    lista.imprimeLista();
}