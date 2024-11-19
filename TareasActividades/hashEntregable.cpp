/**
 * Programa que demuestra la utilización de las operaciones sobre conjuntos
 * Autor: Javier Luis Castillo Solórzano
 * Matrícula: A01658415
 * Fecha: {19-11-2024}
 */
#include <iostream>
#include <vector>
#include <string>
using namespace std;

/**
 * Clase que implementa el quadratic Probing
 */
class HashTable {
private:
    vector <int> table;
    int table_size;

/**
 * Funcion hash primaria que evalua el valor ingresado con el tamano de tabla
 * @param key
 * @return resultado de la operacion 
 * Complejidad de tiempo: O(1)
 * Complejidad de espacio: O(1)
 */
    int hashFunction(int key) {
        return key % table_size;
    }

/**
 * Funcion hash que utiliza quadratic probing
 * @param key, i ->index
 * @return resultado de la operacion
 * Complejidad de tiempo: O(1)
 * Complejidad de espacio: O(1)
 */
    int quadraticProbing(int key, int i) {
        return (hashFunction(key) + i * i) % table_size;
    }

public:
    HashTable(int size): table_size(size) { 
        table.resize(size, -1);
    }

/**
 * Funcion que inserta un valor al conjunto. 
 * @param key
 * @return n/a
 * Complejidad de Tiempo: O(n)
 * Complejidad de espacio: O(n)
 */
    void insert(int key) {
        int index = hashFunction(key);
        int i = 0;

        while (table[quadraticProbing(key, index)] != -1) {
            index++;
        }

        table[quadraticProbing(key, index)] = key;
    }

/**
 * Funcion que despliega la tabla de hash
 * @param n/a
 * @return n/a
 * Complejidad de tiempo: O(n)
 * Complejidad de espacio: O(1)
 */
    void display() {
        for (int i = 0; i < table_size; i++) {
            if (table[i] != -1)
                std::cout << i << " --> " << table[i] << std::endl;
            else
                std::cout << i << " --> " << std::endl;
        }
    }
};

/**
 * Clase que implementa el chainProbing
 */
class HashTable2 {
private:
    vector <int> table;
    int table_size;

/**
 * Funcion hash primaria que evalua el valor ingresado con el tamano de tabla
 * @param key
 * @return resultado de la operacion 
 * Complejidad de tiempo: O(1)
 * Complejidad de espacio: O(1)
 */
    int hashFunction(int key) {
        return key % table_size;
    }

/**
 * Funcion hash que utiliza chain probing
 * @param key, i ->index
 * @return resultado de la operacion
 * Complejidad de tiempo: O(1)
 * Complejidad de espacio: O(1)
 */
    int chainProbing(int key, int i) {
        return (hashFunction(key) + i) % table_size;
    }

public:
    HashTable2(int size): table_size(size) { 
        table.resize(size, -1);
    }

/**
 * Funcion que inserta un valor al conjunto. 
 * @param key
 * @return n/a
 * Complejidad de Tiempo: O(n)
 * Complejidad de espacio: O(n)
 */
    void insert(int key) {
        int index = hashFunction(key);
        int i = 0;

        while (table[chainProbing(key, index)] != -1) {
            index++;
        }

        table[chainProbing(key, index)] = key;
    }

/**
 * Funcion que despliega la tabla de hash
 * @param n/a
 * @return n/a
 * Complejidad de tiempo: O(n)
 * Complejidad de espacio: O(1)
 */
    void display() {
        for (int i = 0; i < table_size; i++) {
            if (table[i] != -1)
                std::cout << i << " --> " << table[i] << std::endl;
            else
                std::cout << i << " --> " << std::endl;
        }
    }
};
int main() {
    HashTable hashTable(10);

    hashTable.insert(23);
    hashTable.insert(43);
    hashTable.insert(13);
    hashTable.insert(27);

    cout << "IMPRESION DE HASH CON QUADRATIC PROBING" << endl;
    cout << "<<----------------------------------->>" << endl; 
    hashTable.display();
    cout << endl; 


    HashTable2 hashTable2(10);

    hashTable2.insert(23);
    hashTable2.insert(43);
    hashTable2.insert(13);
    hashTable2.insert(27);
    cout << "IMPRESION DE HASH CON CHAIN PROBING" << endl;
    cout << "<<----------------------------------->>" << endl; 
    hashTable2.display();
    cout << endl; 
    return 0;
}
