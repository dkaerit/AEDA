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

#include <utility>
#include <string>
#include <iostream>

#include "../State/state.abstract.hpp"
class State;
class Grid;

typedef std::pair<int,int> point;

/////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                             //
//                                       CABECERA                                              //
//                                                                                             //
/////////////////////////////////////////////////////////////////////////////////////////////////

class Cell {
    private:
        State* _state; // estado de la célula
        int _i, _j;   // first: eje x, second: eje y
        bool _transition = false;

    public:
        Cell() {} // constructor por defecto
        Cell(int, int, State*); // construye la célula dado i,j,code
        virtual ~Cell() {} // destructor

        char getState() const; // state getter
        void setState(State*); // state setter

        point getPos(); // pos getter
        void  setPos(int,int); // pos setter
        
        int neighbors(const Grid&); // consultar el estado de los vecinos
        void updateState(); // aplica regla de transición
    
        friend std::ostream& operator<<(std::ostream&, const Cell&); // print cell
};


#include "./cell.helper.inl"
#endif




