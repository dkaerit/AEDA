#include "./cell.basic.hpp"

/**
 * @brief Construct a new Cell:: Cell object
 * @param i Posición i en el eje x
 * @param j Posición j en el eje y
 * @param sc Numero entero que define el stado de una célula
 */

Cell::Cell(int i, int j, int sc) {
    _pos   = std::make_pair(i,j);
    _state = State(sc);
}




/**
 * @brief Devuelve el estado de la célula
 * @return State 
 */

State Cell::getState() const { 
    return _state; 
}




/**
 * @brief Devuelve el estado de la célula
 * @param st Nuevo estado
 * @return State Nuevo estado actualizado
 */

State Cell::setState(State st) { 
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
 * @brief Actualiza y devuvelve el estado siguiente de una célula en base al estado de sus células vecinas
 * @param grid 
 * @return int 
 */

int Cell::neighbors(const Grid& grid) {
    int x = _pos.first, y = _pos.second;
    //std::cout << "Neighbors (" << x << ", " << y << "): " << std::endl;
    int vivas = countNeighbors(grid, State(viva));
    //if(vivas != 0) std::cout << "(" << x << ", " << y << ") vivas: " << vivas << std::endl;

    switch(_state.getCurrent()) {
        case muerta: return (vivas == 3)?               _state.setNext(viva) : _state.setNext(muerta); break;
        case viva:   return (vivas == 2 || vivas == 3)? _state.setNext(viva) : _state.setNext(muerta); break;
        default: return _state.setNext(muerta);
    }
}

/**
 * @brief Devuelve el número de células vecinas vivas 
 * @param grid 
 * @return int 
 */

int Cell::countNeighbors(const Grid& grid, const State& st) {
    int x = _pos.first, y = _pos.second;
    int vivas = 0;
    for(auto i = -1; i < 2; i++) {
        for(auto j = -1; j < 2; j++) {
            //if(!grid.isMargin(x+i,y+j) && !(i==0 && j==0)) {
            if(grid.isInside(x+i,y+j) && !(i==0 && j==0)) {
                //std::cout << x+i << " " << y+j << " ~~ no es margen" << std::endl;
                if(grid.getCell(x+i,y+j).getState().getCurrent() == st.getCurrent()) vivas++;
                //if(grid.getCell(x+i,y+j).getState().getCurrent() == viva) std::cout << " ~ (" << x+i << ", " << y+j << ") count: " << vivas << std::endl;
            } 
            //std::cout << "~~ fin check margin" << std::endl;
        }
    }
    //std::cout << "~~ fin count" << std::endl;
    return vivas;
}


void Cell::updateState() {
    setState(State(_state.getNext()));
}
