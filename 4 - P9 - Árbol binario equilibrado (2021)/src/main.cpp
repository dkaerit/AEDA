#include <iostream>     // cout
#include <system_error> // e.what()
#include <cstdlib>      // system(clear), rand
#include <iomanip>      // setw

#include "../include/__auxiliares/colors.inl"
#include "../include/_arboles/~ArbolBinario.tcc"
#include "../include/_nodos/NodoBinario.tcc"
#include "../include/_otros/cola.tcc"

using namespace std;

int protectedMain(int argc, char* argv[]) {
    int opt, clave;
    nodoB<int>* res;
    AB<int> arbol;

    do {
        bool err = system("clear");
        
        cout << "[0] Salir.\n";
        cout << "[1] Insertar clave.\n";
        cout << "[2] Buscar clave.\n";
        arbol.recorreN();
        cout << "\n\n";
        cout << "Opción: "; cin >> opt;

        

        switch(opt) {
            case 1:
                cout << "Insertar Clave: "; cin >> clave;
                arbol.insertar(clave);
                break;

            case 2:
                cout << "Buscar Clave: "; cin >> clave;
                res = arbol.buscar(clave);
                if(res) cout << "Resultado: " << res->dato;
                else  cout << "["<<BOLD_CYAN<< "null" <<RESET<<"] No se encontró el valor.";
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
    } while(opt != 0);
    
    cout << "\n";
    return EXIT_SUCCESS;
}

/**
 * 
 * @verbatim Funciones globales
 * @endverbatim
 * 
*/



/**
 * 
 * @verbatim Gestión de exepciones finales
 * @endverbatim
 * 
*/

int main(int argc, char *argv[]) {
    try {
      return protectedMain(argc, argv);  
	} catch(system_error& e) {
        cerr << e.what() << '\n';
	    return 2;
    }

    return EXIT_SUCCESS;
}