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

#include "../Cell/cell.basic.hpp"
#include "../Auxiliar/array.helper.tpp"
#include <iomanip> // setw
#include <cassert> // assert
#include <unistd.h> // usleep

class Cell;
typedef Array<Cell> row; 
typedef Array<row> matrix;
typedef std::pair<int,int> point;

class Grid {
    private:
        int    _n, _m; // row x col (n filas: tamaño en alto, m columnsas: tamaño en ancho)
        int    _turns; // turnos que se repite
        matrix _petri; // estrutura de la rejilla

    public:
        Grid(int t=0); 
        Grid(int,int,int t=0); // construye la rejilla dado un x,y,t
        virtual ~Grid() {} // destructor

        const point getDim() const; // obtiene las dimensiones de la rejilla
        const Cell& getCell(int, int) const; // obtiene la célula de una posición i,j (sólo lectura)
        void  setCell(int,int,State);

        void start();
        void nextGeneration(); // controla el paso de las iteraciones
        void toString(); // print grid

        row& operator[](int index);
        bool isMargin(int, int) const;
    
    protected:
        void fill(int);
};

#endif