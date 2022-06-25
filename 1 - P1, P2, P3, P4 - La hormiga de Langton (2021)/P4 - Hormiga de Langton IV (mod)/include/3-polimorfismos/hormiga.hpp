#ifndef HORMIGA_H
#define HORMIGA_H

#include "../1-auxiliares/colors.tcc"
#include "../2-genericas/evector.tcc"
#include <iostream>     // cout
#include <string>       // string
#include <cassert>      // assert
#include <vector>       // vector de enteros
#include <cstdlib>      // clear, rand
#include <utility>      // pair
#include <ctime>        // semilla variable

using namespace std;
typedef pair<int,int>           point;
typedef pair<point,int>         cell;
typedef evector<evector<cell>>  matrix;
typedef deque<int>              ints;

enum color { WHITE = 0, BLACK = 1 };
enum mov { UP_LE = 0, UP = 1, UP_RI = 2, RI = 3, DO_RI = 4, DO = 5, DO_LE = 6, LE = 7 }; 
static const string aim[] = { "↖", "↑", "↗", "→", "↘", "↓", "↙", "←" }; 

/**
 * 
 * @verbatim Clase
 * @endverbatim
 * ------------------------------------------------------------------------------------------
 * */

class Hormiga {
    protected:
        int   _aim;
        point _pos;
        // first: coordenada y;
        // second: coordenada x;

    protected:
        virtual void girar(bool) = 0;         
        virtual void desplazar() = 0;        
        void desplazar(ints);

    public:
        virtual ~Hormiga() {}
        Hormiga(int,int,int aimm=-1);

        void actualizar(matrix&); 

        // getters/setters
        int   getAim() { return _aim; }
        point getPos() { return _pos; }
        void  setPos(int,int);
};

/**
 * ------------------------------------------------------------------------------------------
 * @verbatim Definiciones
 * @endverbatim
 * 
 * */

Hormiga::Hormiga(int x, int y, int aimm) {
    
    bool valid = (-1 < aimm && aimm < 8); 
    bool defau = (aimm == -1);

    srand(time(0));
    if(defau) _aim = rand()%8;         // orientación inicial aleatoria
    if(valid) _aim = aimm;             // orientación inicial definida
    _pos = std::make_pair(x,y);        // definir posición
}

void Hormiga::actualizar(matrix& malla) {
    int color = malla[_pos.second][_pos.first].second;
    girar(color);
    malla[_pos.second][_pos.first].second = color? WHITE:BLACK;
    desplazar();
}


void Hormiga::girar(bool color) {
    switch(color) {
        case BLACK: _aim = (_aim == LE)    ? UP_LE : _aim+1; break;
        case WHITE: _aim = (_aim == UP_LE) ? LE    : _aim-1; break;
    }
}

void Hormiga::desplazar() {
    switch(_aim) {
        case UP   : desplazar(ints({UP}));    break;
        case DO   : desplazar(ints({DO}));    break;
        case LE   : desplazar(ints({LE}));    break;
        case RI   : desplazar(ints({RI}));    break;
        case UP_LE: desplazar(ints({UP,LE})); break; 
        case UP_RI: desplazar(ints({UP,RI})); break;
        case DO_LE: desplazar(ints({DO,LE})); break;
        case DO_RI: desplazar(ints({DO,RI})); break;
    }
}

void Hormiga::desplazar(ints aims) {
    for(int aim: aims) {
        switch(aim) {
            case UP   : _pos.second -= 1; break;
            case DO   : _pos.second += 1; break;
            case LE   : _pos.first  -= 1; break;
            case RI   : _pos.first  += 1; break;
        }
    }
}

void Hormiga::setPos(int i, int j) {
    _pos.first = i;
    _pos.second = j;
}

/**
 * 
 * @verbatim Sobrecarca de operadores
 * @endverbatim
 * 
 * */

static std::ostream& operator<<(std::ostream& os, Hormiga& H) {
    os << aim[H.getAim()];
    return os;
}

#endif 