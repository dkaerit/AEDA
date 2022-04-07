#ifndef FE_CUADRATICA_H
#define FE_CUADRATICA_H
#include "~fnExploration.tpp"
#include <cmath>

/////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                             //
//                                       CABECERA                                              //
//                                                                                             //
/////////////////////////////////////////////////////////////////////////////////////////////////

template<class Key>
class feCuadratica: public ExplorationFn<Key> {      
    public:
        virtual ~feCuadratica() {}
        feCuadratica() {}

        unsigned operator()(const Key& k, unsigned i) const { 
            return ((++i)*(++i)); 
        }
};

#endif