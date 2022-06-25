#include <iostream>
#include <system_error>
#include <cstdlib> // system(clear), rand
#include "ArbolBinario/abe.tpp"
#include "ArbolBinario/abb.tpp"
using namespace std;

// @brief Inserta un elemento en el árbol.
// @param ab: árbol

template <class Key>
void insertar(AB<Key>* ab) {
    cout << "Ingrese un número: ";
    int num; cin >> num; getchar();
    if(!ab->insertar(num)) { 
        cout << "Error al insertar " << num << endl;
        getchar();
    }
    
}

// @brief Busca un elemento en el árbol.
// @param ab: árbol

template <class Key>
void buscar(AB<Key>* ab) {
    cout << "Ingrese un número: ";
    int num; cin >> num; getchar();
    if(ab->buscar(num)) cout << "Encontrado " << num << endl;
    else cout << "No encontrado " << num << endl;
    getchar();
}

template <class Key>
void eliminar(AB<Key>* ab) {
    cout << "Ingrese un número: ";
    int num; cin >> num; getchar();
    if(!ab->eliminar(num)) { 
        cout << "Error al eliminar " << num << endl;
        getchar();
    }
}

// @brief Presenta el menú de opciones tras haber elegido el tipo de arbol
// @param ab: arbol a trabajar

template <class Key> 
void options(AB<Key>* ab, int& opcion) {
    do {
        if(system("clear")) throw system_error(errno, system_category(), "Error limpiando la consola");
        cout << *ab << endl << endl;
        cout << "[0] Salir" << endl;
        cout << "[1] Insertar clave" << endl;
        cout << "[2] Buscar clave" << endl;
        cout << "[3] Eliminar clave" << endl;
        //cout << "[4] Mostrar árbol inorden" << endl;
        cout << ">> ";
        cin >> opcion; getchar();

        switch(opcion) {
            case 1: insertar<int>(ab); break;
            case 2: buscar<int>(ab); break;
            case 3: eliminar<int>(ab); break;
            //case 4: ab->inorden(); getchar(); break;
            case 0: break;
            default: cout << "Opción inválida" << endl;
        }
    } while(opcion != 0);
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
    int numero, opcion, tipo;
    ABE<int> abe;
    ABB<int> abb;

    do {
        if(system("clear")) throw system_error(errno, system_category(), "Error limpiando la consola");
        cout << "Tipo de árbol: " << tipo << endl;
        cout << "[1] Árbol ABE" << endl;
        cout << "[2] Árbol ABB" << endl;
        cout << ">> ";
        cin >> tipo; getchar();
        switch(tipo) {
            case 1: options<int>(&abe, opcion); break;
            case 2: options<int>(&abb, opcion); break;
            default: cout << "Opción inválida" << endl;
        }
    } while(tipo != 1 && tipo != 2);

    
    
        
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
