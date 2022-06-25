#ifndef SHELLSORT_H
#define SHELLSORT_H
#include <iostream>
#include <iomanip> // setw
#include <algorithm> // copy
#include <iterator> // back_inserter
#include "../Auxiliar/array.tpp"
#include "../Auxiliar/traza.inl"

using namespace std;
/////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                             //
//                                 FUNCIÓN SHELLSORT                                           //
//                                                                                             //
/////////////////////////////////////////////////////////////////////////////////////////////////


/*
* #brief Usando delta (d) como incremento, ordena el arreglo
* #param a, arreglo a ordenar
* #param delta, incremento
* #return Array<Key>, arreglo ordenado
*/

template<class Key> 
void deltasort(int d, Array<Key>& a, size_t sz) {
    cout << "\n";
    for(int i = d; i < sz; ++i) { // bucle comenzando en delta y acabando en size
        int x = a[i]; // guardo el valor a ordenar
        int j = i; // guardo el indice del valor a ordenar
        traza(a,i,j,j-d, BOLD_VIOL); cout << endl;
        // mientras el valor a ordenar sea menor que el valor que esta a la izquierda de delta
        while((j >= d) && (x < a[j-d])) { 
            a.swap(j,j-d); // intercambio los valores
            traza(a,-1,j,j-d, BOLD_CYAN); cout << endl;
            j -= d; // decremento el indice
        }
        a[j] = x;
    }
}

/*
* #brief Ordena un array con el algoritmo de Shellsort
* #param a, array a ordenar
* #return Array<Key>, array ordenado
*/

template<class Key> 
Array<Key> ShellSort(Array<Key>& a, size_t sz = 0) {
    int del = (sz <= 0)? a.size(): sz; // si no se pasa el tamaño, lo toma como el tamaño del array
    while(del > 1) { // mientras delta sea mayor que 1
        del /= 2; // delimitador que define los grupos
        deltasort(del, a, a.size()); // ordeno el array con el delimitador
    }

    traza(a);
    return a;
}

#endif