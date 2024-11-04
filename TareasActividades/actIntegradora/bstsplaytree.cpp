/*
 * Descripción breve del programa:
 * Este programa implementa dos estructuras de árboles: un árbol binario de búsqueda (ABB) y un árbol biselado.
 * Ambos árboles almacenan direcciones IP, permiten buscar e insertar IPs, y manejan sus nodos con diferentes
 * enfoques. El ABB mantiene el orden de forma clásica, mientras que el árbol biselado rota nodos frecuentemente
 * para optimizar accesos. Además, el ABB tiene una función para leer IPs desde un archivo y almacenarlas tanto
 * en el árbol como en un vector.
 *
 * Autor: Renato Lopez, Javier Luis Castillo
 * Matrícula: A01640057, A01658415
 * Fecha de creación: 18/10/2024
 */
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

class Nodo
{
public:
    string ip;
    Nodo *izquierda;
    Nodo *derecha;

    /*
     * Constructor: Nodo
     * Descripción: Inicializa un nodo con la dirección IP proporcionada y
     *              establece los punteros a sus nodos hijos en nullptr.
     * Parámetros:
     *     - const string &ip: La dirección IP que se almacena en el nodo.
     * Efectos:
     *     - Asigna el valor de la IP al atributo `ip`.
     *     - Inicializa los punteros `izquierda` y `derecha` a nullptr.
     * Complejidad de tiempo:
     *     - O(1), ya que las operaciones son de asignación directa.
     */
    Nodo(const string &ip)
    {
        this->ip = ip;
        izquierda = nullptr;
        derecha = nullptr;
    }
};

class ABB
{
private:
    Nodo *raiz;

    /*
     * Función: buscar (sobrecarga privada)
     * Descripción: Busca de manera recursiva un nodo que contenga la IP especificada.
     * Parámetros:
     *     - Nodo *nodo: Puntero al nodo actual durante la búsqueda.
     *     - const string &ip: IP que se busca en el árbol.
     * Valor de retorno:
     *     - Nodo*: Puntero al nodo que contiene la IP, o nullptr si no se encuentra.
     * Complejidad de tiempo:
     *     - O(h), donde h es la altura del árbol.
     * Complejidad de espacio:
     *     - O(h) debido a la recursión.
     */
    Nodo *buscar(Nodo *nodo, const string &ip) const
    {
        if (nodo == nullptr || nodo->ip == ip)
        {
            return nodo; // Devuelve el nodo encontrado o nullptr si no existe
        }

        if (ip < nodo->ip)
        {
            return buscar(nodo->izquierda, ip); // Buscar en el subárbol izquierdo
        }
        else
        {
            return buscar(nodo->derecha, ip); // Buscar en el subárbol derecho
        }
    }

