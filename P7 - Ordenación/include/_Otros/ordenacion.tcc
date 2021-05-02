#ifndef ORDENACION_H
#define ORDENACION_H

#include <iostream>
#include <deque>
#include <iomanip> // setw
#include <algorithm> // copy
#include <iterator> // back_inserter

#include "../_Auxiliares/colors.inl"

using namespace std;
bool trazaOrdenacion = true;

/**
 * 
 * @verbatim Cabeceras
 * @endverbatim
 * ----------------------------------------------------------------------------------------
 * */

template<class Clave> deque<Clave> Insercion(deque<Clave> secuencia, size_t sz);
template<class Clave> deque<Clave> QuickSort(deque<Clave> secuencia, size_t sz);
template<class Clave> deque<Clave> ShellSort(deque<Clave> secuencia, size_t sz);

/**
 * ----------------------------------------------------------------------------------------
 * @verbatim Auxiliares
 * @endverbatim
 * 
 * */

template<class Clave> 
void traza(deque<Clave> v, int piv = -1, int le = -1, int ri = -1, bool colored = false) {
    Clave clave;
    for(int i = 0; i < v.size(); ++i) {
        if(i != 0) cout << ",";
        if((piv != -1) && (piv == i)) cout << BOLD_YELL;
        if((le != -1) && (le == i)) cout << BOLD_VIOL;
        if((ri != -1) && (ri == i)) cout << BOLD_CYAN;
        cout << setw(4) << v[i];
        if(!colored) cout << RESET;
    }
}

template<class Clave> 
void swap(deque<Clave>& v, unsigned i, unsigned j) {
    Clave c = v[i];
    v[i] = v[j];
    v[j] = c;
}


/**
 * ----------------------------------------------------------------------------------------
 * @verbatim Definiciones
 * @endverbatim
 * 
 * */

// Inserción
template<class Clave> 
deque<Clave> Insercion(deque<Clave> v, size_t sz) {
    Clave clave;
    
    for(int i = 1; i < sz; ++i) {
        if(trazaOrdenacion) { cout << "(" << setw(2) << i << ",   ): "; traza(v,i); cout << "\n"; }
        for(int j = i; j >= 1; --j) {
            if(v[j] < v[j-1]) {
                if(trazaOrdenacion) { cout << "(" << setw(2) << i << ", " << setw(2) << j << "): "; traza(v,-1,j,j-1); cout << "\n"; }
                swap(v,j,j-1);
            }
            
        }
    }
    cout << "result. : "; traza(v); cout << "\n";
    return v;
}


// Quick Sort
template<class Clave> 
void particionar(deque<Clave>& v, int& i, int& f) {
    int pinx = (i+f)/2;
    int p = v[(i+f)/2];     

    if(trazaOrdenacion) cout << BGRO_CLAI << "[" << i << ", " << f << "]  → pivote: " << p << RESET << endl;
    if(trazaOrdenacion) { traza(v,pinx,i,f); cout << "\n";}
    while(i <= f) {
        while(v[i] < p) i++;
        while(v[f] > p) f--;
        if(i <= f) {
            if(trazaOrdenacion) { traza(v,pinx,i,f); cout << "\n"; }
            swap(v,i,f);
            i++; f--;
        }
        if(trazaOrdenacion) { traza(v,pinx,i,f); cout << "\n"; }
    }
}

template<class Clave> 
void QuickSort(deque<Clave>& v, int ini, int fin) {
    int i = ini, f = fin; particionar(v,i,f);
    
    if(ini < f  ) QuickSort(v,ini,f);
    if(i   < fin) QuickSort(v,i,fin);

}

template<class Clave> 
deque<Clave> QuickSort(deque<Clave> v, size_t sz) {
    int ini =  0;  
    int fin = sz-1; 
    QuickSort(v,ini,fin);
    traza(v); cout << "\n";

    return v;
}


// ShellSort
template<class Clave> 
void deltasort(int d, deque<Clave>& v, size_t sz) {
    cout << "\n";
    for(int i = d; i < sz; ++i) {
        int x = v[i];
        int j = i;
        while((j >= d) && (x < v[j-d])) {
            if(trazaOrdenacion) traza(v,-1,j,j-d); cout << "\n";
            v[j] = v[j-d];
            j -= d;
        }
        v[j] = x;
    }
}

template<class Clave> 
deque<Clave> ShellSort(deque<Clave> v, size_t sz) {
    int del = sz;
    while(del > 1) {
        del /= 2; // delimitador que define los grupos
        deltasort(del, v, sz);
    }

    if(trazaOrdenacion) traza(v); cout << "\n";
    return v;
}



#endif