/**
 * @file state.class.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-02-22
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef STATE_H
#define STATE_H

#include <string>

enum StateCoding { viva=0, muerta=1 };
static const std::string symbol[] = { "◼ ", "  " };

class State {
    private:
        int _current; // código entero que define el estado
        int _next; // estado siguiente

    public:
        State(int current=muerta): _current(current) {} // constructor dado un código (viva|muerta)
        virtual ~State() {} // destructor

        int getCurrent() const; // get estado actual
        int setCurrent(int); // set estado actual

        int getNext() const; // get estado siguiente
        int setNext(int); // set estado siguiente
};

#endif



