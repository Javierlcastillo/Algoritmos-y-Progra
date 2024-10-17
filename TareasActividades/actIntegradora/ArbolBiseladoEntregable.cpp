#include <iostream>
#include <fstream>
#include <sstream>
#include <locale.h>
#include <stack>
#include <string>
using namespace std;

/*
struct Registro {
    int ano;
    int mes;
    int dia;
    string hora;
    string ip;
    string mensaje;
};
void imprimirRegistro(const Registro& reg) {
    cout << "Año: " << reg.ano << endl;
    cout << "Mes: " << reg.mes << endl;
    cout << "Día: " << reg.dia << endl;
    cout << "Hora: " << reg.hora << endl;
    cout << "IP: " << reg.ip << endl;
    cout << "Mensaje: " << reg.mensaje << endl;
}

class Nodo {
public: 
    Registro datos; 
    Nodo* siguiente;
    Nodo* anterior;
    Nodo(Registro dataValue) {
        datos = dataValue;
        siguiente = nullptr;
        anterior = nullptr; 
    }
    Registro getDatos() {
        return datos;
    }
};
*/
class Nodo {
public:
    Nodo(long long valor) {
        accesos = 0;
        ip = valor;
        progenitore = nullptr;
        izquierdo = nullptr;
        derecho = nullptr;
    }
    long long ip = 0;
    int accesos = 0;
    Nodo* progenitore;
    Nodo* izquierdo;
    Nodo* derecho;
};

typedef Nodo* NodoPtr;

