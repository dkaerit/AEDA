#ifndef ARBOL_BINARIO_H
#define ARBOL_BINARIO_H
#include "../Nodo/NodoBinario.tpp"
#include "../_auxiliar_/array.tpp"
using namespace std;

/////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                             //
//                                       CABECERA                                              //
//                                                                                             //
/////////////////////////////////////////////////////////////////////////////////////////////////

template<class Key>
class AB {
    private:
        NodoB<Key>* _raiz;

    protected:
        NodoB<Key>* getRaiz() const { return _raiz; }
        void setRaiz(NodoB<Key>* raiz) { _raiz = raiz; }
        void podar(NodoB<Key>* nodo);  

    public:
        AB(): _raiz(nullptr) {}
        ~AB() { podar(_raiz); }  

        virtual bool buscar(const Key& k) const = 0;
        virtual bool insertar(const Key& k) = 0;
        virtual bool eliminar(const Key& k) = 0;

        virtual void byLevel() const = 0;
        virtual void inorden() const = 0;
        //void preorden() const = 0;
        //void postorden() const = 0;

        template <class shadow> friend ostream& operator<<(ostream&, AB<shadow>&);
};

/////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                             //
//                                     DEFINICIONES                                            //
//                                                                                             //
/////////////////////////////////////////////////////////////////////////////////////////////////


template<class Key>
ostream& operator<<(ostream& os, AB<Key>& a) {
    a.byLevel();
    return os;
}

template<class Key>
void AB<Key>::podar(NodoB<Key>* nodo) {
    if(nodo) {
        podar(nodo->getIzdo());
        podar(nodo->getDcho());
        delete nodo;
        nodo = nullptr;
    }
}


#endif