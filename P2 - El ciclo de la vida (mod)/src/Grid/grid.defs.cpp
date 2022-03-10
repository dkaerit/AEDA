#include "../Grid/grid.basic.hpp"

/////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                             //
//                                DEFINICIONES DE LA CLASE                                     //
//                                                                                             //
/////////////////////////////////////////////////////////////////////////////////////////////////

Grid::Grid(State* st, int t): _turns(t) {
    srand(time(0));
    _n = (rand()%5+30)+2; // alto
    _m = (rand()%5+85)+2; // ancho

    _petri.resize(_n, Array<Cell>(_m));
    fill(st);
}





/**
 * @brief Construct a new Grid:: Grid object
 * @param x Entero de la dimensión del eje x
 * @param y Entero de la dimensión del eje y
 * @param t Entero de los turnos de iteración
 */

Grid::Grid(int x, int y, State* st, int t): 
_n(x+2), _m(y+2), _turns(t) {
    _petri.resize(_n, Array<Cell>(_m));
    fill(st);
}





/**
 * @brief Propaga una célula en todo el grid (incluyendo márgenes)
 * @param st Estado inicial de la célula a propagar
 */

void Grid::fill(State* st) {
    //std::cout << "Rellenando petri: " << std::endl;
    for(auto i = 0; i < _n; i++) {
        for(auto j = 0; j < _m; j++) {
            _petri[i][j] = Cell(i,j,st);
        }
    }
}





/**
 * @brief Devuelve un par con las dimensiones del grid
 * @return const point 
 */

const point Grid::getDim() const {
    return std::make_pair(_n-2,_m-2);
}







/**
 * @brief Retorna una referencia a la célula en la posición i,j
 * @param i Posición i en el eje x
 * @param j Posición j en el eje y
 * @return const Cell& referenci a célula de sólo lectura
 */

const Cell& Grid::getCell(int i, int j) const {
    assert(!isMargin(i,j));
    return _petri[i][j];
}






/**
 * @brief Setea un estado en la célula ubicda en i, j
 * @param i Posición i en el eje x
 * @param j Posición j en el eje y
 */

void Grid::setCell(int i, int j, State* st) {
    assert(!isMargin(i+1,j+1));
    _petri[i+1][j+1].setState(st);    
}





/**
 * @brief Comienza el bucle
 */

void Grid::start() {
    std::cout << "Start: " << std::endl;
    if(_turns == 0) {
        for(;;) {
            toString();
            nextGeneration();
        }
    } else {
        for(auto i = 0; i <= _turns; i++) {
            toString();
            nextGeneration();
        }
    }

}





/**
 * @brief Calcula el estado siguiente de cada célula de la rejilla
 */

 void Grid::nextGeneration() {
    // calcular estados siguientes
    for(auto i=1; i<_n-1; i++) {
        for(auto j=1; j<_m-1; j++) {
            if(!isMargin(i,j)) _petri[i][j].neighbors(*this);
        }
    }

    // establecer estdo siguiente de la rejilla
    for(auto i=1; i<_n-1; i++) {
        for(auto j=1; j<_m-1; j++) {
            if(!isMargin(i,j)) _petri[i][j].updateState();
        }
    }
 }





/**
 * @brief Imprime por pantalla la rejilla
 */

void Grid::toString() {
    //usleep(249599);
    usleep(199599);
    //usleep(149599);
    //getchar(); getchar();
    bool err = system("clear");

    for(auto &[i,row]: _petri.getBase()) {
        std::cout << std::setw(3) << i << " "; // imprimir el numero de la fila
        for(auto &[j,cell]: row.getBase()) {
            std::cout << cell;
        }
        std::cout << std::endl;
    }
}





/**
 * @brief SObrecarga de perador de indexación
 * @param index 
 * @return row& 
 */

row& Grid::operator[](int index) {
    return _petri[index];
}





/**
 * @brief Comporbación si la posición dda es margen de la rejilla
 * @param i Posición en el eje x
 * @param j Posición en el eje y
 * @return true 
 * @return false 
 */

bool Grid::isMargin(int i, int j) const {
    //std::cout << i << " " << j << " ~~ " << _n-1 << " " << _m-1 << std::endl;
    return (i == 0 || j == 0 || i == (_n-1) || j == (_m-1));
}