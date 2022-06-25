#ifndef QUICKSORT_H
#define QUICKSORT_H
#include <iostream>
#include <iomanip> // setw
#include <algorithm> // copy
#include <iterator> // back_inserter
#include "../Auxiliar/array.tpp"
#include "../Auxiliar/traza.inl"

using namespace std;
/////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                             //
//                                 FUNCIÓN QUICKSORT                                           //
//                                                                                             //
/////////////////////////////////////////////////////////////////////////////////////////////////

/*
* #brief Partición de un array
* #param a, array a particionar
* #param i, índice inicial
* #param f, índice final
* #return int, índice de la partición
*/

template<class Key>
void Partition(Array<Key>& a, int& i, int& f) {
    int piv_inx = (i+f)/2; // índice del pivote
    Key piv_val = a[piv_inx]; // valor del pivote

    pivote(i, f, piv_val); // particionamos el array
    while(i <= f) { // recorremos el array hasta que i sea mayor que f
        traza(a,piv_inx,i,f,BOLD_VIOL);  cout << endl;
        while(a[i] < piv_val) i++; // buscamos el elemento mayor que el pivote
        while(a[f] > piv_val) f--; // buscamos el elemento menor que el pivote
        if(i <= f) { // si i es menor o igual que f intercambiamos los valores
            traza(a,piv_inx,i,f,BOLD_CYAN); cout << endl;
            a.swap(i,f);
            i++; f--; // avanzamos i y f
        }
        traza(a,piv_inx,i,f,BOLD_VIOL); cout << endl;
    }
}

/*
* #brief Ordena un array de manera recursiva por el algoritmo de quicksort
* #param a, array a ordenar
* #param ini, índice inicial
* #param fin, índice final
*/

template<class Key>
void QuickSort(Array<Key>& a, int ini, int fin) {
    int inp = ini, fip = fin; Partition(a, ini, fin); // Partición
    if(fip > ini) QuickSort(a, ini, fip); // Ordenar subarreglo izquierdo
    if(inp < fin) QuickSort(a, inp, fin); // Ordenar subarreglo derecho
}

/*
* #brief Ordena un array usando el algoritmo de ordenación QuickSort
* #param a, array de enteros a ordenar
* #param sz, tamaño del array
* #return void
*/

template<class Key>
Array<Key> QuickSort(Array<Key>& a, size_t sz = 0) {
    int ini = 0, fin = (sz <= 0)? a.size()-1: sz-1; // sz = 0 -> todo el array
    QuickSort(a, ini, fin); // llamada a la función recursiva
    return a;
}

#endif