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
    _pos   = std::make_pair(i,j);
    _state = st;
}




/**
 * @brief Devuelve el estado de la célula
 * @return State 
 */

State* Cell::getState() const { 
    return _state; 
}




/**
 * @brief Devuelve el estado de la célula
 * @param st Nuevo estado
 * @return State Nuevo estado actualizado
 */

State* Cell::setState(State* st) { 
    _state = st;
    return _state;
}




/**
 * @brief Asinga una posición a la célula
 * @param i Posición i en el eje x
 * @param j Posición j en el eje y
 */

void Cell::setPos(int i, int j) {
    _pos = std::make_pair(i,j);
}




/**
 * @brief Devuelve la posición de la célula
 * @return point 
 */

point Cell::getPos() { 
    return _pos; 
}





/**
 * @brief Actualiza el estado siguiente de una célula en base al estado de sus células vecinas
 * @param grid 
 * @return int 
 */

int Cell::neighbors(const Grid& grid) {
    _state->neighbors(grid, _pos.first, _pos.second);
    return 0;
}

/**
 * @brief Actualiza el estado actual de la célula segun el estado siguiente de dicha célula
 */

void Cell::updateState() {
    setState(_state->nextState());
}