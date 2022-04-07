/**
 * @file array.generic.tpp
 * @author Diego Vázquez Campos (alu0101014326@ull.edu.es)
 * @brief Extensión de la cola doble para la creación map-array con indexación negativa
 * @version 0.1
 * @date 2022-03-10
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef ARRAY_H
#define ARRAY_H
#include <iostream>
#include <utility>
#include <deque>
#include <iomanip>

template <class t> using keyval = std::pair<int,t>;
template <class t> using dmap = std::deque<keyval<t>>;
typedef unsigned int index_t;

/////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                             //
//                                       CABECERA                                              //
//                                                                                             //
/////////////////////////////////////////////////////////////////////////////////////////////////

template <class type>
class Array {
    private:
        dmap<type> base; // array/vector/cola
        int zero; // índice mínimo      

    public:
        virtual ~Array() {} // destructor virtual
        Array(): zero(0) { base = dmap<type>(); } // constructor default
        Array(int, const type& value = type()); // constructor (0,max)
        Array(int, int, const type& value = type()); // constructor (min,max)

        dmap<type> getBase()       { return base; } // devuelve el deque-mapa
        dmap<type> getBase() const { return base; } // devuelve el deque-mapa


        type& operator[](const int i); // operador de indexación        
        const type& operator[](const int i) const; // operador de indexación

        int suplim() const { return zero + base.size(); } // limite superiro
        int sublim() const { return zero; } // limite inferior
        int size() const   { return (suplim() - sublim()); } // tamaño del array

        void resize(int, const type& value = type()); // redimensiona el tamaño del array
        void resize(int, int, const type& value = type());  // redimensiona el tamaño del array
        void pushBack(const type&);  // añade un elemento al final del array
        void pushFront(const type&); // añade un elemento al principio del array
        type& popBack(); // remueve el ultimo elemento del array
        type& popFront(); // remueve el primer eleemento del array

        template<class shadow> friend std::ostream& operator<<(std::ostream& os, const Array<shadow>&);
        template<class shadow> friend std::istream& operator>>(std::istream& is, Array<shadow>&);  
};

/////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                             //
//                                     DEFINICIONES                                            //
//                                                                                             //
/////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * #brief Construct a new Array<type>::Array object
 * #tparam type Tipo de valores que almacena el array
 * #param max Dimensión del array
 * #param value Valor inicial a propagar
 */

template<class type>
Array<type>::Array(int max, const type& value):
base(max), zero(0)  {
    for(auto i = 0; i < size(); i++)
        base[i] = std::make_pair(i,value);
}

/**
 * #brief Construct a new Array<type>::Array object
 * #tparam type Tipo de valores que almacena el array
 * #param min, índice mínimo del array  
 * #param max, índice máximo del array 
 * #param value, Valor inicial a propagar 
 */

template<class type>
Array<type>::Array(int min, int max, const type& value):
base((max-min+1)), zero(min) {
    for(auto i = 0; i < size(); i++) 
        base[i] = std::make_pair(min+i,value);
}

/**
 * #brief, Consulta un elemento del array 
 * #tparam type Tipo de valores que almacena el array
 * #param i, índice del elemento a consultar
 * #return type&, referencia al elemento consultado 
 */

template<class type>
type& Array<type>::operator[](const int i) { 
    if(sublim() > i || i >= suplim()) {
        if(sublim()  > i) throw base[i-zero+1].second;
        if(suplim() <= i) throw base[i-zero-1].second;
    } return base[i-zero].second;
}

/**
 * #brief, Consulta un elemento del array
 * #tparam type Tipo de valores que almacena el array
 * #param i, índice del elemento a consultar
 * #return type&, referencia al elemento consultado 
 */

template<class type>
const type& Array<type>::operator[](const int i) const {
    if(sublim() > i || i >= suplim()) {
        if(sublim()  > i) throw base[i-zero+1].second;
        if(suplim() <= i) throw base[i-zero-1].second;
    } return base[i-zero].second;
}  

/**
 * #brief Redimensiona el tamaño del array sin mutar el contenido
 * #tparam type Tipo de valores que almacena el array
 * #param max, Nuevo tamaño del array
 * #param value, Valor inicial a propagar
 */

template<class type>
void Array<type>::resize(int max, const type& value) {
    base.resize(max); zero = 0;
    for(auto i = 0; i < size(); i++)
        base[i] = std::make_pair(i,value);
}



/**
 * #brief Inserta un valor por la cola del array
 * #tparam type, Tipo de valores que almacena el array
 * #param a, Valor a insertar
 */

template<class type>
void Array<type>::pushBack(const type& a) {
    base.push_back(std::make_pair(suplim(),a));
}


/**
 * #brief Inserta un valor por la cabeza del array
 * #tparam type, Tipo de valores que almacena el array
 * #param a, Valor a insertar
 */

template<class type>
void Array<type>::pushFront(const type& a) {
    base.push_front(std::make_pair(zero-1,a));
    zero -= 1;
}


/**
 * #brief Redimensiona el array sin mutar los valores del mismo
 * #tparam type Tipo de valores que almacena el array
 * #param min, tamaño mínimo del array -INF < n < max
 * #param max, tamaño máximo del array min < n < INF
 * #param value, valor a propagar en caso de que el array sea redimensionado
 */

template<class type>
void Array<type>::resize(int min, int max, const type& value) {
    base.resize((max-min)); zero = min;
    for(auto i = 0; i < size(); i++) 
        base[i] = std::make_pair(min+i,value);
}

/**
 * #brief Imprime por salida ostream el contenido del array
 * #tparam type Tipo de valores que almacena el array
 * #param os, flujo de salida
 * #param array, array a imprimir 
 * #return std::ostream&, flujo de salida
 */

template<class type>
static std::ostream& operator<<(std::ostream& os, const Array<type>& array) {
    for(auto &[key,value]: array.base) os << std::setw(3) << key << " " << value << std::endl;
    return os;
}


#endif