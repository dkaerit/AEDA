#ifndef TRAZA_H
#define TRAZA_H
#include <cmath> // INFINITY
#include <iostream>
#include "../Auxiliar/color.inl"
#include "../Auxiliar/array.tpp"

/////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                             //
//                                     FUNCIÓN TRAZA                                           //
//                                                                                             //
/////////////////////////////////////////////////////////////////////////////////////////////////

template<class Key> 
inline void traza(Array<Key>& a, const int piv = -999999, const int lef = -999999, const int rig = -999999, const char* color = NULL) {
    #ifdef TRAZA
    for(auto &[i,value]: a.getBase()) {
        if(i != a.sublim()) cout << ", ";
        if(i == piv && piv >= 0) cout << BOLD_REDD; 
        if(i == lef && lef >= 0 && color != NULL) cout << color; 
        if(i == rig && rig >= 0 && color != NULL) cout << color; 
        //cout << "(" << i << ":"  << value << ")" << RESET; 
        cout << setw(5) << value << RESET; 
    }
    #endif
}

template<class Key>
inline void pivote(int& i, int& f, Key& piv_val) {
    #ifdef TRAZA
    cout << BGRO_REDD << "[l: " << i << ", r: " << f << "]  → piv: " << piv_val << RESET << endl;
    #endif
}

template<class Key>
inline void trazaWithOrdered(int suplim_ordered, Array<Key>& a, const int lef = -999999, const int rig = -999999, const char* color = NULL) {
    #ifdef TRAZA
    for(auto &[i,value]: a.getBase()) {
        if(i != a.sublim()) cout << ", ";
        if(i <= suplim_ordered) cout << BOLD_GREN; 
        if(i == lef && lef >= 0 && color != NULL) cout << color; 
        if(i == rig && rig >= 0 && color != NULL) cout << color; 
        //cout << "(" << i << ":"  << value << ")" << RESET; 
        cout << setw(5) << value << RESET; 
    }
    cout << endl;
    #endif
}


#endif