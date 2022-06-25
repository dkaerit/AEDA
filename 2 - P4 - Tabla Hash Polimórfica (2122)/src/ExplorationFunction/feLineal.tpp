#ifndef FE_LINEAL_H
#define FE_LINEAL_H
#include "~fnExploration.tpp"

/////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                             //
//                                       CABECERA                                              //
//                                                                                             //
/////////////////////////////////////////////////////////////////////////////////////////////////

template<class Key>
class feLineal: public ExplorationFn<Key> {
    public:
        feLineal() {}
        virtual ~feLineal() {}

        unsigned operator()(const Key& k, unsigned i) const { return ++i; }
};

#endif