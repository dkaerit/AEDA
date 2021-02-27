#ifndef MUNDO_H
#define MUNDO_H

#include <vector>

// constantes globales
#define BLACK "█" // 0
#define WHITE " " // 1

typedef std::vector<std::vector<int>> matrix;

class Mundo {
    private:
        matrix _malla;
    public:
        Mundo();
        virtual ~Mundo();

        void start();
};

#endif 