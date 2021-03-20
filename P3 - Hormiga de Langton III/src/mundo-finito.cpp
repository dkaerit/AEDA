#include "../include/mundo-finito.hpp"

#define MIRROR 1;

MundoFinito::~MundoFinito() {}
MundoFinito::MundoFinito(int w, int h) { 

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

void MundoFinito::nextState(anthill& ants) {
    int x,y;
    anthill aux;
    bool mode = 1;
    int co;

    for(auto ant: ants) {

        // auxiliares de coordenadas
        y = ant.pos().second;
        x = ant.pos().first;
        
        // límites, homrigamover, actualizar celda y slavar cambios de la hormiga
        ant.basicMove(_malla[y][x],mode,_sx,_sy); // checkOverflow(x,y)
        _malla[y][x] = (_malla[y][x]) ? WHITE : BLACK; 
        aux.push_back(ant); 
    }
    ants = aux; // actualizar los nuevos cambios de las hormigas
}