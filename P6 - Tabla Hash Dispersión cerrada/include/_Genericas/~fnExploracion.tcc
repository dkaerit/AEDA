#ifndef FN_EXPLORACION_H
#define FN_EXPLORACION_H

/**
 * 
 * @verbatim Clase
 * @endverbatim
 * ----------------------------------------------------------------------------------------
 * */

template<class Clave>
class fnExploracion {
    protected:  
        
    public:
        virtual ~fnExploracion() {}
        fnExploracion() {}

        virtual unsigned operator() (const Clave& k, unsigned i) const = 0;
};

/**
 * ----------------------------------------------------------------------------------------
 * @verbatim Definiciones
 * @endverbatim
 * 
 * */

#endif