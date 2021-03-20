#include "../include/mundo.hpp"

int main(int argc, char *argv[]) {
    int x = 150;
    int y = 45;
    Mundo M(x,y);

    
    int num = 3;
    //M.start(ant);
    Hormiga ant(rand()%x, rand()%y);
    M.start(ant);
    return 0;
}