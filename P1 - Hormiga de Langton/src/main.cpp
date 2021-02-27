#include "../include/mundo.hpp"

int main(int argc, char *argv[]) {
    //Mundo M(160,50);
    int x = 150;
    int y = 45;
    Mundo M(x,y);

    srand(time(0));
    Hormiga ant(rand() % x,rand() % y);
    
    M.start(10000000, ant);
    return 0;
}