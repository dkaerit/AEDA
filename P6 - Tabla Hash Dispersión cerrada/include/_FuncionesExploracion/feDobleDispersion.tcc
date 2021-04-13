#ifndef FE_DOBLEDISPERSION_H
#define FE_DOBLEDISPERSION_H

#include "../_genericas/~fnExploracion.tcc"

/**
 * 
 * @verbatim Clase
 * @endverbatim
 * ----------------------------------------------------------------------------------------
 * */

template<class Clave>
class feDobleDispersion: public fnExploracion<Clave> {
    private:
        fnDispersion<Clave>* _fd;

    public:
        virtual ~feDobleDispersion() {}
        feDobleDispersion(fnDispersion<Clave>* fd): _fd(fd) {}
        unsigned operator() (const Clave& k, unsigned i) const { 
            return ((++i)*((*_fd)(k))); 
        }
};

/**
 * ----------------------------------------------------------------------------------------
 * @verbatim Definiciones
 * @endverbatim
 * 
 * */

#endif