#include "../include/mundo-infinito.hpp"

MundoInfinito::~MundoInfinito() {}
MundoInfinito::MundoInfinito(int w, int h) { 

    _sx = (PAR(w)) ? 
        std::make_pair(-w/2, w/2): 
        std::make_pair(-w/2, h/2+1);
    
    _sy = (PAR(h)) ? 
        std::make_pair(-h/2, h/2): 
        std::make_pair(-h/2, h/2+1);

    _malla.resize(
        _sy.first, 
        _sy.second, 
        negavector<int>(_sx.first, _sx.second, 1)
    );
}

void MundoInfinito::increase(int fromwhat) {
    switch(fromwhat) {
        case ODOWN:    
            _sy.first -= 1;
            _malla.push_front(negavector<int>(_sx.first,_sx.second,1));
            break;

        case OUP:  
            _sy.second += 1; 
            _malla.push_back(negavector<int>(_sx.first,_sx.second,1));
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
        default: break;
    }
}

void MundoInfinito::nextState(anthill& ants) {
    int x,y;
    anthill aux;
    bool mirror = 0;

    for(auto ant: ants) {

        // auxiliares de coordenadas
        y = ant.pos().second;
        x = ant.pos().first;

        // límites, homrigamover, actualizar celda y slavar cambios de la hormiga
        increase(checkOverflow(x,y)); 
        ant.basicMove(_malla[y][x],mirror); 
        _malla[y][x] = (_malla[y][x]) ? WHITE : BLACK; 
        aux.push_back(ant); 
    }
    ants = aux; // actualizar los nuevos cambios de las hormigas
}