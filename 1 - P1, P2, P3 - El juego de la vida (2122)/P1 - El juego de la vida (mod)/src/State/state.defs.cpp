#include "./state.basic.hpp"

int State::getCurrent() const {
    return _current;
}

int State::setCurrent(int st) {
    _current = st;
    return _current;
}

int State::getNext() const {
    return _next;
}



int State::setNext(int st) {
    _next = st;
    return _next;
}