#include <iostream>
#include <system_error>
#include <cstdlib>      // system(clear), rand
#include <iomanip>      // setw

#include "../include/_auxiliares/colors.inl"
#include "../include/_Otros/ordenacion.tcc"

using namespace std;

void showStatusTraza();

int protectedMain(int argc, char* argv[]) {

    unsigned opt;
    size_t N;
    deque<int> v;
    int value;
    
    cout << "Tamaño de la secuencia: "; cin >> N;
    v.resize(N,0);

    do {
        bool err = system("clear");
        
        showStatusTraza();
        cout << "\n( N = " << N << " ) → "; traza(v);
        
        cout << "\n\n";
        cout << "1. Ordenación por Inserción.\n";
        cout << "2. Ordenación por Quicksort.\n";
        cout << "3. Ordenación por ShellSort.\n";
        cout << "\n";
        cout << "4. Activar/Desactivar traza.\n";
        cout << "5. Introducir valores manualmente.\n";
        cout << "6. Generar valores automáticamente.\n";
        cout << "7. Redimensionar.\n";
        cout << "\n";
        cout << "0. Salir.\n";
        cout << "\n";
        cout << "Opción: "; cin >> opt;

        switch(opt) {
            case 1:
                Insercion<int>(v,N);
                getchar(); getchar();
                break;

            case 2:
                QuickSort<int>(v,N);
                getchar(); getchar();
                break;

            case 3:
                ShellSort<int>(v,N);
                getchar(); getchar();
                break;
            
            case 4:
                if(trazaOrdenacion) trazaOrdenacion = false;
                else trazaOrdenacion = true;
                break;

            case 5:
                for(int i = 0; i < v.size(); ++i) {
                    cout << "valor " << setw(2) << i <<": ";
                    cin >> value;
                    v[i] = value;
                }
                break;

            case 6:
                srand(time(0));
                for(int i = 0; i < v.size(); ++i) {
                    v[i] = rand()%1001;
                }
                break;
            
            case 7:
                cout << "Nuevo tamaño: "; cin >> N;
                v.resize(N);
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

void showStatusTraza() {
    cout << "[ TRAZA ";
    if(trazaOrdenacion) cout << color("ACTIVADA", BOLD_GREN) << " ]\n";
    else                cout << color("DESACTIVADA", BOLD_REDD) << " ]\n";
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