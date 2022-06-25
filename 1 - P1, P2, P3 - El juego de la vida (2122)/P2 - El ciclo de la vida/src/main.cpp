#include <iostream>
#include <fstream>
#include <string>

#include "Auxiliar/root.helper.inl"


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

