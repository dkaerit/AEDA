#include "../include/hormiga.hpp"

Hormiga::Hormiga(int x, int y) {
    srand(time(0));
    setAim(rand() % 4);
    _now = std::make_pair(x,y);
}

Hormiga::~Hormiga() {}

void Hormiga::setPosition(int x, int y) {
    _now = std::make_pair(x,y);
}

void Hormiga::setAim(int c) {
    if(c == 0) _aim = D_MOV; 
    if(c == 1) _aim = L_MOV; 
    if(c == 2) _aim = U_MOV; 
    if(c == 3) _aim = R_MOV; 
}

void Hormiga::move() {
    
    if(_aim == D_MOV) _now.second++;
    else if(_aim == L_MOV) _now.first--;
    else if(_aim == U_MOV) _now.second--;
    else if(_aim == R_MOV) _now.first++;
}

void Hormiga::turn(int mode) {
    if(mode == 0) { // blanco
        if(_aim == D_MOV) _aim = L_MOV;
        else if(_aim == L_MOV) _aim = U_MOV;
        else if(_aim == U_MOV) _aim = R_MOV;
        else if(_aim == R_MOV) _aim = D_MOV;  
    }
    if(mode == 1) { // negro
        if(_aim == D_MOV) _aim = R_MOV;
        else if(_aim == L_MOV) _aim = D_MOV;
        else if(_aim == U_MOV) _aim = L_MOV;
        else if(_aim == R_MOV) _aim = U_MOV;
    }
    
}