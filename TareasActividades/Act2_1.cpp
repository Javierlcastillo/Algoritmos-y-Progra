/**
 * Codigo que disena e implementa un ADT que represente una estructura 
 * de datos lineal para lista ligada, lista doblemente ligada y 
 * lista circular doblemente ligada.
 * Autor: Javier Luis Castillo Solórzano 
 * Matrícula: A01658415
 * Creado: {23-09-2024}
 */

#include <iostream>
using namespace std;

class Nodo {
    public:
    int valor;
    Nodo* siguiente;

    Nodo(int dataValue){
        valor = dataValue;
    }
}