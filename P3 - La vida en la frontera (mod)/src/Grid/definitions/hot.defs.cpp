#include "../../Grid/headers/hot.derived.hpp"

/////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                             //
//                                DEFINICIONES DE LA CLASE                                     //
//                                                                                             //
/////////////////////////////////////////////////////////////////////////////////////////////////


/**
 * @brief Construct a new Grid:: Grid object
 * @param x Entero de la dimensión del eje x
 * @param y Entero de la dimensión del eje y
 * @param t Entero de los turnos de iteración
 */

GridWithHotOpenBorder::GridWithHotOpenBorder(int x, int y, State* st, int t): 
Grid(x+2, y+2, t) {

    _grid.resize(_n, Array<Cell>(_m, Cell(0,0,st)));
    for(auto i = 0; i < _n; i++) {
        for(auto j = 0; j < _m; j++) {
            if(isMargin(i,j)) _grid[i][j].setState(new StateAlive());
            else              _grid[i][j].setState(st);
            _grid[i][j].setPos(i,j);         
        }
    }
}




/**
 * @brief Get the Cell object
 * @param i 
 * @param j 
 * @return const Cell& 
 */
const Cell& GridWithHotOpenBorder::getCell(int i, int j) const {
    if(!isInside(i,j)) throw std::system_error(errno, std::system_category(),"Posición (i,j) fuera del rango de la rejilla");
    return _grid[i][j];
}




/**
 * @brief Get the Cell object
 * @param i 
 * @param j 
 * @return const Cell& 
 */
Cell& GridWithHotOpenBorder::getCell(int i, int j) {
    if(!isInside(i,j)) throw std::system_error(errno, std::system_category(),"Posición (i,j) fuera del rango de la rejilla");
    return _grid[i][j];
}





/**
 * @brief Representación del borde, específico para este tipo de rejilla
 * @param i 
 * @param j 
 * @param os 
 */
void GridWithHotOpenBorder::frame(int i, int j, std::ostream& os) const {
    int x = _m-1, y=_n-1;

    os << BRED;
    if(j == 0) {
        if(i == 0) os << "┌─";
        if(i == y) os << "└─";
    } 

    if(j == x) {
        if(i == 0) os << "┐";
        if(i == y) os << "┘";
    }

    if(0 < j && j < x) {
        if(i == 0 || i == y) os << "──";
    }

    if(0 < i && i < y) {
        if(j == 0) os << "│ ";
        if(j == x) os << "│";
    }  
    os << RESET;
}  