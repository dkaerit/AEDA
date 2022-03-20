#include "../State/egg.derived.hpp"
#include "../State/larva.derived.hpp"
#include "../State/pupa.derived.hpp"
#include "../State/adult.derived.hpp"
#include "../State/dead.derived.hpp"
#include "../State/xenon.derived.hpp"

template<class Stream>
Grid definedByFile(Stream&& extract);
Grid definedByCommand(char* argv[]);
Grid definedByDefault();


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
    
    for(int i = 0; i < x; i++) {
        for(int j = 0; j < y; j++) {
            grid.setCell(i, j, new StateDead()); 
        }
    }

    for(auto k = 0; k < lcn; k++) {
        extract >> i >> j;
        extract >> tipo;
        switch(tipo) {
            case 'H': grid.setCell(i, j, new StateEgg()); break;
            case 'L': grid.setCell(i, j, new StateLarva()); break;
            case 'P': grid.setCell(i, j, new StatePupa()); break;
            case 'A': grid.setCell(i, j, new StateAdult()); break;
            case 'X': grid.setCell(i, j, new StateXenon()); break;
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

    for(int i = 0; i < x; i++) {
        for(int j = 0; j < y; j++) {
            grid.setCell(i, j, new StateDead()); 
        }
    }
    
    for(auto i = 0; i < std::stoi(argv[4]); i++) {
        grid.setCell((rand()%x), (rand()%y), new StateEgg());
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
    //int alpha = 0.125; //porcentaje de células
    float alpha = 0.325; //porcentaje de células

    for(int i = 0; i < x; i++) {
        for(int j = 0; j < y; j++) {
            grid.setCell(i, j, new StateDead()); 
        }
    }

    //std::cout << "Colocando células en (" << x << ", " << y << "): " << std::endl;
    for(auto i = 0; i < (x*y)*alpha; i++) {
        switch(rand()%4) {
            case 0: grid.setCell(rand()%x, rand()%y, new StateEgg()); break;
            case 1: grid.setCell(rand()%x, rand()%y, new StateLarva()); break;
            case 2: grid.setCell(rand()%x, rand()%y, new StatePupa()); break;
            case 3: grid.setCell(rand()%x, rand()%y, new StateAdult()); break;
        }
        
    }
        

    return grid;
}