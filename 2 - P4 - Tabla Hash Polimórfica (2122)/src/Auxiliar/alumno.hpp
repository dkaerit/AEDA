#ifndef ALUMNADO_H
#define ALUMNADO_H

#include "color.inl"
#include <string>
#include <iostream>
#include <cstdlib> // RAND_MAX
using namespace std;

class Alumno {
    private:
        int    alu;
        int    edad;
        string nombre;

    public:
        Alumno(): alu(0), edad(0), nombre("") {}
        Alumno(int alu, int edad, string nombre): alu(alu), edad(edad), nombre(nombre) {}
        Alumno(const Alumno& a): alu(a.alu), edad(a.edad), nombre(a.nombre) {}
        ~Alumno() {}

        int getAlu() const { return alu; }
        int getEdad() const { return edad; }
        string getNombre() const { return nombre; }

        friend void srand(const Alumno& a) { srand(a.alu); }
        bool operator==(const Alumno& a) const { return alu == a.alu; }
        operator int() const { return alu; }
        Alumno operator=(int a) { return Alumno(a,edad,nombre); }

        bool operator()(Alumno const& b) { return alu == b.alu; }



        friend ostream& operator<<(ostream& os, const Alumno& a) {
            os << "{ " << a.alu << ", " << a.edad << ", " << a.nombre << " }";
            return os;
        }

        friend istream& operator>>(istream& is, Alumno& a) {
            cout << "Ingrese el alu: "; is >> a.alu; getchar();
            cout << "Ingrese la edad: "; is >> a.edad; getchar();
            cout << "Ingrese el nombre: "; is >> a.nombre; getchar();
            return is;
        }

};

#endif