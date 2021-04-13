#ifndef FE_LINEAL_H
#define FE_LINEAL_H

#include "../_Genericas/~fnExploracion.tcc"

/**
 * 
 * @verbatim Clase
 * @endverbatim
 * ----------------------------------------------------------------------------------------
 * */

template<class Clave>
class feLineal: public fnExploracion<Clave> {
    private:
        
    public:
        virtual ~feLineal() {}
        feLineal() {}
        unsigned operator() (const Clave& k, unsigned i) const { 
            return (++i); 
        }
};

/**
 * ----------------------------------------------------------------------------------------
 * @verbatim Definiciones
 * @endverbatim
 * 
 * */

#endif