#ifndef FE_REDISPESION_H
#define FE_REDISPESION_H

#include "../_genericas/~fnExploracion.tcc"

/**
 * 
 * @verbatim Clase
 * @endverbatim
 * ----------------------------------------------------------------------------------------
 * */

template<class Clave>
class feReDispersion: public fnExploracion<Clave> {
    private:
        fnDispersion<Clave>* _fd;
        
    public:
        virtual ~feReDispersion() {}
        feReDispersion(fnDispersion<Clave>* fd): _fd(fd) {}
        unsigned operator() (const Clave& k, unsigned i) const {
            unsigned value; 
            srand(k);

            for(int j = 0; j < i; ++j) value = rand();

            return ((++i)*((*_fd)(value))); 
        }
};

/**
 * ----------------------------------------------------------------------------------------
 * @verbatim Definiciones
 * @endverbatim
 * 
 * */

#endif