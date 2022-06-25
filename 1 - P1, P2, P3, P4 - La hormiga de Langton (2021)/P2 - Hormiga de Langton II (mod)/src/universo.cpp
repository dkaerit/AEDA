#include "../include/universo.hpp"

Universo::~Universo() {}
Universo::Universo(anthill& ants, Mundo& world):
_ants(ants), _world(world) {}

void Universo::start() {
    for(;;) {
        _world.print(_ants); 
        _world.nextState(_ants);
    }
}