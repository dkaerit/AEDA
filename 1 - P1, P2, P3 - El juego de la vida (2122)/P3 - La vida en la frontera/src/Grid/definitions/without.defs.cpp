#include "../../Grid/headers/without.derived.hpp"

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

GridWithoutBorder::GridWithoutBorder(int x, int y, State* st, int t): 
Grid(x+2, y+2, t) {
    _grid.resize(_n, Array<Cell>(_m, Cell(0,0,st)));
    for(auto i = 0; i < _n; i++) {
        for(auto j = 0; j < _m; j++) {
            _grid[i][j].setState(st);
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
const Cell& GridWithoutBorder::getCell(int i, int j) const {
    if(!isInside(i,j)) throw std::system_error(errno, std::system_category(),"Posición (i,j) fuera del rango de la rejilla");
    //std::cout << "(" << i << "," << j << ")" << std::endl;
    return _grid[i][j];
}




/**
 * @brief Get the Cell object
 * @param i 
 * @param j 
 * @return const Cell& 
 */
Cell& GridWithoutBorder::getCell(int i, int j) {
    if(!isInside(i,j)) throw std::system_error(errno, std::system_category(),"Posición (i,j) fuera del rango de la rejilla");
    //std::cout << "(" << i << "," << j << ")" << std::endl;
    return _grid[i][j];
}





/**
 * @brief Representación del borde, específico para este tipo de rejilla
 * @param i 
 * @param j 
 * @param os 
 */
void GridWithoutBorder::frame(int i, int j, std::ostream& os) const {
    os << BRED;
    if(j == minw()) {
        if(i == minh()) os << "┌─";
        if(i == maxh()) os << "└─";
    } 

    if(j == maxw()) {
        if(i == minh()) os << "┐";
        if(i == maxh()) os << "┘";
    }

    if(minw() < j && j < maxw()) {
        if(i == minh() || i == maxh()) os << "──";
    }

    if(minh() < i && i < maxh()) {
        if(j == minw()) os << "│ ";
        if(j == maxw()) os << "│";
    }  
    os << RESET;
}  




/**
 * @brief 
 * @param i 
 * @param j 
 */

void GridWithoutBorder::handleGridOverflow(int i, int j) const {
    //std::cout << "(" << i << "," << j << ") <==> (";
    //std::cout << "[w//" << minw() << " - " << maxw() << "]";
    //std::cout << "[h//" << minh() << " - " << maxh() << "]";
    //std::cout << std::endl;

    if(i >= maxh()-1) expandir(ABAJO);     // abajo
    if(j >= maxw()-1) expandir(DERECHA);   // derecha

    if(i <= minh()+1) expandir(ARRIBA);    // arriba
    if(j <= minw()+1) expandir(IZQUIERDA); // izquierda

}




/**
 * @brief 
 * @param frontera 
 */

#include <iomanip>
void GridWithoutBorder::expandir(int frontera) const {
    switch(frontera) {
        case ARRIBA: 
            _grid.pushFront(Array<Cell>(minw(), maxw(), Cell(0,0,new StateDead()) )); 
            break;
        
        case ABAJO:  
            _grid.pushBack(Array<Cell>(minw(), maxw(), Cell(0,0,new StateDead()) ));     
            break;
        
        case DERECHA:
            for(auto &[i,row]: _grid.getBase())
                _grid[i].pushBack( Cell(0,0,new StateDead()) );
            break;

        case IZQUIERDA:
            for(auto &[i,row]: _grid.getBase())
                _grid[i].pushFront( Cell(0,0,new StateDead()) );
            break;
    }

    for(auto &[i,row]: _grid.getBase()) { //for() {
        for(auto &[j,cell]: row.getBase()) { //for() {
            if(getCell(i,j).getState() != symbol[viva]) _grid[i][j] = Cell(i,j, new StateDead());
        }
    }
}


static bool first_print = true;
void GridWithoutBorder::toString(std::ostream& os) const {
    usleep(149599);  
    if(system("clear")) throw std::system_error(errno, std::system_category(),"Error limpiando la consola");

    os << std::endl;
    for(int i = minh(); i <= maxh(); i++) { //for(auto &[i,row]: _grid.getBase()) {
        os << std::setw(3) << i << " "; // imprimir el numero de la fila
        for(int j = minw(); j <= maxw(); j++) { //for(auto &[j,cell]: row.getBase()) {
            if(isMargin(i,j)) frame(i,j,os);
            else os << getCell(i,j) << " ";
        }
        os << std::endl;
    }

    if(first_print) { os << "\n[ PRESS ENTER ]"; getchar(); }
    first_print = false;
}




/**
 * @brief  
 * @param i 
 * @param j 
 * @return true 
 * @return false 
 */

bool GridWithoutBorder::isMargin(int i, int j) const {
    return (i == minh() || j == minw() || i == maxh() || j == maxw());
}




/**
 * @brief 
 * @param i 
 * @param j 
 * @return true 
 * @return false 
 */

bool GridWithoutBorder::isInside(int i, int j) const {
    return (minh() <= i && i <= maxh() && minw() <= j && j <= maxw());
}




/**
 * @brief 
 * 
 */

void GridWithoutBorder::nextGeneration() {
    // check desbordamiento
    for(int i = minh(); i <= maxh(); i++) {
        for(int j = minw(); j <= maxw(); j++) {
            if(getCell(i,j).getState() == symbol[viva]) handleGridOverflow(i, j);
        }
    }
    
    // primr bucle para calcular estados siguientes
    for(int i = minh(); i <= maxh(); i++) {
        for(int j = minw(); j <= maxw(); j++) {
            if(!isMargin(i,j)) _grid[i][j].neighbors(*this);
        }
    }

    // segundo bucle para establecer estdo siguiente de la rejilla
    for(int i = minh(); i <= maxh(); i++) {
        for(int j = minw(); j <= maxw(); j++) {
            if(!isMargin(i,j)) _grid[i][j].updateState();
        }
    }
}
