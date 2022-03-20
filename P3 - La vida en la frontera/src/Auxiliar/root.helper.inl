#include "../State/headers/dead.derived.hpp"
#include "../State/headers/alive.derived.hpp"

template<class Stream>
Grid definedByFile(Stream&& extract);
Grid definedByCommand(char* argv[]);
Grid definedByDefault();
void refill(Grid& grid);


/**
 * @brief Se define todos los valores por fichero
 * @tparam Stream 
 * @param extract 
 * @return Grid 
 */

template<class Stream>
Grid definedByFile(Stream&& extract) {
    int x, y, r, lcn, i, j;
    char tipo;
    extract >> x >> y >> r >> lcn;
    Grid grid(x, y, new StateDead(), r); 
    
    refill(grid);
    for(auto k = 0; k < lcn; k++) {
        extract >> i >> j;
        extract >> tipo;
        switch(tipo) {
            case 'D': grid.setCell(i, j, new StateDead()); break;
            case 'A': grid.setCell(i, j, new StateAlive()); break;
            default: grid.setCell(i, j, new StateDead()); break;
        }
    }
    
    return grid;
}






/**
 * @brief Se definen las dimensiones de la rejilla y el 
 * número de celdas vivas, pero su posicion es random
 * @param argv 
 * @return Grid 
 */

Grid definedByCommand(char* argv[]) {
    int x = std::stoi(argv[1]), y = std::stoi(argv[2]);
    Grid grid(x, y, new StateDead(), std::stoi(argv[3]));

    refill(grid);
    for(auto i = 0; i < std::stoi(argv[4]); i++) {
        grid.setCell((rand()%x), (rand()%y), new StateAlive());
    }
        
    
    return grid;
}




/**
 * @brief Todos los valores se generan de forma aleatoria
 * @return Grid 
 */

Grid definedByDefault() {
    Grid grid(new StateDead());
    int x = grid.getDim().first; // _n-2, alto
    int y = grid.getDim().second; // _m-2, ancho
    float alpha = 0.325; //porcentaje de células

    refill(grid);
    for(auto i = 0; i < (x*y)*alpha; i++) {
        switch(rand()%2) {
            case 0: grid.setCell(rand()%x, rand()%y, new StateAlive()); break;
            case 1: grid.setCell(rand()%x, rand()%y, new StateDead()); break;
        }
        
    }
        

    return grid;
}


void refill(Grid& grid) {
    for(int i = 0; i < grid.getDim().first; i++) {
        for(int j = 0; j < grid.getDim().second; j++) {
            grid.setCell(i, j, new StateDead()); 
        }
    }
}