/**
 * @file live.derived.hpp
 * @author Diego Vázquez Campos (alu0101014326@ull.edu.es)
 * @brief Clase para especificar la particularidad de estado vivo
 * @version 0.1
 * @date 2022-02-22
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef STATE_ALIVE_H
#define STATE_ALIVE_H

#include "./state.abstract.hpp"

/////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                             //
//                                       CABECERA                                              //
//                                                                                             //
/////////////////////////////////////////////////////////////////////////////////////////////////

class StateAlive: public State {
    public:
        StateAlive(): State() {}
        State* nextState(); // setea el estdo siguiente (_next)
        char getState() const; // obtiene el estado actual (_current)
        int neighbors(const Grid&, int, int);
};



#endif