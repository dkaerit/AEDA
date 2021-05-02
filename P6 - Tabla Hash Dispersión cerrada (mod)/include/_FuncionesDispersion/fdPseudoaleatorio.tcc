#ifndef FD_PSEUDOALEATORIO_H
#define FD_PSEUDOALEATORIO_H

#include "../_genericas/~fnDispersion.tcc"
#include <cstdlib> // RAND_MAX

/**
 * 
 * @verbatim Clase
 * @endverbatim
 * ----------------------------------------------------------------------------------------
 * */

template<class Clave>
class fdPseudoaleatorio: public fnDispersion<Clave> {
    private:
        unsigned _nDatos;
        
    public:
        virtual ~fdPseudoaleatorio() {}
        fdPseudoaleatorio(const unsigned n): _nDatos(n) {}
        unsigned operator() (const Clave& k) const { 
            srand(k);
            return (rand()%_nDatos); 
        }
};

/**
 * ----------------------------------------------------------------------------------------
 * @verbatim Definiciones
 * @endverbatim
 * 
 * */

#endif