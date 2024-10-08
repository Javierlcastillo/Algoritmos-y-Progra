/*
 * Descripción breve del programa:
 * Este programa lee un archivo de bitácora, ordena los registros basados en las direcciones IP
 * utilizando el algoritmo Merge Sort, y permite buscar un rango de IPs específicas
 * usando una búsqueda binaria. Los registros encontrados en el rango se guardan en un archivo de salida.
 *
 * Autores: Armando Chavez Villarreal, Javier Luis Castillo, Renato Lopez
 * Matrículas: A01720866, A01658415, A01640057
 * Fecha de creación: 05/09/2024
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <string>

/*
 * Estructura: Registro
 * Descripción: Representa un registro de la bitácora con los campos de año, mes, día, hora, IP y mensaje.
 */
struct Registro {
    std::string año;
    std::string mes;
    std::string dia;
    std::string hora;
    std::string ip;
    std::string mensaje;

};

/*
 * Función: leerArchivo
 * Descripción: Lee un archivo de bitácora y devuelve un vector con los registros leídos.
 * Parámetros:
 *     - const std::string& nombreArchivo: Nombre del archivo de bitácora a leer.
 * Valor de retorno:
 *     - std::vector<Registro>: Vector de registros leídos desde el archivo.
 * Complejidad de tiempo:
 *     - O(n), donde n es el número de líneas en el archivo.
 * Complejidad de espacio:
 *     - O(n), donde n es el número de registros en el archivo.
 */
std::vector<Registro> leerArchivo(const std::string& nombreArchivo) {
    std::vector<Registro> registros;
    std::ifstream archivo(nombreArchivo);
    std::string linea;

    if (archivo.is_open()) {
        while (std::getline(archivo, linea)) {
            Registro registro;
            std::istringstream iss(linea);
            std::string token;

            // Procesa la fecha y hora
            std::getline(iss, token, '|');
            std::istringstream fechaHora(token);
            fechaHora >> registro.año >> registro.mes >> registro.dia >> registro.hora;

            // Procesa la IP
            std::getline(iss, token, '|');
            registro.ip = token.substr(token.find(":") + 1);

            // Procesa el mensaje de la bitácora
            std::getline(iss, token, '|');
            registro.mensaje = token.substr(token.find(":") + 1);

            registros.push_back(registro); // Agrega el registro al vector
        }
        archivo.close();
    } else {
        std::cerr << "No se pudo abrir el archivo: " << nombreArchivo << std::endl;
    }

    return registros;
}

/*
 * Función: descomponerIP
 * Descripción: Descompone una dirección IP en sus cuatro partes numéricas.
 * Parámetros:
 *     - const std::string& ip: Dirección IP en formato de cadena.
 * Valor de retorno:
 *     - std::tuple<int, int, int, int>: Tupla con las cuatro partes de la IP.
 * Complejidad de tiempo:
 *     - O(1)
 * Complejidad de espacio:
 *     - O(1)
 */
std::tuple<int, int, int, int> descomponerIP(const std::string& ip) {
    std::istringstream iss(ip);
    int a;
    int b;
    int c;
    int d;
    char punto; // Para ignorar los puntos en la IP
    iss >> a >> punto >> b >> punto >> c >> punto >> d;
    return std::make_tuple(a, b, c, d);
}

/*
 * Función: compararRegistros
 * Descripción: Compara dos registros en función de sus direcciones IP.
 * Parámetros:
 *     - const Registro& r1: Primer registro a comparar.
 *     - const Registro& r2: Segundo registro a comparar.
 * Valor de retorno:
 *     - bool: True si la IP de r1 es menor que la de r2, False en caso contrario.
 * Complejidad de tiempo:
 *     - O(1)
 * Complejidad de espacio:
 *     - O(1)
 */
bool compararRegistros(const Registro& r1, const Registro& r2) {
    return descomponerIP(r1.ip) < descomponerIP(r2.ip);
}

/*
 * Función: merge
 * Descripción: Realiza la mezcla (merge) de dos sub-vectores de registros en el algoritmo Merge Sort.
 * Parámetros:
 *     - std::vector<Registro>& registros: Vector de registros a ordenar.
 *     - int inicio: Índice inicial del sub-vector.
 *     - int medio: Índice medio del sub-vector.
 *     - int fin: Índice final del sub-vector.
 * Complejidad de tiempo:
 *     - O(n), donde n es el número de elementos en los dos sub-vectores.
 * Complejidad de espacio:
 *     - O(n), ya que se utilizan dos vectores temporales.
 */
