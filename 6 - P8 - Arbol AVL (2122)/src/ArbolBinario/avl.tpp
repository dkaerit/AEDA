#ifndef ARBOL_BINARIO_BUSQUEDA_BALANCEADO_H
#define ARBOL_BINARIO_BUSQUEDA_BALANCEADO_H
#include "abb.tpp"
#include "../Nodo/NodoAVL.tpp"
#include "../_auxiliar_/message.inl"
using namespace std;

/////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                             //
//                                       CABECERA                                              //
//                                                                                             //
/////////////////////////////////////////////////////////////////////////////////////////////////

template<class Key>
class AVL: public ABB<Key> {
    public:
        AVL(): ABB<Key>() {}

        // buscar insertar eliminar
        bool insertar(const Key&);
        bool eliminar(const Key&);

        // rotaciones
        void rotacion_II (NodoAVL<Key>*&);
        void rotacion_ID (NodoAVL<Key>*&);
        void rotacion_DI (NodoAVL<Key>*&);
        void rotacion_DD (NodoAVL<Key>*&);

    private:
        NodoAVL<Key>* getRoot() const { return reinterpret_cast<NodoAVL<Key>*>(ABB<Key>::getRaiz()); }
        NodoAVL<Key>*& getRoot(int i) { return reinterpret_cast<NodoAVL<Key>*&>(ABB<Key>::getRaiz(i)); }
        
        void inserta_bal(NodoAVL<Key>*& nodo, NodoAVL<Key>* nuevo, bool& crece);

        void insert_re_balancea_izda(NodoAVL<Key>*& nodo, bool &crece);
        void insert_re_balancea_dcha(NodoAVL<Key>*& nodo, bool &crece);

        void elimina_rama(NodoAVL<Key>*& nodo, const Key& k, bool& decrece);
        void sustituye(NodoAVL<Key>*& eliminado, NodoAVL<Key>*& sust, bool& decrece);

        void eliminar_re_balancea_dcha(NodoAVL<Key>* &nodo, bool& decrece);
        void eliminar_re_balancea_izda(NodoAVL<Key>* &nodo, bool& decrece);
};

/////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                             //
//                                     DEFINICIONES                                            //
//                                       inserción                                             //
//                                                                                             //
/////////////////////////////////////////////////////////////////////////////////////////////////

template<class Key>
bool AVL<Key>::insertar(const Key& k) {
    NodoAVL<Key>* nuevo = new NodoAVL<Key>(k, 0);
    bool crece = false;
    if(ABB<Key>::buscar(k)) return false;
    else {
        inserta_bal(getRoot(0), nuevo, crece);
        return true;
    }
}

template<class Key>
void AVL<Key>::inserta_bal(NodoAVL<Key>*& nodo, NodoAVL<Key>* nuevo, bool& crece) {
    if(nodo == nullptr) {
        nodo = nuevo;
        crece = true;
    }
    else if(nuevo->getDato() < nodo->getDato()) {
        inserta_bal(nodo->izdo(), nuevo, crece);
        if(crece) insert_re_balancea_izda(nodo,crece);
    }
    else {
        inserta_bal(nodo->dcho(), nuevo, crece);
        if(crece) insert_re_balancea_dcha(nodo,crece);
    }
}

template<class Key>
void AVL<Key>::insert_re_balancea_dcha(NodoAVL<Key>*& nodo, bool &crece) {
    switch (nodo->getBal()) {
        case  1: nodo->setBal( 0); crece = false; break; 
        case  0: nodo->setBal(-1); break; 
        case -1: 
            NodoAVL<Key>* nodo1 = nodo->dcho();
            (nodo1->getBal() == -1)? traza<Key>(DD, nodo->getDato()): traza<Key>(DI, nodo->getDato());
            (nodo1->getBal() == -1)? rotacion_DD(nodo): rotacion_DI(nodo);
            crece = false;
    }
}

template<class Key>
void AVL<Key>::insert_re_balancea_izda(NodoAVL<Key>*& nodo, bool &crece) {
    switch (nodo->getBal()) {
        case -1: nodo->setBal(0); crece = false; break; 
        case  0: nodo->setBal(1); break; 
        case  1: 
            NodoAVL<Key>* nodo1 = nodo->izdo();
            (nodo1->getBal() == 1)? traza<Key>(II, nodo->getDato()): traza<Key>(ID, nodo->getDato());
            (nodo1->getBal() == 1)? rotacion_II(nodo): rotacion_ID(nodo);
            crece = false;
    }

}



/////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                             //
//                                     DEFINICIONES                                            //
//                                     eliminación                                             //
//                                                                                             //
/////////////////////////////////////////////////////////////////////////////////////////////////

template<class Key>
bool AVL<Key>::eliminar(const Key& k) {
    bool decrece = false;    
    elimina_rama(getRoot(0), k, decrece);
    return true;
}