class ArbolBiselado {
private:
    NodoPtr raiz;

/*
 * Funcion de tipo Nodo* que realiza la buscqueda de un nodo con un key (ip) especifico.
 * @param nodo de tipo Nodo* 
 * @param ip de tipo long long que es la key a buscar dentro del arbol
 * @return nodo en caso de que el nodo no exista o si el ip del nodo equivale a la key a encontrar,
 * sin embargo si la ip a buscar es menor al valro de la ip del nodo ingresado, esta funcion se vuelve recursiva
 * hasta encontrar el nodo con la misma key o el fin del arbol.
 * Complejidad de Espacio: O(n)
 * Complejidad de Tiempo: O(n)
 */
    NodoPtr buscar(NodoPtr nodo, long long ip) {
        if (nodo == nullptr || ip == nodo->ip) {
            return nodo;
        }

        if (ip < nodo->ip) {

            return buscar(nodo->izquierdo, ip);
        }
        return buscar(nodo->derecho, ip);
    }

/**
 * Funcion eliminar de tipo VOID que elimina un nodo del arbol biselado, primero dividiendo el arbol, 
 * eliminando el nodo y luego uniendo los otros nodos en un mismo arbol
 * @param nodo de tipo NODO*
 * @param ip de tipo LONG LONG
 * @return n/a
 */
    void eliminar(NodoPtr nodo, long long ip) {
        NodoPtr eliminado = nullptr;
        NodoPtr t, s;
        while (nodo != nullptr) {
            if (nodo->ip == ip) {
                eliminado = nodo;
            }

            if (nodo->ip <= ip) {
                nodo = nodo->derecho;
            }
            else {
                nodo = nodo->izquierdo;
            }
        }

        if (eliminado == nullptr) {
            cout << "No se encontró la IP" << endl;
            return;
        }
        divide(eliminado, s, t);
        if (s->izquierdo) { // elimina el nodo
            s->izquierdo->progenitore = nullptr;
        }
        //une los dos subárboles
        raiz = une(s->izquierdo, t);
        //libera memoria
        delete(s);
        s = nullptr;
    }

/**
 * Funcion de tipo VOID que imprime el ip (key) de un cierto nodo, utilizando un stack para
 * representarlo como IP, manejando los valores como bytes
 * @param value de tipo LONG LONG que es el valor del ip en un nodo
 * @return n/a
 * Complejidad de Tiempo: O(logn)
 * Complejidad de Espacio: O(logn)
 */
    void imprimeIp(long long value) {
        string valorAImprimir = "";
        int contador = 0;
        stack<int>* s = new  stack<int>();
        while (value > 0) {
            s->push(value % 256);
            value = value / 256;
            contador++;
        }
        int contador2 = contador;
        while (contador < 4) {
            cout << "0.";
            contador++;
        }
        while (!s->empty()) {
            cout << s->top();
            if (contador2 > 1) {
                cout << ".";
            }
            s->pop();
            contador2--;
        }
    }

/**
 * Funcion de tipo VOID recursiva que Imprime los elementos de un arbol biselado con forma de arbol
 * @param raiz de tipo NODO* que representa desde donde comienza a correr el codigo
 * @param rellleno de tipo STRING que son la ingtegracion de elementos visuales para representar la forma de arbol
 * @param ultimo de tipo BOOL para representar si es el ultimo elemento de una branch
 * @return n/a
 * Complejidad de tiempo: O(n)
 * Complejidad de Espacio O(n)
 */
    void imprime(NodoPtr raiz, string rellleno, bool ultimo) {
        if (raiz != nullptr) {
            cout << rellleno;
            if (ultimo) {
                cout << "└────";
                rellleno += "     ";
            }
            else {
                cout << "├────";
                rellleno += "|    ";

            }
            imprimeIp(raiz->ip);
            cout << "," << raiz->accesos << endl;
            imprime(raiz->izquierdo, rellleno, false);
            imprime(raiz->derecho, rellleno, true);
        }
    }

/** 
 * Funcion de tipo VOID que 'rota a la izquirda' una parte del arbol biselado, balanceando el arbol
 * El nodo->derecho se vuelve hijo del nodo->progenitore o raiz
 * El nodo de entrada se vuelve hijo->izquierdo de nodo->derecho
 * El nodo->derecho->izqierdo  se vuleve el hijo derecho del nodo de entrada (nodo->derecho) 
 * @param nodo de tipo NODO* 
 * @return n/a
 * Complejidad de Espacio: O(1)
 * Complejidad de Tiempo: O(1)
 */
    void rotarIzquierda(NodoPtr nodo) {
        NodoPtr y = nodo->derecho;
        nodo->derecho = y->izquierdo;
        if (y->izquierdo != nullptr) {
            y->izquierdo->progenitore = nodo;
        }
        y->progenitore = nodo->progenitore;
        if (nodo->progenitore == nullptr) {
            this->raiz = y;
        }
        else if (nodo == nodo->progenitore->izquierdo) {
            nodo->progenitore->izquierdo = y;
        }
        else {
            nodo->progenitore->derecho = y;
        }
        y->izquierdo = nodo;
        nodo->progenitore = y;
    }

/**
 * Funcion de tipo VOID que 'rota a la derecha' una parte del arbol biselado, balanceando el arbol
 * El nodo->izquierdo se vuelve hijo del nodo->progenitore o raiz
 * El nodo de entrada se vuelve hijo->derecho de nodo->izquierdo
 * El nodo->izquierdo->derecho  se vuleve el hijo derecho del nodo de entrada (nodo->derecho) 
 * @param nodo de tipo NODO* 
 * @return n/a
 * Complejidad de Espacio: O(1)
 * Complejidad de Tiempo: O(1)
 */
    void rotarDerecha(NodoPtr nodo) {
        NodoPtr y = nodo->izquierdo;
        //y es igual al hijo izquierdo
        nodo->izquierdo = y->derecho;
        //l izquierdo del nodo rotado apunta al derecho del hijo izquierdo, balanceo
        if (y->derecho != nullptr) {
            y->derecho->progenitore = nodo;
        }
        // si se hizo el balanceo el progenitor es el nuevo padre

        y->progenitore = nodo->progenitore;
        // si es raiz actualizar raíz
        if (nodo->progenitore == nullptr) {
            this->raiz = y;
        }
        else if (nodo == nodo->progenitore->derecho) {
            // el hijo derecho del padre del nodo es y
            nodo->progenitore->derecho = y;
        }
        else {
            //el  hijo izquierdo del padre del nodo es y
            nodo->progenitore->izquierdo = y;
        }
        // establece lado derecho
        y->derecho = nodo;
        // establece padre

        nodo->progenitore = y;
    }

/**
 * Funcion de tipo VOID que mueve el nodo ingresado hacia la raiz por medio de Funciones de Rotacion
 * @param nodo de tipo NODO*, es el nodo a mover hacia la raiz.
 * @return n/a
 * Complejidad de Espacio: O(n)
 * Complejidad de Espacio: O(1)
 */
    void biselar(NodoPtr nodo) {
        while (nodo->progenitore) {
            if (!nodo->progenitore->progenitore) {
                if (nodo == nodo->progenitore->izquierdo) {
                    // zig
                    rotarDerecha(nodo->progenitore);
                }
                else {
                    // zag 
                    rotarIzquierda(nodo->progenitore);
                }
            }
            else if (nodo == nodo->progenitore->izquierdo && nodo->progenitore == nodo->progenitore->progenitore->izquierdo) {
                // zig-zig 
                rotarDerecha(nodo->progenitore->progenitore);
                rotarDerecha(nodo->progenitore);
            }
            else if (nodo == nodo->progenitore->derecho && nodo->progenitore == nodo->progenitore->progenitore->derecho) {
                // zag-zag
                rotarIzquierda(nodo->progenitore->progenitore);
                rotarIzquierda(nodo->progenitore);
            }
            else if (nodo == nodo->progenitore->derecho && nodo->progenitore == nodo->progenitore->progenitore->izquierdo) {
                // zig-zag 
                rotarIzquierda(nodo->progenitore);
                rotarDerecha(nodo->progenitore);
            }
            else {
                // zag-zig 
                rotarDerecha(nodo->progenitore);
                rotarIzquierda(nodo->progenitore);
            }
        }
    }

/**
 * Funcion une de tipo NODO* que une dos sub-arboles por medio de los nodos de entrada.
 * Si alguno de los dos nodos de entrada no existen
 * devuelve el otro nodo.. Enncontrando el valor maximo del arbol s dejandolo como 'cabeza'
 * y lo bisela, establece el otro nodo como hijo derecho de x. 
 * @param s de tipo NODO*
 * @param t de tipo NODO*
 * @return x de tipo NODO* 
 */
    NodoPtr une(NodoPtr s, NodoPtr t) {
        if (!s) {
            return t;
        }

        if (!t) {
            return s;
        }
        NodoPtr x = maximo(s);
        biselar(x);
        x->derecho = t;
        t->progenitore = x;
        return x;
    }

/**
 * Funcion dividir de tipo VOID que divide un arbol en dos subarboles. Bisela (mueve hacia la punta) el valor x
 * y establece t como la 'cabeza' del arbol derecho y s como la 'cabeza' del arbol izquierdo
 * @param x de tipo NODO*& 
 * @param s de tipo NODO*& 
 * @param t de tipo NODO*& 
 * @return n/a
 * Complejidad de tiempo: O(n)
 * Complejidad de Espacio: O(1)
 */
    void divide(NodoPtr& x, NodoPtr& s, NodoPtr& t) {
        biselar(x);
        if (x->derecho) {
            t = x->derecho;
            t->progenitore = nullptr;
        }
        else {
            t = nullptr;
        }
        s = x;
        s->derecho = nullptr;
        x = nullptr;
    }

public:
    ArbolBiselado() {
        raiz = nullptr;
    }

/**
 * Funcion buscar de tipo NODO* que encuentra el valor de un nodo en el arbol
 * Esta funcion aumenta el atributo ACCESOS del nodo
 * @param k de tipo LONG LONG que es el valor a encontrar en el arbol
 * @return x de tipo NODE*. Es el nodo donde se encuentra el key k
 * Complejidad de Tiempo: O(n)
 */
    NodoPtr buscar(long long  k) {
        NodoPtr x = buscar(this->raiz, k);
        if (x) {
            x->accesos++;
            biselar(x);
        }
        return x;
    }

/**
 * Funcion de tipo NODO* que recorre el arbol por el lado izquierdo para encontrar el nodo con el valor  minimo
 * @param nodo de tipo NODO*
 * @return nodo de tipo NODO* que devuelve el nodo con el valor mas pequeno
 * Complejidad de Tiempo: O(n)
 * Complejidad de Espacio: O(1)
 */
    NodoPtr minimo(NodoPtr nodo) {
        while (nodo->izquierdo != nullptr) {
            nodo = nodo->izquierdo;
        }
        return nodo;
    }

/** Funcion de tipo NODO* que devuelve el nodo mas grande del arbol, recorriendo todo el lado derecho del arbol
 * @param nodo de tipo NODO* 
 * @return nodo de tipo NODO* que es el nodo mayor del arbol
 * Complejidad de Tiempo: O(n)
 * Complejidad de espacio: O(1)
 */
    NodoPtr maximo(NodoPtr nodo) {
        while (nodo->derecho != nullptr) {
            nodo = nodo->derecho;
        }
        return nodo;
    }

 
/** 
 * Funcion crear de tipo Void que asigna un elemento en el arbol comparando sus valores por medio de ip
 * para asignar un 'lado' dentro del arbol
 * @param key de tipo LONG LONG 
 * @return n/a
 */
    void crear(long long key) {
        NodoPtr nodo = new Nodo(key);
        nodo->progenitore = nullptr;
        nodo->izquierdo = nullptr;
        nodo->derecho = nullptr;
        nodo->ip = key;
        NodoPtr y = nullptr;
        NodoPtr x = this->raiz;

        while (x != nullptr) {
            y = x;
            if (nodo->ip < x->ip) {
                x = x->izquierdo;
            }
            else {
                x = x->derecho;
            }
        }
        
        // si  nunca se asignó y  AB vacío
        nodo->progenitore = y;
        if (y == nullptr) {
            raiz = nodo;
        }// Si es menor el valor a insertar es hijo izquierdo
        else if (nodo->ip < y->ip) {
            y->izquierdo = nodo;
        }// Si es mayor el valor a insertar es hijo derecho
        else {
            y->derecho = nodo;
        }
        //Biselar el nodo hasta la raíz
        biselar(nodo);
    }

