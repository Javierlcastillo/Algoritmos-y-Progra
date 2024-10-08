#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

struct Registro {
    int ano;
    int mes;
    int dia;
    string hora;
    string ip;
    string mensaje;
};
void imprimirRegistro(const Registro& reg) {
    cout << "Año: " << reg.ano << endl;
    cout << "Mes: " << reg.mes << endl;
    cout << "Día: " << reg.dia << endl;
    cout << "Hora: " << reg.hora << endl;
    cout << "IP: " << reg.ip << endl;
    cout << "Mensaje: " << reg.mensaje << endl;
}

class Nodo {
public: 
    Registro datos; 
    Nodo* siguiente;
    Nodo* anterior;
    Nodo(Registro dataValue) {
        datos = dataValue;
        siguiente = nullptr;
        anterior = nullptr; 
    }
    Registro getDatos() {
        return datos;
    }
};

class ListaLigada {
    Nodo *cabeza;
    Nodo *finLista;
    int tamanio; 
public:
    ListaLigada() {
        cabeza = nullptr;
    }
    void crear(Registro valor) {
        if (cabeza == nullptr) {
            cabeza = new Nodo(valor);
            finLista = cabeza;
        }
        else{
            Nodo *nuevo = new Nodo(valor);
            nuevo->anterior = finLista;
            finLista->siguiente = nuevo;
            finLista = nuevo;
        }
        tamanio++;
    
    }
    void imprimeLista() {
        Nodo *nodoActual = cabeza;
        while (nodoActual != nullptr) {
            Registro tmp = nodoActual->datos;
            cout << "elemento " << endl;
            imprimirRegistro(tmp);
            nodoActual = nodoActual->siguiente;
        }
        cout << endl;   
    }
    Nodo* getNodo(int indice) {
        Nodo* nodoActual = cabeza;
        int contador = 0;
        for(int i = 0; i < indice-1; i++) {
            if(nodoActual != nullptr) {
                nodoActual = nodoActual->siguiente;
                contador++;
            }
        }
        if(contador == indice-1) {
            return nodoActual;
        } else {
            return nullptr;
        }
    }
    /*Nodo getElemento(int indice){
        Nodo* nodoActual = cabeza;
        int contador = 0;
        for (int i = 0; i < indice-1; i++){
            if (nodoActual != nullptr){
                nodoActual = nodoActual-> siguiente;
                contador++;
            }
        }
        if(contador == indice-1){
            return nodoActual->datos;
        } else{
            return -1;
        }

    }*/
    int dameTamano(){
        return tamanio;
    }

    ~ListaLigada() {
        Nodo* nodoActual = cabeza;
        while (nodoActual) {
            Registro tmp = nodoActual->datos; 
            Nodo* temp = nodoActual;
            nodoActual = nodoActual->siguiente;
            delete temp;
        }

    }
};

ListaLigada leerArchivo(const string& nombreArchivo) {
    ListaLigada registros;
    ifstream archivo(nombreArchivo);
    string linea;

    if(archivo.is_open()) {
        while(getline(archivo, linea)) {
            Registro registro;
            istringstream iss(linea);
            string token;
            
            //procesa la fecha y la hora
            getline(iss, token, '|');
            istringstream fechaHora(token);
            fechaHora >> registro.ano >> registro.mes >> registro.dia >> registro.hora;

            //procesa la ip
            getline(iss, token, '|');
            registro.ip = token.substr(token.find(":") + 1);

            //procesa el mensaje de la bitacora
            getline(iss, token, '|');
            registro.mensaje = token.substr(token.find(":") + 1);

            registros.crear(registro);
        }
        archivo.close();
    } else {
        cerr << "No se pudo abrir el archivo: " << nombreArchivo << endl;
    }
    return registros;
}

int main() {
    ListaLigada datosRegistrados;
    datosRegistrados = leerArchivo("ips_en_rango.txt");
    datosRegistrados.imprimeLista();    
}
