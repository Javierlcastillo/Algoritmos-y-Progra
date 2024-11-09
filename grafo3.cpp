#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
/*
Ejemplo de ordenamiento topologico usando el algoritmo de Kahn

03112022
*/

/*
Clase que representa una arista
*/
class Arista {
public:
    int origen, destino;
    Arista(int origen, int destino) {
        this->origen = origen;
        this->destino = destino;
    }
};
/*
  Clase que representa un grafo
*/
class Grafo {
public:
 
   vector<vector<int>> listaAdyacencia;

    /*
    Constructor de Grafo
    @param vector<Arista> aristas: vector con aristas del grafo
    @param int nodos: cantidad de nodo
    */
    Grafo(vector<Arista> const& aristas, int nodos) {
        // Establece el tamaño del vector
        listaAdyacencia.resize(nodos);
        for (size_t i = 0; i < aristas.size(); ++i) {
            listaAdyacencia[aristas[i].origen].push_back(aristas[i].destino);
        }
    }
};

vector<int> dfs(Grafo const& grafo, int inicio) {
    vector<bool> visitado(grafo.listaAdyacencia.size(), false);
    vector<int> recorrido;
    stack<int> pila;

    pila.push(inicio);
    visitado[inicio] = true;
    while(!pila.empty()) {
        int nodoActual = pila.top();
        pila.pop();
        recorrido.push_back(nodoActual);
        for (int vecino: grafo.listaAdyacencia[nodoActual]) {
            if (!visitado[vecino]) {
                pila.push(vecino);
                visitado[vecino] = true;  
            }
        }
    }
 

    return recorrido;
}

vector<int> ordTopologico(Grafo const& grafo, int inicio) {
    vector<int> incidencias; 
}

vector<int> bfs(Grafo const& grafo, int inicio) {
    vector<bool> visitado(grafo.listaAdyacencia.size(), false);
    vector<int> recorrido;
    queue<int> cola;

    cola.push(inicio);
    visitado[inicio] = true;

    while(!cola.empty()) {
        int nodoActual = cola.front();
        cola.pop();
        recorrido.push_back(nodoActual);

        for (int vecino: grafo.listaAdyacencia[nodoActual]) {
            if(!visitado[vecino]) {
                cola.push(vecino);
                visitado[vecino] = true;
            }
        }
    }
    return recorrido;
}

int main() {
    int nodos2 = 7;
    vector<Arista> aristas2;
    Arista* arista1 = new Arista(0, 1);
    Arista* arista2 = new Arista(1, 2);
    Arista* arista3 = new Arista(2, 4);
    Arista* arista4 = new Arista(4, 3);
    Arista* arista5 = new Arista(3, 5);
    Arista* arista6 = new Arista(5, 6);
    Arista* arista7 = new Arista(1, 6);

    aristas2.push_back(*arista1);
    aristas2.push_back(*arista2);
    aristas2.push_back(*arista3);
    aristas2.push_back(*arista4);
    aristas2.push_back(*arista5);
    aristas2.push_back(*arista6);
    aristas2.push_back(*arista7);
    vector<int> nodosOrdenados2;
    Grafo grafo2(aristas2, nodos2);
    vector<int> recorrido= dfs(grafo2, 1);
    for (int i = 0; i < recorrido.size(); i++){
        cout << recorrido[i]<< " ";
    }
    cout << endl;
    vector<int> recorrido2 = bfs(grafo2, 0);
    for (int i = 0; i < recorrido2.size(); i++) {
        cout << recorrido2[i] << " ";
    }
    cout << endl;


    return 0;

}
