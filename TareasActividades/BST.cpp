/*
 * Descripción breve del programa:
 * Este programa implementa un árbol binario de búsqueda (ABB) y permite insertar valores,
 * realizar recorridos (preorden, inorden, postorden y por niveles), calcular la altura del árbol,
 * encontrar ancestros de un valor dado y determinar el nivel de un nodo específico.
 *
 * Autor: Renato Lopez
 * Matrícula: A01640057
 * Fecha de creación: 11/10/2024
 */
#include <iostream>
using namespace std;

class Nodo
{
public:
    int valor;
    Nodo *izquierda;
    Nodo *derecha;

    /*
     * Constructor: Nodo
     * Descripción: Inicializa un nodo con un valor y punteros a izquierda y derecha en nullptr.
     * Parámetros:
     *     - int val: El valor del nodo.
     * Complejidad de tiempo:
     *     - O(1)
     * Complejidad de espacio:
     *     - O(1)
     */
    Nodo(int val) : valor(val), izquierda(nullptr), derecha(nullptr) {}
};

class ABB
{
private:
    Nodo *raiz;

    /*
     * Función: preorden
     * Descripción: Realiza un recorrido en preorden sobre el árbol.
     * Parámetros:
     *     - Nodo *nodo: Nodo actual en el recorrido.
     * Complejidad de tiempo:
     *     - O(n)
     * Complejidad de espacio:
     *     - O(n)
     */
    void preorden(Nodo *nodo) const
    {
        if (nodo != nullptr)
        {
            cout << nodo->valor << " ";
            preorden(nodo->izquierda);
            preorden(nodo->derecha);
        }
    }

    /*
     * Función: inorden
     * Descripción: Realiza un recorrido en inorden sobre el árbol.
     * Parámetros:
     *     - Nodo *nodo: Nodo actual en el recorrido.
     * Complejidad de tiempo:
     *     - O(n)
     * Complejidad de espacio:
     *     - O(n)
     */
    void inorden(Nodo *nodo) const
    {
        if (nodo != nullptr)
        {
            inorden(nodo->izquierda);
            cout << nodo->valor << " ";
            inorden(nodo->derecha);
        }
    }

    /*
     * Función: postorden
     * Descripción: Realiza un recorrido en postorden sobre el árbol.
     * Parámetros:
     *     - Nodo *nodo: Nodo actual en el recorrido.
     * Complejidad de tiempo:
     *     - O(n)
     * Complejidad de espacio:
     *     - O(n)
     */
    void postorden(Nodo *nodo) const
    {
        if (nodo != nullptr)
        {
            postorden(nodo->izquierda);
            postorden(nodo->derecha);
            cout << nodo->valor << " ";
        }
    }

    /*
     * Función: recorridoPorNivel
     * Descripción: Realiza un recorrido por niveles del árbol.
     * Parámetros:
     *     - Nodo *nodo: Nodo actual en el recorrido.
     *     - int nivel: Nivel actual a recorrer.
     * Complejidad de tiempo:
     *     - O(n), donde n es el número de nodos.
     * Complejidad de espacio:
     *     - O(n)
     */
    void recorridoPorNivel(Nodo *nodo, int nivel) const
    {
        if (nodo == nullptr)
            return;
        if (nivel == 1)
        {
            cout << nodo->valor << " ";
        }
        else if (nivel > 1)
        {
            recorridoPorNivel(nodo->izquierda, nivel - 1);
            recorridoPorNivel(nodo->derecha, nivel - 1);
        }
    }

    /*
     * Función: altura
     * Descripción: Calcula la altura del árbol.
     * Parámetros:
     *     - Nodo *nodo: Nodo actual desde el cual calcular la altura.
     * Valor de retorno:
     *     - int: La altura del nodo.
     * Complejidad de tiempo:
     *     - O(n)
     * Complejidad de espacio:
     *     - O(n)
     */
    int altura(Nodo *nodo) const
    {
        if (nodo == nullptr)
        {
            return 0;
        }
        int alturaIzquierda = altura(nodo->izquierda);
        int alturaDerecha = altura(nodo->derecha);
        return 1 + max(alturaIzquierda, alturaDerecha);
    }

