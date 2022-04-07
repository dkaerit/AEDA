#ifndef FD_MODULO_H
#define FD_MODULO_H
#include "~fnDispersion.tpp"


/////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                             //
//                                       CABECERA                                              //
//                                                                                             //
/////////////////////////////////////////////////////////////////////////////////////////////////

template<class Key>
class fdModule: public DispersionFn<Key> {
    private:
        unsigned tableSize; 
        
    public:
        fdModule(const unsigned n): tableSize(n) {}

        unsigned operator()(const Key& k) const { return k % tableSize; }
};

#endif
