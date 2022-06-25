#ifndef ARBOL_BINARIO_EQUILIBRADO_H
#define ARBOL_BINARIO_EQUILIBRADO_H
#define nullnode "[     ]";
#include "~ab.tpp"
#include <stdexcept> // runtime_error
using namespace std;

/////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                             //
//                                       CABECERA                                              //
//                                                                                             //
/////////////////////////////////////////////////////////////////////////////////////////////////

template<class Key>
class ABE: public AB<Key> {
    public:
        ABE(): AB<Key>() {}

        // buscar insertar eliminar
        bool buscar(const Key&) const;
        bool insertar(const Key&);
        bool eliminar(const Key&);

        // tamaño, altura, equilibrio
        const int  tam() const { return tamRama(AB<Key>::getRaiz()); }
        const int  alt() const { return altRama(AB<Key>::getRaiz()); }
        const bool equ() const { return equRama(AB<Key>::getRaiz()); }

        // recorridos
        void byLevel() const;
        void inorden() const { inordenRama(AB<Key>::getRaiz()); }
        //void preorden() const;
        //void postorden() const;

    private:
        const int  tamRama(NodoB<Key>*) const;
        const int  altRama(NodoB<Key>*) const;
        const bool equRama(NodoB<Key>*) const;

        void inordenRama(NodoB<Key>*) const;
        
        NodoB<Key>* buscarRama(const Key&, NodoB<Key>*) const;
        NodoB<Key>* insertarRama(const Key&, NodoB<Key>*);

        bool esVacio(NodoB<Key>* nodo) { return nodo?false:true; }
        bool esHoja(NodoB<Key>* nodo) { return nodo?(!nodo->getDcho() && !nodo->getIzdo()):true; }
};

/////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                             //
//                                     DEFINICIONES                                            //
//                              tamaño, altura, equilibrio                                     //
//                                                                                             //
/////////////////////////////////////////////////////////////////////////////////////////////////

// @brief Calcula el tamaño de una rama del árbol.
// @param nodo: nodo del que se parte para calcular el tamaño
// @return: int: tamaño de la rama

template<class Key>
const int ABE<Key>::tamRama(NodoB<Key>* nodo) const {
    return nodo ? (1+tamRama(nodo->getIzdo())) + tamRama(nodo->getDcho()) : 0;
}

// @brief Calcula la altura de una rama del árbol.
// @param nodo: nodo del que se parte para calcular la altura
// @return: int: altura de la rama

template<class Key>
const int ABE<Key>::altRama(NodoB<Key>* nodo) const {
    if(nodo) {
        int i = altRama(nodo->getIzdo());
        int d = altRama(nodo->getDcho());
        return (d > i)? ++d : ++i;
    } else return 0;
}



// @brief Calcula la equilibrio de una rama del árbol.
// @param nodo: nodo del que se parte para calcular el equilibrio
// @return: bool: true si la rama está equilibrada, false en caso contrario

template<class Key>
const bool ABE<Key>::equRama(NodoB<Key>* nodo) const {
    if(nodo) {
        switch(tamRama(nodo->izdo) - tamRama(nodo->dcho)) {
            case -1:
            case  0:
            case  1:
            return (equRama(nodo->izdo) && equRama(nodo->dcho));
        }
    } else return true;
}

/////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                             //
//                                     DEFINICIONES                                            //
//                            búsqueda, inserción eliminación                                  //
//                                                                                             //
/////////////////////////////////////////////////////////////////////////////////////////////////

// @brief Busca un elemento en el árbol.
// @param k Key del elemento a buscar.
// @return true si el elemento está en el árbol, false en caso contrario.

template<class Key>
bool ABE<Key>::buscar(const Key& k) const {
    return buscarRama(k, AB<Key>::getRaiz()) != nullptr;
}

// @breif: Busca un nodo con la Key k en el arbol.
// @param: k: Key a buscar.
// @return: NodoB<Key>*: puntero al nodo con la Key k.

template<class Key>
NodoB<Key>* ABE<Key>::buscarRama(const Key& k, NodoB<Key>* nodo) const {
    if(nodo) {
        if(nodo->getDato() == k) return nodo;
        else {
            NodoB<Key>* izdo = buscarRama(k, nodo->getIzdo());
            NodoB<Key>* dcho = buscarRama(k, nodo->getDcho());
            if(izdo != nullptr && izdo->getDato() == k) return izdo;
            if(dcho != nullptr && dcho->getDato() == k) return dcho;
        }
    }

    return nullptr;
}


// @brief Inserta un elemento en el árbol.
// @param k Key del elemento a insertar.
// @return true si el elemento se insertó, false en caso contrario.

template<class Key>
bool ABE<Key>::insertar(const Key& k) {
    if(buscar(k)) return false;
    else {
        if(AB<Key>::getRaiz()) insertarRama(k, AB<Key>::getRaiz());
        else AB<Key>::setRaiz(new NodoB<Key>(k));
        return true;
    }
}

// @brief Inserta un nodo con la Key k en el arbol.
// @param k: Key a insertar.
// @param nodo: puntero al nodo a insertar.
// @return: NodoB<Key>*: puntero al nodo insertado.

template<class Key>
NodoB<Key>* ABE<Key>::insertarRama(const Key& k, NodoB<Key>* nodo) {
    if(nodo) {
        if(tamRama(nodo->getDcho()) > tamRama(nodo->getIzdo())) {
            if(nodo->getIzdo()) insertarRama(k, nodo->getIzdo());
            else nodo->setIzdo(new NodoB<Key>(k));
        } else {
            if(nodo->getDcho()) insertarRama(k, nodo->getDcho()); 
            else nodo->setDcho(new NodoB<Key>(k));  
        }
    }
    return nodo;
}

// @brief Elimina un elemento en el árbol.
// @param k Key del elemento a eliminar.
// @return true si el elemento se eliminó, false en caso contrario.

template<class Key>
bool ABE<Key>::eliminar(const Key& k) {
    if(!buscar(k)) return false;
    else throw runtime_error("Eliminación no implementada");
}

/////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                             //
//                                     DEFINICIONES                                            //
//                                      recorridos                                             //
//                                                                                             //
/////////////////////////////////////////////////////////////////////////////////////////////////

// @brief Realiza recorrido por niveles

template<class Key>
void ABE<Key>::byLevel() const {
    Array<NodoB<Key>*> Q;
    NodoB<Key>* nodo;
    int actual = 0, spaces = 0;
    int nv = actual;

    Q.insertar(AB<Key>::getRaiz(),0); // insertar raiz
    cout << "\nNivel " << actual << ": ";
    while(!Q.empty()) { // mientras haya nodos que explorar
        Q.extraer(nodo,nv); // actualizar nodo y nivel
        if(nv > actual) { // cuando el nivel supere el actual
            actual = nv;
            cout << "\nNivel " << actual << ": ";
        } 

        //for(int i = 0; i <= ((alt()*7)/(nv+1))-7; ++i) cout << " ";
        if(nodo) {
            cout << "[ " << *nodo << " ]";
            Q.insertar(nodo->getIzdo(),nv+1);
            Q.insertar(nodo->getDcho(),nv+1);
        } else {
            cout << nullnode; // imprimir nodo vacío
        }
    }
}

// @brief recorrido en inorden del arbol.
// @param nodo: nodo a partir del cual se realiza el recorrido.

template<class Key>
void ABE<Key>::inordenRama(NodoB<Key>* nodo) const {
    if(nodo) {
        inordenRama(nodo->getIzdo());
        cout << *nodo << ", ";
        inordenRama(nodo->getDcho());
    }
}


#endif