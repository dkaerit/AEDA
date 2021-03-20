#ifndef MUNDO_H
#define MUNDO_H

#include "../include/hormiga.hpp"
#include "../include/colors.hpp"

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

// constantes globales
#define BLACK " " // 0
#define WHITE "█" // 1

typedef std::vector<std::vector<int>> matrix;
typedef std::vector<Hormiga> anthill;

class Mundo {
    private:
        matrix _malla;
        int _x, _y;

    public:
        Mundo(int x, int y);
        virtual ~Mundo();

        void start(Hormiga& ant);
        void start(int num);
        
        void printWorld(Hormiga& ant);
        void printWorld(anthill& h);
};

#endif 