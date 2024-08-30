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
 * Ordena en forma ascendente los daots con un metodo de Intercambio
 * 
 * @param datos vector<int> con n-numeros para hacer el ordenamiento 
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

template <class T>
void OrdenaIntercambio(vector<T> &datos){
    
}
int main(){
    vector<int> vec1 = {7, 4, 2, 7, 8, 9, 1};
    cout << "Vector antes del ordenamiento: ";
    ImprimeVector(vec1);
    cout << endl << "Metodo de Intercambio" << endl << "---------------------" << endl;
    OrdenaIntercambio(vec1);

    return 0;
}