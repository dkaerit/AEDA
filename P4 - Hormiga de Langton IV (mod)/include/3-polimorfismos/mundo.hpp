#ifndef MUNDO_H
#define MUNDO_H


#include "../2-genericas/evector.tcc"
#include "../3-polimorfismos/hormiga.hpp"
#include <iostream>     // cout
#include <list>         // list
#include <utility>      // pair
#include <cstdlib>      // system(clear), rand
#include <unistd.h>     // usleep
#include <iomanip>

using namespace std;
typedef list<Hormiga*>   anthill;
typedef pair<int,int>    range;
typedef pair<point,int>  cell;
typedef evector<cell>    row;
typedef evector<row>     matrix;

static const std::string color[] = { " ", "█" }; 

/**
 * 
 * @verbatim Clase
 * @endverbatim
 * ----------------------------------------------------------------------------------------
 * */

class Mundo {
    protected:
        matrix _malla;
    
    protected:
        void markCells();

    public:
        virtual ~Mundo() {}
        Mundo(int,int);
        Mundo() {}

        virtual void to_s(anthill&);
        virtual void actualizar(anthill&);

        //get/set
        int    getColor(int x, int y) { return _malla[x][y].second; }
        int    getAltura() { return _malla.size(); }
        int    getAchura() { return _malla[_malla.suplim()-1].size(); }  
        matrix& getMalla() { return _malla; }
    
    private:
        virtual void handlerAntOverflow(anthill&,cell&);    
};

/**
 * ------------------------------------------------------------------------------------------
 * @verbatim Definiciones
 * @endverbatim
 * 
 * */

Mundo::Mundo(int acho, int alto) {
    _malla.resize(
        0,acho, evector<cell>(
        0,alto, make_pair(make_pair(0,0),WHITE))
    );
    markCells();
}

void Mundo::markCells() {
    for(int i = _malla.sublim(); i < _malla.suplim(); i++) {
        for(int j = _malla[i].sublim(); j < _malla[i].suplim(); j++) { 
            _malla[i][j].first = make_pair(i,j);
        }
    }
}

static int countExepctions = 0;
void Mundo::actualizar(anthill& ants) {
    try { 
        try {
            for(auto ant: ants) ant->actualizar(getMalla());        
        } catch(cell& c) {
            countExepctions++;
            handlerAntOverflow(ants,c);
        } catch(row& r) {
            countExepctions++;
            handlerAntOverflow(ants,r[_malla.suplim()]);
        }
    } catch(cell& c) {
        countExepctions++;
        handlerAntOverflow(ants,c);
    }
    
}

void Mundo::handlerAntOverflow(anthill& ants, cell& c) {
    int ant_x, ant_y;
        
    const int MIN_ACHURA = _malla[_malla.suplim()-1].sublim(); 
    const int MAX_ACHURA = _malla[_malla.suplim()-1].suplim(); 
    const int MIN_ALTURA = _malla.sublim();                    
    const int MAX_ALTURA = _malla.suplim();    

    for(auto ant: ants) {
        ant_x = ant->getPos().second; // coordenada y de la hormiga
        ant_y = ant->getPos().first;  // coordenada x de la hormiga
        
        // eje vertical
        if(ant_x <= MIN_ALTURA  ) ant->setPos(ant_y,MIN_ALTURA  ); // arriba
        if(ant_x >= MAX_ALTURA-1) ant->setPos(ant_y,MAX_ALTURA-1); // abajo

        // eje horizontal
        if(ant_y <= MIN_ACHURA  ) ant->setPos(MIN_ACHURA,ant_x);   // izquierda
        if(ant_y >= MAX_ACHURA-1) ant->setPos(MAX_ACHURA,ant_x);   // derecha

        // esquinas
        if((ant_x >= MAX_ALTURA-1) && (ant_y <= MIN_ACHURA  )) ant->setPos(MIN_ACHURA,MAX_ALTURA-1); // abajo/izquierda
        if((ant_x >= MAX_ALTURA-1) && (ant_y >= MAX_ACHURA-1)) ant->setPos(MAX_ACHURA,MAX_ALTURA-1); // abajo/derecha
        if((ant_x <= MIN_ALTURA  ) && (ant_y <= MIN_ACHURA  )) ant->setPos(MIN_ACHURA,MIN_ALTURA  ); // arriba/izquierda
        if((ant_x <= MIN_ALTURA  ) && (ant_y >= MIN_ACHURA-1)) ant->setPos(MAX_ACHURA,MIN_ALTURA  ); // arriba/derecha
    }
}

void Mundo::to_s(anthill& ants) {
    bool hubohormiga = 0;
    usleep(149599);
    bool err = system("clear");

    cout << endl;
    for(int i = _malla.sublim(); i < _malla.suplim(); i++) { // recorrer filas
        cout << setw(3) << i << " "; // imprimir el numero de la fila
        for(int j = _malla[i].sublim(); j < _malla[i].suplim(); j++) { // recorrer columnas
            _malla[i][j].first = make_pair(i,j); // actualizo el par de posición de la celda
            for(auto ant: ants) {  // para cada hormiga en una celda
                if((ant->getPos().second == i) && (ant->getPos().first == j)) { // detecto localización
                    if(!hubohormiga) { // si aun no se ha encontrado hormiga (superposiciones)
                        _malla[i][j].second ?  
                        cout << RED_BG  << (*ant) << RESET:  // hormiga en rojo si celda blanca
                        cout << CYAN_BG  << (*ant) << RESET; // hormiga en cyan si celda negro
                    }
                    hubohormiga = 1; // marcar hormiga econtrada
                }
            }
            if(!hubohormiga) // tras recorrer todas las hormigas si no hubo hormiga
            (!_malla[i][j].second) ? cout << color[BLACK] : cout << color[WHITE]; // pintar celda
            hubohormiga = 0; // resetear booleano de hormiga encontrada
        }
        cout << endl; 
    }
    cout << "Excepciones: " << countExepctions << "\n";

    //getchar();
}

#endif