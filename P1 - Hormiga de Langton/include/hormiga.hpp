#ifndef HORMIGA_H
#define HORMIGA_H

#include <utility>

// constantes globales
#define L_MOV "←" // 0
#define R_MOV "→" // 1
#define U_MOV "↑" // 2
#define D_MOV "↓" // 3

class Hormiga {
    private:
        int _mov;
        std::pair<int,int> _stNow;
    public:
        Hormiga();
        virtual ~Hormiga();
};

#endif 