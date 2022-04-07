#ifndef FN_DISPERSION_H
#define FN_DISPERSION_H

/////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                             //
//                                       CABECERA                                              //
//                                                                                             //
/////////////////////////////////////////////////////////////////////////////////////////////////

template<class Key>
class DispersionFn {
    public:
        virtual unsigned operator()(const Key& k) const = 0; 
};

#endif
