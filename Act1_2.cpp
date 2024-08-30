/**
 * Aplicación en C++ donde dado n numeros de entrada que son almacenados
 * en un vector <int> y realica distintos tipos de ordenamiento:
 * 1) Intercambio, 2) Burbuja, 3) Merge, 4) Sequencial 5) Busqueda Binaria
 * Autor: Javier Luis Castillo Solórzano
 * Matrícula = A01658415
 * Creado: {30-08-2024}
*/
#include <iostream>
#include <vector>
using namespace std;

/**
 * Funcion que imprime los valores de un vector 
*/
template <class T>
void ImprimeVector(const vector<T> &dato){
    int n = dato.size();
    for (int i = 0; i < n; i++){
        cout << dato[i] << " ";
    }
    cout << endl;
}

/**  
 * Funcion OrdenaIntercambio
 * Ordena en forma ascendente los datos con un metodo de Intercambio
 * despues imprime la nueva 
 * 
 * @param datos vector<T> con n-numeros para hacer el ordenamiento 
 * @return nada
 * Complejidad de Tiempo:
 * Complejidad de Espacio:
*/
template <class T>
void OrdenaIntercambio(vector<T> &datos){
    int n = datos.size();
    for (int i = 0; i <= n-2; i++){
        for(int j = i+1; j <= n-1; j++){
            if(datos[i] > datos[j]){
                T temp = datos[i];
                datos[i] = datos[j];
                datos[j] = temp;
                
            }
        }
    }
    ImprimeVector(datos);
}

/**  
 * Funcion OrdenaBurbuja
 * Ordena en forma ascendente los datos con un metodo de Burbuja
 * e imprime el vector ordenado.
 * 
 * @param datos vector<T> con n-numeros para hacer el ordenamiento 
 * @return nada
 * Complejidad de Tiempo:
 * Complejidad de Espacio:
*/
template <class T>
void OrdenaBurbuja(vector<T> datos){
    int n = datos.size();
    bool interruptor = true;
    for (int paso = 0; paso <= n-1 && interruptor; paso++){
        interruptor = false;
        for (int j = 0; j < n-1-paso; j++){
            if (datos[j] > datos[j+1]){
                T tmp = datos[j];
                datos[j] = datos[j+1];
                datos[j+1] = tmp;
                interruptor = true;
                ImprimeVector(datos);
            }
        }
    }
}

int main(){
    vector<int> vec1 = {7, 4, 2, 7, 8, 9, 1};
    cout << "Vector antes del ordenamiento: ";
    ImprimeVector(vec1);
    cout << endl << "Metodo de Intercambio" << endl << "---------------------" << endl;
    OrdenaIntercambio(vec1);

    vector<int> vec2 = {6, 9, 2, 33, 4, 2, 13, 1, 4, 1};
    cout << "Vector antes del ordenamiento: ";
    ImprimeVector(vec2);
    cout << endl << "Metodo de Burbuja" << endl << "---------------------" << endl;
    OrdenaBurbuja(vec2);
    return 0;
}