#ifndef MUNDOINFFINITO_H
#define MUNDOINFFINITO_H

#include "mundo.hpp"

class MundoInfinito: public Mundo {
    public:
        MundoInfinito(int w, int h);
        virtual ~MundoInfinito();

        void increase(int fromwhat); 
        void nextState(anthill& ants);
};

#endif 