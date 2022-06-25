#include <iostream>
#include <system_error>
#include <cstdlib> // system(clear), rand
#include <fstream>
#include "./Auxiliar/color.inl"
#include "./Auxiliar/vehiculo.hpp"
#include "./Ordenation/quicksort.tpp"
#include "./Ordenation/shellsort.tpp"
#include "./Ordenation/selectsort.tpp"
#include "./Ordenation/heapsort.tpp"
#include "./Ordenation/radixsort.tpp"
unsigned Vehiculo::cont;

using namespace std;

void showStatus();
template<class Key> void menu(Array<Key>& a);

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
    if(system("clear")) throw system_error(errno, system_category(), "Error limpiando la consola");
    srand(time(0));
    
    Vehiculo::cont = 0;
    Array<Vehiculo> a;
    menu<Vehiculo>(a);

    cout << endl;
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

void showStatus() {
    cout << "[ TRAZA ";
    #ifdef TRAZA
        color(BOLD_GREN, "ACTIVADA"); cout << " ]\n";
    #endif

    #ifndef TRAZA
        color(BOLD_REDD, "DESACTIVADA"); cout << " ]\n";
    #endif          
}

template<class Key> 
void menu(Array<Key>& a) {
    int size = 0, opt, mat;
    ifstream file("data.txt");
    Array<Key> b;

    do {
        if(system("clear")) throw system_error(errno, system_category(), "Error limpiando la consola");
        showStatus();
        cout << endl << "count("<< Vehiculo::cont <<"): " << endl;
        cout << "Array("<< size <<"): ";
        for(int i = 0; i < a.size(); i++) cout << a[i] << " ";
        
        
        cout << "\n\n";
        cout << "1. Ordenación por Selección.\n";
        cout << "2. Ordenación por QuickSort.\n";
        cout << "3. Ordenación por ShellSort.\n";
        cout << "4. Ordenación por HeapSort.\n";
        cout << "5. Ordenación por RadixSort.\n";
        cout << "\n";
        cout << "6. Introducir valores del fichero (data.txt).\n";
        cout << "7. Solicitar valores 1 a 1.\n";
        cout << "8. Generar valores automáticamente.\n";
        cout << "9. Redimensionar.\n";
        cout << "\n";
        cout << "0. Salir.\n";
        cout << "\n";
        cout << "Opción: "; cin >> opt;

        switch(opt) {
            case 1: // Selección
                b = a;
                Vehiculo::cont = 0;
                SelectSort<Key>(b);
                getchar(); getchar();
                break;

            case 2: // QuickSort
                b = a;
                Vehiculo::cont = 0;
                QuickSort<Key>(b);
                getchar(); getchar();
                break;

            case 3: // ShellSort
                b = a;
                Vehiculo::cont = 0;
                ShellSort<Key>(b);
                getchar(); getchar();
                break;

            case 4: // HeapSort
                b = a;
                Vehiculo::cont = 0;
                HeapSort<Key>(b);
                getchar(); getchar();
                break;

            case 5: // RadixSort
                b = a;
                Vehiculo::cont = 0;
                RadixSort<Key>(b);
                getchar(); getchar();
                break;

            case 6: // Introducir valores del fichero (data.txt)
            Vehiculo::cont = 0;
                if(file.is_open()) {
                    file >> size;
                    a.resize(size);
                    for(int i = 0; i < size; i++) {
                        file >> mat;
                        a[i] = Vehiculo(mat);
                    }
                    file.close();
                    Vehiculo::cont = 0;
                } else throw system_error(errno, system_category(), "Error abriendo el fichero");
                break;

            case 7: 
                cout << "Nuevo tamaño: "; cin >> size;
                a.resize(size);
                for(int i = 0; i < size; i++) {
                    cout << "Vehículo " << i << ": "; 
                    cin >> mat;
                    a[i] = Vehiculo(mat);
                }
                Vehiculo::cont = 0;
                break;
            
            case 8: // Generar valores automáticamente;
                for(int i = 0; i < size; i++) {
                    a[i] = Vehiculo(rand()%(9999-1000+1)+1000);
                } 
                Vehiculo::cont = 0;
                break;

            case 9:
                cout << "Nuevo tamaño: "; cin >> size;
                a.resize(size);
                Vehiculo::cont = 0;
                break;

            case 0: // Salir
                color(BOLD_REDD, "\nSaliendo... "); cout << endl;
                break;

            default:
                color("\nEsa no es una opción valida.", BOLD_REDD); cout << endl;
                getchar(); getchar();
                break;
        }

    } while(opt != 0);
}