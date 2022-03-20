/**
 * @file alive.defs.cpp
 * @author Diego Vázquez Campos (alu0101014326@ull.edu.es)
 * @brief Definiciones de las clases derivadas de State
 * @version 0.1
 * @date 2022-03-10
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "../headers/dead.derived.hpp"
#include "../headers/alive.derived.hpp"

/////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                             //
//                             DEFINICIONES DE LA CLASE DEAD                                   //
//                                                                                             //
/////////////////////////////////////////////////////////////////////////////////////////////////

State* StateAlive::nextState() { 
    return _next;
}

char StateAlive::getState() const {
    return symbol[viva];
}


int StateAlive::neighbors(const Grid& grid, int i, int j) {
    int vivas = 0;

    // Contar vecinos    
    for(auto x = -1; x < 2; x++) {
        for(auto y = -1; y < 2; y++) {
            if(!grid.isMargin(x+i,y+j) && !(x==0 && y==0)) {
                if(grid.getCell(x+i,y+j).getState() == symbol[viva]) vivas++;
            }
        }
    }
    
    // condiciones
    if(vivas == 2 || vivas == 3) _next = new StateAlive();
    else _next = new StateDead(); 

    return vivas;
}