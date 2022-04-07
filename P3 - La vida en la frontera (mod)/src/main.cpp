#include <iostream>
#include <fstream>
#include <string>

// errores para el throw
#include <cerrno>        // variable global errno
#include <system_error>  // function system_error

#include "Auxiliar/root.helper.inl"


/**
 * @brief Main envuelto por try-catch final
 * @param argc 
 * @param argv 
 * @return int 
 */

int protectedMain(int argc, char* argv[]) {
    srand(time(0));
    int frontera, nc;
    int x = rand()%5+35;
    int y = rand()%5+75; 
    int turns = 0;
    std::ifstream file(argv[1]);
    
    switch(argc) {
        case 2: file >> x >> y >> turns >> nc; break; // 1 argumento
        default: break;
    }

    do {
        if(system("clear")) throw std::system_error(errno, std::system_category(),"Error limpiando la consola");
        
        std::cout << "Selecciona el tipo de frontera: \n\n";
        std::cout << "[0] Frontera natural/abierta (fría)\n";
        std::cout << "[1] Frontera periódica\n";
        std::cout << "[2] Frontera reflectora\n";
        std::cout << "[3] Sin frontera\n";
        std::cout << "[4] Frontera natural/abiert (caliente)\n";
        std::cout << ">> ";
        std::cin >> frontera;

        switch(frontera) {
            case 0: {
                getchar();
                GridWithOpenBorder grid(x, y, new StateDead(), turns);
                SetInitiallCells(argc, nc, file, &grid);
                break;
            } 

            case 1: {
                getchar();
                GridWithPeriodicBorder grid(x, y, new StateDead(), turns);
                SetInitiallCells(argc, nc, file, &grid);
                break;
            }
                
            case 2: {
                getchar();
                GridWithReflectiveBorder grid(x, y, new StateDead(), turns);
                SetInitiallCells(argc, nc, file, &grid);
                break;
            }

            case 3: {
                getchar();
                GridWithoutBorder grid(x, y, new StateDead(), turns);
                SetInitiallCells(argc, nc, file, &grid);
                break;
            }   

            case 4: {
                getchar();
                GridWithHotOpenBorder grid(x, y, new StateDead(), turns);
                SetInitiallCells(argc, nc, file, &grid);
                break;
            }  
               
            default: {
                std::cout << "\nEsa opción no es válida, vuelve a elegir otra opción. [ENTER] \n";
                getchar(); getchar(); 
                break;
            }
        }
        
    } while(frontera != 0 && frontera != 1 && frontera != 2 && frontera != 3);

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

