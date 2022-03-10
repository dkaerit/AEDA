#ifndef COLA_H
#define COLA_H

#include <deque>
#include <utility> // pair
using namespace std;

/**
 * 
 * @verbatim Cabecera
 * @endverbatim
 * ----------------------------------------------------------------------------------------
 * */

template<class Nodo>
class cola {
    private:
        deque<pair<Nodo,int>> _q;

    public:
        virtual ~cola() {};
        cola(): _q(deque<pair<Nodo,int>>()) {}

        void insertar(Nodo& nodo, int nv) { 
            _q.push_back(make_pair(nodo,nv)); 
        }


        void extraer(Nodo& nodo, int& nv) { 
            nodo = _q[0].first; 
            nv = _q[0].second;
            _q.pop_front();
        }

        bool vacia() { return _q.empty(); }
        deque<Nodo> get() { return _q; }
};

/**
 * ----------------------------------------------------------------------------------------
 * @verbatim Definiciones
 * @endverbatim
 * 
 * */

#endif
