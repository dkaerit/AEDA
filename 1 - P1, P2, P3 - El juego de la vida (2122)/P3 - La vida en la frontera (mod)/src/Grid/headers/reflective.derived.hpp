/**
 * @file grid.class.hpp
 * @author Diego Vázquez Campos (alu0101014326@ull.edu.es)
 * @brief Clase que define la rejilla del juego de la vida 
 * @version 0.1
 * @date 2022-02-22
 * @copyright Copyright (c) 2022
 */

#ifndef GRID_W_REFLECTIVE_BORDER_H
#define GRID_W_REFLECTIVE_BORDER_H

#include "./grid.abstract.hpp"

/////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                             //
//                                       CABECERA                                              //
//                                                                                             //
/////////////////////////////////////////////////////////////////////////////////////////////////

class GridWithReflectiveBorder: public Grid {
    public:
        GridWithReflectiveBorder(int t=0): Grid(t) {}
        GridWithReflectiveBorder(int,int, State*, int t=0);
        ~GridWithReflectiveBorder() {}

        const Cell& getCell(int, int) const; // obtiene la célula de una posición i,j (sólo lectura)
        Cell& getCell(int, int); // obtiene la célula (modificable)    
        void frame(int, int, std::ostream&) const;   
};


#endif