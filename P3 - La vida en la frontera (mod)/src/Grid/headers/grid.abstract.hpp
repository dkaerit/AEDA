/**
 * @file grid.class.hpp
 * @author Diego Vázquez Campos (alu0101014326@ull.edu.es)
 * @brief Clase que define la rejilla del juego de la vida 
 * @version 0.1
 * @date 2022-02-22
 * @copyright Copyright (c) 2022
 */

#ifndef GRID_H
#define GRID_H

#include <iomanip> // setw
#include <cassert> // assert
#include <unistd.h> // usleep

// errores para el throw
#include <cerrno>        // variable global errno
#include <system_error>  // function system_error

#include "../../Auxiliar/array.generic.tpp"
#include "../../Auxiliar/colors.helper.inl"
#include "../../Cell/cell.basic.hpp"
class Cell;
class State;

typedef Array<Cell> row; 
typedef Array<row> matrix;
typedef std::pair<int,int> point;

/////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                             //
//                                       CABECERA                                              //
//                                                                                             //
/////////////////////////////////////////////////////////////////////////////////////////////////

class Grid {
    protected:
        int    _n, _m; // row x col (n filas: tamaño en alto, m columnsas: tamaño en ancho)
        int    _turns; // turnos que se repite
        mutable matrix _grid; // estrutura de la rejilla

    public:
        Grid(int t=0): _turns(t) {}
        Grid(int n, int m, int t=0): _n(n), _m(m), _turns(t) {}
        virtual ~Grid() {} // destructor

        virtual const Cell& getCell(int, int) const = 0; // obtiene la célula de una posición i,j (sólo lectura)
        virtual Cell& getCell(int, int) = 0;
        
    public: 
        void setCell(int,int,State*); // setea una celula con un estado dado, en una posición dada
        void start(); // comienza el bucle 
        row& operator[](int index);
        
        virtual void nextGeneration(); // controla el paso de las iteraciones
        virtual const point getDim() const; // obtiene las dimensiones de la rejilla
        
        // print
        virtual void toString(std::ostream&) const; // print grid
        virtual void frame(int,int,std::ostream&) const; // pinta las células que representan el marco como lineas que hacen el cuadrilátero
        
        // checkers
        virtual bool isMargin(int, int) const;
        virtual bool isInside(int, int) const;
        virtual bool isAllDead();
        

};

#include "../definitions/grid.helper.inl"
#endif