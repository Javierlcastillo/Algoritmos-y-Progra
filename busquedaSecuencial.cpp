#include <iostream>
using namespace std;

int BusquedaSecuencial(int arreglo[], int tamano, int busqueda){
    for (int i = 0; i < tamano; i++){
        if (arreglo[i] == busqueda){
            return i;
        }
    }
    return -1;
}

int BusquedaRecursiva(int arreglo[], int low, int high, int key){
    if (low > high)
        return -1;
	int mid = low + (high - low) / 2;
	int midVal = arreglo[mid];
    if(arreglo[mid] == key){
		return mid;
    }
	else if (arreglo[mid] < key){
        low = mid + 1;
		BusquedaRecursiva(arreglo, low, high, key); 
	}
	else if(arreglo[mid] > key){
		high = mid - 1;
        BusquedaRecursiva(arreglo, low, high, key);
	}
    return 3;
} 

int main (){
    int arreglo[] = {10,20,30,50};
    int n = sizeof(arreglo) / sizeof(arreglo[0]);
    int busqueda = 30;
    int resultado = BusquedaRecursiva(arreglo, 0, n-1, busqueda);
        cout << "Resultado found at: " << resultado;
}
