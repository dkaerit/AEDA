#ifndef ARBOL_BINARIO_BUSQUEDA_H
#define ARBOL_BINARIO_BUSQUEDA_H
#include "~ab.tpp"
using namespace std;

template<class Key>
class ABB: public AB<Key> {
    public:
        ABB(): AB<Key>() {}

        // buscar insertar eliminar
        bool buscar(const Key& k) const { return buscarRama(k, AB<Key>::getRaiz()) != nullptr; }
        bool insertar(const Key& k);
        bool eliminar(const Key& k); 

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
        NodoB<Key>* buscarRama(const Key&, NodoB<Key>*) const;
        NodoB<Key>* insertarRama(const Key&, NodoB<Key>*);
        NodoB<Key>* eliminarRama(const Key&, NodoB<Key>*);

        void inordenRama(NodoB<Key>*) const;
        void preordenRama(NodoB<Key>*) const;
        void postordenRama(NodoB<Key>*) const;

        NodoB<Key>* sustituye(NodoB<Key>*);
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
NodoB<Key>* ABB<Key>::sustituye(NodoB<Key>* sust) {
    if(sust->getIzdo()->getIzdo() != nullptr) {
        sustituye(sust->getIzdo());
    } else {
        NodoB<Key>* aux = sust->getIzdo();
        sust->setIzdo(nullptr);
        return aux;
    }
    return sust;
}

// @brief Elimina un nodo en el árbol.
// @param k: clave del nodo a eliminar.
// @return: true si se pudo eliminar, false si no se pudo.

template <class Key>
bool ABB<Key>::eliminar(const Key& k) {
    // el elemento buscado está en la raiz
    if(AB<Key>::getRaiz() && k == AB<Key>::getRaiz()->getDato()) {
        // si es nodo hoja
        if(AB<Key>::esHoja(AB<Key>::getRaiz())) {
            AB<Key>::setRaiz(nullptr);
            return true;
        }
    }

    return eliminarRama(k, AB<Key>::getRaiz()) != nullptr;
}


// @brief Elimina un nodo en el árbol.
// @param k: clave del nodo a eliminar.
// @param nodo: nodo del que se parte para eliminar el nodo.
// @return: nodo eliminado o nullptr si no se pudo eliminar.

template <class Key>
NodoB<Key>* ABB<Key>::eliminarRama(const Key& k, NodoB<Key>* nodo) {
    if(!nodo) return nullptr;

    // el elemento buscado está en el hijo derecho
    else if(nodo->getDcho() && k == nodo->getDcho()->getDato()) {
        // si el hijo derecho es nodo hoja
        if(AB<Key>::esHoja(nodo->getDcho())) {
            delete nodo->getDcho();
            nodo->setDcho(nullptr);
            return nodo;
        }

        // si el hijo derecho tiene dos hijos
        else if(nodo->getDcho()->getDcho() && nodo->getDcho()->getIzdo()) {
            NodoB<Key>* sust = sustituye(nodo->getDcho()->getDcho());
            sust->setDcho(nodo->getDcho()->getDcho());
            sust->setIzdo(nodo->getDcho()->getIzdo());
            nodo->setDcho(sust);
            return nodo;
        }

        // si el hijo derecho tiene un hijo derecho
        else if(nodo->getDcho()->getDcho()) {
            nodo->setDcho(nodo->getDcho()->getDcho());
            return nodo;
        }

        // si el hijo derecho tiene un hijo izquierdo
        else if(nodo->getDcho()->getIzdo()) {
            nodo->setDcho(nodo->getDcho()->getIzdo());
            return nodo;
        }


    }

    // el elemento buscado está en el hijo izquierdo
    else if(nodo->getIzdo() && k == nodo->getIzdo()->getDato()) {
        // el hijo izquierdo es nodo hoja
        if(AB<Key>::esHoja(nodo->getIzdo())) {
            delete nodo->getIzdo();
            nodo->setIzdo(nullptr);
            return nodo;
        }

        // si el hijo izquierdo tiene dos hijos
        else if(nodo->getIzdo()->getDcho() && nodo->getIzdo()->getIzdo()) {
            NodoB<Key>* sust = sustituye(nodo->getIzdo()->getDcho());
            sust->setDcho(nodo->getIzdo()->getDcho());
            sust->setIzdo(nodo->getIzdo()->getIzdo());
            nodo->setIzdo(sust);
            return nodo;
        }

        // el hijo izquierdo tiene 1 hijo derecho
        else if(nodo->getIzdo()->getDcho()) {
            nodo->setIzdo(nodo->getIzdo()->getDcho());
            return nodo;
        }

        // el hijo izquierdo si tiene 1 hijo izquierdo
        else if(nodo->getIzdo()->getIzdo()) {
            nodo->setIzdo(nodo->getIzdo()->getIzdo());
            return nodo;
        }
    }

    else if(k  < nodo->getDato()) return eliminarRama(k, nodo->getIzdo());
    else if(k  > nodo->getDato()) return eliminarRama(k, nodo->getDcho());

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