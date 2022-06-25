#ifndef TABLA_HASH_H
#define TABLA_HASH_H

#include <iostream>
#include <deque>
#include "~fndispersion.tcc"
#include "lista.tcc"
using namespace std;

/**
 * 
 * @verbatim Clase
 * @endverbatim
 * ----------------------------------------------------------------------------------------
 * */

template<class Clave>
class TablaHash {
    private:
        unsigned             _nDatos; // dimensión de la tabla (celdas de contenedores)
        deque<Lista<Clave>>  _vDatos; // Define la estructura de celdas de contenedores
        fnDispersion<Clave>* _fd;     // Define la clase función para accesar datos

    protected:
      

    public:
        virtual ~TablaHash() {}
        TablaHash(unsigned n, fnDispersion<Clave>* fd);

        bool buscar(Clave& X) const;   // true si x está en la tabla, en otro caso retorna 0
        bool insertar(const Clave& X); // true si puede insertar x en la tabla, si ya lo esta, retorn 0

        void print();

};

/**
 * ----------------------------------------------------------------------------------------
 * @verbatim Definiciones
 * @endverbatim
 * 
 * */


template<class Clave>
TablaHash<Clave>::TablaHash(unsigned n, fnDispersion<Clave>* fd):
_fd(fd), 
_nDatos(n),
_vDatos(deque<Lista<Clave>>(n, Lista<Clave>())) {}


template<class Clave>
bool TablaHash<Clave>::buscar(Clave& X) const {
    unsigned dir = (*_fd)(X);
    if(_vDatos[dir].buscar(X)) { 
        // posicion de memoria en la tabla / dirección de memoria real
        //cout << "[✔] Se ha encontrado en la dirección: " << dir << " (" << &_vDatos[dir] << ")" << endl;
        return true;
    } else {
        //cout << "[✘] No existe esa clave en la tabla: " << dir << " (" << &_vDatos[dir] << ")" << endl;
        return false;
    }
}

template<class Clave>
bool TablaHash<Clave>::insertar(const Clave& X) {
    unsigned dir = (*_fd)(X);

    if(_vDatos[dir].insertar(X)) { 
        cout << "[✔] Insertado en la dirección: " << dir << " (" << &_vDatos[dir] << ")" << endl;
        return true;
    } else {
        cout << "[✘] Ya se ha insertado esa clave en: " << dir << " (" << &_vDatos[dir] << ")" << endl;
        return false;
    }

}

template<class Clave>
void TablaHash<Clave>::print() {
    for(int i = 0; i < _nDatos; i++) {
        cout << "[" << i << "]: ";
        _vDatos[i].print(); 
        cout << endl;
    }
}





#endif