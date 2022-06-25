/**
 * @file pupa.derived.hpp
 * @author Diego Vázquez Campos (alu0101014326@ull.edu.es)
 * @brief Clase para especificar la particularidad de estado pupa
 * @version 0.1
 * @date 2022-02-22
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef STATE_XENON_H
#define STATE_XENON_H

#include "./state.abstract.hpp"

/////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                             //
//                                       CABECERA                                              //
//                                                                                             //
/////////////////////////////////////////////////////////////////////////////////////////////////

//class Grid;
class StateXenon: public State {
    public:
        StateXenon(): State() {}
    
        State* nextState(); // setea el estdo siguiente (_next)
        char getState() const; // obtiene el estado actual (_current)
        int neighbors(const Grid&, int, int);

};

#endif