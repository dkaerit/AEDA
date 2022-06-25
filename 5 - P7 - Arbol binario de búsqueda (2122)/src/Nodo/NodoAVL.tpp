#ifndef NODO_AVL_H
#define NODO_AVL_H
#include "NodoBinario.tpp"
using namespace std;

/////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                             //
//                                       CABECERA                                              //
//                                                                                             //
/////////////////////////////////////////////////////////////////////////////////////////////////

template<class Key>
class NodoAVL: public NodoB<Key> {
    private:
        int _bal; // factor de blanceo del nodo (diferencia de alturas de sus subarboles)

    public:
        NodoAVL(const Key dat, int bal=0, NodoAVL* izq=nullptr, NodoAVL* der=nullptr): 
        NodoB<Key>(dat, izq, der), _bal(bal) {}

        int getBal() { return _bal; }
        void setBal(int bal) { _bal = bal; }

        NodoAVL*& izdo() { return reinterpret_cast<NodoAVL*&>(NodoB<Key>::getIzdo()); }
        NodoAVL*& dcho() { return reinterpret_cast<NodoAVL*&>(NodoB<Key>::getDcho()); }

        ostream& write(ostream& os = cout);
        template <class shadow> friend ostream& operator<<(ostream&, NodoAVL<shadow>&);
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
ostream& NodoAVL<Key>::write(ostream& os) {
    os << setw(3) << NodoB<Key>::getDato();
    return os;
}

// @brief Imprime el NodoB
// @param os Flujo de salida
// @param n NodoB a imprimir
// @return Flujo de salida

template <class shadow>
ostream& operator<<(ostream& os, NodoAVL<shadow>& n) {
    n.write(os);
    return os;
}

#endif