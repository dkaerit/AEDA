#pragma once
#include "array.tpp"

/*
* #brief: algoritmo linear search. Busca una key en un array.
* #param k: key a buscar
* #param a: array en el que se va a buscar
* #return: índice de la key si se encontró, -1 en cso contrario
*/

template<class Key>
inline bool linearSearch(const Key& k, Array<Key>& a) {
    for (auto i = 0; i < a.size(); i++) {
        if (k == a[i]) return true;
    }
    return false;
}

/*
* #brief: algoritmo binary search algorithm. Busca una key en un array ordernado.
* #param k: key a buscar
* #param a: array en el que se va a buscar
* #return: índice de la key si se encontró, -1 en cso contrario
*/

template<class Key>
inline bool binarySearch(const Key& k, Array<Key>& a) {
    Key ini{0}, mid{ini}, fin{a.size()-1};

    while (ini <= fin) {
        mid = (ini+fin) / 2;
        if(k < a[mid]) fin = mid-1;
        else if(k > a[mid]) ini = mid+1;
        else return true;
    }

    return false;
}

/*
* #brief: algoritmo interpolation search algorithm. Busca una key en un array ordenado.
* #param k: key a buscar
* #param a: array en el que se va a buscar
* #return: índice de la key si se encontró, -1 en cso contrario
*/

template<class Key>
inline bool interpolationSearch(const Key& k, Array<Key>& a) {
    Key ini{0}, mid{ini}, fin{a.size()-1};

    while (ini <= fin) {
        mid = ini + (fin-ini)*(k-a[ini])/(a[fin]-a[ini]);
        if(k < a[mid]) fin = mid-1;
        else if(k > a[mid]) ini = mid+1;
        else return true;
    }

    return false;
}