template<class Key>
void AVL<Key>::elimina_rama(NodoAVL<Key>*& nodo, const Key& k, bool& decrece) {
    if(nodo == nullptr) return;
    if(k < nodo->getDato()) {
        elimina_rama(nodo->izdo(), k, decrece);
        if(decrece) eliminar_re_balancea_izda(nodo,decrece);
    }
    else if(k > nodo->getDato()) {
        elimina_rama(nodo->dcho(), k, decrece);
        if(decrece) eliminar_re_balancea_dcha(nodo,decrece);
    } 
    else { // k == nodo->clave
        NodoAVL<Key>* elim = nodo;
        if (nodo->izdo() == nullptr) {
            nodo = nodo->dcho();
            decrece = true;
        }
        else if (nodo->dcho() == nullptr) {
            nodo = nodo->izdo();
            decrece = true;
        } 
        else {
            sustituye(elim, nodo->izdo(), decrece);
            if(decrece) eliminar_re_balancea_izda(nodo,decrece);
        }
        delete elim;
    }
}

template<class Key>
void AVL<Key>::sustituye(NodoAVL<Key>* &eliminado, NodoAVL<Key>* &sust, bool &decrece) {
    if (sust->dcho() != nullptr) { 
        sustituye(eliminado, sust->dcho(), decrece);
        if (decrece) 
        eliminar_re_balancea_dcha(sust, decrece);
    }
    else {
        eliminado->setDato(sust->getDato());
        eliminado = sust;
        sust = sust->izdo();
        decrece = true;
    }
}


template<class Key>
void AVL<Key>::eliminar_re_balancea_dcha(NodoAVL<Key>* &nodo, bool& decrece) {
    switch (nodo->getBal()) {
        case -1: nodo->setBal(0); break;
        case  0: nodo->setBal(1); decrece = false; break; 
        case  1: NodoAVL<Key>* nodo1 = nodo->izdo();
            (nodo1->getBal() < 0)? traza<Key>(ID, nodo->getDato()): traza<Key>(II, nodo->getDato());
            if (nodo1->getBal() < 0) rotacion_ID(nodo);
            else {
                if (nodo1->getBal() == 0) decrece = false;
                rotacion_II(nodo);
            }
    }
}

template<class Key>
void AVL<Key>::eliminar_re_balancea_izda(NodoAVL<Key>* &nodo, bool& decrece) {
    switch (nodo->getBal()) {
        case  1: nodo->setBal(0); break;
        case  0: nodo->setBal(-1); decrece = false; break; 
        case -1: NodoAVL<Key>* nodo1 = nodo->dcho();
            (nodo1->getBal() > 0)? traza<Key>(DI, nodo->getDato()): traza<Key>(DD, nodo->getDato());
            if (nodo1->getBal() > 0) rotacion_DI(nodo);
            else {
                if (nodo1->getBal() == 0) decrece = false;
                rotacion_DD(nodo);
            }
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                             //
//                                     DEFINICIONES                                            //
//                                      rotaciones                                             //
//                                                                                             //
/////////////////////////////////////////////////////////////////////////////////////////////////

template<class Key>
void AVL<Key>::rotacion_II(NodoAVL<Key>*& nodo) {
    NodoAVL<Key>* nodo1 = nodo->izdo();
    nodo->setIzdo(nodo1->dcho());
    nodo1->setDcho(nodo);
    if (nodo1->getBal() == 1) {
        nodo->setBal(0);
        nodo1->setBal(0);
    }
    else { // nodo1->bal == 0
        nodo->setBal(1);
        nodo1->setBal(-1);
    }
    nodo = nodo1;
}

template<class Key>
void AVL<Key>::rotacion_ID(NodoAVL<Key>*& nodo) {
    NodoAVL<Key>* nodo1 = nodo->izdo();
    NodoAVL<Key>* nodo2 = nodo1->dcho();
    nodo->setIzdo(nodo2->dcho());
    nodo2->setDcho(nodo);
    nodo1->setDcho(nodo2->izdo());
    nodo2->setIzdo(nodo1);    
    if (nodo2->getBal() == -1) nodo1->setBal(1);
    else nodo1->setBal(0);
    if (nodo2->getBal() == 1) nodo->setBal(-1);
    else nodo->setBal(0);
    nodo2->setBal(0);
    nodo = nodo2;
}

template<class Key>
void AVL<Key>::rotacion_DI(NodoAVL<Key>*& nodo) {
    NodoAVL<Key>* nodo1 = nodo->dcho();
    NodoAVL<Key>* nodo2 = nodo1->izdo();
    nodo->setDcho(nodo2->izdo());
    nodo2->setIzdo(nodo);
    nodo1->setIzdo(nodo2->dcho());
    nodo2->setDcho(nodo1);
    if (nodo2->getBal() == 1) nodo->setBal(-1);
    else nodo->setBal(0);
    if (nodo2->getBal() == -1) nodo1->setBal(1);
    else nodo1->setBal(0);
    nodo2->setBal(0);
    nodo = nodo2;
}

template<class Key>
void AVL<Key>::rotacion_DD(NodoAVL<Key>*& nodo) {
    NodoAVL<Key>* nodo1 = nodo->dcho();
    nodo->setDcho(nodo1->izdo());
    nodo1->setIzdo(nodo);
    if (nodo1->getBal() == -1) {
        nodo->setBal(0);
        nodo1->setBal(0);
    }
    else { // nodo1->bal == 0
        nodo->setBal(-1);
        nodo1->setBal(1);
    }
    nodo = nodo1;
}

#endif