#include "../include/4-derivadas/mundo-infinito.hpp"
#include "../include/4-derivadas/mundo-finito.hpp"
#include "../include/4-derivadas/hormiga-a.hpp"
#include "../include/4-derivadas/hormiga-b.hpp"
#include "../include/1-auxiliares/macros.tcc"
#include "../include/2-genericas/universo.hpp"

int protectedMain(int argc, char* argv[]) {
    //MundoInfinito Mi(15,10);
    //MundoFinito   Mf(20,10);
    
    
    anthill ants;
    HormigaA anta(-2, 2,DO_LE); ants.push_back(&anta);
    HormigaB antb( 2,-2,UP_RI); ants.push_back(&antb);
    


    Mundo M(-5,6);
    M.to_s(ants);

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
    } catch(std::bad_alloc& e) {
		std::cerr << "main" << ": memoria insuficiente\n";
        return 1;
	} catch(std::system_error& e) {
        std::cerr << e.what() << '\n';
	    return 2;
    } catch(...) {
        std::cout << "Error desconocido\n";
        return 99;
    }

    return EXIT_SUCCESS;
}