    /*
     * Función: insertar (sobrecarga privada)
     * Descripción: Inserta recursivamente una IP en el árbol en su posición correcta.
     * Parámetros:
     *     - Nodo *nodo: Puntero al nodo actual durante la inserción.
     *     - const string &ip: IP que se va a insertar en el árbol.
     * Valor de retorno:
     *     - Nodo*: Puntero al nodo actualizado después de la inserción.
     * Complejidad de tiempo:
     *     - O(h), donde h es la altura del árbol.
     * Complejidad de espacio:
     *     - O(h) debido a la recursión.
     */
    Nodo *insertar(Nodo *nodo, const string &ip)
    {
        if (nodo == nullptr)
        {
            return new Nodo(ip);
        }
        // Comparar IPs para determinar la ubicación
        if (ip < nodo->ip)
        {
            nodo->izquierda = insertar(nodo->izquierda, ip);
        }
        else if (ip > nodo->ip)
        {
            nodo->derecha = insertar(nodo->derecha, ip);
        }
        return nodo;
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
     * Función: insertar (método público)
     * Descripción: Inserta una IP en el árbol binario de búsqueda.
     * Parámetros:
     *     - const string &ip: IP que se va a insertar.
     * Valor de retorno:
     *     - void
     * Complejidad de tiempo:
     *     - O(h), donde h es la altura del árbol.
     * Complejidad de espacio:
     *     - O(h) debido a la recursión interna.
     */
    void insertar(const string &ip)
    {
        raiz = insertar(raiz, ip);
    }

    /*
     * Función: buscar (método público)
     * Descripción: Verifica si una IP está presente en el árbol.
     * Parámetros:
     *     - const string &ip: IP que se va a buscar.
     * Valor de retorno:
     *     - bool: Retorna true si la IP está en el árbol, false en caso contrario.
     * Complejidad de tiempo:
     *     - O(h), donde h es la altura del árbol.
     * Complejidad de espacio:
     *     - O(h) debido a la recursión interna.
     */
    bool buscar(const string &ip) const
    {
        Nodo *resultado = buscar(raiz, ip);
        return resultado != nullptr; // Retorna true si se encontró, false en caso contrario
    }

    /*
     * Función: leerArchivo
     * Descripción: Lee un archivo y llena el árbol con las IPs extraídas del archivo.
     * Parámetros:
     *     - const string &nombreArchivo: Nombre del archivo a leer.
     *     - vector<string> &ips: Vector donde se guardarán las IPs extraídas.
     * Valor de retorno:
     *     - void
     * Complejidad de tiempo:
     *     - O(n * h), donde n es el número de líneas en el archivo y h es la altura del árbol.
     * Complejidad de espacio:
     *     - O(n), debido al almacenamiento de las IPs en el vector.
     */
    void leerArchivo(const string &nombreArchivo, vector<string> &ips)
    {
        ifstream archivo(nombreArchivo);
        string linea;

        if (archivo.is_open())
        {
            while (getline(archivo, linea))
            {
                istringstream iss(linea);
                string token;

                // Extraer IP de la línea
                getline(iss, token, '|');
                getline(iss, token, '|');
                string ip = token.substr(token.find(":") + 1); // Obtiene la IP

                insertar(ip);      // Insertar la IP en el árbol
                ips.push_back(ip); // Guardar la IP en el vector
            }
            archivo.close();
        }
        else
        {
            cerr << "No se pudo abrir el archivo: " << nombreArchivo << endl;
        }
    }
};

class NodoAB
{
public:
    string ip; // Almacena la IP directamente
    int accesos;
    NodoAB *progenitore;
    NodoAB *izquierdo;
    NodoAB *derecho;

    /*
     * Constructor: NodoAB
     * Descripción: Inicializa un nodo con la IP proporcionada y configura
     *              los atributos del nodo en sus valores por defecto.
     * Parámetros:
     *     - const string &valor: La dirección IP que se almacena en el nodo.
     * Efectos:
     *     - Establece el contador de accesos en 0.
     *     - Inicializa los punteros progenitore, izquierdo y derecho a nullptr.
     * Complejidad de tiempo:
     *     - O(1), ya que todas las operaciones son de inicialización básica.
     */
    NodoAB(const string &valor)
    {
        ip = valor;
        accesos = 0;
        progenitore = nullptr;
        izquierdo = nullptr;
        derecho = nullptr;
    }
};

typedef NodoAB *NodoPtr;

class ArbolBiselado
{
private:
    NodoPtr raiz;

    /*
     * Función: buscarNodo (sobrecarga privada)
     * Descripción: Busca de forma recursiva un nodo que contenga la IP dada.
     * Parámetros:
     *     - NodoPtr nodo: Puntero al nodo actual en la búsqueda.
     *     - const string &ip: IP que se busca en el árbol.
     * Valor de retorno:
     *     - NodoPtr: Puntero al nodo con la IP buscada, o nullptr si no se encuentra.
     * Complejidad de tiempo:
     *     - O(h), donde h es la altura del árbol.
     * Complejidad de espacio:
     *     - O(h) por la recursión.
     */

    NodoPtr buscarNodo(NodoPtr nodo, const string &ip) const
    {
        if (nodo == nullptr || ip == nodo->ip)
        {
            return nodo;
        }

        if (ip < nodo->ip)
        {
            return buscarNodo(nodo->izquierdo, ip);
        }
        return buscarNodo(nodo->derecho, ip);
    }

