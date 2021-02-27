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

class Mundo {
    private:
        matrix _malla;
        int _x, _y;

        void sleep(clock_t sec);

    public:
        Mundo(int x, int y);
        virtual ~Mundo();

        void start(int times, Hormiga& ant);
        void printWorld(Hormiga& ant);
};

#endif 