    /*
     * Función: encontrarAncestros
     * Descripción: Encuentra e imprime los ancestros de un valor dado.
     * Parámetros:
     *     - Nodo *nodo: Nodo actual en la búsqueda.
     *     - int valor: El valor cuyo ancestro se busca.
     * Valor de retorno:
     *     - bool: Verdadero si el valor fue encontrado.
     * Complejidad de tiempo:
     *     - O(n)
     * Complejidad de espacio:
     *     - O(n)
     */
    bool encontrarAncestros(Nodo *nodo, int valor) const
    {
        if (nodo == nullptr)
            return false;
        if (nodo->valor == valor)
            return true;
        if (encontrarAncestros(nodo->izquierda, valor) || encontrarAncestros(nodo->derecha, valor))
        {
            cout << nodo->valor << " ";
            return true;
        }
        return false;
    }

    /*
     * Función: encontrarNivel
     * Descripción: Encuentra el nivel de un valor dado en el árbol.
     * Parámetros:
     *     - Nodo *nodo: Nodo actual en la búsqueda.
     *     - int valor: El valor cuyo nivel se busca.
     *     - int nivel: Nivel actual.
     * Valor de retorno:
     *     - int: El nivel del nodo con el valor dado o -1 si no existe.
     * Complejidad de tiempo:
     *     - O(n)
     * Complejidad de espacio:
     *     - O(n)
     */
    int encontrarNivel(Nodo *nodo, int valor, int nivel) const
    {
        if (nodo == nullptr)
        {
            return -1;
        }
        if (nodo->valor == valor)
        {
            return nivel;
        }
        if (valor < nodo->valor)
        {
            return encontrarNivel(nodo->izquierda, valor, nivel + 1);
        }
        return encontrarNivel(nodo->derecha, valor, nivel + 1);
    }

public:
    /*
     * Constructor: ABB
     * Descripción: Inicializa un árbol binario de búsqueda vacío.
     * Complejidad de tiempo:
     *     - O(1)
     * Complejidad de espacio:
     *     - O(1)
     */
    ABB() : raiz(nullptr) {}

    /*
     * Función: insertar
     * Descripción: Inserta un valor en el árbol binario de búsqueda.
     * Parámetros:
     *     - int valor: El valor a insertar.
     * Complejidad de tiempo:
     *     - O(log n) en promedio, O(n) en el peor caso.
     * Complejidad de espacio:
     *     - O(n)
     */
    void insertar(int valor)
    {
        raiz = insertar(raiz, valor);
    }

    /*
     * Función: insertar (recursiva)
     * Descripción: Función recursiva auxiliar para insertar un valor.
     * Parámetros:
     *     - Nodo *nodo: Nodo actual.
     *     - int valor: El valor a insertar.
     * Valor de retorno:
     *     - Nodo*: Puntero al nodo modificado o nuevo.
     * Complejidad de tiempo:
     *     - O(log n) en promedio, O(n) en el peor caso.
     * Complejidad de espacio:
     *     - O(n)
     */
    Nodo *insertar(Nodo *nodo, int valor)
    {
        if (nodo == nullptr)
        {
            return new Nodo(valor);
        }
        if (valor < nodo->valor)
        {
            nodo->izquierda = insertar(nodo->izquierda, valor);
        }
        else if (valor > nodo->valor)
        {
            nodo->derecha = insertar(nodo->derecha, valor);
        }
        return nodo;
    }

