#include <iostream>
using namespace std;

void imprimeArreglo(int arr[], int tamanio) {
    for (int i = 0; i < tamanio; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int damePivote(int numeros[], int inicio, int fin) {
    int r = inicio; //r es el valor de hasta la izquierda con la cual se van recorriendo los valores. 
    int pivote = fin -1;  
    for (int i = inicio; i < fin; i++){
        if (numeros[i] < numeros[pivote]){
            int aux = numeros[r];
            numeros[r] = numeros[i];
            numeros[i] = aux;
            r++;
        }
    }
    int aux = numeros[r];
    numeros[r] = numeros[pivote];
    numeros[pivote] = aux;
    return r;
}

void quicksort(int numeros[], int inicio, int fin) {
    if (inicio < fin){
        int pivot = damePivote(numeros, inicio, fin);
        cout << "El pivote es: " << pivot << endl; 
        quicksort(numeros, inicio, pivot -1);
        quicksort(numeros, pivot+1, fin);
    }
}

int main(){
    int numeros[19] = { 28,10, 20, 30, 40, 50,10, 20, 30, 40, 50,10, 20, 30, 40, 50,12,345,785 };

    // Llamar a la función para imprimir los elementos del arreglo
    int tamanio = sizeof(numeros) / sizeof(numeros[0]);
    imprimeArreglo(numeros, tamanio);
    quicksort(numeros, 0, tamanio-1);
    imprimeArreglo(numeros, tamanio);
    return 0;
}