#ifndef NODOB_H
#define NODOB_H

using namespace std;

/**
 * 
 * @verbatim Cabecera
 * @endverbatim
 * ----------------------------------------------------------------------------------------
 * */

template<class Clave>
class nodoB {
    public:
        int dato;
        int clave;
        nodoB* izdo;
        nodoB* dcho;
    
    public:

        virtual ~nodoB() {}
        nodoB(const int dat, const int cl, nodoB* izq=NULL, nodoB* der=NULL): 
        dato(dat), clave(cl), izdo(izq), dcho(der) {}

        friend ostream& operator<<(ostream& os, nodoB& node) {
            return "[" << node->dato << "] ";
        }
};

/**
 * ----------------------------------------------------------------------------------------
 * @verbatim Definiciones
 * @endverbatim
 * 
 * */

#endif