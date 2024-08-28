#include <iostream>
using namespace std;

void printArray(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void bubbleSort(int arr[], int n){
	bool interruptor = true;
	int pasada, i, j;
	for (pasada = 0; pasada < n -1 && interruptor; pasada ++){
		interruptor = false; //no se han hecho cambios
		for (int j = 0; j < n-1-pasada; j++){ // el n-1-pasada lo que hace es ir reduciendo desde la "derecha" el indice, ya que idealmente se pasa el ulimo numero hasta el final.
			if(arr[j] > arr[j+1]){
			    int tmp = arr[j];
			    arr[j] = arr[j+1];
			    arr[j+1] = tmp;
			    interruptor = true; //afirma que hubieron cambios.
            }
        }
        printArray(arr, n);  
    }
} 

template <typename T>
void bubbleSort(int arr[], int n){
	bool interruptor = true;
	int pasada, i, j;
	for (pasada = 0; pasada < n -1 && interruptor; pasada ++){
		interruptor = false; //no se han hecho cambios
		for (int j = 0; j < n-1-pasada; j++){
			if(arr[j] > arr[j+1]){
			    T tmp = arr[j];
			    arr[j] = arr[j+i];
			    arr[j+1] = tmp;
                printArray(arr, n);
			    interruptor = true; //afirma que hubieron cambios.
            }
        }   
    }
} 

int main(){
    // Ejemplo de arreglo
    int arr[] = { 64, 34, 25, 12, 22, 11, 90 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Arreglo original: ";
    printArray(arr, n);
    bubbleSort(arr, n);
    cout << "Arreglo ordenado: ";
    printArray(arr, n);


    return 0;
}