#ifndef MUNDOFINITO_H
#define MUNDOFINITO_H

#include "../3-polimorfismos/mundo.hpp"

class MundoFinito: public Mundo { // dimensiones constantes
    public:
        virtual ~MundoFinito() {}
        MundoFinito(int,int);

        void handlerAntOverflow();

};

#endif