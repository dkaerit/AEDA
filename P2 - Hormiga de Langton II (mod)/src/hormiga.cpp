#include "../include/hormiga.hpp"

// macros
#define OVERFLOW(x) x > -1 && x < 8 // es una de las 8 orientaciones
#define DEFAULT(x) x == -1          // es orientación por defecto
#define COMPUESTO(x) x%2 == 0       // es orientación compuesta de orientaciones unitarias

// trazas
#define PPOINT(a,b) std::cout << "(" << a << "," << b << ") ";
#define PDECOMP(a,b) std::cout << "comp:(" << a << "," << b << ") ";
#define PAIM(aim)   std::cout << aim; 

Hormiga::~Hormiga() {}
Hormiga::Hormiga(int x, int y, int aimm) {
    srand(time(0));
    
    assert(OVERFLOW(aimm) || DEFAULT(aimm));
    if(OVERFLOW(aimm)) _aim = aimm;             // orientación inicial definida
    if(DEFAULT(aimm))  _aim = rand()%8;         // orientación inicial aleatoria
    _pos = std::make_pair(x,y);                 // definir posición
}


void Hormiga::basicMove(matrix& m, range sx, range sy) {

    //std::cout << "soy1: (" << aim[_aim] << ") con pos (" << pos().first << "," << pos().second << ")\n";
    turn(m[_pos.second][_pos.first]); // gira según la celda
    //std::cout << "soy2: (" << aim[_aim] << ") con pos (" << pos().first << "," << pos().second << ")\n";
    mirroredAnt(sx, sy);
    move( (COMPUESTO(_aim)) ? decompose(_aim) : ints({_aim}) ); // avanza según el aim 
    //std::cout << "avanzo: (" << aim[_aim] << ") con pos (" << pos().first << "," << pos().second << ")\n";
}

void Hormiga::mirroredAnt(range _sx, range _sy) {
    //std::cout << "posya:" << _pos.second+1 << ", sysec:" << _sy.second << "aim: " << _aim << "d:" << D;
    if(_pos.first == _sx.first && (_aim == UL || _aim == DL || _aim == L))  _pos.first = _sx.second+1;
    if(_pos.first+1 == _sx.second && (_aim == UR || _aim == DR || _aim == R))  _pos.first = _sx.first-1;
    if(_pos.second == _sy.first && (_aim == UR || _aim == UL || _aim == UL)) _pos.second  = _sy.second;
    if(_pos.second+1 == _sy.second && (_aim == DR || _aim == DL || _aim == D)) _pos.second  = _sy.first-1; 
}

void Hormiga::move(const ints& aims) {
    for(int aim: aims) {
        switch(aim) {
            case U: _pos.second -= 1; break; // UP (1)
            case R: _pos.first  += 1; break; // RIGHT (3)
            case D: _pos.second += 1; break; // DOWN (5)
            case L: _pos.first  -= 1; break; // LEFT (7)
        }
    }

}

ints Hormiga::decompose(int m) {
    switch(m) {  // descomponer en aims unitarios
        case UL: return ints({U, L});     break;
        default: return ints({m+1, m-1}); break;
    }
}

void Hormiga::turn(bool cell) {
    switch(cell) {
        case 0: _aim = (_aim == L ) ? UL : _aim+1; break; // BLACK ⭮
        case 1: _aim = (_aim == UL) ? L  : _aim-1; break; // WHITE ⭯             
    }
}

// getters/setters
string Hormiga::to_s() { return aim[_aim]; }
point  Hormiga::pos()  { return _pos; }