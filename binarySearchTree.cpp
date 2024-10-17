class Nodo {
public:
    Nodo(long long valor) {
        accesos = 0;
        ip = valor;
        progenitore = nullptr;
        izquierdo = nullptr;
        derecho = nullptr;
    }
    long long ip = 0;
    int accesos = 0;
    Nodo* progenitore;
    Nodo* izquierdo;
    Nodo* derecho;
};

//233.169.24.95