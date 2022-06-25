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

template <class t> using kvp = std::pair<int,t>;
template <class t> using kva = std::deque<kvp<t>>;
typedef unsigned int index_t;

template <class type>
class Array {
    private:
        kva<type> base; // array/vector/cola
        int zero; // índice mínimo      

    public:
        virtual ~Array() {}
        Array(): zero(0) { base = kva<type>(); } // constructor default
        Array(int, const type& value = type()); // constructor (0,max)
        Array(int, int, const type& value = type()); // constructor (min,max)

        kva<type> getBase() { return base; }

        type& operator[](const int i); // operador de indexación        
        const type& operator[](const int i) const; // operador de indexación

        int suplim() const { return zero + base.size(); } // limite superiro
        int sublim() const { return zero; } // limite inferior
        int size() const   { return (suplim() - sublim()); } // tamaño del array

        void resize(int, const type& value = type()); 
        void resize(int, int, const type& value = type()); 
        void pushBack(const type&);  // añade un elemento al final del array
        void pushFront(const type&); // añade un elemento al principio del array
        type& popBack(); // remueve el ultimo elemento del array
        type& popFront(); // remueve el primer eleemento del array

        template<class shadow> friend std::ostream& operator<<(std::ostream& os, const Array<shadow>&);
        template<class shadow> friend std::istream& operator>>(std::istream& is, Array<shadow>&);  
};

/**
 * @brief Construct a new Array<type>:: Array object
 * @tparam type 
 * @param max 
 * @param value 
 */

template<class type>
Array<type>::Array(int max, const type& value):
base(max), zero(0)  {
    for(auto i = 0; i < size(); i++)
        base[i] = std::make_pair(i,value);
}

/**
 * @brief Construct a new Array<type>:: Array object
 * @tparam type 
 * @param min 
 * @param max 
 * @param value 
 */

template<class type>
Array<type>::Array(int min, int max, const type& value):
base((max-min+1)), zero(min) {
    for(auto i = 0; i < size(); i++) 
        base[i] = std::make_pair(min+i,value);
}

/**
 * @brief 
 * @tparam type 
 * @param i 
 * @return type& 
 */

template<class type>
type& Array<type>::operator[](const int i) { 
    if(sublim() > i || i >= suplim()) {
        if(sublim()  > i) throw base[i-zero+1].second;
        if(suplim() <= i) throw base[i-zero-1].second;
    } return base[i-zero].second;
}

/**
 * @brief 
 * @tparam type 
 * @param i 
 * @return type& 
 */

template<class type>
const type& Array<type>::operator[](const int i) const {
    if(sublim() > i || i >= suplim()) {
        if(sublim()  > i) throw base[i-zero+1].second;
        if(suplim() <= i) throw base[i-zero-1].second;
    } return base[i-zero].second;
}  

/**
 * @brief 
 * @tparam type 
 * @param max
 * @param value 
 */

template<class type>
void Array<type>::resize(int max, const type& value) {
    base.resize(max); zero = 0;
    for(auto i = 0; i < size(); i++)
        base[i] = std::make_pair(i,value);
}



/**
 * @brief 
 * @tparam type 
 * @param a 
 */

template<class type>
void Array<type>::pushBack(const type& a) {
    base.push_back(std::make_pair(suplim(),a));
}


/**
 * @brief  
 * @tparam type 
 * @param a 
 */

template<class type>
void Array<type>::pushFront(const type& a) {
    base.push_front(std::make_pair(zero-1,a));
    zero -= 1;
}


/**
 * @brief 
 * @tparam type 
 * @param min 
 * @param max
 * @param value 
 */

template<class type>
void Array<type>::resize(int min, int max, const type& value) {
    base.resize((max-min)); zero = min;
    for(auto i = 0; i < size(); i++) 
        base[i] = std::make_pair(min+i,value);
}

/**
 * @brief 
 * @tparam type 
 * @param os 
 * @param array 
 * @return std::ostream& 
 */

template<class type>
static std::ostream& operator<<(std::ostream& os, const Array<type>& array) {
    for(auto &[key,value]: array.base) os << std::setw(3) << key << " " << value << std::endl;
    return os;
}

#endif