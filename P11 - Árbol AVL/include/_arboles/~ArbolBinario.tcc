#ifndef AB_H
#define AB_H

#include <deque>
#include "../__auxiliares/colors.inl"
#include "../_nodos/NodoBinario.tcc"
#include "../_otros/cola.tcc"
using namespace std;

#define nullnode "[" << BOLD_CYAN << "null" << RESET << "] ";

/**
 * 
 * @verbatim Cabecera
 * @endverbatim
 * ----------------------------------------------------------------------------------------
 * */

template<class Clave>
class AB {
    protected:
        nodoB<Clave>* _raiz;
    
    public:
        virtual ~AB() { podar(_raiz); }
        AB(): _raiz(NULL) {}

        //inserciones y búsquedas
        nodoB<Clave>* buscar(Clave& x);
        nodoB<Clave>* buscarRama(Clave& x, nodoB<Clave>* nodo);

        void insertar(const Clave& x);
        void insertarRama(const Clave& x, nodoB<Clave>* nodo);

        // iniciales
        void podar(nodoB<Clave>* &nodo);
        bool esVacio(nodoB<Clave>* nodo);
        bool esHoja(nodoB<Clave>* nodo);

        // tamaño, altura, equilibrio
        const int  tam() { return tamRama(_raiz); }
        const int  alt() { return altNivl(_raiz); }
        const bool equ() { return equRama(_raiz); }
        
        // recorridos
        void inorden() { inordenRama(_raiz); } 
        void recorre() { recorreRama(_raiz); }
        void recorreN();

    private:   
        const bool equRama(nodoB<Clave>* nodo);
        const int  tamRama(nodoB<Clave>* nodo);
        const int  altNivl(nodoB<Clave>* nodo);

        void   recorreRama(nodoB<Clave>* nodo);
        void   inordenRama(nodoB<Clave>* nodo);

        
        
        
};

/**
 * ----------------------------------------------------------------------------------------
 * @verbatim Definiciones
 * @endverbatim
 * 
 * */

template<class Clave>
nodoB<Clave>* AB<Clave>::buscar(Clave& x) {
    return buscarRama(x, _raiz);
}

template<class Clave>
nodoB<Clave>* AB<Clave>::buscarRama(Clave& x, nodoB<Clave>* nodo) {
    if(nodo) {
        if(nodo->dato == x) return nodo; 
        else {
            auto a = buscarRama(x, nodo->izdo);
            auto b = buscarRama(x, nodo->dcho);
            if(a != NULL && a->dato == x) return a;
            if(b != NULL &&  b->dato == x) return b;
        }  
    } 
    return NULL;
}

/*template<class Clave>
nodoB<Clave>* AB<Clave>::buscar(Clave& x) {
    return buscarRama(x, _raiz);
}

template<class Clave>
nodoB<Clave>* AB<Clave>::buscarRama(Clave& x, nodoB<Clave>* nodo) {
    if(!nodo)            return NULL;
    if(x == nodo->clave) return nodo;
    if(x  < nodo->clave) return buscarRama(x, nodo->izdo);
    return buscarRama(x, nodo->dcho);
}*/





template<class Clave>
void AB<Clave>::insertar(const Clave& x) {
    if(_raiz) insertarRama(x,_raiz);
    else      _raiz = new nodoB<Clave>(x,x,NULL,NULL);
}

template<class Clave>
void AB<Clave>::insertarRama(const Clave& x, nodoB<Clave>* nodo) {
    if(tamRama(nodo->izdo) <= tamRama(nodo->dcho)) {
        if(nodo->izdo) insertarRama(x, nodo->izdo);
        else           nodo->izdo = new nodoB<Clave>(x,x, NULL, NULL);
    } else {
        if(nodo->dcho) insertarRama(x, nodo->dcho);
        else           nodo->dcho = new nodoB<Clave>(x,x, NULL, NULL);
    }
}

/*template<class Clave>
void AB<Clave>::insertar(const Clave& x) { 
    if(_raiz) insertarRama(x,_raiz);
    else      _raiz = new nodoB<Clave>(x,x);
}

template<class Clave>
void AB<Clave>::insertarRama(const Clave& x, nodoB<Clave>* nodo) {
    if(nodo == NULL) nodo = new nodoB<Clave>(x,x);
    else if(x < nodo->clave) insertarRama(x, nodo->izdo);
    else                     insertarRama(x, nodo->dcho);
}*/




// Iniciales
template<class Clave> bool AB<Clave>::esVacio(nodoB<Clave>* nodo) { return nodo?false:true; }
template<class Clave> bool AB<Clave>::esHoja(nodoB<Clave>* nodo) { return !nodo->dcho && !nodo->izdo; }
template<class Clave>
void AB<Clave>::podar(nodoB<Clave>* &nodo) {
    if(nodo) {
        podar(nodo->izdo); // Podar subarbol izquierdo
        podar(nodo->dcho); // Podar subarbol derecho
        delete nodo;       // Eliminar nodo
        nodo = NULL;
    }
}




// Tamaño, altura, equilibrio
template<class Clave>
const int AB<Clave>::tamRama(nodoB<Clave>* nodo) {
    if(nodo) return (1+tamRama(nodo->izdo)+tamRama(nodo->dcho));
    else     return 0;
}




template<class Clave>
const int AB<Clave>::altNivl(nodoB<Clave>* nodo) {
    if(nodo) {
        int i = altN(nodo->izdo), d = altN(nodo->dcho);
        return (d > i)? ++d: ++i;
    } else return 0;
}




template<class Clave>
const bool AB<Clave>::equRama(nodoB<Clave>* nodo) {
    if(nodo) {
        switch(tamRama(nodo->izdo) - tamRama(nodo->dcho)) {
            case -1:
            case  0:
            case  1:
            return (equilibrioRama(nodo->izdo) && equilibrioRama(nodo->dcho));
        }
    } else return true;
}




// recorridos 
template<class Clave>
void AB<Clave>::recorreRama(nodoB<Clave>* nodo) {
    if(nodo) {
        cout << nodo->dato << ", ";
        recorreRama(nodo->izdo);
        recorreRama(nodo->dcho);
    }   
}



template<class Clave>
void AB<Clave>::inordenRama(nodoB<Clave>* nodo) {
    if(nodo) {
        inordenRama(nodo->izdo);
        cout << nodo->dato << ", ";
        inordenRama(nodo->dcho);
    }   
}





template<class Clave>
void AB<Clave>::recorreN() {
    cola<nodoB<Clave>*> Q;
    nodoB<Clave>* nodo;
    int actual = 0;
    int nv = actual;

    Q.insertar(_raiz,0); // insertar raiz
    cout << "\nNivel " << actual << ": ";
    while(!Q.vacia()) { // mientras haya nodos que explorar
        Q.extraer(nodo,nv); // actualizar nodo y nivel
        if(nv > actual) { // cuando el nivel supere el actual
            actual = nv;
            cout << "\nNivel " << actual << ": ";
        } 
        if(nodo) {
            cout << nodo->dato << " ";
            Q.insertar(nodo->izdo,nv+1);
            Q.insertar(nodo->dcho,nv+1);
            
        } else cout << nullnode; // imprimir nodo vacío
    }
}



#endif