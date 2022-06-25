#pragma once
#include "color.inl"

/*
* #brief Muestra mensaje de éxito por pantalla y retorna true
* #param c, mensaje a mostrar
* #param pos, posición afectada
* #return bool, true
*/


inline bool success(const char* c, unsigned pos) {
    cout << BOLD_GREN << c << " " << RESET;
    cout << BOLD_GREN "en la posición " << RESET << pos;
    getchar();
    return true;
}

/*
* #brief Muestra mensaje de fallo por pantalla y retorna true
* #param c, mensaje a mostrar
* #param pos, posición afectada
* #return bool, true
*/

inline bool failure(const char* c, unsigned pos) {
    cout << BOLD_REDD << c << " " << RESET;
    cout << BOLD_REDD "en la posición " << RESET << pos;
    getchar();
    return false;
}

/*
* #brief Muestra mensaje de éxito por pantalla y retorna true
* #param c, mensaje a mostrar
* #param k, clave objetivo
* #return bool, true
*/

inline bool success(const char* c) {
    cout << BOLD_GREN << c << " " << RESET;
    getchar();
    return true;
}

/*
* #brief Muestra mensaje de fallo por pantalla y retorna true
* #param c, mensaje a mostrar
* #param k, clave objetivo
* #return bool, true
*/

inline bool failure(const char* c) {
    cout << BOLD_REDD << c << " " << RESET;
    getchar();
    return false;
}

enum rot {II, ID, DI, DD};
template<class Key>
inline void traza(int tipo, Key k) {
    #ifdef TRAZA
    switch (tipo) {
        case II: cout << BOLD_CYAN << "rotación II en " << RESET << k << endl; break;
        case ID: cout << BOLD_CYAN << "rotación ID en " << RESET << k << endl; break;
        case DI: cout << BOLD_CYAN << "rotación DI en " << RESET << k << endl; break;
        case DD: cout << BOLD_CYAN << "rotación DD en " << RESET << k << endl; break;
    }
    getchar();
    #endif
}

