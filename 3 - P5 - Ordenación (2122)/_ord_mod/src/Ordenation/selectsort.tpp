#ifndef SELECTSORT_H
#define SELECTSORT_H
#include <iostream>
#include <iomanip> // setw
#include <algorithm> // copy
#include <iterator> // back_inserter
#include "../Auxiliar/array.tpp"
#include "../Auxiliar/traza.inl"

using namespace std;
/////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                             //
//                                 FUNCIÓN SELECCIÓN                                           //
//                                                                                             //
/////////////////////////////////////////////////////////////////////////////////////////////////

/*
* #brief Busca el mínimo elemento de una subsecuencia
* #param a, vector de elementos
* #param begin, posición de inicio de la subsecuencia
* #param sz, tamaño de la secuencia original
* #return int, posición del mínimo elemento
*/

template<class Key>
size_t Min(Array<Key>& a, unsigned int begin, size_t sz) {
    size_t min_pos = begin; // Posición del mínimo
    for (size_t i = begin + 1; i < sz; i++) { // Recorre la parte no ordenada
        if (a[i] < a[min_pos]) { // Si el elemento es menor que el mínimo
            min_pos = i; // Actualiza la posición del mínimo
        }
    }
    trazaWithOrdered(begin, a, begin, min_pos, BOLD_CYAN);
    return min_pos;
}

/*
* #brief Ordena un array de enteros de forma ascendente
* #param a, array de enteros
* #param sz, tamaño del array
* #return array de enteros ordenado
*/

template<class Key> 
Array<Key> SelectSort(Array<Key>& a, size_t sz = 0) {
    sz = (sz <= 0)? a.size(): sz; // Si no se especifica el tamaño, se toma el tamaño del array
    for (size_t i = 0; i < sz; i++) { // Se recorre el array
        size_t min_pos = Min(a, i, sz); // Se busca el mínimo de la parte no ordenada
        a.swap(i, min_pos); // Se intercambia el mínimo con el elemento actual
    }
    return a;
}

#endif