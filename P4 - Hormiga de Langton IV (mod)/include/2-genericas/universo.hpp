#ifndef UNIVERSO_H
#define UNIVERSO_H

#include <ctime>        // semilla variable
#include <unistd.h>

#include "../3-polimorfismos/hormiga.hpp"
#include "../3-polimorfismos/mundo.hpp"

/**
 * 
 * @verbatim Clase
 * @endverbatim
 * ------------------------------------------------------------------------------------------
 * */

class Universo {
    private:
        anthill _ants;
        Mundo*  _world;
        
    public:
        virtual ~Universo() {}
        Universo(anthill& ants, Mundo* world):
            _ants(ants), _world(world) {}

        void comenzar();
        void actualizar(); 
};

/**
 * ------------------------------------------------------------------------------------------ 
 * @verbatim Definiciones
 * @endverbatim
 * 
 * */

void Universo::comenzar() {
    for(;;) actualizar();
}

void Universo::actualizar() {
    _world->to_s(_ants);
    _world->actualizar(_ants);
    
}

#endif 