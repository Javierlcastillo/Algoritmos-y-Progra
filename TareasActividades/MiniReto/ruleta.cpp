#include <iostream>
using namespace std;

class Nombre {
public:
    string nombre;
    Nombre* siguiente;
    Nombre* anterior;

    Nombre(string dato) {
        nombre = dato;
        siguiente = nullptr;
        anterior = nullptr;
    }
};

class Ruleta {
    Nombre* cabeza;
    Nombre* finRuleta;
public: 
    Ruleta() {
        cabeza = nullptr;
        finRuleta = nullptr;
    }
    void crear (string valor) {
        if (cabeza == nullptr) {
            cabeza = new Nombre(valor);
            finRuleta = cabeza;
        } else {
            Nombre *nuevo = new Nombre(valor);
            finRuleta->siguiente = nuevo;
            finRuleta = nuevo; 
        }
    }
    void imprimeLista() {
        Nombre* nombreActual = cabeza;
        while (nombreActual != nullptr) {
            cout << nombreActual->nombre<< " ";
            nombreActual = nombreActual->siguiente;
        }
        cout << endl;
    }
    Nombre* getElemento(int indice) {
        
    }
    Nombre getSpin(int moveX, int reverse) {

    }
};

int main() {

}