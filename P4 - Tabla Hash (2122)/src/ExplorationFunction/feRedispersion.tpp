#ifndef FE_REDISPESION_H
#define FE_REDISPESION_H
#include "~fnExploration.tpp"
#include <cstdlib> // RAND_MAX

/////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                             //
//                                       CABECERA                                              //
//                                                                                             //
/////////////////////////////////////////////////////////////////////////////////////////////////

template<class Key>
class feReDispersion: public ExplorationFn<Key> {  
    private:
        DispersionFn<Key>* fd; 

    public:
        feReDispersion(DispersionFn<Key>* fd): fd(fd) {}
        virtual ~feReDispersion() {}

        unsigned operator()(const Key& k, unsigned i) const {
            Key value; 
            srand(k);
            for(int j = 0; j < i; ++j) value = rand();
            return ((++i)*((*fd)(value)));
        }
};

#endif