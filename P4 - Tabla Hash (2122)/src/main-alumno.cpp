#include <iostream>
#include <system_error>
#include <cstdlib> // system(clear), rand

#include "./Auxiliar/color.inl"
#include "./Auxiliar/alumno.hpp"
#include "./TablaHash/HashTable.tpp"

#include "./DispersionFunction/fdModule.tpp"
#include "./DispersionFunction/fdSum.tpp"
#include "./DispersionFunction/fdPseudoaleatorio.tpp"

#include "./ExplorationFunction/feLineal.tpp"
#include "./ExplorationFunction/feCuadratic.tpp"
#include "./ExplorationFunction/feDoubleDispersion.tpp"
#include "./ExplorationFunction/feRedispersion.tpp"

using namespace std;
enum {ClosedDispersion = 0, OpenedDispersion = 1};

int chooseDispersionType();
template<class Key> DispersionFn<Key>* chooseDispersionFn(unsigned n);
template<class Key> ExplorationFn<Key>* chooseExplorationFn(unsigned n);
template<class Key> void menu(unsigned, DispersionFn<Key>*, ExplorationFn<Key>*, unsigned);

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
    unsigned ts, bs = 0;
    if(system("clear")) throw system_error(errno, system_category(), "Error limpiando la consola");
    color<string>(BOLD_YELL, "Ingrese el tamaño de la tabla: ", cout); cin >> ts; getchar();

    auto fd = chooseDispersionFn<Alumno>(ts);
    auto fe = chooseDispersionType()?  nullptr : chooseExplorationFn<Alumno>(ts);

    if(fe) { 
        color(BOLD_YELL, "\nTamaño del bloque de sinónimos: ", cout); 
        cin >> bs; getchar(); 
    }
    
    menu<Alumno>(ts,fd,fe,bs);

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

/*
* #brief Menu de elección de tipo de dispersión
*/

int chooseDispersionType() {
    int cas;
    do {
        cout << endl;
        cout << "[1] Dispersión abierta" << endl;
        cout << "[2] Dispersión cerrada" << endl;
        cout << ">> "; cin >> cas; getchar();
        switch(cas) {
            case 1: return OpenedDispersion;
            case 2: return ClosedDispersion;
        }
    } while(cas != 1 && cas != 2);
    return OpenedDispersion;
}



/*
* #brief Menu de elección de función de dispersión
* #param n, tamaño de la tabla
*/

template<class Key>
DispersionFn<Key>* chooseDispersionFn(unsigned n) {
    int cas;
    do {
        cout << endl;
        cout << "[1] Módulo" << endl;
        cout << "[2] Pseudoaletorio" << endl;
        cout << "[3] Basado en Suma" << endl;
        cout << ">> "; cin >> cas; getchar();
        switch(cas) {
            case 1: return new fdModule<Key>(n); break;
            case 2: return new fdPseudoaleatorio<Key>(n); break;
            case 3: return new fdSum<Key>(n); break;
        }
    } while(cas != 1 && cas != 2 && cas != 3);
    return new fdModule<Key>(n);
}



/*
* #brief Menu de elección de función de exploración
* #param n, tamaño de la tabla
*/

template<class Key>
ExplorationFn<Key>* chooseExplorationFn(unsigned n) {
    int cas;
    do {
        cout << endl;
        cout << "[1] Lineal" << endl;
        cout << "[2] Cuadrática" << endl;
        cout << "[3] Doble dispersión" << endl;
        cout << "[4] Redispersión" << endl;
        cout << ">> "; cin >> cas; getchar();
        switch(cas) {
            case 1: return new feLineal<Key>(); break;
            case 2: return new feCuadratica<Key>(); break;
            
            case 3: {
                cout << endl << "Seleccione la función de dispersión para la redispersion: ";
                return new feDobleDispersion<Key>(chooseDispersionFn<Key>(n)); 
            }; break;

            case 4: {
                cout << endl << "Seleccione la función de dispersión para la redispersion: ";
                return new feReDispersion<Key>(chooseDispersionFn<Key>(n)); 
            }; break;
        }
    } while(cas != 1 && cas != 2 && cas != 3  && cas != 4);
    return new feLineal<Key>();
}

/*
* #brief Menu principal de la aplicación (insertar, buscar, salir)
* #param ts, tamaño de la tabla
* #param fd, función de dispersión
* #param fe, función de exploración
* #param bs, tamaño del bloque de sinónimos
*/

template<class Key>
void menu(unsigned ts, DispersionFn<Key>* fd, ExplorationFn<Key>* fe, unsigned bs) {
    int cas, alu; Key key;
    HashTable<Key> ht(ts, fd, fe, bs);
    do {
        if(system("clear")) throw system_error(errno, system_category(), "Error limpiando la consola");
        cout << ht;
        cout << endl;
        cout << "[1] Insertar clave" << endl;
        cout << "[2] Buscar clave" << endl;
        cout << "[3] Salir" << endl;
        cout << ">> "; cin >> cas; getchar();
        switch(cas) {
            case 1: {
                cin >> key; 
                ht.insert(key);
            }; break;
            case 2: {
                cout << "Ingrese el alu: "; cin >> alu; getchar();
                ht.search(Alumno(alu,0,""));
            }; break;
        }
    } while(cas != 3);
}