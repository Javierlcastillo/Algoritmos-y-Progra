#include <iostream>
#include <queue>

using namespace std;

// Definición de la clase Nodo
class Nodo {
public:
    int valor;         // Valor almacenado en el nodo
    Nodo* izquierda;   // Puntero al nodo hijo izquierdo
    Nodo* derecha;     // Puntero al nodo hijo derecho

    // Constructor
    Nodo(int val) {
        valor = val;
        izquierda = nullptr;
        derecha = nullptr;
    }
};

// Definición de la clase Árbol Binario de Búsqueda (ABB)
class ABB {
private:
    Nodo* raiz;  // Puntero a la raíz del árbol

    // Función auxiliar para insertar un valor en el árbol
    Nodo* insertar(Nodo* nodo, int valor) {
        if (nodo == nullptr) {
            return new Nodo(valor);  // Si llegamos a un nodo vacío, creamos uno nuevo
        }

        // Si el valor es menor, lo insertamos en el subárbol izquierdo
        if (valor < nodo->valor) {
            nodo->izquierda = insertar(nodo->izquierda, valor);
        }
        // Si el valor es mayor, lo insertamos en el subárbol derecho
        else if (valor > nodo->valor) {
            nodo->derecha = insertar(nodo->derecha, valor);
        }

        // Devolvemos el nodo (sin cambios si ya existía)
        return nodo;
    }

    // Función auxiliar para recorrer el árbol en orden (in-order)
    void recorridoEnOrden(Nodo* nodo) {
        if (nodo != nullptr) {
            recorridoEnOrden(nodo->izquierda);   // Recorremos el subárbol izquierdo
            cout << nodo->valor << " ";          // Mostramos el valor del nodo actual
            recorridoEnOrden(nodo->derecha);     // Recorremos el subárbol derecho
        }
    }
    void recorridoPorNivel(queue<int> fila) {
            fila.push();
            recorridoPorNivel(nodo->izquierda);
            

        }
    }

public:
    // Constructor
    ABB() {
        raiz = nullptr;
    }

    // Función para insertar un valor en el árbol
    void insertar(int valor) {
        raiz = insertar(raiz, valor);
    }

    // Función para mostrar el recorrido en orden del árbol
    void recorridoEnOrden() {
        recorridoEnOrden(raiz);
        cout << endl;
    }
    
    void recorridoPorNivel() {
        queue<int> fila;

    }
};

int main() {
    ABB arbol;

    arbol.insertar(50);
    arbol.insertar(30);
    arbol.insertar(20);
    arbol.insertar(40);
    arbol.insertar(70);
    arbol.insertar(60);
    arbol.insertar(80);

    cout << "Recorrido en orden (in-order): ";
    arbol.recorridoEnOrden();  // Debería mostrar: 20 30 40 50 60 70 80

    return 0;
}