/**
 * Código que calcula la sumatoria de 1 hasta n utilizando tres funcioens diferentes
 * asi como sus complejidades. 
 * 1)Suma Iterativa 2)Suma Recursiva 3)Suma Directa
 * Autor: Javier Luis Castillo Solórzano       Matrícula: A01658415
 * Creado: {16-08-2024}
*/

#include <iostream>
using namespace std;

/**
 * Funcion SumaIterativa
 * Calcula la sumatoria de 1 hasta n con un metodo iterativo.
 * 
 * @param n entero positivo que indica cuanots numeros han de ser sumados
 * @return entero positovo que muestra la sumatoria de 1 hasta n
*/
int SumaIterativa (int n){
    int sumaTotal = 0;
    for(int i = 1; i <= n; i++){
        sumaTotal += i; 
    } 
    return sumaTotal;
}
/*
Funcion SumaRecursiva
Calcula la sumatoria de 1 hasta n utilizando recursion

@param n entero positivo que indica cuantos numeros han de ser sumados
@return entero positivo que muestra la sumatoria de 1 hasta n
 */
int SumaRecursiva(int n){
    int sumaTotal;
    if(n <= 1){
        return n;
    }
    else{ 
        sumaTotal = n + SumaRecursiva(n-1);
    }
    return sumaTotal;
}

int main(){
    int n;
    cout << "Ingresa un valor entero positivo de 'n': ";
    cin >> n;
    cout << "La sumatoria del 1 al " << n << " es de: " << SumaIterativa(n) << endl;
    return 0;

}


