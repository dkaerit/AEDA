/**
 * @file state.abstract.hpp
 * @author Diego Vázquez Campos (alu0101014326@ull.edu.es)
 * @brief Clase para especificar la abstracción de estados
 * @version 0.1
 * @date 2022-02-22
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef STATE_H
#define STATE_H

#include <algorithm>
#include "../Grid/grid.basic.hpp"
class Grid;

enum StateCoding { muerta=0, huevo=1, larva=2, pupa=3, adulta=4 };
static char symbol[] = { ' ', 'H', 'L', 'P', 'A' };
//static const char* especial[] = { " ", "⛶", "▢", "◧", "◼" };


/////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                             //
//                                       CABECERA                                              //
//                                                                                             //
/////////////////////////////////////////////////////////////////////////////////////////////////

class State {
    protected:
        State* _next; // estado siguiente

    public:
        State() {} // constructor dado un código (viva|muerta)
        virtual ~State() {} // destructor

        // Funciones nulas
        virtual State* nextState() = 0; // setea el estdo siguiente (_next)
        virtual void setNext(State* st) {
            _next = st;
        }
        virtual char getState() const = 0; // obtiene el estado actual (_current)
        virtual int neighbors(const Grid&, int i, int j) = 0; // cuenta la vecindad

        friend std::ostream& operator<<(std::ostream&, const State* state); // print cell
    
    protected:
        
};

#endif



