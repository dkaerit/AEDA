/**
 * @file dead.derived.hpp
 * @author Diego Vázquez Campos (alu0101014326@ull.edu.es)
 * @brief Clase para especificar la particularidad de estado muerto
 * @version 0.1
 * @date 2022-02-22
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef STATE_DEAD_H
#define STATE_DEAD_H

#include "./state.abstract.hpp"

/////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                             //
//                                       CABECERA                                              //
//                                                                                             //
/////////////////////////////////////////////////////////////////////////////////////////////////

class StateDead: public State {
    public:
        StateDead(): State() {}
        
        State* nextState(); 
        const char* getState() const; 
        int neighbors(const Grid&, int i, int j);

};




#endif