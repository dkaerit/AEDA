#include <iostream>
#include <system_error>
#include <cstdlib> // system(clear), rand
#include "ArbolBinario/abe.tpp"
using namespace std;

template <class Key>
void insertar(AB<Key>* ab) {
    cout << "Ingrese un número: ";
    int num; cin >> num; getchar();
    if(!ab->insertar(num)) { 
        cout << "Error al insertar " << num << endl;
        getchar();
    }
    
}

template <class Key>
void buscar(AB<Key>* ab) {
    cout << "Ingrese un número: ";
    int num; cin >> num; getchar();
    if(ab->buscar(num)) cout << "Encontrado " << num << endl;
    else cout << "No encontrado " << num << endl;
    getchar();
}

template <class Key>
void mostrar(AB<Key>* ab) {
    ab->inorden();
    getchar();
}


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
    int numero, opcion;
    ABE<int> abe;
     
    do {
        if(system("clear")) throw system_error(errno, system_category(), "Error limpiando la consola");
        cout << abe << endl << endl;
        cout << "[0] Salir" << endl;
        cout << "[1] Insertar clave" << endl;
        cout << "[2] Buscar clave" << endl;
        cout << "[3] Mostrar árbol inorden" << endl;
        cout << ">> ";
        cin >> opcion; getchar();

        switch(opcion) {
            case 1: insertar<int>(reinterpret_cast<AB<int>*>(&abe)); break;
            case 2: buscar<int>(reinterpret_cast<AB<int>*>(&abe)); break;
            case 3: mostrar<int>(reinterpret_cast<AB<int>*>(&abe)); break;
            case 0: break;
            default: cout << "Opción inválida" << endl;
        }
    } while(opcion != 0);
        
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
