#ifndef FN_DISPERSION_H
#define FN_DISPERSION_H

/**
 * 
 * @verbatim Clase
 * @endverbatim
 * ----------------------------------------------------------------------------------------
 * */

template<class Clave>
class fnDispersion {
    protected:  
        
    public:
        virtual ~fnDispersion() {}
        fnDispersion() {}

        virtual unsigned operator() (const Clave& k) const = 0;
};

/**
 * ----------------------------------------------------------------------------------------
 * @verbatim Definiciones
 * @endverbatim
 * 
 * */

#endif