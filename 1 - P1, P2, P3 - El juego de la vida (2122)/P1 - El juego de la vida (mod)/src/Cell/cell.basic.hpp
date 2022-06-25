/**
 * @file cell.class.hpp
 * @author Diego Vázquez Campos (alu0101014326@ull.edu.es)
 * @brief Clase que define la célula de una rejilla 
 * @version 0.1
 * @date 2022-02-22
 * @copyright Copyright (c) 2022
 */

#ifndef CELL_H
#define CELL_H

#include "../State/state.basic.hpp"
#include "../Grid/grid.basic.hpp"

#include <utility>
#include <iostream>

class Grid;
typedef std::pair<int,int> point;

class Cell {
    private:
        State _state; // state.life = viva|muerta
        point _pos;   // first: eje x, second: eje y

    public:
        Cell() {} // constructor por defecto
        Cell(int, int, int); // construye la célula dado i,j,code
        virtual ~Cell() {} // destructor

        State getState() const; // state getter
        State setState(State); // state setter
        

        point getPos(); // pos getter
        void  setPos(int,int); // pos setter
        
        int neighbors(const Grid&); // consultar el estado de los vecinos, devuelve vivo o muerto (code)
        void updateState(); // mira las 8 células vecinas y actualiza el estado de la celula central
    
        friend std::ostream& operator<<(std::ostream&, const Cell&); // print cell
    
    protected:
        int countNeighbors(const Grid&, const State&); // cuenta los vecinos que cumplan un estado dado
};

#include "./cell.helper.inl"
#endif




