#include "../include/universo.hpp"

int main(int argc, char *argv[]) {

    MundoInfinito Mi(15,10);
    MundoFinito   Mf(20,10);

    anthill ants;
    //Hormiga ant1(2,-2,UR); ants.push_back(ant1);
    Hormiga ant2(-2,2,DL); ants.push_back(ant2);
    
    //Universo<MundoInfinito>(ants,Mi).start();
    Universo<MundoInfinito>(ants,Mi).start();

    return 0;
}