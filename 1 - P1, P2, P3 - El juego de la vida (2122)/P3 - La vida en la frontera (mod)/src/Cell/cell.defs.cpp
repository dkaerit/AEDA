#include "../Cell/cell.basic.hpp"

/////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                             //
//                                DEFINICIONES DE LA CLASE                                     //
//                                                                                             //
/////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Construct a new Cell:: Cell object
 * @param i Posición i en el eje x
 * @param j Posición j en el eje y
 * @param sc Numero entero que define el stado de una célula
 */

Cell::Cell(int i, int j, State* st) {
    _i = i;
    _j = j;
    _state = st;
}




/**
 * @brief Devuelve el estado de la célula
 * @return State 
 */

char Cell::getState() const { 
    return _state->getState(); 
}




/**
 * @brief Devuelve el estado de la célula
 * @param st Nuevo estado
 * @return State Nuevo estado actualizado
 */

void Cell::setState(State* st) { 
    _state = st;
}




/**
 * @brief Asinga una posición a la célula
 * @param i Posición i en el eje x
 * @param j Posición j en el eje y
 */

void Cell::setPos(int i, int j) {
    _i = i;
    _j = j;
}




/**
 * @brief Devuelve la posición de la célula
 * @return point 
 */

point Cell::getPos() { 
    return std::make_pair(_i,_j); 
}



/**
 * @brief Devuelve la posición de la célula
 * @return point 
 */

point Cell::getPos() const { 
    return std::make_pair(_i,_j); 
}




/**
 * @brief Actualiza el estado siguiente de una célula en base al estado de sus células vecinas
 * @param grid 
 * @return int 
 */

int Cell::neighbors(const Grid& grid) {
    _state->neighbors(grid, _i, _j);
    return 0;
}

/**
 * @brief Actualiza el estado actual de la célula segun el estado siguiente de dicha célula
 */

void Cell::updateState() {
    _state = _state->nextState();
}