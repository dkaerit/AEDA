#include "../include/mundo.hpp"

#define PAR(n) n%2 == 0
#define THEREIS(n,i,j) n.pos().second == i && n.pos().first == j

Mundo::~Mundo() {}
Mundo::Mundo(int x, int y) { 

    _sx = (PAR(x)) ? std::make_pair(-x/2, x/2): std::make_pair(-x/2, x/2+1);
    _sy = (PAR(y)) ? std::make_pair(-y/2, y/2): std::make_pair(-y/2, y/2+1);

    _malla.resize(std::get<0>(_sy), std::get<1>(_sy), 
    negavector<int>(std::get<0>(_sx), std::get<1>(_sx), 1));
}

void Mundo::increase(int fromwhat) {
    switch(fromwhat) {
        case ODOWN:    
            _sy.first -= 1;
            _malla.push_front(negavector<int>(std::get<0>(_sx),std::get<1>(_sx),1));
            break;

        case OUP:  
            _sy.second += 1; 
            _malla.push_back(negavector<int>(std::get<0>(_sx),std::get<1>(_sx),1));
            break;

        case OLEFT:  
            _sx.first -= 1;
            for(int i = _malla.sublim(); i < _malla.suplim(); i++) 
                _malla[i].push_front(1);
            break;

        case ORIGHT: 
            _sx.second += 1;
            for(int i = _malla.sublim(); i < _malla.suplim(); i++) 
                _malla[i].push_back(1);
            break;
    }
}

void Mundo::checkAntInLimit(int x, int y) {
    std::cout << "\ny:" << y << ", sy: (" << _sy.first << "," << _sy.second << ")\n" << std::flush;
    std::cout << "x:" << x << ", sx: (" << _sx.first << "," << _sx.second << ")\n" << std::flush;
    if(x == _sx.first)  increase(OLEFT);
    if(x+1 == _sx.second) increase(ORIGHT);
    if(y == _sy.first)  increase(ODOWN);
    if(y+1 == _sy.second) increase(OUP);
}

void Mundo::nextState(anthill& ants) {
    int x,y;
    anthill aux;
    for(auto ant: ants) {

        y = ant.pos().second;
        x = ant.pos().first;
        
        checkAntInLimit(x,y);
        ant.basicMove(this);
        _malla[y][x] = (_malla[y][x]) ? WHITE : BLACK;
        aux.push_back(ant);
    }
    ants = aux;
}

void Mundo::print(anthill& ants) {

    usleep(149599);
    //getchar();
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

//getters/setters
matrix Mundo::getMatrix() { return _malla; }

