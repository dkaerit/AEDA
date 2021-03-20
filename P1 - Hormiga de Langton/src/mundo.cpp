#include "../include/mundo.hpp"

Mundo::Mundo(int x, int y): 
_x(x),_y(y) {   
    std::system("clear");
    _malla.resize(_y,std::vector<int>(_x,0));
}

Mundo::~Mundo() {}

void Mundo::printWorld(Hormiga& ant) {
    //std::system("clear");
    bool black = false;

    for(int i = 0; i < _y; i++) {   
        for(int j = 0; j < _x; j++) {
            if(i == ant.getY() && j == ant.getX()) {
                if(_malla[i][j] == 0) { // si casilla negra
                    black = true;
                    std::cout << CYAN_BG << ant.getAim() << RESET;
                    _malla[i][j] = 1; // poner un blanco
                    
                }
                else if(_malla[i][j] == 1) { // si casilla blanca
                    black = false;
                    std::cout << RED_BG << ant.getAim() << RESET;
                    _malla[i][j] = 0; // poner un negro
                }
            } else {
                if(_malla[i][j] == 0) std::cout << BLACK;
                if(_malla[i][j] == 1) std::cout << WHITE;   
            }
             
        }
        std::cout << "\n";
    }
    if(black) ant.turn(1);
    else      ant.turn(0);    
    ant.move();

}

void Mundo::start(Hormiga& ant) {   
    for(;;) {
        printWorld(ant);
        time_t before = time(0);
        //while(difftime(time(0), before) < 1);
    }
}

void Mundo::start(int num) {   
    anthill h;
    srand(time(0));
    for(int i = 0; i < num; i++) 
        h.push_back(Hormiga(rand()%_x, rand()%_y));

    for(;;) {
        printWorld(h);
        time_t before = time(0);
        while(difftime(time(0), before) < 1);
    }
}

void Mundo::printWorld(anthill& h) {
    //std::cout << h[0].getX() << std::endl;
    //std::cout << h[1].getX() << std::endl;
    //std::cout << h[2].getX() << std::endl;

    for(int i = 0; i < _y; i++) {   
        for(int j = 0; j < _x; j++) {
            for(int k = 0; k < h.size(); k++) {
                if(i == h[k].getY() && j == h[k].getX()) {
                    if(_malla[i][j] == 0) { // si casilla negra
                        h[k].setCellT(true); // negro booleano para comprobaciones futuras
                        std::cout << CYAN_BG << h[k].getAim() << RESET;
                        _malla[i][j] = 1; // poner un blanco
                    }
                    else if(_malla[i][j] == 1) { // si casilla blanca
                        h[k].setCellT(false); // blanco booleano para comprobaciones futuras
                        std::cout << RED_BG << h[k].getAim() << RESET;
                        _malla[i][j] = 0; // poner un negro
                    }
                } else {
                    if(_malla[i][j] == 0) std::cout << BLACK;
                    if(_malla[i][j] == 1) std::cout << WHITE;   
                }
            }
        }
        std::cout << "\n";
    }

    for(int k = 0; k < h.size(); k++) {
        if(h[k].getCellT()) h[0].turn(1);
        else      h[0].turn(0);    
        h[0].move(); 
    }
    

}