void merge(std::vector<Registro>& registros, int inicio, int medio, int fin) {
    int n1 = medio - inicio + 1;
    int n2 = fin - medio;

    std::vector<Registro> izquierda(n1);
    std::vector<Registro> derecha(n2);

    for (int i = 0; i < n1; i++){
        izquierda[i] = registros[inicio + i];
    }
    for (int j = 0; j < n2; j++){
        derecha[j] = registros[medio + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = inicio;

    // Mezcla los dos sub-vectores
    while (i < n1 && j < n2) {
        if (compararRegistros(izquierda[i], derecha[j])) {
            registros[k] = izquierda[i];
            i++;
        } else {
            registros[k] = derecha[j];
            j++;
        }
        k++;
    }

    // Copia los elementos restantes de izquierda, si los hay
    while (i < n1) {
        registros[k] = izquierda[i];
        i++;
        k++;
    }

    // Copia los elementos restantes de derecha, si los hay
    while (j < n2) {
        registros[k] = derecha[j];
        j++;
        k++;
    }
}

/*
 * Función: mergeSort
 * Descripción: Ordena un vector de registros utilizando el algoritmo Merge Sort.
 * Parámetros:
 *     - std::vector<Registro>& registros: Vector de registros a ordenar.
 *     - int inicio: Índice inicial del vector.
 *     - int fin: Índice final del vector.
 * Complejidad de tiempo:
 *     - O(n log n), donde n es el número de registros.
 * Complejidad de espacio:
 *     - O(n), por los vectores temporales usados durante la mezcla.
 */
void mergeSort(std::vector<Registro>& registros, int inicio, int fin) {
    if (inicio < fin) {
        int medio = inicio + (fin - inicio) / 2;

        // Ordena ambas mitades
        mergeSort(registros, inicio, medio);
        mergeSort(registros, medio + 1, fin);

        // Mezcla las dos mitades
        merge(registros, inicio, medio, fin);
    }
}

/*
 * Función: busquedaBinaria
 * Descripción: Realiza una búsqueda binaria para encontrar la posición de una dirección IP en el vector de registros.
 * Parámetros:
 *     - const std::vector<Registro>& registros: Vector de registros ordenados.
 *     - const std::string& ip: Dirección IP a buscar.
 * Valor de retorno:
 *     - int: Índice del registro que contiene la IP, o -1 si no se encuentra.
 * Complejidad de tiempo:
 *     - O(log n), donde n es el número de registros.
 * Complejidad de espacio:
 *     - O(1)
 */
int busquedaBinaria(const std::vector<Registro>& registros, const std::string& ip) {
    int izquierda = 0;
    int derecha = registros.size() - 1;

    while (izquierda <= derecha) {
        int medio = izquierda + (derecha - izquierda) / 2;
        if (compararRegistros({ "", "", "", "", ip, "" }, registros[medio])) {
            derecha = medio - 1;
        } else if (compararRegistros(registros[medio], { "", "", "", "", ip, "" })) {
            izquierda = medio + 1;
        } else {
            return medio;
        }
    }
    return -1; 
}

int main() {
    // Leer registros desde el archivo de bitácora
    std::vector<Registro> registros = leerArchivo("bitacoraelb.txt");

    // Ordenar registros por dirección IP
    mergeSort(registros, 0, registros.size() - 1);

    // Solicitar al usuario el rango de IPs
    std::string ipInicio;
    std::string ipFin;
    std::cout << "Ingrese la IP de inicio: ";
    std::cin >> ipInicio;
    std::cout << "Ingrese la IP de fin: ";
    std::cin >> ipFin;

    // Buscar las posiciones de las IPs en el rango
    int posInicio = busquedaBinaria(registros, ipInicio);
    int posFin = busquedaBinaria(registros, ipFin);

    //Verificar que sí existan las IPs
    if (posInicio != -1 && posFin != -1) {

        if(posInicio>posFin){
            std::cerr << "La IP de inicio es mayor que el del final" << std::endl;
        } else{
            // Crear archivo de salida
            std::ofstream archivoSalida("salida.txt");
            for (int i = posInicio; i <= posFin; ++i) {
                archivoSalida << registros[i].año << " " << registros[i].mes << " " << registros[i].dia << " "
                            << registros[i].hora << " | IP:" << registros[i].ip << " | INFO:" << registros[i].mensaje << std::endl;
            }
            archivoSalida.close();
            std::cout << "Los registros se han guardado en el archivo 'salida.txt'." << std::endl;
        } 

    } else {
        std::cout << "No se encontraron registros en el rango especificado." << std::endl;
    }
        
    return 0;
}


