#ifndef HEAPSORT_H
#define HEAPSORT_H
#include <iostream>
#include <iomanip> // setw
#include <algorithm> // copy
#include <iterator> // back_inserter
#include "../Auxiliar/array.tpp"
#include "../Auxiliar/traza.inl"

using namespace std;
/////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                             //
//                                  FUNCIÓN HEAPSORT                                           //
//                                                                                             //
/////////////////////////////////////////////////////////////////////////////////////////////////

template<class Key>
void heapify(int i, Array<Key>& a, size_t n) {
    while(2*i <= n) {
        int h1 = 2*i;
        int h2 = h1+1;
        int h = (h1 == n)? h1 : 
                (a[h1] > a[h2])? h1: h2;

        traza(a, i, h1, h2, BOLD_VIOL); cout << endl;
        if(a[h] <= a[i]) break;
        else {
            traza(a, -1, i, h, BOLD_CYAN); cout << endl;
            a.swap(i, h);
            i = h;
        }
    }
}

template<class Key>
Array<Key> HeapSort(Array<Key>& a, size_t sz = 0) {
    sz = (sz == 0) ? a.size()-1 : sz-1;
    for(int i = sz/2; i >= 0; --i) heapify(i, a, sz);
    for(int i = sz; i >= 1; --i) {
        a.swap(0, i);
        heapify(0, a, i-1);
    }
    return a;
}



#endif