    /*
     * Función: rotarIzquierda
     * Descripción: Realiza una rotación hacia la izquierda sobre el nodo especificado.
     * Parámetros:
     *     - NodoPtr nodo: Puntero al nodo sobre el que se realiza la rotación.
     * Valor de retorno:
     *     - void
     * Complejidad de tiempo:
     *     - O(1)
     * Complejidad de espacio:
     *     - O(1)
     */
    void rotarIzquierda(NodoPtr nodo)
    {
        NodoPtr y = nodo->derecho;
        nodo->derecho = y->izquierdo;
        if (y->izquierdo != nullptr)
        {
            y->izquierdo->progenitore = nodo;
        }
        y->progenitore = nodo->progenitore;
        if (nodo->progenitore == nullptr)
        {
            this->raiz = y;
        }
        else if (nodo == nodo->progenitore->izquierdo)
        {
            nodo->progenitore->izquierdo = y;
        }
        else
        {
            nodo->progenitore->derecho = y;
        }
        y->izquierdo = nodo;
        nodo->progenitore = y;
    }

    /*
     * Función: rotarDerecha
     * Descripción: Realiza una rotación hacia la derecha sobre el nodo especificado.
     * Parámetros:
     *     - NodoPtr nodo: Puntero al nodo sobre el que se realiza la rotación.
     * Valor de retorno:
     *     - void
     * Complejidad de tiempo:
     *     - O(1)
     * Complejidad de espacio:
     *     - O(1)
     */
    void rotarDerecha(NodoPtr nodo)
    {
        NodoPtr y = nodo->izquierdo;
        nodo->izquierdo = y->derecho;
        if (y->derecho != nullptr)
        {
            y->derecho->progenitore = nodo;
        }
        y->progenitore = nodo->progenitore;
        if (nodo->progenitore == nullptr)
        {
            this->raiz = y;
        }
        else if (nodo == nodo->progenitore->derecho)
        {
            nodo->progenitore->derecho = y;
        }
        else
        {
            nodo->progenitore->izquierdo = y;
        }
        y->derecho = nodo;
        nodo->progenitore = y;
    }

    /*
     * Función: biselar
     * Descripción: Realiza una serie de rotaciones para mover un nodo a la raíz.
     * Parámetros:
     *     - NodoPtr nodo: Puntero al nodo que se desea mover a la raíz.
     * Valor de retorno:
     *     - void
     * Complejidad de tiempo:
     *     - O(h), donde h es la altura del árbol.
     * Complejidad de espacio:
     *     - O(1)
     */
    void biselar(NodoPtr nodo)
    {
        while (nodo->progenitore)
        {
            if (!nodo->progenitore->progenitore)
            {
                if (nodo == nodo->progenitore->izquierdo)
                {
                    rotarDerecha(nodo->progenitore);
                }
                else
                {
                    rotarIzquierda(nodo->progenitore);
                }
            }
            else if (nodo == nodo->progenitore->izquierdo && nodo->progenitore == nodo->progenitore->progenitore->izquierdo)
            {
                rotarDerecha(nodo->progenitore->progenitore);
                rotarDerecha(nodo->progenitore);
            }
            else if (nodo == nodo->progenitore->derecho && nodo->progenitore == nodo->progenitore->progenitore->derecho)
            {
                rotarIzquierda(nodo->progenitore->progenitore);
                rotarIzquierda(nodo->progenitore);
            }
            else if (nodo == nodo->progenitore->derecho && nodo->progenitore == nodo->progenitore->progenitore->izquierdo)
            {
                rotarIzquierda(nodo->progenitore);
                rotarDerecha(nodo->progenitore);
            }
            else
            {
                rotarDerecha(nodo->progenitore);
                rotarIzquierda(nodo->progenitore);
            }
        }
    }

public:
    /*
     * Constructor: ArbolBiselado
     * Descripción: Inicializa un árbol biselado vacío.
     * Complejidad de tiempo:
     *     - O(1)
     * Complejidad de espacio:
     *     - O(1)
     */
    ArbolBiselado()
    {
        raiz = nullptr;
    }

    /*
     * Función: insertar
     * Descripción: Inserta una IP en el árbol y aplica biselado para mover el nodo a la raíz.
     * Parámetros:
     *     - const string &ip: IP que se va a insertar.
     * Valor de retorno:
     *     - void
     * Complejidad de tiempo:
     *     - O(h), donde h es la altura del árbol.
     * Complejidad de espacio:
     *     - O(1)
     */
    void insertar(const string &ip)
    {
        NodoPtr nodo = new NodoAB(ip);
        NodoPtr y = nullptr;
        NodoPtr x = this->raiz;

        while (x != nullptr)
        {
            y = x;
            if (nodo->ip < x->ip)
            {
                x = x->izquierdo;
            }
            else if (nodo->ip > x->ip)
            {
                x = x->derecho;
            }
            else
            {
                // Si la IP ya existe, simplemente aumentamos el contador de accesos
                x->accesos++;
                delete nodo; // No es necesario crear un nuevo nodo
                return;
            }
        }

        nodo->progenitore = y;
        if (y == nullptr)
        {
            raiz = nodo; // El árbol estaba vacío
        }
        else if (nodo->ip < y->ip)
        {
            y->izquierdo = nodo;
        }
        else
        {
            y->derecho = nodo;
        }
        biselar(nodo); // Biselar el nodo recién insertado
    }

