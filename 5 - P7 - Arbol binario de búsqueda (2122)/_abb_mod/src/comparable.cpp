#include <iostream>
#include <system_error>
#include <cstdlib> // system(clear), rand
#include <iomanip>
#include "ArbolBinario/abe.tpp"
#include "ArbolBinario/abb.tpp"
#include "_auxiliar_/dummy.hpp"
unsigned Dummy::cont;
using namespace std;


/////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                             //
//                                    PROTECTED MAIN                                           //
//                                                                                             //
/////////////////////////////////////////////////////////////////////////////////////////////////

/* 
* #brief Programa primario
* #param argc, cantidad de argumentos 
* #param argv, argumentos[] 
* #return int, código de salida 
*/	
int protectedMain(int argc, char* argv[]) {
    ABE<Dummy> abe;
    ABB<Dummy> abb;
    Dummy::cont = 0;

    // insertar 100 claves aleatorias
    for(int i = 0; i < 1000; i++) {
        int k = rand() % 100;
        abe.insertar(k);
        abb.insertar(k);
    }

    // buscar claves aletorias
    for(int i = 0; i < 20; i++) {
        int k = rand() % 100;
        
        Dummy::cont = 0;
        cout << "ABE(" << setw(3) << k << "): " << abe.buscar(k) << ", contador: " << Dummy::cont << "  //  ";

        Dummy::cont = 0;
        cout << "ABB(" << setw(3) << k << "): " << abb.buscar(k) << ", contador: " << Dummy::cont << endl;
    }

    return EXIT_SUCCESS;
}

/////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                             //
//                                         MAIN                                                //
//                                                                                             //
/////////////////////////////////////////////////////////////////////////////////////////////////

/* 
* #brief Gestión de excepciones finales 
* #param argc, cantidad de argumentos 
* #param argv, argumentos[] 
* #return int, código de salida 
*/	

int main(int argc, char *argv[]) {
    try {
      return protectedMain(argc, argv);  
	} catch(std::system_error& e) {
        std::cerr << e.what() << '\n';
	    return 2;
    }

    return EXIT_SUCCESS;
}

/////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                             //
//                                FUNCIONES DEL MAIN                                           //
//                                                                                             //
/////////////////////////////////////////////////////////////////////////////////////////////////
