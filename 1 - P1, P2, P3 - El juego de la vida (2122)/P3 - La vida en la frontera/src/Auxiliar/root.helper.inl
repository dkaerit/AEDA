#include "../State/headers/dead.derived.hpp"
#include "../State/headers/alive.derived.hpp"
#include "../Grid/headers/open.derived.hpp"
#include "../Grid/headers/periodic.derived.hpp"
#include "../Grid/headers/reflective.derived.hpp"
#include "../Grid/headers/without.derived.hpp"


/**
 * @brief Se define todos los valores por fichero
 * @tparam Stream 
 * @param extract 
 * @return Grid 
 */

void setInitialCellsByFile(const int nc, std::ifstream& file, Grid* grid) {
    int i,j;
    char tipo;
    for(auto k = 0; k < nc; k++) {
        file >> i >> j;
        file >> tipo;
        //std::cout << "(" << i << ", " << j << ")" << " [" << grid->getDim().first << ", " << grid->getDim().second << "]" << std::endl;
        switch(tipo) {
            case 'D': grid->setCell(i, j, new StateDead()); break;
            case 'A': grid->setCell(i, j, new StateAlive()); break;
            default: grid->setCell(i, j, new StateDead()); break;
        }
    }
}




/**
 * @brief Todos los valores se generan de forma aleatoria
 * @return Grid 
 */

void setInitialCellsByDefault(Grid* grid) {    
    int x = grid->getDim().first; // _n-2, alto
    int y = grid->getDim().second; // _m-2, ancho
    for(auto i = 0; i < (x*y)*0.325; i++) {
        switch(rand()%2) {
            case 0: grid->setCell(rand()%x, rand()%y, new StateAlive()); break;
            case 1: grid->setCell(rand()%x, rand()%y, new StateDead()); break;
        }
    } 
}





/**
 * @brief Rellena el contenido de células muertas para que sean mutables
 * @param grid 
 */

void refill(Grid* grid) {
    for(int i = 0; i < grid->getDim().first; i++) {
        for(int j = 0; j < grid->getDim().second; j++) { 
            grid->setCell(i, j, new StateDead()); 
        }
    }
}



/**
 * @brief Set the Initiall Cells object
 * @param argc 
 * @param nc 
 * @param file 
 * @param grid 
 */
void SetInitiallCells(int argc, int nc, std::ifstream& file, Grid* grid) {
    refill(grid);
    switch(argc) {
        case 2: setInitialCellsByFile(nc, file, grid); break;
        default: setInitialCellsByDefault(grid); break;
    }
    grid->start();
}