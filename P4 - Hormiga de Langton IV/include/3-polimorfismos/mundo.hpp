#ifndef MUNDO_H
#define MUNDO_H

#include "../2-genericas/evector.tcc"
#include "../3-polimorfismos/hormiga.hpp"
#include <iostream>     // cout
#include <list>         // list
#include <utility>      // pair
#include <cstdlib>      // system(clear), rand
#include <unistd.h>     // usleep

using namespace std;
typedef list<Hormiga*>          anthill;
typedef evector<evector<int>>   matrix;
typedef pair<int,int>           range;
typedef pair<int,point>         cell;

enum class colorM { WHITE = 0, BLACK = 1 }; 
static const std::string color[] = { " ", "█" }; 

/**
 * 
 * @verbatim Clase
 * @endverbatim
 * 
 * */

class Mundo {
    protected:
        matrix _malla;

    public:
        virtual ~Mundo() {}
        Mundo(int,int);
        Mundo() {}

        void to_s(anthill&);

        //get/set
        int getColor(int x, int y) { return _malla[x][y]; }
        int getAltura() { return _malla.size(); }
        int getAchura() { return _malla[0].size(); }  
};

/**
 * 
 * @verbatim Definiciones
 * @endverbatim
 * 
 * */

#define PAR(x) (x%2 == 0)
Mundo::Mundo(int acho, int alto) {
    
    int mw = acho/2;
    int mh = alto/2;
    
    range sx = PAR(acho)? make_pair(-mw,mw): make_pair(-mw,mw+1);
    range sy = PAR(alto)? make_pair(-mh,mh): make_pair(-mh,mh+1);

    _malla.resize(
        sy.first, sy.second, 
        evector<int>(sx.first,sx.second, WHITE)
    );
    _malla[0][1] = 1;
}

void Mundo::to_s(anthill& ants) {
    //usleep(149599);
    getchar();
    bool err = system("clear");
    bool hubohormiga = 0;

    cout << endl;
    for(int i = _malla.sublim(); i < _malla.suplim(); i++) { 
        for(int j = _malla[i].sublim(); j < _malla[i].suplim(); j++) {
            for(auto ant: ants) { 
                if((ant->getPos().second == i) && (ant->getPos().first == j)) 
                _malla[i][j] ? cout << RED_BG  << ant << RESET: cout << CYAN_BG  << ant << RESET; 
            }
            if(!hubohormiga) 
            _malla[i][j] ? cout << color[BLACK] : cout << color[WHITE];
        }
        cout << endl;
    }
}

#endif