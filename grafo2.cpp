#include <iostream>
using namespace std;

class Grafo {
    int** matriz;
    int numNodos;
    int aristas;

public:
    Grafo(int n) : numNodos(n) {
        matriz = new int* [n];
        for (int i = 0; i < n; ++i) {
            matriz[i] = new int[n] {0}; // Inicializa cada fila con 0
        }
    }

    ~Grafo() {
        for (int i = 0; i < numNodos; ++i) {
            delete[] matriz[i];
        }
        delete[] matriz;
    }

    // Agregar arista dirigida desde u hacia v
    void agregarArista(int u, int v) {
        matriz[u][v] = 1;
        aristas++;
    }

    // Verificar si una ruta puede ser recorrida exactamente
    bool rutaValida(int* ruta, int rutaLongitud) {
        for(int i = 0; i < rutaLongitud-1; i++) {
            int origen = ruta[i];
            int destino = ruta[i+1];
            if(matriz[origen][destino] != 1)
                return false;
        }   
        return true;
    }
    
};

int main() {
    int n, m;
    cout << "Introduce el número de nodos en el grafo: ";
    cin >> n;

    Grafo grafo(n);

    cout << "Introduce el número de aristas dirigidas en el grafo: ";
    cin >> m;
    cout << "Introduce cada arista (nodo inicial y nodo final):\n";
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        grafo.agregarArista(u, v);
    }
    grafo.listaAdjacencia();
    int rutaLongitud;
    cout << "Introduce la longitud de la ruta a verificar: ";
    cin >> rutaLongitud;

    int* ruta = new int[rutaLongitud];
    cout << "Introduce los nodos de la ruta en orden: ";
    for (int i = 0; i < rutaLongitud; ++i) {
        cin >> ruta[i];
    }

    if (grafo.rutaValida(ruta, rutaLongitud)) {
        cout << "La ruta puede ser recorrida exactamente en el grafo.\n";
    }
    else {
        cout << "La ruta NO puede ser recorrida exactamente en el grafo.\n";
    }

    delete[] ruta; // Liberar la memoria asignada a la ruta
    return 0;
}