    /*
     * Función: visitar
     * Descripción: Realiza un recorrido del árbol según el tipo especificado.
     * Parámetros:
     *     - const int tipoRecorrido: Tipo de recorrido (1: Preorden, 2: Inorden, 3: Postorden, 4: Nivel).
     * Complejidad de tiempo:
     *     - O(n)
     * Complejidad de espacio:
     *     - O(n)
     */
    void visit(const int tipoRecorrido) const
    {
        if (tipoRecorrido == 1)
        {
            cout << "Recorrido Preorder: ";
            preorden(raiz);
        }
        else if (tipoRecorrido == 2)
        {
            cout << "Recorrido Inorder: ";
            inorden(raiz);
        }
        else if (tipoRecorrido == 3)
        {
            cout << "Recorrido Postorder: ";
            postorden(raiz);
        }
        else if (tipoRecorrido == 4)
        {
            cout << "Recorrido Level by Level: ";
            int h = altura(raiz);
            for (int i = 1; i <= h; ++i)
            {
                recorridoPorNivel(raiz, i);
            }
        }
        else
        {
            cout << "Tipo de recorrido no válido." << endl;
        }
        cout << endl;
    }

    /*
     * Función: height
     * Descripción: Devuelve la altura del árbol.
     * Valor de retorno:
     *     - int: La altura del árbol.
     * Complejidad de tiempo:
     *     - O(n)
     * Complejidad de espacio:
     *     - O(n)
     */
    int height() const
    {
        return altura(raiz);
    }

    /*
     * Función: ancestors
     * Descripción: Imprime los ancestros de un valor dado en el árbol.
     * Parámetros:
     *     - int valor: El valor del cual se buscan los ancestros.
     * Complejidad de tiempo:
     *     - O(n)
     * Complejidad de espacio:
     *     - O(n)
     */
    void ancestors(int valor) const
    {
        if (!encontrarAncestros(raiz, valor))
        {
            cout << "El valor no se encuentra en el árbol." << endl;
        }
        else
        {
            cout << endl;
        }
    }

    /*
     * Función: whatlevelamI
     * Descripción: Devuelve el nivel de un valor dado en el árbol.
     * Parámetros:
     *     - int valor: El valor cuyo nivel se busca.
     * Valor de retorno:
     *     - int: El nivel del nodo con el valor dado o -1 si no existe.
     * Complejidad de tiempo:
     *     - O(n)
     * Complejidad de espacio:
     *     - O(n)
     */
    int whatlevelamI(int valor)
    {
        return encontrarNivel(raiz, valor, 1);
    }
};

int main()
{
    ABB arbol;
    ABB arbol2;
    ABB arbol3;
    ABB arbol4;

    // Arbol 1
    arbol.insertar(50);
    arbol.insertar(30);
    arbol.insertar(20);
    arbol.insertar(40);
    arbol.insertar(70);
    arbol.insertar(60);
    arbol.insertar(80);

    // Arbol 2
    arbol2.insertar(30);
    arbol2.insertar(20);
    arbol2.insertar(10);
    arbol2.insertar(40);
    arbol2.insertar(35);
    arbol2.insertar(50);

    // Arbol 3
    arbol3.insertar(100);

    // Arbol 4
    arbol4.insertar(15);
    arbol4.insertar(10);

    cout << "Visit en arbol 1: " << endl;
    arbol.visit(1);
    arbol.visit(2);
    arbol.visit(3);
    arbol.visit(4);

    cout << "La altura del arbol 1 es: " << arbol.height() << endl;
    cout << "La altura del arbol 2 es: " << arbol2.height() << endl;
    cout << "La altura del arbol 3 es: " << arbol3.height() << endl;
    cout << "La altura del arbol 4 es: " << arbol4.height() << endl;

    cout << "Ancestros de 40 arbol 1: ";
    arbol.ancestors(40);
    cout << "Ancestros de 80 arbol 1: ";
    arbol.ancestors(80);
    cout << "Ancestros de raiz arbol 1: "; // Ningun valor de retorno, no tiene
    arbol.ancestors(50);
    cout << "Ancestros de 20 arbol 1: ";
    arbol.ancestors(20);

    cout << "El nivel de 40 arbol 1 es: " << arbol.whatlevelamI(40) << endl;
    cout << "El nivel de 80 arbol 1 es: " << arbol.whatlevelamI(80) << endl;
    cout << "El nivel de 100 arbol 1 es: " << arbol.whatlevelamI(100) << endl;
    cout << "El nivel de 30 arbol 1 es: " << arbol.whatlevelamI(30) << endl;
}
