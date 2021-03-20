#ifndef EVECTOR_H
#define EVECTOR_H

#include <iostream>
#include <vector>
#include <deque>
#include <cassert>

typedef unsigned int index_t; // Tipo del indice

/**
 * 
 * @verbatim Clase
 * @endverbatim
 * 
*/

template<class T>
class evector {
    private:
        std::deque<T> _base; // array vector
        int           _zero; // índice mínimo 

    public:
        virtual ~evector(void);                          
        evector();
        evector(int min, int max, const T& fill = NULL); 
        

        T& operator[](const index_t i)       { return _base[i-_zero]; }                
        T& operator[](const index_t i) const { return _base[i-_zero]; }  
        
        int suplim() const { return _zero + _base.size(); }
        int sublim() const { return _zero; }
        int size() const   { return (suplim() - sublim()); }  

        void push_back(const T& a);
        void push_front(const T& a);   
        void resize(int min, int max, const T& fill = NULL);     

        template<class U> friend std::ostream& operator<<(std::ostream& os, const evector<U>& v);
        template<class U> friend std::istream& operator>>(std::istream& is, evector<U>& v);   
};

/**
 * 
 * @verbatim Definiciones
 * @endverbatim
 * 
 * */

template<class T>
evector<T>::~evector() {}

template<class T>
evector<T>::evector() {
    _base = std::deque<T>();
}

template<class T>
evector<T>::evector(int min, int max, const T& fill):
_base((max-min+1)), _zero(min) {
    _base = std::deque<T>(size(), fill);
}

template<class T>
void evector<T>::resize(int min, int max, const T& fill) {
    _base.resize((max-min));
    _zero = min;
    _base = std::deque<T>(size(), fill);
}

template<class T>
void evector<T>::push_back(const T& a) {
    _base.push_back(a);
}

template<class T>
void evector<T>::push_front(const T& a) {
    _base.push_front(a);
    _zero -= 1;
}

template<class T>
static std::ostream& operator<<(std::ostream& os, const evector<T>& v) {
    for(auto i: v) os << i << " ";
    return os;
}

template<class T>
static std::istream& operator>>(std::istream& is, evector<T>& v) {
    is >> v.size_;
    for(auto i: v) is >> i;
    return is;
}

#endif 