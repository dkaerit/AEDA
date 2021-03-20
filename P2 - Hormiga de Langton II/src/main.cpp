#include "../include/hormiga.hpp"
#include "../include/mundo.hpp"
#include "../include/universo.hpp"

int main(int argc, char *argv[]) {

    // int x = 150, y = 46;
    int x = 15, y = 10; // (-5,4) x (-5,4)
    Mundo   M(x,y);

    anthill ants;
    Hormiga ant1(2,-2,UR); ants.push_back(ant1);
    Hormiga ant2(-2,2,DL); ants.push_back(ant2);
    
    Universo(ants,M).start();

    return 0;
}