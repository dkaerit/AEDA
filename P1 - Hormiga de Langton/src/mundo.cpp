#include "../include/mundo.hpp"

Mundo::Mundo(int x, int y): 
_x(x),_y(y) {   
    std::system("clear");
    _malla.resize(_y,std::vector<int>(_x,0));
}

Mundo::~Mundo() {}

void Mundo::printWorld(Hormiga& ant) {
    std::system("clear");
    bool black = false;

    for(int i = 0; i < _y; i++) {   
        for(int j = 0; j < _x; j++) {
            
            if(i == ant.getY() && j == ant.getX()) {
                if(_malla[i][j] == 0) { // si casilla negra
                    black = true;
                    std::cout << CYAN_BG << ant.getAim() << RESET << std::flush;
                    _malla[i][j] = 1; // poner un blanco
                    
                }
                else if(_malla[i][j] == 1) { // si casilla blanca
                    black = false;
                    std::cout << RED_BG << ant.getAim() << RESET << std::flush;
                    _malla[i][j] = 0; // poner un negro
                }
            } else {
                if(_malla[i][j] == 0) std::cout << BLACK << std::flush;
                if(_malla[i][j] == 1) std::cout << WHITE << std::flush;   
            }
             
        }
        std::cout << "\n";
    }
    if(black) ant.turn(1);
    else      ant.turn(0);    
    ant.move();

}

void Mundo::start(int times, Hormiga& ant) {   
    /*for(int i=0; i < times; i++) {
        printWorld(ant);
        sleep(50);
    }*/
    for(;;) {
        printWorld(ant);
        //sleep(50);
    }
}

void Mundo::sleep(clock_t sec) {
    clock_t ini = clock();
    clock_t fin = sec * 1000 + ini;
    while(clock() != fin);
}