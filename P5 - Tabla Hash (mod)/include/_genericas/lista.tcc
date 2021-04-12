#ifndef LISTA_H
#define LISTA_H

#include <set>
#include <iostream>
#include <algorithm> // find_if

/**
 * 
 * @verbatim Clase
 * @endverbatim
 * ----------------------------------------------------------------------------------------
 * */
using namespace std;
template<class Clave>
class Lista {
    private:
        set<Clave> _lista;
    
    protected:

        
    public:
        virtual ~Lista() {}
        Lista(): _lista(set<Clave>()) {}

        bool buscar(Clave& X) const;   // true si x está en la tabla, sen otro caso retorna 0
        bool insertar(const Clave& X); // true si puede insertar x en la tabla, si ya lo esta, retorn 0
        
        set<Clave> lista() { return _lista; }

        void print();

};

/**
 * ----------------------------------------------------------------------------------------
 * @verbatim Definiciones
 * @endverbatim
 * 
 * */

template<class Clave>
bool Lista<Clave>::buscar(Clave& X) const {
    if(_lista.find(X) != _lista.end()) { // el elemento ya existe
        cout << "Elemento: " (*_lista.find(X)) << endl;
        return true;
    } else {                             // el elemento no está en el set
        return false;
    }                               
}

template<class Clave>
bool Lista<Clave>::insertar(const Clave& X) {
    auto key = find_if(_lista.begin(), _lista.end(), X);
    if(key != _lista.end()) { // el elemento ya existe (no se puede insertar)
        return false; 
    } else {                             // el elemento no está en el set (se puede insertr)
        _lista.insert(X);
        return true;
    }
}

template<class Clave>
void Lista<Clave>::print() {
    for(auto clave = _lista.begin(); clave != _lista.end(); clave++) {
        if(clave != _lista.begin()) cout << ", ";
        cout << (*clave);
    }
}


#endif