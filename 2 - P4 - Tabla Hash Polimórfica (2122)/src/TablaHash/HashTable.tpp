#ifndef TABLA_HASH_H
#define TABLA_HASH_H
#include <iostream>
#include "../Auxiliar/message.inl"
#include "../Auxiliar/array.tpp"
#include "../Sequence/Block.tpp"
#include "../Sequence/List.tpp"
#include "../DispersionFunction/~fnDispersion.tpp"
#include "../ExplorationFunction/~fnExploration.tpp"

/////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                             //
//                                       CABECERA                                              //
//                                                                                             //
/////////////////////////////////////////////////////////////////////////////////////////////////

template <class Key>
class HashTable {
    private:
        unsigned tableSize; // Número de posciciones en la tabla hash
        Array<Sequence<Key>*> table; // Estructura de la tabla hash
        DispersionFn<Key>* fd; // Función de dispersión
        ExplorationFn<Key>* fe; // función de exploración        
        unsigned blockSize; 

    public:
        HashTable(unsigned, DispersionFn<Key>*, ExplorationFn<Key>* fep = nullptr, unsigned bsp = 0);
        virtual ~HashTable() {}

        bool search(const Key& k) const;
        bool insert(const Key& k);

        template<class shadow> friend ostream& operator<<(ostream&, const HashTable<shadow>&);
};

/////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                             //
//                                     DEFINICIONES                                            //
//                                                                                             //
/////////////////////////////////////////////////////////////////////////////////////////////////

/*
* #brief Constructor
* #param tableSize, tamaño de la tabla hash
* #param fd, función de dispersión
* #param fe, función de exploración
* #param bs, tamaño del bloque
*/

template <class Key>
HashTable<Key>::HashTable(unsigned tsp, DispersionFn<Key>* fdp, ExplorationFn<Key>* fep, unsigned bsp):
tableSize(tsp), fd(fdp), fe(fep), blockSize(bsp) {
    table = Array<Sequence<Key>*>(tableSize);
    for(unsigned i = 0; i < tableSize; i++) {
        if(fe) table[i] = new Block<Key>(blockSize);
        else   table[i] = new List<Key>();
    }
}

/* 
* #brief Busca una clave en la tabla hash
* #param k, clave a buscar
* #return bool, true si la clave se encuentra en la tabla hash, false en caso contrario
*/

template <class Key>
bool HashTable<Key>::search(const Key& k) const {
    unsigned pos = (*fd)(k), bet{pos}; // posición de la clave en la tabla hash

    if(table[bet]->search(k)) return success("se encontró",bet);
    else if(fe) { 
        // Si no se encontró y se está usando fe, es que se reubicó por desbordamiento
        // Mientras no se vuelva a la posición desde la que se partió
        do { 
            if(table[bet]->isFull()) bet = (*fe)(k,bet)%tableSize;
            if(table[bet]->search(k)) return success("se encontró",bet);
        } while(bet != pos); 
    } 
    
    return failure("\nNo se encontró la clave."); // No existe en la tabla hash
}

/* 
* #brief Inserta una clave en la tabla hash
* #param k, clave a insertar
* #return bool, true si la clave se insertó en la tabla hash, false en caso contrario
*/

template <class Key>
bool HashTable<Key>::insert(const Key& k) {
    unsigned pos = (*fd)(k), bet{pos}; // posición de la clave en la tabla hash
    
    if(table[bet]->insert(k)) return success("se insertó en",bet); 
    else if(fe) { 
        // si no se pudo insertar y se está usando fe, es que hubo desbordamiento
        // Mientras no se vuelva a la posición desde la que se partió
        do { 
            if(table[bet]->contains(k)) return failure("",bet);
            if(table[bet]->isFull()) {
                failure("",bet);
                bet = (*fe)(k,bet)%tableSize;
            }

            if(table[bet]->insert(k)) return success("se insertó en",bet);
        } while(bet != pos); 
    }

    return failure("\nNo se pudo insertar."); // O la tabla estaba llena, o ya existe dicha clave
}

/*
* #brief Operador de salida
* #param os, flujo de salida
* #param ht, tabla hash
* #return os, flujo de salida
*/

template <class shadow>
static ostream& operator<<(ostream& os, const HashTable<shadow>& ht) {

    for(auto &[key,value]: ht.table.getBase()) {
        os << std::setw(2) << key;
        os << (*value);
        os << std::endl;
    }

    return os;
}


#endif