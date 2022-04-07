#ifndef SEQUENCE_H
#define SEQUENCE_H
#include <iostream>
#include <algorithm>
#include "../Auxiliar/color.inl"

/////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                             //
//                                       CABECERA                                              //
//                                                                                             //
/////////////////////////////////////////////////////////////////////////////////////////////////

/*
* #title, Clase Sequence
* #brief, Abstracción de List (dispersión abierta) y Block (dispersión cerrada)
*/

template<class Key>
class Sequence {
    public:
        virtual bool search(const Key& k) const = 0;
        virtual bool insert(const Key& k) = 0;
        virtual bool isFull() const = 0;
        
        virtual bool contains(const Key& k);
        virtual ostream& toStream(ostream& os = std::cout) const { return os; }
        template<class shadow> friend ostream& operator<<(ostream&, const Sequence<shadow>&);
};

/////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                             //
//                                     DEFINICIONES                                            //
//                                                                                             //
/////////////////////////////////////////////////////////////////////////////////////////////////

template <class shadow>
static ostream& operator<<(ostream& os, const Sequence<shadow>& seq) {
    return seq.toStream(os);
}

#endif