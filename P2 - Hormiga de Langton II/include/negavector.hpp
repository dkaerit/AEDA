#ifndef negavector_H
#define negavector_H

#include <vector>
#include <deque>
#include <cassert>

typedef unsigned int index_t;                            // Tipo del indice

template<class T>
class negavector {
    private:
        std::deque<T> _base;                          // array vector
        int           _zero;                          // índice mínimo 

    public:
        negavector();
        negavector(int min, int max, const T& fill = NULL); // constructor por defecto
        virtual ~negavector(void);                          // destructor

        T& operator[](const index_t i)       { return _base[i-_zero]; }                
        T& operator[](const index_t i) const { return _base[i-_zero]; }  
        
        int suplim() const { return _zero + _base.size(); }
        int sublim() const { return _zero; }
        int size() const   { return (suplim() - sublim()); }  

        void push_back(const T& a);
        void push_front(const T& a);   
        void resize(int min, int max, const T& fill = NULL);     

        //friend std::ostream& operator<< <>(std::ostream& os, const negavector<T>& v);
        //friend istream& operator>> <>(istream& is, negavector<T>& v);   
};

template<class T>
negavector<T>::~negavector() {}

template<class T>
negavector<T>::negavector() {
    _base = std::deque<T>();
}

template<class T>
negavector<T>::negavector(int min, int max, const T& fill):
_base((max-min)), _zero(min) {
    _base = std::deque<T>(size(), fill);
}

template<class T>
void negavector<T>::resize(int min, int max, const T& fill) {
    _base.resize((max-min));
    _zero = min;
    _base = std::deque<T>(size(), fill);
}

template<class T>
void negavector<T>::push_back(const T& a) {
    _base.push_back(a);
}

template<class T>
void negavector<T>::push_front(const T& a) {
    _base.push_front(a);
    _zero -= 1;
}

template<class T>
static std::ostream& operator<<(std::ostream& os, const negavector<T>& v) {
    for(auto i: v) os << i << " ";
    return os;
}

template<class T>
static std::istream& operator>>(std::istream& is, negavector<T>& v) {
    is >> v.size_;
    for(auto i: v) is >> i;
    return is;
}

#endif 