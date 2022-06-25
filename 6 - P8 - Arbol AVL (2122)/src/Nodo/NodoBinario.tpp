#ifndef NODO_BINARIO_H
#define NODO_BINARIO_H
#include <iostream>
#include <iomanip>
using namespace std;

/////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                             //
//                                       CABECERA                                              //
//                                                                                             //
/////////////////////////////////////////////////////////////////////////////////////////////////

template<class Key>
class NodoB {
    protected:
        Key    _dato;
        NodoB* _izdo;
        NodoB* _dcho;

    public:
        NodoB(const Key dat, NodoB* izq=nullptr, NodoB* der=nullptr): _dato(dat), _izdo(izq), _dcho(der) {}
        ~NodoB() { delete _izdo; delete _dcho; }

        Key getDato() { return _dato; }
        virtual NodoB*& getIzdo() { return _izdo; }
        virtual NodoB*& getDcho() { return _dcho; }
        void setDato(Key dato) { _dato = dato; }
        void setIzdo(NodoB* izdo) { _izdo = izdo; }
        void setDcho(NodoB* dcho) { _dcho = dcho; }

        ostream& write(ostream& os = cout);
        template <class shadow> friend ostream& operator<<(ostream&, NodoB<shadow>&);
};  

/////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                             //
//                                     DEFINICIONES                                            //
//                                                                                             //
/////////////////////////////////////////////////////////////////////////////////////////////////

// @brief Imprime el NodoB
// @param os Flujo de salida
// @return Flujo de salida 

template<class Key>
ostream& NodoB<Key>::write(ostream& os) {
    os << setw(3) << _dato;
    return os;
}

// @brief Imprime el NodoB
// @param os Flujo de salida
// @param n NodoB a imprimir
// @return Flujo de salida

template <class shadow>
ostream& operator<<(ostream& os, NodoB<shadow>& n) {
    n.write(os);
    return os;
}


#endif