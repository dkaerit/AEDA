#ifndef VECTOR_H
#define VECTOR_H

#include <deque>
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
class Vector {
    private:
        deque<Clave> _lista;
        unsigned     _nSinonimos;
        
    public:
        virtual ~Vector() {}
        Vector(int n): _lista(deque<Clave>()), _nSinonimos(n) {}

        bool buscar(Clave& X) const;   // true si x está en la tabla, sen otro caso retorna 0
        bool insertar(const Clave& X); // true si puede insertar x en la tabla, si ya lo esta, retorn 0
        bool estaLleno() const;        // true si esta lleno, false si no lo está
        
        deque<Clave> lista() { return _lista; }

        void print();

};

/**
 * ----------------------------------------------------------------------------------------
 * @verbatim Definiciones
 * @endverbatim
 * 
 * */

template<class Clave>
bool Vector<Clave>::buscar(Clave& X) const {
                              
}

template<class Clave>
bool Vector<Clave>::insertar(const Clave& X) {

}


template<class Clave>
bool Vector<Clave>::estaLleno() const {
    if(_nSinonimos < _lista.size()) return false; // no esta lleno
    else                           return true;  // está lleno
}

template<class Clave>
void Vector<Clave>::print() {

}


#endif