/**
 * @file adult.derived.hpp
 * @author Diego Vázquez Campos (alu0101014326@ull.edu.es)
 * @brief Clase para especificar la particularidad de estado adulto
 * @version 0.1
 * @date 2022-02-22
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef STATE_ADULT_H
#define STATE_ADULT_H

#include "./state.abstract.hpp"

/////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                             //
//                                       CABECERA                                              //
//                                                                                             //
/////////////////////////////////////////////////////////////////////////////////////////////////

class StateAdult: public State {
    public:
        StateAdult(): State() {}
        State* nextState(); // setea el estdo siguiente (_next)
        const char* getState() const; // obtiene el estado actual (_current)
        int neighbors(const Grid&, int i, int j);

};





#endif