#ifndef FE_DOBLEDISPERSION_H
#define FE_DOBLEDISPERSION_H
#include "~fnExploration.tpp"

/////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                             //
//                                       CABECERA                                              //
//                                                                                             //
/////////////////////////////////////////////////////////////////////////////////////////////////

template<class Key>
class feDobleDispersion: public ExplorationFn<Key> {
    private:
        DispersionFn<Key>* fd; 

    public:
        feDobleDispersion(DispersionFn<Key>* fd): fd(fd) {}
        virtual ~feDobleDispersion() {}

        unsigned operator() (const Key& k, unsigned i) const { 
            return ((++i)*((*fd)(k))); 
        }
};

#endif