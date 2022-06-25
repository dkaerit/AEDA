#ifndef HORMIGAB_H
#define HORMIGAB_H

#include "../3-polimorfismos/hormiga.hpp"

/**
 * 
 * @verbatim Clase
 * @endverbatim
 * ------------------------------------------------------------------------------------------
 * */

class HormigaB: public Hormiga {
    public:
        HormigaB(int x,int y,int aimm=-1): Hormiga(x,y,aimm) {}

        void girar(bool);         
        void desplazar(); 
};

/**
 * ------------------------------------------------------------------------------------------ 
 * @verbatim Definiciones
 * @endverbatim
 * 
 * */

void HormigaB::girar(bool color) {
    switch(!color) { // black/destrogiro, white/levogiro
        case BLACK: _aim = (_aim == LE)    ? UP_LE : _aim+1; break;
        case WHITE: _aim = (_aim == UP_LE) ? LE    : _aim-1; break;
    }
}

void HormigaB::desplazar() {
    switch(_aim) {
        case UP   : Hormiga::desplazar(ints({UP}));       break;
        case DO   : Hormiga::desplazar(ints({DO}));       break;
        case LE   : Hormiga::desplazar(ints({LE}));       break;
        case RI   : Hormiga::desplazar(ints({RI}));       break;
        case UP_LE: Hormiga::desplazar(ints({UP,LE}));    break; 
        case UP_RI: Hormiga::desplazar(ints({UP,RI}));    break;
        case DO_LE: Hormiga::desplazar(ints({DO,LE}));    break;
        case DO_RI: Hormiga::desplazar(ints({DO,RI}));    break;
        default:    Hormiga::desplazar(ints({UP,UP,UP})); break;
    }
}

#endif