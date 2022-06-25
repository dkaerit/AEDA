#ifndef BLOCK_H
#define BLOCK_H
#include "../Auxiliar/array.tpp"
#include "../Auxiliar/searchers.inl"
#include "~Sequence.tpp"

/////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                             //
//                                       CABECERA                                              //
//                                                                                             //
/////////////////////////////////////////////////////////////////////////////////////////////////

/*
* #title, Clase Block
* #brief, El número de claves sinónimas en cada posición de la tabla hash 
* está acotado por el tamaño del bloque
*/

template<class Key>
class Block: public Sequence<Key> {
    private:
        unsigned blockSize;
        Array<Key> synonyms;
    
    public:
        Block(unsigned bs): blockSize(bs), synonyms() {}
        ~Block() {}

        bool search(const Key& k) const;
        bool insert(const Key& k);
        bool isFull() const;
        
        ostream& toStream(ostream& os = std::cout) const;
        bool contains(const Key& k);        
};

/////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                             //
//                                     DEFINICIONES                                            //
//                                                                                             //
/////////////////////////////////////////////////////////////////////////////////////////////////

/*
* #brief, Busca una clave en el bloque
* #param k, clave a buscar
* #return bool, true si se ha encontrado la clave, false en caso contrario
*/

template<class Key>
bool Block<Key>::search(const Key& k) const {
    for(auto &[key,value]: synonyms.getBase()) {
        if(value == k) {
            cout << BOLD_GREN "La clave " << RESET << value << " ";
            return true;
        }
    }
    
    return false;
}

/*
* #brief, Inserta una clave en la tabla Hash
* #param k, clave a insertar
* #return bool, true si se ha insertado la clave, false en caso contrario
*/

template<class Key>
bool Block<Key>::insert(const Key& k) {  
    if(contains(k)) {
        cout << BOLD_REDD "Ya existe la clave " << RESET << k;
        return false;
    } else if(isFull()) {
        cout << BOLD_REDD "Hubo desbordamiento" << RESET;
        return false;
    } else {
        cout << BOLD_GREN "La clave " << RESET << k << " ";
        synonyms.pushBack(k);
        return true;
    } 
    
    return true;
}

/*
* #brief, Comprueba si el bloque está lleno
* #return bool, true si el bloque está lleno, false en caso contrario
*/

template<class Key>
bool Block<Key>::isFull() const {
    return (synonyms.size() == blockSize)? true : false;
}


/*
* #brief, devuelv al flujo de salida los sinónimos de la posición k
* #param os, flujo de salida
* #return ostream&, flujo de salida
*/

template<class Key>
ostream& Block<Key>::toStream(ostream& os) const {
    bool first = true;
    for(auto &[key,value]: synonyms.getBase()) {
        if(first) {
            if(synonyms.size() == 1) os << " ── ";
            else os << " ┬─ ";
            //os << std::setw(2) << key << ": ";
            first = false;
        } else if(key < synonyms.size()-1) {
            os << "   ├─ ";
            //os << std::setw(2) << key << ": ";
        } else {
            os << "   └─ ";
            //os << std::setw(2) << key << ": ";
        }
        
        color<Key>(BOLD_CYAN, value, os);
        os << std::endl;
    }

    return os;
}

/*
* #brief, Comprueba si la Lista contiene una clave
* #param k, clave a comprobar
* #return bool, true si la Lista contiene la clave, false en caso contrario
*/

template<class Key>
bool Block<Key>::contains(const Key& k) {
    if(linearSearch<Key>(k, synonyms)) return true;
    return false;
}

#endif