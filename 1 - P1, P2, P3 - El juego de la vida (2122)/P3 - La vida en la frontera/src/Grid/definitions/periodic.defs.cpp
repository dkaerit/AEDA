#include "../../Grid/headers/periodic.derived.hpp"

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

GridWithPeriodicBorder::GridWithPeriodicBorder(int x, int y, State* st, int t): 
Grid(x+2, y+2, t) {

    const int n = _n-1;
    const int m = _m-1;
    _grid.resize(_n, Array<Cell>(_m, Cell(0,0,st)));
    
    for(auto i = 0; i < _n; i++) {
        for(auto j = 0; j < _m; j++) {
            _grid[i][j].setState(st);
            if(isMargin(i,j)) {
                if(i == 0 && j == 0) _grid[i][j].setPos(n-1, m-1);
                if(i == 0 && j == m) _grid[i][j].setPos(n-1,   1); 
                if(i == n && j == 0) _grid[i][j].setPos(  1, m-1); 
                if(i == n && j == m) _grid[i][j].setPos(  1,   1);

                if(i == 0 && (0 < j && j < m)) _grid[i][j].setPos(n-1,   j); 
                if(j == 0 && (0 < i && i < n)) _grid[i][j].setPos(  i, m-1);
                if(i == n && (0 < j && j < m)) _grid[i][j].setPos(  1,   j);
                if(j == m && (0 < i && i < n)) _grid[i][j].setPos(  i,   1);
            } else _grid[i][j].setPos(i, j); 

        }
    }
}


/**
 * @brief Get the Cell object
 * @param i 
 * @param j 
 * @return const Cell& 
 */
const Cell& GridWithPeriodicBorder::getCell(int i, int j) const {
    if(!isInside(i,j)) throw std::system_error(errno, std::system_category(),"Posición (i,j) fuera del rango de la rejilla");
    
    point p = _grid[i][j].getPos();
    if(isMargin(i,j)) return getCell(p.first, p.second);
    else return _grid[i][j];
}






/**
 * @brief Get the Cell object
 * @param i 
 * @param j 
 * @return Cell& 
 */
Cell& GridWithPeriodicBorder::getCell(int i, int j) {
    if(!isInside(i,j)) throw std::system_error(errno, std::system_category(),"Posición (i,j) fuera del rango de la rejilla");
    
    point p = _grid[i][j].getPos();
    if(isMargin(i,j)) return getCell(p.first, p.second);
    else return _grid[i][j];
}



/**
 * @brief Representación del borde, específico para este tipo de rejilla
 * @param i 
 * @param j 
 * @param os 
 */
void GridWithPeriodicBorder::frame(int i, int j, std::ostream& os) const {
    int x = _m-1, y=_n-1;
    
    os << BMAGT;
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
    
   //os << getCell(i,j) << " ";
}  