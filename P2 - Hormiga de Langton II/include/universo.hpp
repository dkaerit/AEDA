#ifndef UNIVERSO_H
#define UNIVERSO_H

#include "hormiga.hpp"
#include "mundo.hpp"

class Universo {
    private:
        anthill _ants;
        Mundo _world;
        
    public:
        Universo(anthill& ants, Mundo& world);
        virtual ~Universo();

        void start();
};

#endif 