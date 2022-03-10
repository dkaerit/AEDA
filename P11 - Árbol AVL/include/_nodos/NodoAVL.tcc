#ifndef NODOAVL_H
#define NODOAVL_H

using namespace std;

/**
 * 
 * @verbatim Cabecera
 * @endverbatim
 * ----------------------------------------------------------------------------------------
 * */

template<class Clave>
class nodoAVL {
    public:
        int dato, clave, bal;
        nodoAVL* izdo;
        nodoAVL* dcho;
    
    public:

        virtual ~nodoAVL() {}
        nodoAVL(const int dat, const int cl, nodoB* izq=NULL, nodoB* der=NULL): 
        dato(dat), clave(cl), bal(0), izdo(izq), dcho(der) {}

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