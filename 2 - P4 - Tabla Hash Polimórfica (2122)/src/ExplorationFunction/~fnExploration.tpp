#ifndef FN_EXPLORACION_H
#define FN_EXPLORACION_H

/////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                             //
//                                       CABECERA                                              //
//                                                                                             //
/////////////////////////////////////////////////////////////////////////////////////////////////

template<class Key>
class ExplorationFn {
    public:
        virtual  unsigned operator()(const Key& k, unsigned i) const = 0; 
};

#endif
