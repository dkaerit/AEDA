#pragma once

#include "../3-polimorfismos/hormiga.hpp"
#include "../3-polimorfismos/mundo.hpp"

// macros
#define INFO_HORMIGA(aimm,x,y) std::cout << "aim: " << aim[aimm] << "(" << x << ", " << y << ")\n"

/*


void MundoFinito::handlerAntOverflow(anthill& ants, cell& c) {
    int ant_x, ant_y;

    const int MIN_ACHURA = _malla[_malla.suplim()-1].sublim(); 
    const int MAX_ACHURA = _malla[_malla.suplim()-1].suplim(); 
    const int MIN_ALTURA = _malla.sublim();                    
    const int MAX_ALTURA = _malla.suplim();                    

    for(auto ant: ants) {
        ant_x = ant->getPos().second; // coordenada y de la hormiga
        ant_y = ant->getPos().first;  // coordenada x de la hormiga
        
        // eje vertical
        if(ant_x <=  MIN_ALTURA   ) espejo(UP_TO_DOWN);   // arriba
        if(ant_x >= (MAX_ALTURA-1)) espejo(DOWN_TO_UP);   // abajo

        // eje horizontal
        if(ant_y <=  MIN_ACHURA   ) espejo(LEFT_TO_RIGHT); // izquierda
        if(ant_y >= (MAX_ACHURA-1)) espejo(RIGHT_TO_LEFT); // derecha
    }
}

void MundoFinito::espejo(int AtoB) {
    
    const int MIN_ACHURA = _malla[_malla.suplim()-1].sublim(); 
    const int MAX_ACHURA = _malla[_malla.suplim()-1].suplim(); 

    switch(AtoB) {
        case UP_TO_DOWN: 
            
            break;
        
        case DOWN_TO_UP:  
               
            break;
        
        case LEFT_TO_RIGHT:
            
            break;

        case RIGHT_TO_LEFT:
            
            break;
    }

    */