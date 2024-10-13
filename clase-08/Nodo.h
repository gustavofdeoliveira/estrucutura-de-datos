#include <iostream>

class Nodo {
    private: 
        int dato;
        Nodo* sig;
        
    public:
    // Constructor
        Nodo(int dato);

    int getDato();

    void setDato(int dato);

    Nodo* getSig();

    void setSig(Nodo* sig);
    // Destructor
    ~Nodo();

};