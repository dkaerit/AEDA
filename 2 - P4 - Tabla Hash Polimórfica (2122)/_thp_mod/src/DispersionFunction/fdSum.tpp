#ifndef FD_SUMA_H
#define FD_SUMA_H
#include "~fnDispersion.tpp"

/////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                             //
//                                     DEFINICIONES                                            //
//                                                                                             //
/////////////////////////////////////////////////////////////////////////////////////////////////

template<class Key>
class fdSum: public DispersionFn<Key> {
    private:
        unsigned tableSize; 
        
    public:
        fdSum(const unsigned n): tableSize(n) {}

        unsigned operator()(const Key& k) const { 
            unsigned y, d = 0;
                for(int x = k; x > 0; x /= 10) {
                    y = x % 10;
                    d += y;
                } 
                return (d % tableSize);

            }
};

#endif