#ifndef FD_MODULO_H
#define FD_MODULO_H

#include "../_genericas/~fnDispersion.tcc"

/**
 * 
 * @verbatim Clase
 * @endverbatim
 * ----------------------------------------------------------------------------------------
 * */

template<class Clave>
class fdModulo: public fnDispersion<Clave> {
    private:
        unsigned _nDatos;
        
    public:
        virtual ~fdModulo() {}
        fdModulo(const unsigned n): _nDatos(n) {}
        unsigned operator() (const Clave& k) const { return (k%_nDatos); }
};

/**
 * ----------------------------------------------------------------------------------------
 * @verbatim Definiciones
 * @endverbatim
 * 
 * */

#endif