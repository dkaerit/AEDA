#include "../../Grid/headers/grid.abstract.hpp"
#include "../../State/headers/dead.derived.hpp"

/////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                             //
//                                DEFINICIONES DE LA CLASE                                     //
//                                                                                             //
/////////////////////////////////////////////////////////////////////////////////////////////////


/**
 * @brief Devuelve un par con las dimensiones del grid
 * @return const point 
 */

const point Grid::getDim() const {
    return std::make_pair(_n-2, _m-2);
}



/**
 * @brief Comienza el bucle
 */

void Grid::start() {   
    if(_turns == 0) { // ¿turnos == 0?
        for(;;) { // Entoces bucle infinito
            //std::cout << "Pintando rejilla" << std::endl;
            std::cout << *this; // Se imprime la rejilla
            if(isAllDead()) break; //  ¿Están todas las células muertas? -> break
            nextGeneration(); // calcular siguiente generación
        }
    
        //if(system("clear")) throw std::system_error(errno, std::system_category(),"Error limpiando la consola");
        std::cout << "\n --- Game Over: Todas las células han muerto. [ PRESS ENTER ]\n";
        getchar();
    } else { // ¿turnos > 0?
        for(auto i = 0; i <= _turns; i++) { // entonces bucle en rango 0...turns
            //std::cout << "Pintando rejilla" << std::endl;
            std::cout << *this; // Se imprime la rejilla
            if(isAllDead()) break; //  ¿Están todas las células muertas? -> break
            nextGeneration(); // Se calcula la siguiente generación
        }
    
        //if(system("clear")) throw std::system_error(errno, std::system_category(),"Error limpiando la consola");
        std::cout << "\n --- Game Over: Se acabaron todos los turnos. [ PRESS ENTER ]\n";
        getchar();
    }
}



/**
 * @brief Set the Cell object
 * @param i 
 * @param j 
 * @param st 
 */
void Grid::setCell(int i, int j, State* st) {
    if(isMargin(i+1,j+1)) throw std::system_error(errno, std::system_category(),"Posición (i,j) fuera del rango de la rejilla");;
    _grid[i+1][j+1].setState(st);
}





/**
 * @brief Calcula el estado siguiente de cada célula de la rejilla
 */

 void Grid::nextGeneration() {
    // primr bucle para calcular estados siguientes
    //std::cout << "Revisando neighbors" << std::endl;
    for(auto i=1; i<_n-1; i++) {
        for(auto j=1; j<_m-1; j++) {
            if(!isMargin(i,j)) _grid[i][j].neighbors(*this);
        }
    }

    // segundo bucle para establecer estdo siguiente de la rejilla
    //std::cout << "Actualizando estados" << std::endl;
    for(auto i=1; i<_n-1; i++) {
        for(auto j=1; j<_m-1; j++) {
            if(!isMargin(i,j)) _grid[i][j].updateState();
        }
    }
 }





/**
 * @brief Imprime por pantalla la rejilla
 */

static bool first_print = true;
void Grid::toString(std::ostream& os) const {

    usleep(149599);  
    if(system("clear")) throw std::system_error(errno, std::system_category(),"Error limpiando la consola");

    os << std::endl;
    for(int i = 0; i < _n; i++) { //for(auto &[i,row]: _grid.getBase()) {
        os << std::setw(3) << i << " "; // imprimir el numero de la fila
        for(int j = 0; j < _m; j++) { //for(auto &[j,cell]: row.getBase()) {
            if(isMargin(i,j)) frame(i,j,os);
            else os << getCell(i,j) << " ";
        }
        os << std::endl;
    }

    if(first_print) { os << "\n[ PRESS ENTER ]"; getchar(); }
    first_print = false;
}

/**
 * @brief Pintar el marco que representa el borde de la rejilla
 * @param i 
 * @param j 
 * @return true 
 * @return false 
 */

void Grid::frame(int i, int j, std::ostream& os) const {
    int x = _m-1, y=_n-1;

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
}   




/**
 * @brief SObrecarga de perador de indexación
 * @param index 
 * @return row& 
 */

row& Grid::operator[](int index) {
    return _grid[index];
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



/**
 * @brief Comprueba que una coordenada esta dentro de la rejilla
 * @param i 
 * @param j 
 * @return true 
 * @return false 
 */
bool Grid::isInside(int i, int j) const {
    //std::cout << i << " " << j << " ~~ " << _n-1 << " " << _m-1 << std::endl;
    return (0 <= i && i < _n && 0 <= j && j < _m);
}





/**
 * @brief Comprueba que todas las células de la rejilla están muertas
 * @return true 
 * @return false 
 */

bool Grid::isAllDead() {
    bool all_dead = true;
    for(auto &[i,row]: _grid.getBase()) {
        for(auto &[j,cell]: row.getBase()) {
            if(cell.getState() != symbol[muerta]) all_dead = false;
        }
    }
    return all_dead;
}