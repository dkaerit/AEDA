#include <iostream>
#include <system_error>
#include <cstdlib>      // system(clear), rand

#include "../include/_auxiliares/colors.inl"
#include "../include/_genericas/tablahash.tcc"
#include "../include/_derivadas/fdmodulo.tcc"


using namespace std;

int protectedMain(int argc, char* argv[]) {

    int size, opt, value;
    cout << color("Ingrese el tamaño de la tabla: ", BOLD_YELL); cin >> size;

    fdModulo<int> fd(size);
    TablaHash<int> hash(size, &fd);

    while(opt != 0) {
    bool err = system("clear");
    cout << color("Tamaño de la tabla: ", BOLD_YELL) << size << endl;
    cout << "1. Insterar clave" << endl;
    cout << "2. Buscar clave" << endl;
    cout << "3. Mostrar tabla" << endl;
    cout << "0. Salir" << endl;
    cout << "Opción: "; cin >> opt;

        switch(opt) {
            case 1: 
                cout << color("\nINSERTAR el valor de la (clave): ", BOLD_GREN); cin >> value;
                if(hash.insertar(value)) cout << color("Insertado correctamente.", BOLD_GREN) << endl;     
                else cout << color("Fallo al insertar.", BOLD_REDD) << endl;
                getchar(); getchar();
                break;

            case 2:
                cout << color("\nBUSCAR el valor de la (clave): ", BOLD_GREN); cin >> value;
                if(hash.buscar(value)) cout << color("El elemento está presente en la tabla.", BOLD_GREN) << endl;     
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