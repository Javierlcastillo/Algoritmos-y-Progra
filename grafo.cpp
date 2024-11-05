#include <iostream>
#include <vector>
using namespace std;

class Grafo {
    vector<vector<int>> matriz;
    int numNodos;

public:
    Grafo(int n) : numNodos(n), matriz(n, vector<int>(n, 0)) {}

    // Agregar arista dirigida desde u hacia v
    void agregarArista(int u, int v) {
        matriz[u][v] = 1;
    }

    // Verificar si una ruta puede ser recorrida exactamente
    bool rutaValida(const vector<int>& ruta) {
        for(int i = 0; ruta.size(); i++) {
            int origen = ruta[i];
            int destino = ruta[i+1];
            if(matriz[origen][destino] != 1)
                return false;
        }
        return true; // Se puede recorrer toda la ruta
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

    int rutaLongitud;
    cout << "Introduce la longitud de la ruta a verificar: ";
    cin >> rutaLongitud;

    vector<int> ruta(rutaLongitud);
    cout << "Introduce los nodos de la ruta en orden: ";
    for (int i = 0; i < rutaLongitud; ++i) {
        cin >> ruta[i];
    }

    if (grafo.rutaValida(ruta)) {
        cout << "La ruta puede ser recorrida exactamente en el grafo.\n";
    }
    else {
        cout << "La ruta NO puede ser recorrida exactamente en el grafo.\n";
    }

    return 0;
}