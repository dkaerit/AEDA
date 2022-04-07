#ifndef FD_PSEUDOALEATORIO_H
#define FD_PSEUDOALEATORIO_H
#include "~fnDispersion.tpp"
#include <cstdlib> // RAND_MAX

/////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                             //
//                                     DEFINICIONES                                            //
//                                                                                             //
/////////////////////////////////////////////////////////////////////////////////////////////////

template<class Key>
class fdPseudoaleatorio: public DispersionFn<Key> {
    private:
        unsigned tableSize; 
        
    public:
        fdPseudoaleatorio(const unsigned n): tableSize(n) {}

        unsigned operator()(const Key& k) const { 
            srand(k);
            return (rand()%tableSize); 
        }
};

#endif