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
 * Complejidad de Tiempo: O(n)
 * Complejidad de Espacio: O(1)
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
Complejidad de Tiempo: O(n)
Complejidad de espacio: O(n)
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

/*
Funcion SumaDirecta
Calcula la sumatoria de 1 hasta n utilizando un metodo matematico directo

@param n entero positivo que indica cuantos numeros han de ser sumados
@return entero positivo que muestra la sumatoria de 1 hasta n
Complejidad de Tiempo: O(1)
Complejidad de Espacio: O(1)
 */
int SumaDirecta(int n){
    return n * (n+1)/2;
}


int main(){
    int n = 5;
    int n2 = 10;
    int n3 = 7;
    cout << ">>Suma Iterativa<<" << endl << "-------------------" << endl;
    cout << "Para n = " << n << " -> " << SumaIterativa(n) << endl;
    cout << "Para n = " << n2 << " -> " << SumaIterativa(n2) << endl;
    cout << "Para n = " << n3 << " -> " << SumaIterativa(n3) << endl;
    cout << endl;
        cout << ">>Suma Recursiva<<" << endl << "-------------------" << endl;
    cout << "Para n = " << n << " -> " << SumaRecursiva(n) << endl;
    cout << "Para n = " << n2 << " -> " << SumaRecursiva(n2) << endl;
    cout << "Para n = " << n3 << " -> " << SumaRecursiva(n3) << endl;
    cout << endl;
        cout << ">>Suma Directa<<" << endl << "-------------------" << endl;
    cout << "Para n = " << n << " -> " << SumaDirecta(n) << endl;
    cout << "Para n = " << n2 << " -> " << SumaDirecta(n2) << endl;
    cout << "Para n = " << n3 << " -> " << SumaDirecta(n3) << endl;
    cout << endl;
    return 0;
}