    /*
     * Función: leerArchivo
     * Descripción: Lee un archivo y llena el árbol con las IPs extraídas.
     * Parámetros:
     *     - const string &nombreArchivo: Nombre del archivo a leer.
     * Valor de retorno:
     *     - void
     * Complejidad de tiempo:
     *     - O(n * h), donde n es el número de líneas en el archivo y h es la altura del árbol.
     * Complejidad de espacio:
     *     - O(1)
     */
    void leerArchivo(const string &nombreArchivo)
    {
        ifstream archivo(nombreArchivo);
        string linea;

        if (archivo.is_open())
        {
            while (getline(archivo, linea))
            {
                istringstream iss(linea);
                string token;

                // Extraer IP de la línea
                getline(iss, token, '|');
                getline(iss, token, '|');
                string ip = token.substr(token.find(":") + 1); // Obtiene la IP

                insertar(ip); // Inserta solo la IP en el árbol
            }
            archivo.close();
        }
        else
        {
            cerr << "No se pudo abrir el archivo: " << nombreArchivo << endl;
        }
    }

    /*
     * Función: buscar
     * Descripción: Busca una IP en el árbol y aplica biselado si se encuentra.
     * Parámetros:
     *     - const string &ip: IP que se va a buscar.
     * Valor de retorno:
     *     - NodoPtr: Puntero al nodo encontrado o nullptr si no se encuentra.
     * Complejidad de tiempo:
     *     - O(h) amortizado, donde h es la altura del árbol.
     * Complejidad de espacio:
     *     - O(1)
     */
    NodoPtr buscar(const string &ip)
    {
        NodoPtr x = buscarNodo(this->raiz, ip);
        if (x)
        {
            x->accesos++;
            biselar(x);
        }
        return x;
    }
};

/*
 * Función: medirTiempo
 * Descripción: Mide el tiempo de búsqueda de múltiples IPs en un Árbol Binario de Búsqueda (ABB),
 *              repitiendo la búsqueda varias veces para obtener una estimación más precisa.
 * Parámetros:
 *     - const ABB &arbol: Referencia constante al árbol donde se realizan las búsquedas.
 *     - const vector<string> &ips: Vector con las IPs que se desean buscar.
 *     - const string &tipoBusqueda: Descripción del tipo de búsqueda (e.g., "secuencial", "biselada").
 *     - int repeticiones: Número de veces que se repite la búsqueda completa (por defecto, 100).
 * Valor de retorno:
 *     - void
 * Salida:
 *     - Imprime en consola el tiempo total empleado en segundos para realizar las búsquedas.
 * Complejidad de tiempo:
 *     - O(n * h * repeticiones), donde n es el número de IPs, h es la altura del árbol,
 *       y repeticiones es el número de veces que se repite la búsqueda.
 * Complejidad de espacio:
 *     - O(1), ya que no se utilizan estructuras adicionales significativas.
 */
void medirTiempo(const ABB &arbol, const vector<string> &ips, const string &tipoBusqueda, int repeticiones = 100)
{
    clock_t inicio = clock(); // Iniciar medición de tiempo

    // Repetir la búsqueda 100 veces
    for (int i = 0; i < repeticiones; ++i)
    {
        for (const string &ip : ips)
        {
            arbol.buscar(ip); // Buscar cada IP en el árbol
        }
    }

    clock_t fin = clock(); // Finalizar medición de tiempo
    double tiempo = double(fin - inicio) / CLOCKS_PER_SEC;

    cout << "Tiempo para busqueda " << tipoBusqueda << " en " << repeticiones
         << " repeticiones: " << tiempo << " segundos\n";
}

/*
 * Función: medirTiempoSplay
 * Descripción: Mide el tiempo requerido para buscar múltiples IPs en un Árbol Biselado (Splay Tree),
 *              repitiendo la búsqueda varias veces para obtener un resultado más preciso.
 *              El Árbol Biselado autoajusta su estructura tras cada búsqueda.
 * Parámetros:
 *     - ArbolBiselado &arbol: Referencia al árbol donde se realizarán las búsquedas.
 *     - const vector<string> &ips: Vector que contiene las IPs a buscar en el árbol.
 *     - const string &tipoBusqueda: Descripción del tipo de búsqueda (por ejemplo, "secuencial", "aleatoria").
 *     - int repeticiones: Número de veces que se repite la búsqueda completa (valor por defecto: 100).
 * Valor de retorno:
 *     - void
 * Salida:
 *     - Imprime en consola el tiempo total empleado en segundos para realizar las búsquedas.
 * Complejidad de tiempo:
 *     - O(n * log(n) * repeticiones) en el mejor caso, donde n es el número de IPs.
 *     - O(n^2 * repeticiones) en el peor caso, debido al comportamiento amortiguado del Splay Tree.
 * Complejidad de espacio:
 *     - O(1), ya que no se utilizan estructuras adicionales significativas.
 */
void medirTiempoSplay(ArbolBiselado &arbol, const vector<string> &ips, const string &tipoBusqueda, int repeticiones = 100)
{
    clock_t inicio = clock(); // Iniciar medición de tiempo

    // Repetir la búsqueda 100 veces
    for (int i = 0; i < repeticiones; ++i)
    {
        for (const string &ip : ips)
        {
            arbol.buscar(ip); // Buscar cada IP en el árbol
        }
    }

    clock_t fin = clock(); // Finalizar medición de tiempo
    double tiempo = double(fin - inicio) / CLOCKS_PER_SEC;

    cout << "Tiempo para busqueda en Splay Tree " << tipoBusqueda << " en "
         << repeticiones << " repeticiones: " << tiempo << " segundos\n";
}

int main()
{
    ABB arbolABB;
    ArbolBiselado arbolSplay;
    ArbolBiselado arbolSplayAscendente;
    ArbolBiselado arbolSplayDescendente;
    ArbolBiselado arbolSplayInexistente;
    ArbolBiselado arbolSplayRepetido;
    vector<string> ips;
    vector<string> ipInexistente = {"0.0.0.0"};

    arbolABB.leerArchivo("bitacoraelb.txt", ips);
    arbolSplay.leerArchivo("bitacoraelb.txt");
    arbolSplayAscendente.leerArchivo("bitacoraelb.txt");
    arbolSplayDescendente.leerArchivo("bitacoraelb.txt");
    arbolSplayInexistente.leerArchivo("bitacoraelb.txt");
    arbolSplayRepetido.leerArchivo("bitacoraelb.txt");

    vector<string> ipsAscendentes = ips;
    vector<string> ipsDescendentes = ips;

    // Ordenar IPs en orden ascendente
    sort(ipsAscendentes.begin(), ipsAscendentes.end());

    // Ordenar IPs en orden descendente
    sort(ipsDescendentes.rbegin(), ipsDescendentes.rend());

    // Medir el tiempo para IPs secuencial
    medirTiempo(arbolABB, ips, "secuencial", 1);
    medirTiempoSplay(arbolSplay, ips, "secuencial", 1);

    // Búsqueda con las IPs en orden ascendente
    sort(ips.begin(), ips.end());
    medirTiempo(arbolABB, ipsAscendentes, "en orden ascendente", 1);
    medirTiempoSplay(arbolSplayAscendente, ipsAscendentes, "en orden ascendente", 1);

    // Búsqueda con las IPs en orden descendente
    sort(ips.rbegin(), ips.rend());
    medirTiempo(arbolABB, ipsDescendentes, "en orden descendente", 1);
    medirTiempoSplay(arbolSplayDescendente, ipsDescendentes, "en orden descendente", 1);

    // Búsqueda de un IP inexistente
    medirTiempo(arbolABB, ipInexistente, "Inexistente", 100);
    medirTiempoSplay(arbolSplayInexistente, ipInexistente, "Inexistente", 100);

    // Búsqueda 1000 veces repetido de las IPs
    medirTiempo(arbolABB, ips, "1000 veces", 1000);
    medirTiempoSplay(arbolSplayRepetido, ips, "1000 veces", 1000);

    return 0;
}
