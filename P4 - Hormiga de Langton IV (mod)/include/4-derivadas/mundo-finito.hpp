#ifndef MUNDOFINITO_H
#define MUNDOFINITO_H

#include "../3-polimorfismos/mundo.hpp"

enum atob { ARRIBA_ABAJO = 0, ABAJO_ARRIBA = 1, DERECHA_IZQUIERDA = 2, IZQUIERDA_DERECHA = 3 };

/**
 * 
 * @verbatim Clase
 * @endverbatim
* ------------------------------------------------------------------------------------------
 * */

class MundoFinito: public Mundo { // dimensiones constantes
    public:
        virtual ~MundoFinito() {}
        MundoFinito(int,int);

        void espejo(int,Hormiga&);
        void handlerAntOverflow(anthill&, cell&);
};

/**
 * ------------------------------------------------------------------------------------------
 * @verbatim Definiciones
 * @endverbatim
 * 
 * */

MundoFinito::MundoFinito(int ancho, int largo) {
    _malla.resize(
        0,ancho, evector<cell>(
        0,largo, make_pair(make_pair(0,0),WHITE))
    );
    markCells();
}

void MundoFinito::handlerAntOverflow(anthill& ants, cell& c) {
    int ant_x, ant_y;

    const int MIN_ACHURA = _malla[_malla.suplim()-1].sublim(); 
    const int MAX_ACHURA = _malla[_malla.suplim()-1].suplim(); 
    const int MIN_ALTURA = _malla.sublim();                    
    const int MAX_ALTURA = _malla.suplim();                    

    for(auto ant: ants) {
        ant_x = ant->getPos().second; // coordenada y de la hormiga
        ant_y = ant->getPos().first;  // coordenada x de la hormiga
        
        // eje vertical
        if(ant_x <=  MIN_ALTURA   ) espejo(ARRIBA_ABAJO, (*ant));   // arriba
        if(ant_x >= (MAX_ALTURA-1)) espejo(ABAJO_ARRIBA, (*ant));   // abajo

        // eje horizontal
        if(ant_y <=  MIN_ACHURA   ) espejo(IZQUIERDA_DERECHA, (*ant)); // izquierda
        if(ant_y >= (MAX_ACHURA-1)) espejo(DERECHA_IZQUIERDA, (*ant)); // derecha
    }
}

void MundoFinito::espejo(int AtoB, Hormiga& ant) {
    
    const int MIN_ACHURA = _malla[_malla.suplim()-1].sublim(); 
    const int MAX_ACHURA = _malla[_malla.suplim()-1].suplim(); 
    const int MIN_ALTURA = _malla.sublim();                    
    const int MAX_ALTURA = _malla.suplim();   

    switch(AtoB) {
        case ARRIBA_ABAJO: // negativos a positivos
            ant.setPos(ant.getPos().first,MAX_ALTURA-1); // first en coordenada horizontal
            break;
        
        case ABAJO_ARRIBA: // positivos a negativos
            ant.setPos(ant.getPos().first,MIN_ALTURA);  
            break;
        
        case IZQUIERDA_DERECHA:
            ant.setPos(MAX_ACHURA-1,ant.getPos().second);
            break;

        case DERECHA_IZQUIERDA:
            ant.setPos(MIN_ACHURA,ant.getPos().second);
            break;
    }
}

#endif