#include <iostream>
#include <fstream>

#include "State/egg.derived.hpp"
#include "State/larva.derived.hpp"
#include "State/pupa.derived.hpp"
#include "State/adult.derived.hpp"
#include "State/dead.derived.hpp"

template<class Stream>
inline Grid definedByFile(Stream&& extract);
inline Grid definedByCommand(char* argv[]);
inline Grid definedByDefault();


/**
 * @brief Main envuelto por try-catch final
 * @param argc 
 * @param argv 
 * @return int 
 */

int protectedMain(int argc, char* argv[]) {
    srand(time(0));

    switch(argc) {
        case 2:  definedByFile(std::ifstream(argv[1])).start(); break; // 1 argumento
        case 5:  definedByCommand(argv).start(); break;                // 4 argumentos
        default: definedByDefault().start(); break;
    }
    
    return EXIT_SUCCESS;
}




/**
 * @brief Función main que envuelve protectedMain bajo try-catch (implementación futura)
 * @param argc 
 * @param argv 
 * @return int 
 */

int main(int argc, char* argv[]) {
    return protectedMain(argc, argv);  
}

/**
 * @brief Se define todos los valores por fichero
 * @tparam Stream 
 * @param extract 
 * @return Grid 
 */

template<class Stream>
inline Grid definedByFile(Stream&& extract) {
    int x, y, r, lcn, i, j;
    extract >> x >> y >> r >> lcn;
    Grid grid(x, y, new StateDead(), r); 
    
    for(auto k = 0; k < lcn; k++) {
        extract >> i >> j;
        grid.setCell(i, j, new StateEgg());
    }
    
    return grid;
}






/**
 * @brief Se definen las dimensiones de la rejilla y el 
 * número de celdas vivas, pero su posicion es random
 * @param argv 
 * @return Grid 
 */

inline Grid definedByCommand(char* argv[]) {
    int x = std::stoi(argv[1]), y = std::stoi(argv[2]);
    Grid grid(x, y, new StateDead(), std::stoi(argv[3]));
    
    for(auto i = 0; i < std::stoi(argv[4]); i++) {
        grid.setCell((rand()%x), (rand()%y), new StateEgg());
    }
        
    
    return grid;
}




/**
 * @brief Todos los valores se generan de forma aleatoria
 * @return Grid 
 */

inline Grid definedByDefault() {
    Grid grid(new StateDead());
    int x = grid.getDim().first; // _n-2, alto
    int y = grid.getDim().second; // _m-2, ancho
    //int alpha = 0.125; //porcentaje de células
    float alpha = 0.325; //porcentaje de células
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