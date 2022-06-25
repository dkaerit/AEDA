#ifndef HORMIGA_H
#define HORMIGA_H

#include "colors.hpp"

#include <iostream> // cout
#include <vector>   // cout
#include <utility>  // pair
#include <string>
#include <cstdlib>  // rand
#include <ctime>    // semilla variable
#include <cassert>

typedef std::string string;
typedef std::vector<int> ints;
typedef std::pair<int,int> point;
typedef std::pair<int,int> range;

// constantes globales
enum mov { 
    UL = 0, U = 1, UR = 2, R = 3, 
    DR = 4, D = 5, DL = 6, L = 7  
}; 
static const string aim[] = { 
    "↖", "↑", "↗", "→", 
    "↘", "↓", "↙", "←"     
}; 

class Hormiga {
    private:
        int   _aim;
        point _pos;

        ints decompose(int m);

    public:
        Hormiga(int x, int y, int aimm=-1);
        virtual ~Hormiga();

        // reglas
        void basicMove(bool cell);

        // movimientos unitarios
        void move(const ints& aims);
        void turn(bool cell);
        void mirror(range _sx, range _sy);

        // get/set
        string to_s();
        point pos();
        int pointing();

        void setx(int);
        void sety(int);
};

static std::ostream& operator<<(std::ostream& os, Hormiga& H) {
    os << H.to_s();
    return os;
}

#endif 