    NodoPtr LeerArchivo(const string& nombreArchivo) {
        ifstream archivo(nombreArchivo);
        string linea;
        if(archivo.is_open()) {
            while(getline(archivo, linea)) {
                long long ip; 
                istringstream iss(linea);
                string token;
                string iptemp;
            
                //procesa la fecha y la hora y la ignora
                getline(iss, token, '|');

                // Extraer la IP
                getline(iss, token, '|');
                istringstream ipStream(token.substr(token.find(":") + 1));
                string dato1, dato2, dato3, dato4;

                getline(ipStream, dato1, '.');
                getline(ipStream, dato2, '.');
                getline(ipStream, dato3, '.');
                getline(ipStream, dato4, ' ');

                iptemp = dato1 + dato2 + dato3 + dato4;
                ip = stoll(iptemp);
                // Insertar en el árbol
                this->crear(ip);
            }
        archivo.close();
    } else {
        cerr << "No se pudo abrir el archivo: " << nombreArchivo << endl;
    }
    return this->raiz;
}

/**
 * Funcion eliminar de tipo VOID que recurre a la funciono eliminar privada de el AB, elimina
 * el nodo con la ip ingresada
 * @param ip de tipo LONG LONG 
 * @return n/a
 */
    void eliminar(long long ip) {
        eliminar(this->raiz, ip);
    }

/**
 * Funcion ImprimeArbol de tipo VOID que recurre a la funcion imprime privada del AB,
 * @param n/a
 * @return n/a
 */
    void imprimeArbol() {
        imprime(this->raiz, "", true);
    }

};
