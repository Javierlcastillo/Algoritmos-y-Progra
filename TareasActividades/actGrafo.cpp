/**
 * Programa que demuestra la programación y funcionamiento de un grafo, con funciones basicas de constructor,
 * lista de adjacencia, matriz de adjacencia y recorrido de grafo por anchura y profundidad. 
 * Autor: Javier Luis Castillo Solórzano 
 * Fecha: {11-06-2024}
 */

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

//Clase que representa una arista
class Arista {
public:
    int origen, destino;
    Arista(int origen, int destino) {
        this->origen = origen;
        this->destino = destino;
    }
};

//Clase que representa un grafo
class Grafo {
public:
   vector<vector<int>> listaAdyacencia;
    /**
     * Constructor de Grafo
     * @param vector<Arista> aristas: vector con aristas del grafo
     * @param int nodos: cantidad de nodo
    */
    Grafo(vector<Arista> const& aristas, int nodos) {
        // Establece el tamaño del vector
        listaAdyacencia.resize(nodos);
        for (size_t i = 0; i < aristas.size(); ++i) {
            listaAdyacencia[aristas[i].origen].push_back(aristas[i].destino);
        }
    }
    void imprimeLista() {
        for (int i = 0; listaAdyacencia.size(); i++ )
            int a = 1;
            //cout << listaAdyacencia[i]; 
    }
    /**
     * Función de tipo void que imprime la matriz de Adyacencia de el grafo
     * @param n/a
     * @return n/a
     * Complejidad de tiempo: O(n)
     * Complejidad de espacio: O(n)
     */
    void matrizAdyacencia () {
        int V = listaAdyacencia.size();
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++)
                cout << listaAdyacencia[i][j] << " ";
        cout << endl;
        }
    }
    /**
     * Función de tipo vector<int> que recorre un grafo por proundidad
     * @param inicio
     * @return recorrido 
     * Complejidad de Tiempo: O(v+e)
     * Complejida de Espacio: O(v)
     */
    vector<int> dfs(int inicio) {
        vector<bool> visitado(listaAdyacencia.size(), false);
        vector<int> recorrido;
        stack<int> pila;

        pila.push(inicio);  
        visitado[inicio] = true;
        while(!pila.empty()) {
            int nodoActual = pila.top();
            pila.pop();
            recorrido.push_back(nodoActual);
            for (int vecino: listaAdyacencia[nodoActual]) {
                if (!visitado[vecino]) {
                    pila.push(vecino);
                    visitado[vecino] = true;  
                }
            }
        }
        return recorrido;
    }
    /**
     * Función de tipo vector<int> que recorre un grafo por anchura
     * @param inicio
     * @return recorrido 
     * Complejidad de Tiempo: O(v+e)
     * Complejida de Espacio: O(v)
     */
    vector<int> bfs(int inicio) {
        vector<bool> visitado(listaAdyacencia.size(), false);
        vector<int> recorrido;
        queue<int> cola;
        cola.push(inicio);
        visitado[inicio] = true;
        while(!cola.empty()) {
            int nodoActual = cola.front();
            cola.pop();
            recorrido.push_back(nodoActual);
            for (int vecino: listaAdyacencia[nodoActual]) {
                if(!visitado[vecino]) {
                    cola.push(vecino);
                    visitado[vecino] = true;
                }
            }
        }

    }
    // Falta comparar si no hay elementos que se repitan y devolver true o false
    bool bipartito(int inicio) {
        vector<int> visitado(listaAdyacencia.size(), -1);
        vector<int> recorrido;
        stack<int> pila;

        pila.push(inicio);
        int cont = 0;  
        visitado[inicio] = cont;
        while(!pila.empty()) {
            cont++;
            int nodoActual = pila.top();
            pila.pop();
            recorrido.push_back(nodoActual);
            for (int vecino: listaAdyacencia[nodoActual]) {
                if (!visitado[vecino]) {
                    pila.push(vecino);
                    int valor = (cont % 2 == 0 ? 0 : 1);
                    visitado[vecino] = valor;  
                }
            }
        }
        }

};


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

    
    cout << "Demostración de recorrido por anchura en 4 puntos de inicio" << endl;
    vector<int> recorrido= grafo2.bfs(1);
    for (int i = 0; i < recorrido.size(); i++){
        cout << recorrido[i]<< " ";
    }
    cout << endl;
    vector<int> recorrido2 = grafo2.bfs(0);
    for (int i = 0; i < recorrido2.size(); i++) {
        cout << recorrido2[i] << " ";
    }
    cout << endl;
    vector<int> recorrid= grafo2.bfs(2);
    for (int i = 0; i < recorrid.size(); i++){
        cout << recorrid[i]<< " ";
    }
    cout << endl;
    vector<int> recorrid2 = grafo2.bfs(3);
    for (int i = 0; i < recorrid2.size(); i++) {
        cout << recorrid2[i] << " ";
    }
    cout << endl;

    cout << "Demsotración de recorrido por profundidad en 4 puntos de incicio" << endl; 
    vector<int> recorridoo= grafo2.bfs(1);
    for (int i = 0; i < recorridoo.size(); i++){
        cout << recorridoo[i]<< " ";
    }
    cout << endl;
    vector<int> recorridoo2 = grafo2.bfs(0);
    for (int i = 0; i < recorridoo2.size(); i++) {
        cout << recorridoo2[i] << " ";
    }
    cout << endl;
    vector<int> recorrdoo= grafo2.bfs(2);
    for (int i = 0; i < recorrdoo.size(); i++){
        cout << recorrdoo[i]<< " ";
    }
    cout << endl;
    vector<int> recorrdoo2 = grafo2.bfs(3);
    for (int i = 0; i < recorrdoo2.size(); i++) {
        cout << recorrdoo2[i] << " ";
    }
    cout << endl;


    //cout << "Lista de Adyacencia: " << grafo2.listaAdyacencia << endl;
    cout << "Matriz de Adyacencia: " << endl;
    grafo2.matrizAdyacencia();
    cout << endl;
    return 0;
}
