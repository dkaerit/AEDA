#include "../include/mundo.hpp"

Mundo::~Mundo() {}
Mundo::Mundo() {}
Mundo::Mundo(int w, int h) { 

    _sx = (PAR(w)) ? 
        std::make_pair(-w/2, w/2): 
        std::make_pair(-w/2, h/2+1);
    
    _sy = (PAR(h)) ? 
        std::make_pair(-h/2, h/2): 
        std::make_pair(-h/2, h/2+1);

    _malla.resize(
        std::get<0>(_sy), 
        std::get<1>(_sy), 
        negavector<int>(std::get<0>(_sx), std::get<1>(_sx), 1)
    );

}

void Mundo::print(anthill& ants) {

    usleep(149599);
    getchar();
    bool err = std::system("clear");
    bool antf = 0; // ant founded

    std::cout << "\n";
    for(int i = _malla.sublim(); i < _malla.suplim(); i++) { 
        for(int j = _malla[i].sublim(); j < _malla[i].suplim(); j++) {
            for(auto ant: ants) {
                if(THEREIS(ant,i,j)) { 
                    antf = 1;
                    _malla[i][j] ? 
                        std::cout << RED_BG  << ant << RESET: 
                        std::cout << CYAN_BG << ant << RESET;
                } 
            }
            if(!antf) _malla[i][j] ? std::cout << color[BLACK] : std::cout << color[WHITE];
            antf = 0;
        }
        std::cout << "\n";
    }
}

int Mundo::checkOverflow(int x, int y) {
    std::cout << "\ny:" << y << ", sy: (" << _sy.first << "," << _sy.second << ")\n" << std::flush;
    std::cout << "x:" << x << ", sx: (" << _sx.first << "," << _sx.second << ")\n" << std::flush;
    if(x+1 == _sx.first)  return OLEFT;
    if(x == _sx.second) return ORIGHT;
    if(y+1 == _sy.first)  return ODOWN; // borde de arriba
    if(y == _sy.second) return OUP;   // borde de abajo
    return -1;
}

//getters/setters
matrix Mundo::getMatrix() { return _malla; }

