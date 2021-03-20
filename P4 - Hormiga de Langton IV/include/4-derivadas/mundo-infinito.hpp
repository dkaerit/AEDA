#ifndef MUNDOINFFINITO_H
#define MUNDOINFFINITO_H

#include "../3-polimorfismos/mundo.hpp"

class MundoInfinito: public Mundo { // vector expansible
    public:
        virtual ~MundoInfinito() {}
        MundoInfinito(int,int);
        
        void expandir();
        void handlerAntOverflow();
};

#endif