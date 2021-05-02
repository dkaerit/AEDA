#include <iostream>
#include <system_error>
#include <cstdlib>      // system(clear), rand

#include "../include/_Auxiliares/colors.inl"
#include "../include/_Genericas/TablaHash.tcc"

// Funciones de dispersión
#include "../include/_FuncionesDispersion/fdModulo.tcc"
#include "../include/_FuncionesDispersion/fdPseudoaleatorio.tcc"

// Funciones de exploración
#include "../include/_FuncionesExploracion/feLineal.tcc"
#include "../include/_FuncionesExploracion/feCuadratica.tcc"
#include "../include/_FuncionesExploracion/feDobleDispersion.tcc"
#include "../include/_FuncionesExploracion/feReDispersion.tcc"

#include "../include/_Otros/alumnado.hpp"

using namespace std;

int protectedMain(int argc, char* argv[]) {

    unsigned size, symos, opt;

    string nombre;
    int edad;
    int alu;
    Alumnado Alumno;

    cout << color("Ingrese el tamaño de la tabla: ", BOLD_YELL); cin >> size;
    cout << color("Ingrese el número de sinonimos: ", BOLD_YELL); cin >> symos;

    fdModulo<Alumnado> fdM(size);
    fdPseudoaleatorio<Alumnado> fdP(size);
    
    feCuadratica<Alumnado> feCu;
    feReDispersion<Alumnado> feRd(&fdP);

    TablaHash<Alumnado> hash(size, symos, &fdM, &feRd);

    while(opt != 0) {
    bool err = system("clear");
    cout << color("Tamaño de la tabla: ", BOLD_YELL) << size << endl;
    cout << "1. Insterar alumno" << endl;
    cout << "2. Buscar alumno" << endl;
    cout << "3. Mostrar tabla" << endl;
    cout << "0. Salir" << endl;
    cout << "Opción: "; cin >> opt;

        switch(opt) {
            case 1: 
                cout << color("\nINSERTAR el valor de la (clave): \n", BOLD_GREN); 
                cout << color(" - Nombre: ", BOLD_GREN); cin >> nombre;
                cout << color(" - Edad: ", BOLD_GREN); cin >> edad;
                cout << color(" - Alu: ", BOLD_GREN); cin >> alu;
                Alumno = Alumnado(alu,edad,nombre);
                if(hash.insertar(Alumno)) cout << color("Insertado correctamente.", BOLD_GREN) << endl;     
                else cout << color("Fallo al insertar.", BOLD_REDD) << endl;
                getchar(); getchar();
                break;

            case 2:
                cout << color("\nBUSCAR el valor de la (clave): ", BOLD_GREN); 
                cout << color("\nAlu: ", BOLD_GREN); cin >> alu;
                Alumno.setAlu(alu);
                if(hash.buscar(Alumno)) cout << color("El elemento está presente en la tabla.", BOLD_GREN) << endl;     
                else cout << color("El elemento NO está presente en la tabla.", BOLD_REDD) << endl;     
                getchar(); getchar();
                break;

            case 3:
                hash.print();
                getchar(); getchar();
                break;

            case 0:
                cout << color("\nSaliendo... ", BOLD_REDD) << endl;
                break;

            default: 
                cout << color("\nEsa no es una opción valida.", BOLD_REDD) << endl;
                getchar(); getchar();
                break;
        }

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
    }

    return EXIT_SUCCESS;
}