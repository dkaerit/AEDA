#ifndef MUNDOINFFINITO_H
#define MUNDOINFFINITO_H

#include "../3-polimorfismos/mundo.hpp"

enum frontera { ARRIBA = 0, ABAJO = 1, DERECHA = 2, IZQUIERDA = 3 };

/**
 * 
 * @verbatim Clase
 * @endverbatim
 * ------------------------------------------------------------------------------------------
 * */

class MundoInfinito: public Mundo { // vector expansible
    public:
        virtual ~MundoInfinito() {}
        MundoInfinito(int,int);
        
    private:
        void expandir(int frontera);
        void handlerAntOverflow(anthill& ants, cell& c);
};

/**
 * ------------------------------------------------------------------------------------------ 
 * @verbatim Definiciones
 * @endverbatim
 * 
 * */

MundoInfinito::MundoInfinito(int min, int max) {
    _malla.resize(
        min,max, evector<cell>(
        min,max, make_pair(make_pair(0,0),WHITE))
    );
    markCells();
}

void MundoInfinito::handlerAntOverflow(anthill& ants, cell& c) {
    int ant_x, ant_y;

    const int MIN_ACHURA = _malla[_malla.suplim()-1].sublim(); 
    const int MAX_ACHURA = _malla[_malla.suplim()-1].suplim(); 
    const int MIN_ALTURA = _malla.sublim();                    
    const int MAX_ALTURA = _malla.suplim();                    

    for(auto ant: ants) {
        ant_x = ant->getPos().second; // coordenada y de la hormiga
        ant_y = ant->getPos().first;  // coordenada x de la hormiga
        
        // eje vertical
        if(ant_x <=  MIN_ALTURA   ) expandir(ARRIBA);    // arriba
        if(ant_x >= (MAX_ALTURA-1)) expandir(ABAJO);     // abajo

        // eje horizontal
        if(ant_y <=  MIN_ACHURA   ) expandir(IZQUIERDA); // izquierda
        if(ant_y >= (MAX_ACHURA-1)) expandir(DERECHA);   // derecha
    }
}

void MundoInfinito::expandir(int frontera) {
    
    const int MIN_ACHURA = _malla[_malla.suplim()-1].sublim(); 
    const int MAX_ACHURA = _malla[_malla.suplim()-1].suplim(); 

    switch(frontera) {
        case ARRIBA: 
            _malla.push_front(evector<cell>(
                MIN_ACHURA, MAX_ACHURA-1,
                make_pair(make_pair(0,0),WHITE))); 
                break;
        
        case ABAJO:  
            _malla.push_back(evector<cell>( 
                MIN_ACHURA, MAX_ACHURA-1,
                make_pair(make_pair(0,0),WHITE)));    
            break;
        
        case DERECHA:
            for(int i = _malla.sublim(); i < _malla.suplim(); i++) 
                _malla[i].push_back(make_pair(make_pair(0,0),WHITE));
                break;

        case IZQUIERDA:
            for(int i = _malla.sublim(); i < _malla.suplim(); i++) 
                _malla[i].push_front(make_pair(make_pair(0,0),WHITE));
                break;
    }
}

#endif