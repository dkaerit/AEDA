#ifndef MUNDOFINITO_H
#define MUNDOFINITO_H

#include "mundo.hpp"

class MundoFinito: public Mundo { 
    public:
        MundoFinito(int w, int h);
        virtual ~MundoFinito();

        void mirrored(int fromwhat, Hormiga& ant); 
        void nextState(anthill& ants);
};

#endif 