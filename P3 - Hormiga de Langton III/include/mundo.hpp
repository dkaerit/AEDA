#ifndef MUNDO_H
#define MUNDO_H

#include "hormiga.hpp"
#include "negavector.hpp"

#include <iostream>
#include <vector>
#include <list>
#include <tuple>
#include <cstdlib> 
#include <unistd.h>
#include <cassert>
#include <utility>  // pair

#define PAR(n) n%2 == 0
#define THEREIS(n,i,j) n.pos().second == i && n.pos().first == j

typedef negavector<negavector<int>> matrix;
typedef std::list<Hormiga> anthill;
typedef std::tuple<int,point> cell;
typedef std::pair<int,int> range;

// constantes globales
enum overflow { OUP = 0, ODOWN = 1, ORIGHT = 2, OLEFT = 3 }; 
enum color { WHITE = 0, BLACK = 1 }; 
static const std::string color[] = { " ", "█" }; 

class Mundo { 
    protected:
        matrix _malla;
        range _sy, _sx;

    public:
        Mundo();
        Mundo(int w, int h);
        virtual ~Mundo();

        int  checkOverflow(int x, int y); 
        void print(anthill& ants);

        // get/set
        matrix getMatrix();   
};

#endif 