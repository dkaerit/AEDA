#ifndef FE_CUADRATICA_H
#define FE_CUADRATICA_H

#include "../_genericas/~fnExploracion.tcc"
#include <cmath>

using namespace std;

/**
 * 
 * @verbatim Clase
 * @endverbatim
 * ----------------------------------------------------------------------------------------
 * */

template<class Clave>
class feCuadratica: public fnExploracion<Clave> {
    private:
        
    public:
        virtual ~feCuadratica() {}
        feCuadratica() {}
        unsigned operator() (const Clave& k, unsigned i) const { 
            return ((++i)*(++i)); 
        }
};

/**
 * ----------------------------------------------------------------------------------------
 * @verbatim Definiciones
 * @endverbatim
 * 
 * */

#endif