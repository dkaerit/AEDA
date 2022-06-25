#ifndef ARBOL_BINARIO_EQUILIBRADO_H
#define ARBOL_BINARIO_EQUILIBRADO_H
#include <string>
#include <cmath>
#include <stdexcept> // runtime_error
#include "~ab.tpp"
#include "../_auxiliar_/array.tpp"
#include "../_auxiliar_/color.inl"
#include "../_auxiliar_/helpers.inl"
using namespace std;
static const string nullnode = " .... ";

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

        void write() const;

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
        if(altRama(nodo->getDcho()) > altRama(nodo->getIzdo())) {
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
    int actual, nv;

    Q.insertar(0,AB<Key>::getRaiz()); // insertar raiz
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

/////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                             //
//                                     DEFINICIONES                                            //
//                                      impresión                                              //
//                                                                                             //
/////////////////////////////////////////////////////////////////////////////////////////////////

// @brief Impresión del arvol como grafico

template <class Key>
void ABE<Key>::write() const {
    // crear matriz de strings
    Array<Array<string>> mat(alt()+1, Array<string>(0));
    Array<NodoB<Key>*> Q;
    NodoB<Key>* nodo;
    string spaces;
    ostringstream os;
    int nv, h, x;

    Q.insertar(0, AB<Key>::getRaiz()); // insertar raiz

    while(!Q.empty()) { // mientras haya nodos que explorar
        Q.extraer(nv,nodo); // actualizar nodo y nivel 
        x = alt() - nv;
        h = (pow(x,3)+5*x)/2; // heurística para calcular número de espacios
        spaces = string(h,' '); // n spaces   

        os.str("");
        if(nodo) {
            os << spaces << " " << setw(4) << centered(to_string(nodo->getDato())) << " " << spaces;
            mat[nv].pushBack(os.str());
            Q.insertar(nv+1, nodo->getIzdo());
            Q.insertar(nv+1, nodo->getDcho());
        } else {
            os << spaces << BOLD_CYAN << nullnode << RESET << spaces;
            mat[nv].pushBack(os.str());
            if(nv+1 < mat.size()) {
                os.str("");
                x = alt()-(nv+1);
                h = (pow(x,3)+5*x)/2;
                spaces = string(h,' '); // n spaces  
                os << spaces << BOLD_CYAN << nullnode << RESET << spaces;
                mat[nv+1].pushBack(os.str());
                mat[nv+1].pushBack(os.str());
            }
        }
        
        spaces = ""; // reset spaces      
    }

    string li, ld; int z = 0, iz, de, s, t;
    // imprimir matriz
    for(auto &[i, row]: mat.getBase()) {
        for(auto &[j, col]: row.getBase()) cout << col;
        cout << endl;

        if(z < mat.size()-1) {
            li = ""; ld = "";
            x = alt()-z;
            iz = 2*pow(x,2)-3*x+2;
            de = iz+1;
            //s = (3*pow(x,2)-3*x)/2+3;
            //s = pow(x,2)+2;
            s = ((5*pow(x,3)+55*x)/6)-4*pow(x,2)-3;

            for(int k = 0; k < iz; k++) li += "─";
            for(int k = 0; k < de; k++) ld += "─";
            spaces = string(s,' '); // n spaces  
            t = ((pow(z,3)+5*z)/6)+1;
            for(int k = 0; k < t; k++)
            cout << spaces << "┌" << li << "┸" << ld << "┐" << spaces;
        }

        cout << endl;
        z++;
    }

}

#endif