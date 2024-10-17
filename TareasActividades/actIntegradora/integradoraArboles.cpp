#include <iostream>
#include <fstream>
#include <sstream>
#include <locale.h>
#include <stack>
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

    NodoPtr buscar(NodoPtr nodo, long long ip) {
        if (nodo == nullptr || ip == nodo->ip) {
            return nodo;
        }

        if (ip < nodo->ip) {

            return buscar(nodo->izquierdo, ip);
        }
        return buscar(nodo->derecho, ip);
    }

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

    NodoPtr buscar(long long  k) {
        NodoPtr x = buscar(this->raiz, k);
        if (x) {
            x->accesos++;
            biselar(x);
        }
        return x;
    }

    NodoPtr minimo(NodoPtr nodo) {
        while (nodo->izquierdo != nullptr) {
            nodo = nodo->izquierdo;
        }
        return nodo;
    }

    NodoPtr maximo(NodoPtr nodo) {
        while (nodo->derecho != nullptr) {
            nodo = nodo->derecho;
        }
        return nodo;
    }

 

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

 


    void eliminar(long long ip) {
        eliminar(this->raiz, ip);
    }

    void imprimeArbol() {
        imprime(this->raiz, "", true);
    }

};