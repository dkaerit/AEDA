#ifndef LIST_H
#define LIST_H
#include "../Auxiliar/array.tpp"
#include "../Auxiliar/searchers.inl"
#include "~Sequence.tpp"

/////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                             //
//                                       CABECERA                                              //
//                                                                                             //
/////////////////////////////////////////////////////////////////////////////////////////////////

/*
* #title, Clase List
* #brief, La tabla Hash puede almacenar un número indefinido de sinónimos 
* en una posición concreta de la misma
*/

template<class Key>
class List: public Sequence<Key> {
    private:
        Array<Key> synonyms;

    public:
        List(): synonyms() {}
        ~List() {}

        bool search(const Key& k) const;
        bool insert(const Key& k);
        bool isFull() const { return false; }

        ostream& toStream(ostream& os = std::cout) const;
        bool contains(const Key& k);
};

/////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                             //
//                                     DEFINICIONES                                            //
//                                                                                             //
/////////////////////////////////////////////////////////////////////////////////////////////////

/*
* #brief, Busca una clave en la Lista
* #param k, clave a buscar
* #return bool, true si se ha encontrado la clave, false en caso contrario
*/

template<class Key>
bool List<Key>::search(const Key& k) const {
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
bool List<Key>::insert(const Key& k) {    
    if(contains(k)) {
        cout << BOLD_REDD "Ya existe la clave " << RESET << k;
        return false;
    } else {
        cout << BOLD_GREN "La clave " << RESET << k << " ";
        synonyms.pushBack(k);
        return true;
    } 
    
    return true;
}

/*
* #brief, Devuelve al flujo de salida los sinónimos
* #param os, flujo de salida
* #return ostream&, flujo de salida
*/

template<class Key>
ostream& List<Key>::toStream(ostream& os) const {
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
bool List<Key>::contains(const Key& k) {
    if(linearSearch<Key>(k, synonyms)) return true;
    return false;
}

#endif