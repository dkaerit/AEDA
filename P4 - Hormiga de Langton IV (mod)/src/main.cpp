#include "../include/4-derivadas/mundo-infinito.hpp"
#include "../include/4-derivadas/mundo-finito.hpp"
#include "../include/4-derivadas/hormiga-a.hpp"
#include "../include/4-derivadas/hormiga-b.hpp"
#include "../include/1-auxiliares/macros.tcc"
#include "../include/2-genericas/universo.hpp"

int protectedMain(int argc, char* argv[]) {
    anthill ants;                                     // first   second 
    HormigaA anta(3,4,UP_RI); ants.push_back(&anta); // x=11  y=4 
    HormigaB antb(5 ,6,DO_LE); ants.push_back(&antb); // x=9   y=6
    HormigaB antc(0,7,DO_LE); ants.push_back(&antc);   // x=9   y=6

    Mundo         M(10,20); // 10 filas * 20 columnas (Y*X)
    MundoFinito   Mf(20,20);
    MundoInfinito Mi(-5,15);
    
    int option;
    cout << "1- Mundo Infinito \n";
    cout << "2- Mundo Finitio \n";
    cout << "3- Mundo estándar \n";
    cout << "Elija una opción: ";
    cin >> option;
    switch(option) {
        case 1:  Universo(ants, &Mi).comenzar(); break;
        case 2:  Universo(ants, &Mf).comenzar(); break;
        default: Universo(ants, &M).comenzar(); break;
    }

    

    return EXIT_SUCCESS;
}

/**
 * 
 * @verbatim Gestión de exepciones finales
 * @endverbatim
 * 
*/

int main(int argc, char *argv[]) {
    try {
      return protectedMain(argc, argv);  
	} catch(std::system_error& e) {
        std::cerr << e.what() << '\n';
	    return 2;
    } catch(cell& c) {
        cout << "(" << c.first.first << ", "  << c.first.second << ")";
    }

    return EXIT_SUCCESS;
}