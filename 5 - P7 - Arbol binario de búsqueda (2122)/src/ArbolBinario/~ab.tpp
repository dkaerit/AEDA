#ifndef ARBOL_BINARIO_H
#define ARBOL_BINARIO_H
#include "../Nodo/NodoBinario.tpp"
#include "../_auxiliar_/array.tpp"
using namespace std;
static const string nullnode = " .... ";

/////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                             //
//                                       CABECERA                                              //
//                                                                                             //
/////////////////////////////////////////////////////////////////////////////////////////////////

template<class Key>
class AB {
    private:
        NodoB<Key>* _raiz;

    public:
        AB(): _raiz(nullptr) {}
        ~AB() { podar(_raiz); }  

        virtual bool buscar(const Key& k) const = 0;
        virtual bool insertar(const Key& k) = 0;
        virtual bool eliminar(const Key& k) = 0;

        virtual void byLevel() const;
        virtual void inorden() const = 0;
        //void preorden() const = 0;
        //void postorden() const = 0;

        virtual void write(ostream& os = cout) const { byLevel(); }
        template <class shadow> friend ostream& operator<<(ostream&, AB<shadow>&);

    protected:
        NodoB<Key>* getRaiz() const { return _raiz; }
        NodoB<Key>*& getRaiz(int i) { return _raiz; }
        void setRaiz(NodoB<Key>* raiz) { _raiz = raiz; }
        void podar(NodoB<Key>* nodo);  

        const int tamRama(NodoB<Key>*) const;
        const int altRama(NodoB<Key>*) const;

        bool esVacio(NodoB<Key>* nodo) { return nodo?false:true; }
        bool esHoja(NodoB<Key>* nodo) { return nodo?(!nodo->getDcho() && !nodo->getIzdo()):true; }
};

/////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                             //
//                                     DEFINICIONES                                            //
//                                     write, podar                                            //    
//                                                                                             //
/////////////////////////////////////////////////////////////////////////////////////////////////

// @brief Calcula el tamaño de una rama del árbol.
// @param nodo: nodo del que se parte para calcular el tamaño
// @param a: árbol
// @return: ostream&: flujo de salida

template<class Key>
ostream& operator<<(ostream& os, AB<Key>& a) {
    a.write();
    return os;
}

// @brief poda una rama del árbol
// @param nodo: nodo del que se parte para podar

template<class Key>
void AB<Key>::podar(NodoB<Key>* nodo) {
    if(nodo) {
        podar(nodo->getIzdo());
        podar(nodo->getDcho());
        delete nodo;
        nodo = nullptr;
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                             //
//                                     DEFINICIONES                                            //
//                                    tamaño, altura                                           //
//                                                                                             //
/////////////////////////////////////////////////////////////////////////////////////////////////

// @brief Calcula el tamaño de una rama del árbol.
// @param nodo: nodo del que se parte para calcular el tamaño
// @return: int: tamaño de la rama

template<class Key>
const int AB<Key>::tamRama(NodoB<Key>* nodo) const {
    return nodo ? (1+tamRama(nodo->getIzdo())) + tamRama(nodo->getDcho()) : 0;
}

// @brief Calcula la altura de una rama del árbol.
// @param nodo: nodo del que se parte para calcular la altura
// @return: int: altura de la rama

template<class Key>
const int AB<Key>::altRama(NodoB<Key>* nodo) const {
    if(nodo) {
        int i = altRama(nodo->getIzdo());
        int d = altRama(nodo->getDcho());
        return (d > i)? ++d : ++i;
    } else return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                             //
//                                     DEFINICIONES                                            //
//                                      recorridos                                             //
//                                                                                             //
/////////////////////////////////////////////////////////////////////////////////////////////////

// @brief Realiza recorrido por niveles

template<class Key>
void AB<Key>::byLevel() const {
    Array<NodoB<Key>*> Q;
    NodoB<Key>* nodo;
    int actual, nv;

    Q.insertar(0,_raiz); // insertar raiz
    cout << "\nNivel " << actual << ": ";
    while(!Q.empty()) { // mientras haya nodos que explorar
        Q.extraer(nv,nodo); // actualizar nodo y nivel
        if(nv > actual) { // cuando el nivel supere el actual
            actual = nv;
            cout << "\nNivel " << actual << ": ";
        } 

        if(nodo) {
            cout << "[ " << *nodo << " ]";
            Q.insertar(nv+1,nodo->getIzdo());
            Q.insertar(nv+1,nodo->getDcho());
        } else cout << nullnode; // imprimir nodo vacío
    }
}


#endif