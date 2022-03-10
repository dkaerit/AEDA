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

const char* StateDead::getState() const {
    return "  "; 
    //return " ";
}

int StateDead::neighbors(const Grid& grid, int i, int j) {
    int adultas = 0;

    // Contar vecinos
    for(auto x = -1; x < 2; x++) {
        for(auto y = -1; y < 2; y++) {
            if(!grid.isMargin(x+i,y+j) && !(x==0 && y==0)) {
                if(instanceof<StateAdult>(grid.getCell(x+i,y+j).getState())) adultas++;
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

const char* StateEgg::getState() const {
    return "⛶ ";
    //return "E";
}

int StateEgg::neighbors(const Grid& grid, int i, int j) {
    int larvas = 0;
    int huevos = 0;

    // Contar vecinos
    for(auto x = -1; x < 2; x++) {
        for(auto y = -1; y < 2; y++) {
            if(!grid.isMargin(x+i,y+j) && !(x==0 && y==0)) {
                if(instanceof<StateLarva>(grid.getCell(x+i,y+j).getState())) larvas++;
                if(instanceof<StateEgg>(grid.getCell(x+i,y+j).getState())) huevos++;
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

const char* StateLarva::getState() const {
    return "▢ ";
    //return "L";
}

int StateLarva::neighbors(const Grid& grid, int i, int j) {
    int larvas = 0;
    int hpa = 0; // suma de huevos pupas y adultas

    // Contar vecinos
    for(auto x = -1; x < 2; x++) {
        for(auto y = -1; y < 2; y++) {
            if(!grid.isMargin(x+i,y+j) && !(x==0 && y==0)) {
                if(instanceof<StateLarva>(grid.getCell(x+i,y+j).getState())) larvas++;
                if(instanceof<StateEgg>(grid.getCell(x+i,y+j).getState())) hpa++;
                if(instanceof<StatePupa>(grid.getCell(x+i,y+j).getState())) hpa++;
                if(instanceof<StateAdult>(grid.getCell(x+i,y+j).getState())) hpa++;
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

const char* StatePupa::getState() const {
    return "◧ ";
    //return "P";
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
                if(instanceof<StateLarva>(grid.getCell(x+i,y+j).getState())) larvas++;
                if(instanceof<StateEgg>(grid.getCell(x+i,y+j).getState())) huevos++;
                if(instanceof<StatePupa>(grid.getCell(x+i,y+j).getState())) pupas++;
                if(instanceof<StateAdult>(grid.getCell(x+i,y+j).getState())) adultas++;
            }
            
        }
    }

    // condiciones
    _next = (larvas > std::max({huevos, pupas, adultas}))? static_cast<State*>(new StateEgg()) : static_cast<State*>(new StateAdult());
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

const char* StateAdult::getState() const {
    return "◼ ";
    //return "A";
}

int StateAdult::neighbors(const Grid& grid, int i, int j) {
    int adultas = 0;

    // Contar vecinos
    for(auto x = -1; x < 2; x++) {
        for(auto y = -1; y < 2; y++) {
            if(!grid.isMargin(x+i,y+j) && !(x==0 && y==0)) {
                if(instanceof<StateAdult>(grid.getCell(x+i,y+j).getState())) adultas++;
            }
            
        }
    }

    // condiciones
    _next = (adultas > 1)? static_cast<State*>(new StateEgg()) : static_cast<State*>(new StateDead());
    return adultas;
}