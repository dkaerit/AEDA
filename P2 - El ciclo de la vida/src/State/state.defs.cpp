/**
 * @file state.defs.cpp
 * @author your name (you@domain.com)
 * @brief Definiciones de las clases derivadas de State
 * @version 0.1
 * @date 2022-03-10
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "./state.abstract.hpp"
#include "./dead.derived.hpp"
#include "./egg.derived.hpp"
#include "./larva.derived.hpp"
#include "./pupa.derived.hpp"
#include "./adult.derived.hpp"


/////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                             //
//                             DEFINICIONES DE LA CLASE DEAD                                   //
//                                                                                             //
/////////////////////////////////////////////////////////////////////////////////////////////////

State* StateDead::nextState() { 
    return _next;
}

char StateDead::getState() const {
    return symbol[muerta];
}


int StateDead::neighbors(const Grid& grid, int i, int j) {
    int adultas = 0;

    // Contar vecinos    
    for(auto x = -1; x < 2; x++) {
        for(auto y = -1; y < 2; y++) {
            if(!grid.isMargin(x+i,y+j) && !(x==0 && y==0)) {
                if(grid.getCell(x+i,y+j).getState() == symbol[adulta]) adultas++;
            }
        }
    }
    
    // condiciones
    _next = (adultas >= 2)? static_cast<State*>(new StateEgg()) : static_cast<State*>(new StateDead());


    return adultas;
}

/////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                             //
//                              DEFINICIONES DE LA CLASE EGG                                   //
//                                                                                             //
/////////////////////////////////////////////////////////////////////////////////////////////////

State* StateEgg::nextState() {
    return _next;
}

char StateEgg::getState() const {
    return symbol[huevo];
}

int StateEgg::neighbors(const Grid& grid, int i, int j) {
    int larvas = 0;
    int huevos = 0;

    // Contar vecinos
    for(auto x = -1; x < 2; x++) {
        for(auto y = -1; y < 2; y++) {
            if(!grid.isMargin(x+i,y+j) && !(x==0 && y==0)) {
                if(grid.getCell(x+i,y+j).getState() == symbol[larva]) larvas++;
                if(grid.getCell(x+i,y+j).getState() == symbol[huevo]) huevos++;
            }
            
        }
    }

    // condiciones
    _next = (larvas > huevos)? static_cast<State*>(new StateDead()) : static_cast<State*>(new StateLarva());
    
    return (larvas+huevos);
}

/////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                             //
//                             DEFINICIONES DE LA CLASE LARVA                                  //
//                                                                                             //
/////////////////////////////////////////////////////////////////////////////////////////////////

State* StateLarva::nextState() {
    return _next;
}

char StateLarva::getState() const {
    return symbol[larva];
}

int StateLarva::neighbors(const Grid& grid, int i, int j) {
    int larvas = 0;
    int hpa = 0; // suma de huevos pupas y adultas

    // Contar vecinos
    for(auto x = -1; x < 2; x++) {
        for(auto y = -1; y < 2; y++) {
            if(!grid.isMargin(x+i,y+j) && !(x==0 && y==0)) {
                if(grid.getCell(x+i,y+j).getState() == symbol[larva]) larvas++;
                if(grid.getCell(x+i,y+j).getState() == symbol[huevo]) hpa++;
                if(grid.getCell(x+i,y+j).getState() == symbol[pupa]) hpa++;
                if(grid.getCell(x+i,y+j).getState() == symbol[adulta]) hpa++;
            }
            
        }
    }

    // condiciones
    _next = (larvas > hpa)? static_cast<State*>(new StateDead()) : static_cast<State*>(new StatePupa());
    return (larvas+hpa);
}

/////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                             //
//                             DEFINICIONES DE LA CLASE PUPA                                   //
//                                                                                             //
/////////////////////////////////////////////////////////////////////////////////////////////////

State* StatePupa::nextState() {
    return _next;
}

char StatePupa::getState() const {
    return symbol[pupa];
}

int StatePupa::neighbors(const Grid& grid, int i, int j) {
    int larvas = 0;
    int huevos = 0;
    int pupas = 0;
    int adultas = 0;

    // Contar vecinos
    for(auto x = -1; x < 2; x++) {
        for(auto y = -1; y < 2; y++) {
            if(!grid.isMargin(x+i,y+j) && !(x==0 && y==0)) {
                if(grid.getCell(x+i,y+j).getState() == symbol[larva]) larvas++;
                if(grid.getCell(x+i,y+j).getState() == symbol[huevo]) huevos++;
                if(grid.getCell(x+i,y+j).getState() == symbol[pupa]) pupas++;
                if(grid.getCell(x+i,y+j).getState() == symbol[adulta]) adultas++;
            }
            
        }
    }

    // condiciones
    _next = (larvas > std::min({huevos, pupas, adultas}))? static_cast<State*>(new StateEgg()) : static_cast<State*>(new StateAdult());
    return adultas;
}


/////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                             //
//                             DEFINICIONES DE LA CLASE ADULT                                  //
//                                                                                             //
/////////////////////////////////////////////////////////////////////////////////////////////////

State* StateAdult::nextState() {
    return _next;
}

char StateAdult::getState() const {
    return symbol[adulta];
}

int StateAdult::neighbors(const Grid& grid, int i, int j) {
    int adultas = 0;

    // Contar vecinos
    for(auto x = -1; x < 2; x++) {
        for(auto y = -1; y < 2; y++) {
            if(!grid.isMargin(x+i,y+j) && !(x==0 && y==0)) {
                if(grid.getCell(x+i,y+j).getState() == symbol[adulta]) adultas++;
            }
            
        }
    }

    // condiciones
    _next = (adultas > 1)? static_cast<State*>(new StateEgg()) : static_cast<State*>(new StateDead());
    
    return adultas;
}