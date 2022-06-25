#ifndef ALUMNADO_H
#define ALUMNADO_H

#include <string>
#include <iostream>
using namespace std;

/**
 * 
 * @verbatim Clase
 * @endverbatim
 * ----------------------------------------------------------------------------------------
 * */

class Alumnado {
    private:
        int    _alu;
        int    _edad;
        string _nombre;
       
    public:
        virtual ~Alumnado() {}
        Alumnado() {}
        Alumnado(int alu, int edad = 0, string nombre = ""): _alu(alu), _edad(edad), _nombre(nombre) {}

        unsigned operator%(unsigned val) const { return _alu%val; }
        
        bool operator()(Alumnado const& b) {
        return _alu == b._alu
            && _edad == b._edad
            && _nombre == b._nombre;
        }

        friend bool operator<(const Alumnado& a, const Alumnado& b) { return a._alu < b._alu;}

        string nombre() { return _nombre; }
        int edad() { return _edad; }
        int alu() { return _alu; }

        void setAlu(int alu) { _alu = alu; }
        friend ostream& operator<<(ostream& os, const Alumnado& a) {
            os << "[";
            os << "nombre: " << a._alu << ", ";
            os << "edad: " << a._edad << ", ";
            os << "alu: " << a._nombre;
            os << "]";
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