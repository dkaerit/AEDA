#ifndef ARBOL_BINARIO_BUSQUEDA_H
#define ARBOL_BINARIO_BUSQUEDA_H
#include "~ab.tpp"
using namespace std;

template<class Key>
class ABB: public AB<Key> {
    public:
        ABB(): AB<Key>() {}

        // buscar insertar eliminar
        virtual bool buscar(const Key& k) const { return buscarRama(k, AB<Key>::getRaiz()) != nullptr; }
        virtual bool insertar(const Key& k);
        virtual bool eliminar(const Key& k); 

        // tamaño, altura
        const int  tam() const { return AB<Key>::tamRama(AB<Key>::getRaiz()); }
        const int  alt() const { return AB<Key>::altRama(AB<Key>::getRaiz()); }

        // recorridos
        void preorden() const { preordenRama(AB<Key>::getRaiz()); }
        void inorden() const { inordenRama(AB<Key>::getRaiz()); }
        void postorden() const { postordenRama(AB<Key>::getRaiz()); }

        // impresión
        void write(ostream& os = cout) const;

    private:
        NodoB<Key>* sustituye(NodoB<Key>*&, NodoB<Key>*&);
        NodoB<Key>* eliminarRama(const Key&, NodoB<Key>*&);
        NodoB<Key>* insertarRama(const Key&, NodoB<Key>*);
        NodoB<Key>* buscarRama(const Key&, NodoB<Key>*) const;

        void inordenRama(NodoB<Key>*) const;
        void preordenRama(NodoB<Key>*) const;
        void postordenRama(NodoB<Key>*) const;

        
};

/////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                             //
//                                     DEFINICIONES                                            //
//                            búsqueda, inserción eliminación                                  //
//                                                                                             //
/////////////////////////////////////////////////////////////////////////////////////////////////

// @brief Busca un nodo en el árbol.
// @param k: clave del nodo a buscar.
// @param nodo: nodo del que se parte para buscar el nodo.
// @return: nodo encontrado o nullptr si no se encuentra.

template <class Key>
NodoB<Key>* ABB<Key>::buscarRama(const Key& k, NodoB<Key>* nodo) const {
    if(nodo) {
        if(k == nodo->getDato()) return nodo;
        else return (k < nodo->getDato()) ? buscarRama(k, nodo->getIzdo()) : buscarRama(k, nodo->getDcho());
    }
    return nullptr;
}


template <class Key>
bool ABB<Key>::insertar(const Key& k) {
    if(buscar(k)) return false;
    else {
        if(AB<Key>::getRaiz()) insertarRama(k, AB<Key>::getRaiz());
        else AB<Key>::setRaiz(new NodoB<Key>(k));
        return true;
    }
}

// @brief Inserta un nodo en el árbol.
// @param k: clave del nodo a insertar.
// @param nodo: nodo del que se parte para insertar el nodo.
// @return: nodo insertado o nullptr si no se pudo insertar.

template <class Key>
NodoB<Key>* ABB<Key>::insertarRama(const Key& k, NodoB<Key>* nodo) {
    if(!nodo) return new NodoB<Key>(k);
    else {
        if(k < nodo->getDato()) nodo->setIzdo(insertarRama(k, nodo->getIzdo()));
        else nodo->setDcho(insertarRama(k, nodo->getDcho()));
        return nodo;
    }
}

template <class Key>
NodoB<Key>* ABB<Key>::sustituye(NodoB<Key>*& elim, NodoB<Key>*& sust) {
    if(sust->getDcho() != nullptr) return sustituye(elim, sust->getDcho());
    else {
        elim->setDato(sust->getDato());
        elim = sust;
        sust = sust->getIzdo();
        return new NodoB<Key>(0);
    }

}

// @brief Elimina un nodo en el árbol.
// @param k: clave del nodo a eliminar.
// @return: true si se pudo eliminar, false si no se pudo.

template <class Key>
bool ABB<Key>::eliminar(const Key& k) {
    return eliminarRama(k, AB<Key>::getRaiz(0)) != nullptr;
}


// @brief Elimina un nodo en el árbol.
// @param k: clave del nodo a eliminar.
// @param nodo: nodo del que se parte para eliminar el nodo.
// @return: nodo eliminado o nullptr si no se pudo eliminar.

template <class Key>
NodoB<Key>* ABB<Key>::eliminarRama(const Key& k, NodoB<Key>*& nodo) {
    //NodoB<Key>* nodo = nodo;
    if(nodo == nullptr) return nullptr;
    if(k < nodo->getDato()) return eliminarRama(k, nodo->getIzdo()); else 
    if(k > nodo->getDato()) return eliminarRama(k, nodo->getDcho());
    else {
        NodoB<Key>* elim = nodo;
        if (nodo->getDcho() == nullptr) nodo = nodo->getIzdo(); else 
        if (nodo->getIzdo() == nullptr) nodo = nodo->getDcho();
        else return sustituye(elim, nodo->getIzdo());
        delete (elim);
        return new NodoB<Key>(0);
    }   
    return nullptr;
}

/////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                             //
//                                     DEFINICIONES                                            //
//                              preorden, inorden, postorden                                   //
//                                                                                             //
/////////////////////////////////////////////////////////////////////////////////////////////////

// @brief Recorre el árbol en preorden.
// @param nodo: nodo del que se parte para recorrer el árbol.

template <class Key>
void ABB<Key>::inordenRama(NodoB<Key>* nodo) const {
    if (nodo) {
        inordenRama(nodo->getIzdo());
        cout << *nodo << ", ";
        inordenRama(nodo->getDcho());
    }
}

// @brief Recorre el árbol en preorden.
// @param nodo: nodo del que se parte para recorrer el árbol.

template <class Key>
void ABB<Key>::preordenRama(NodoB<Key>* nodo) const {
    if (nodo) {
        cout << *nodo << ", ";
        preordenRama(nodo->getIzdo());
        preordenRama(nodo->getDcho());
    }
}

// @brief Recorre el árbol en postorden.
// @param nodo: nodo del que se parte para recorrer el árbol.

template <class Key>
void ABB<Key>::postordenRama(NodoB<Key>* nodo) const {
    if (nodo) {
        postordenRama(nodo->getIzdo());
        postordenRama(nodo->getDcho());
        cout << *nodo << ", ";
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                             //
//                                     DEFINICIONES                                            //
//                                        write                                                //
//                                                                                             //
/////////////////////////////////////////////////////////////////////////////////////////////////

template <class Key>
void ABB<Key>::write(ostream& os) const {
    if(AB<Key>::getRaiz()) {
        os << "Preorden: ";
        preordenRama(AB<Key>::getRaiz());
        os << endl;
        os << "Inorden: ";
        inordenRama(AB<Key>::getRaiz());
        os << endl;
        os << "Postorden: ";
        postordenRama(AB<Key>::getRaiz());
        os << endl;
        AB<Key>::byLevel();   
    }
    else os << "El arbol esta vacio" << endl;
}



#endif