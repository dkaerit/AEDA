#ifndef HORMIGA_H
#define HORMIGA_H

#include <iostream>
#include <utility>
#include <string>
#include <ctime>
#include <cstdlib>

// constantes globales
#define L_MOV "←" // 0
#define R_MOV "→" // 1
#define U_MOV "↑" // 2
#define D_MOV "↓" // 3

class Hormiga {
    private:
        int _mov;
        std::string _aim;
        std::pair<int,int> _now;

    public:
        Hormiga(int x, int y);
        virtual ~Hormiga();

        void setPosition(int x, int y);
        void setX(int c) { _now.first = c; }
        void setY(int c) { _now.second = c; } 
        void setAim(int c);

        int getX() { return _now.first; }
        int getY() { return _now.second; }
        std::string getAim() { return _aim; }

        void move();
        void turn(int mode);
};

#endif 