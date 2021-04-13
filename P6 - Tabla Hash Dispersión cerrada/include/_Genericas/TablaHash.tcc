#ifndef TABLA_HASH_H
#define TABLA_HASH_H

#include <iostream>
#include <deque>
#include <iomanip>
#include "~fnDispersion.tcc"
#include "~fnExploracion.tcc"
#include "../_Contenedores/vector.tcc"
#include "../_Contenedores/lista.tcc"

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
        unsigned              _nDatos; // dimensión de la tabla (celdas de contenedores
        deque<Lista<Clave>>   _vDatos; // Define la estructura de celdas de contenedores
        fnDispersion<Clave>*  _fd;     // Define la clase función para accesar datos
        fnExploracion<Clave>* _fe;     // Define la clase función para revaluar posicion

    public:
        virtual ~TablaHash() {}
        TablaHash(unsigned size, unsigned n, fnDispersion<Clave>* fd, fnExploracion<Clave>* fe);

        bool buscar(Clave& X) const;   // true si x está en la tabla, en otro caso retorna 0
        bool insertar(const Clave& X); // true si puede insertar x en la tabla, si ya lo esta, retorn 

        void print();
    
    protected:
        bool agregar(const Clave& X, unsigned dir);
        bool encontrar(Clave& X, unsigned dir) const;
        bool mr(bool l, const string& s, int dir = -1) const;

};

/**
 * ----------------------------------------------------------------------------------------
 * @verbatim Definiciones
 * @endverbatim
 * 
 * */


template<class Clave>
TablaHash<Clave>::TablaHash(unsigned size, unsigned n, fnDispersion<Clave>* fd, fnExploracion<Clave>* fe):
_fd(fd), 
_fe(fe),
_nDatos(size),
_vDatos(deque<Lista<Clave>>(size, Lista<Clave>(n))) {}


template<class Clave>
bool TablaHash<Clave>::buscar(Clave& X) const {
    unsigned base = (*_fd)(X);  // direccion base
    unsigned otra = base;       // dirección de los futuros candidatos

    do {
        if(!_vDatos[otra].buscar(X)) {
            if(!_vDatos[otra].estaLleno()) return encontrar(X,otra);
            if( _vDatos[otra].estaLleno()) otra = ((*_fe)(X,otra))%_nDatos; 
        } else return mr(true, "[✔] Se ha encontrado en la dirección: ", otra);
    } while(otra != base); // de vuelta a la celda inicial
    
    return mr(false, "[✘] Tabla rastreada al completo sin éxito ");

}

template<class Clave>
bool TablaHash<Clave>::insertar(const Clave& X) {
    unsigned base = (*_fd)(X); // direccion base
    unsigned otra = base;      // dirección de los futuros candidatos

    do {
        if(_vDatos[otra].insertar(X)) {
            if(!_vDatos[otra].estaLleno()) return agregar(X,otra);
            if( _vDatos[otra].estaLleno()) otra = ((*_fe)(X,otra))%_nDatos; 
        } else return mr(false, "[✘] Ya se ha insertado esa clave en: ", otra); // ya existe en esa celda
    } while(otra != base); // de vuelta a la celda inicial
    
    return mr(false, "[✘] Tabla llena ");

}

template<class Clave>
bool TablaHash<Clave>::mr(bool l, const string& s, int dir) const {
    cout << s;
    if(dir != -1) {
        cout << dir;
        cout << " (" << &_vDatos[dir] << ")";
    }
    cout << "\n";

    return l;
}

template<class Clave>
bool TablaHash<Clave>::agregar(const Clave& X, unsigned dir) {
    _vDatos[dir].lista().insert(X);
    return mr(true, "[✔] Insertado en la dirección: ", dir);
}

template<class Clave>
bool TablaHash<Clave>::encontrar(Clave& X, unsigned dir) const {
    cout << "Elemento: " << _vDatos[dir].find(X);
    return mr(true, "[✘] Encontrado con éxito en: ", dir);
}

template<class Clave>
void TablaHash<Clave>::print() {
    for(int i = 0; i < _nDatos; i++) {
        cout << "[" << setw(2) << i << "]: ";
        _vDatos[i].print(); 
        cout << endl;
    }
}





#endif