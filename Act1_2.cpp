/**
 * Aplicación en C++ donde dado n numeros de entrada que son almacenados
 * en un vector <int> y realica distintos tipos de ordenamiento:
 * 1) Intercambio, 2) Burbuja, 3) merge, 4) Sequencial 5) Busqueda Binaria
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
void imprimeVector(const vector<T> &dato){
    int n = dato.size();
    for (int i = 0; i < n; i++){
        cout << dato[i] << " ";
    }
    cout << endl;
}

/**  
 * Funcion ordenaIntercambio
 * ordena en forma ascendente los datos con un metodo de Intercambio
 * despues imprime la nueva 
 * 
 * @param datos vector<T> con n-numeros para hacer el ordenamiento 
 * @return nada
 * Complejidad de Tiempo: O(n^2)
 * Complejidad de Espacio: O(1)
*/
template <class T>
void ordenaIntercambio(vector<T> &datos){
    cout << "Vector antes del ordenamiento: ";
    imprimeVector(datos);
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
    imprimeVector(datos);
}

/**  
 * Funcion ordenaBurbuja
 * ordena en forma ascendente los datos con un metodo de Burbuja
 * e imprime el vector ordenado.
 * 
 * @param datos vector<T> con n-numeros para hacer el ordenamiento 
 * @return nada
 * Complejidad de Tiempo: O(n^2)
 * Complejidad de Espacio: O(1)
*/
template <class T>
void ordenaBurbuja(vector<T> &datos){
    cout << "Vector antes del ordenamiento: ";
    imprimeVector(datos);
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
    imprimeVector(datos);
}

/**  
 * Funcion merge
 * divide una matriz por la mitad y ordena cada una ara despes unirlas en orden ascendente
 * 
 * @param datos vector<T> con n-numeros para hacer el ordenamiento 
 * @param left int el inicio de dodne se comiemz a ejecutar el metodo
 * @param right int el fin hasta donde se ejecuta el metodo 
 * @return nada
 * Complejidad de Tiempo: O(n)
 * Complejidad de Espacio: O(1)
*/
template <class T>
void merge(vector<T> &datos, int left, int mid, int right){
    int tamano =  right - left + 1;

    int i = left, j = mid + 1, k = 0;
    vector<T> aux; //creamos vector auxiliar

    while (i <= mid && j <= right){
        if (datos[i] < datos[j]){
            //cout << "el Valor:" << aux[k] << endl;
            aux.push_back(datos[i]);
            i++;
            k++;
        } else {
            aux.push_back(datos[j]);
            j++;
            k++;
        }
    }

    while (i <= mid){
        aux.push_back(datos[i]); 
        i++;
        k++;
    } 

    while (j <= right){
        aux.push_back(datos[j]);
        j++;
        k++;
    }

    for (int  l = 0; l < tamano; l++) {
        datos[left + l] = aux[l];
    }
}

/**  
 * Funcion mergeSort
 * Divide el arreglo recursivamente lo ordena
 * e imprime el vector ordenado.
 * 
 * @param datos vector<T> con n-numeros para hacer el ordenamiento \
* @param inicio int el inicio de dodne se comiemz a ejecutar el metodo
 * @param fin int el fin hasta donde se ejecuta el metodo 
 * @return nada
 * Complejidad de Tiempo: O(nlogn)
 * Complejidad de Espacio: O(n)
*/

template <class T>
void mergeSort(vector<T> &datos, int inicio, int fin){
    if (inicio < fin){
        int mitad = inicio + (fin - inicio) / 2;
        mergeSort(datos, inicio, mitad);
        mergeSort(datos, mitad + 1, fin);
        merge(datos, inicio ,mitad, fin);
    }
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
    imprimeVector(datos);
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
    imprimeVector(datos);
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
    ordenaIntercambio(vec1);
    ordenaIntercambio(vec2);
    ordenaIntercambio(vec3);
    ordenaIntercambio(vec4);
    cout << endl;

    vec1 = {7, 4, 2, 7, 8, 9, 1};
    vec2 = {6, 9, 2, 33, 4, 2, 13, 1, 4, 1};
    vec3 = {18, 57, 32, 20, 2, 1, 4, 78};
    vec4 = {9, 4, 5, 6, 2, 1, 7, 134, 32};

    cout << endl << "Metodo de Burbuja" << endl << "---------------------" << endl;
    ordenaBurbuja(vec1);
    ordenaBurbuja(vec2);
    ordenaBurbuja(vec3);
    ordenaBurbuja(vec4);
    cout << endl;

    vec1 = {7, 4, 2, 7, 8, 9, 1};
    vec2 = {6, 9, 2, 33, 4, 2, 13, 1, 4, 1};
    vec3 = {18, 57, 32, 20, 2, 1, 4, 78};
    vec4 = {9, 4, 5, 6, 2, 1, 7, 134, 32};

    cout << endl << "Metodo Sort merge" << endl << "---------------------" << endl;
    cout << "Vector antes del intercambio: ";
    imprimeVector(vec1);
    mergeSort(vec1, 0, vec1.size()-1);
    imprimeVector(vec1);
    cout << "Vector antes del intercambio: ";
    imprimeVector(vec2);
    mergeSort(vec2, 0, vec2.size()-1);
    imprimeVector(vec2);
    cout << "Vector antes del intercambio: ";
    imprimeVector(vec3);
    mergeSort(vec3, 0, vec3.size()-1);
    imprimeVector(vec3);
    cout << "Vector antes del intercambio: ";
    imprimeVector(vec4);
    mergeSort(vec4, 0, vec4.size()-1);
    imprimeVector(vec4);
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