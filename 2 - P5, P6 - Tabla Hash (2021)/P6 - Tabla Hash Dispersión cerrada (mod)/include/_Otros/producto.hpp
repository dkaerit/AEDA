#ifndef ALUMNADO_H
#define ALUMNADO_H

#include <string>
#include <iostream>
#include "../_Auxiliares/colors.inl"
using namespace std;

/**
 * 
 * @verbatim Clase
 * @endverbatim
 * ----------------------------------------------------------------------------------------
 * */

class Producto {
    private:
        int    _codigo;
        int    _precio;
        string _nombre;
       
    public:
        virtual ~Producto() {}
        Producto() {}
        Producto(int codigo, int precio = 0, string nombre = ""): _codigo(codigo), _precio(precio), _nombre(nombre) {}

        unsigned operator%(unsigned val) const { return _codigo%val; }
        
        bool operator()(Producto const& b) {
        return _codigo == b._codigo
            && _precio == b._precio
            && _nombre == b._nombre;
        }

        friend bool operator<(const Producto& a, const Producto& b) { return a._codigo < b._codigo;}
        friend unsigned srand(const Producto& a) {
            srand(a._codigo);
        }

        string nombre() { return _nombre; }
        int precio() { return _precio; }
        int codigo() { return _codigo; }

        void setCod(int codigo) { _codigo = codigo; }
        friend ostream& operator<<(ostream& os, const Producto& a) {
            os << BGRO_VIOL;
            os << "{";
            os << "nombre: " << a._nombre << ", ";
            os << "precio: " << a._precio << ", ";
            os << "codigo: " << a._codigo;
            os << "}";
            os << RESET;
            return os;
        }
};

/**
 * ----------------------------------------------------------------------------------------
 * @verbatim Definiciones
 * @endverbatim
 * 
 * */

#endif