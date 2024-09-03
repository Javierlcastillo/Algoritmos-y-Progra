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
 * Complejidad de Tiempo: O(n)
 * Complejidad de espacio: O(1)
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
 * Complejidad de Tiempo: O(n^2)
 * Complejidad de Espacio: O(1)
*/
template <class T>
void OrdenaIntercambio(vector<T> &datos){
    cout << "Vector antes del ordenamiento: ";
    ImprimeVector(datos);
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
 * Complejidad de Tiempo: O(n^2)
 * Complejidad de Espacio: O(1)
*/
template <class T>
void OrdenaBurbuja(vector<T> &datos){
    cout << "Vector antes del ordenamiento: ";
    ImprimeVector(datos);
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
            }
        }
    }
    ImprimeVector(datos);
}

/**  
 * Funcion BusqSecuencial
 * Encuentra un numero dado en un vector arreglado ascendentemente y devuelve el
 * indice o -1 si este no esta en el valor. 
 * 
 * @param datos vector<T> con n-numeros
 * @param busqueda es el elemento a encontrar
 * 
 * @return nada
 * Complejidad de Tiempo: O(n)
 * Complejidad de Espacio: O(1)
*/
template <class T>
int BusquedaSecuencial(vector<T> &datos, int busqueda){
    cout << "Vector para la busqueda Secuencial de " << busqueda << endl;
    ImprimeVector(datos);
    int tamano = datos.size();
    for (int i = 0; i < tamano; i++){
        if (datos[i] == busqueda){
            return i;
        }
    }
    return -1;
}

/**  
 * Funcion BusqBinaria
 * Encuentra un numero dado en un vector arreglado ascendentemente y devuelve el
 * indice o -1 si este no esta en el valor. 
 * 
 * @param datos vector<T> con n-numeros
 * @param key es el elemento a encontrar
 * 
 * @return nada
 * Complejidad de Tiempo: O(logn)
 * Complejidad de Espacio: O(1)
*/
template <class T>
int BusqBinaria(vector<T> &datos, T key){
    cout << "Vector para la busqueda Binaria de " << key << endl;
    ImprimeVector(datos);
    int low = 0; 
    int high = datos.size() - 1;
    bool ans = false;
	while(low <=  high){
		int mid = low + (high - low) / 2;
		int midVal = datos[mid];

		if (midVal < key){
			low = midVal + 1;
		}
		else if(midVal > key){
			high = mid - 1;
		}
		else if(midVal == key){
			ans = true;
            int valor = midVal;
            return valor;
        }
	} 
    return -1;
}
int main(){
    vector<int> vec1 = {7, 4, 2, 7, 8, 9, 1};
    vector<int> vec2 = {6, 9, 2, 33, 4, 2, 13, 1, 4, 1};
    vector<int> vec3 = {18, 57, 32, 20, 2, 1, 4, 78};
    vector<int> vec4 = {9, 4, 5, 6, 2, 1, 7, 134, 32};

    cout << endl << "Metodo de Intercambio" << endl << "---------------------" << endl;
    OrdenaIntercambio(vec1);
    OrdenaIntercambio(vec2);
    OrdenaIntercambio(vec3);
    OrdenaIntercambio(vec4);
    cout << endl;

    cout << endl << "Metodo de Burbuja" << endl << "---------------------" << endl;
    OrdenaBurbuja(vec1);
    OrdenaBurbuja(vec2);
    OrdenaBurbuja(vec3);
    OrdenaBurbuja(vec4);
    cout << endl;

    cout << endl << "Busqueda Secuencial" << endl << "---------------------" << endl;
    //Busqueda Secuencial 
    int key3 = 18, key1 = 7, key2 = 24, key4 = 13;
    int resultado = BusquedaSecuencial(vec1, key1);
    (resultado != -1) ? cout << "El numero " << key1 << " se encuentra en el indice " << resultado+1 << endl : cout << "El numero " << key1 << " no esta en el vector" << endl;
    resultado = BusquedaSecuencial(vec2, key2);
    (resultado != -1) ? cout << "El numero " << key2 << " se encuentra en el indice " << resultado+1 << endl : cout << "El numero " << key2 << " no esta en el vector" << endl;
    resultado = BusquedaSecuencial(vec3, key3);
    (resultado != -1) ? cout << "El numero " << key3 << " se encuentra en el indice " << resultado+1 << endl : cout << "El numero " << key3 << " no esta en el vector" << endl;
    resultado = BusquedaSecuencial(vec4, key4);
    (resultado != -1) ? cout << "El numero " << key4 << " se encuentra en el indice " << resultado+1 << endl : cout << "El numero " << key4 << " no esta en el vector" << endl;
    cout << endl;

    cout << endl << "Busqueda Binaria" << endl << "---------------------" << endl;
    // Busqueda Binaria
    resultado = BusqBinaria(vec1, key1);
    (resultado != -1) ? cout << "El numero " << key1 << " se encuentra en el indice " << resultado+1 << endl : cout << "El numero " << key1 << " no esta en el vector" << endl;
    resultado = BusqBinaria(vec2, key2);
    (resultado != -1) ? cout << "El numero " << key2 << " se encuentra en el indice " << resultado+1 << endl : cout << "El numero " << key2 << " no esta en el vector" << endl;
    resultado = BusqBinaria(vec3, key3);
    (resultado != -1) ? cout << "El numero " << key3 << " se encuentra en el indice " << resultado+1 << endl : cout << "El numero " << key3 << " no esta en el vector" << endl;
    resultado = BusqBinaria(vec4, key4);
    (resultado != -1) ? cout << "El numero " << key4 << " se encuentra en el indice " << resultado+1 << endl : cout << "El numero " << key4 << " no esta en el vector" << endl;

    




    
    return 0;
}