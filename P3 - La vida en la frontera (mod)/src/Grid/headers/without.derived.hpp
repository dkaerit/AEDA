/**
 * @file grid.class.hpp
 * @author Diego Vázquez Campos (alu0101014326@ull.edu.es)
 * @brief Clase que define la rejilla del juego de la vida 
 * @version 0.1
 * @date 2022-02-22
 * @copyright Copyright (c) 2022
 */

#ifndef GRID_WITHOUT_BORDER_H
#define GRID_WITHOUT_BORDER_H

#include "./grid.abstract.hpp"
#include "../../State/headers/dead.derived.hpp"
#include "../../State/headers/alive.derived.hpp"

/////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                             //
//                                       CABECERA                                              //
//                                                                                             //
/////////////////////////////////////////////////////////////////////////////////////////////////

enum frontera { ARRIBA = 0, ABAJO = 1, DERECHA = 2, IZQUIERDA = 3 };
class GridWithoutBorder: public Grid {
    public:
        GridWithoutBorder(int t=0): Grid(t) {}
        GridWithoutBorder(int,int, State*, int t=0);
        ~GridWithoutBorder() {}

        const Cell& getCell(int, int) const; // obtiene la célula de una posición i,j (sólo lectura)
        Cell& getCell(int, int); // obtiene la célula (modificable)    
        void frame(int, int, std::ostream&) const;   

        void handleGridOverflow(int i, int j) const;
        void expandir(int frontera) const;

        // print
        void toString(std::ostream&) const; // print grid
        void nextGeneration();
        
        // checkers
        bool isMargin(int, int) const;
        bool isInside(int, int) const;

        // dimensions
        const int maxh() const { return _grid.suplim()-1; }
        const int maxw() const { return _grid[_grid.suplim()-1].suplim()-1; }
        const int minw() const { return _grid[_grid.suplim()-1].sublim(); }
        const int minh() const { return _grid.sublim(); }
};


#endif