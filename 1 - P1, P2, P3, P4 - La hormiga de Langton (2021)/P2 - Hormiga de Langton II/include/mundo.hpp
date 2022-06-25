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

typedef negavector<negavector<int>> matrix;
typedef std::list<Hormiga> anthill;
typedef std::tuple<int,point> cell;
typedef std::pair<int,int> range;

// constantes globales
enum overflow { OUP = 0, ODOWN = 1, ORIGHT = 2, OLEFT = 3 }; 
enum color { WHITE = 0, BLACK = 1 }; 
static const std::string color[] = { " ", "█" }; 

class Mundo {
    private:
        matrix _malla;
        range _sy, _sx;

    public:
        Mundo(int w, int h);
        virtual ~Mundo();

        void increase(int fromwhat); // inferior/derecha o superior/izquierda
        void nextState(anthill& ants);
        void print(anthill& ants);
        void checkAntInLimit(int x, int y);

        // get/set
        matrix getMatrix();        
};

#endif 