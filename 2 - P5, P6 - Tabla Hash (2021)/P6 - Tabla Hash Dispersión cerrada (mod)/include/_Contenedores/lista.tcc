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
        unsigned   _nSinonimos;

    public:
        virtual ~Lista() {}
        Lista(int sinonimos = 0);

        bool buscar(Clave& X) const;   // true si x está en la tabla, sen otro caso retorna 0
        bool insertar(const Clave& X); // true si puede insertar x en la tabla, si ya lo esta, retorn 0
        bool estaLleno() const;        // true si esta lleno, false si no lo está

        set<Clave>& lista() { return _lista; }
        const Clave find(const Clave& X) const { return (*_lista.find(X)); }

        void print();

};

/**
 * ----------------------------------------------------------------------------------------
 * @verbatim Definiciones
 * @endverbatim
 * 
 * */

template<class Clave>
Lista<Clave>::Lista(int sinonimos): _lista(set<Clave>()) {
    if(sinonimos > 0) _nSinonimos = sinonimos;
}

template<class Clave>
bool Lista<Clave>::buscar(Clave& X) const {
    //auto key = find_if(_lista.begin(), _lista.end(), X);
    if(_lista.find(X) != _lista.end()) { 
        return true;  // el elemento ya existe  
    } else {                             
        return false; // el elemento no está en el set
    }                               
}

template<class Clave>
bool Lista<Clave>::insertar(const Clave& X) {
    //auto key = find_if(_lista.begin(), _lista.end(), X);
    if(_lista.find(X) != _lista.end()) {
        return false; // el elemento ya existe (no se puede insertar)
    } else {
        return true;  // el elemento no está en el set (se puede insertr)
    }                              
}

template<class Clave>
bool Lista<Clave>::estaLleno() const {
    if(_lista.size() < _nSinonimos) return false; // no esta lleno
    else                            return true;  // está lleno
}

template<class Clave>
void Lista<Clave>::print() {
    cout << "MAX: " << _nSinonimos << " → ";
    for(auto clave = _lista.begin(); clave != _lista.end(); clave++) {
        if(clave != _lista.begin()) cout << ", ";
        cout << (*clave);
    }
}


#endif