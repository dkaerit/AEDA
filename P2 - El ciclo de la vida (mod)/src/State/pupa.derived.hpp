/**
 * @file pupa.derived.hpp
 * @author Diego Vázquez Campos (alu0101014326@ull.edu.es)
 * @brief Clase para especificar la particularidad de estado pupa
 * @version 0.1
 * @date 2022-02-22
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef STATE_PUPA_H
#define STATE_PUPA_H

#include "./state.abstract.hpp"

/////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                             //
//                                       CABECERA                                              //
//                                                                                             //
/////////////////////////////////////////////////////////////////////////////////////////////////

//class Grid;
class StatePupa: public State {
    public:
        StatePupa(): State() {}
    
        State* nextState(); // setea el estdo siguiente (_next)
        const char* getState() const; // obtiene el estado actual (_current)
        int neighbors(const Grid&, int i, int j);

};




#endif