#ifndef UNIVERSO_H
#define UNIVERSO_H

#include "hormiga.hpp"
#include "mundo-infinito.hpp"
#include "mundo-finito.hpp"

template<class T>
class Universo {
    private:
        anthill _ants;
        T       _world;
        
    public:
        Universo(anthill& ants, T& world);
        virtual ~Universo();

        void start();
};

template<class T>
Universo<T>::~Universo() {}

template<class T>
Universo<T>::Universo(anthill& ants, T& world):
_ants(ants), _world(world) {}

template<class T>
void Universo<T>::start() {
    for(;;) {
        _world.print(_ants); 
        _world.nextState(_ants);
    }
}

#endif 