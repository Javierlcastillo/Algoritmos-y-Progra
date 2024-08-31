#include <iostream>
using namespace std;

//O(n^2)
void ordInsercion (int a[], int n, int valor){
    int j, aux;
    for (int i = 1; i < n; i++){ // El índice j explora sublista a[i-1]..a[0] buscando posición correcta del elemento destino, para asignarlo en a[j]
        j = i;
        aux = a[i];
        while (j > 0 && aux < a[j-1]){ // desplazar elementos hacia arriba para hacer espacio
            a[j] = a[j-1];
            j--;
        }
        a[j] = aux;
    }
}