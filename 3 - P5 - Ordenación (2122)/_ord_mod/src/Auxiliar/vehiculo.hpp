#ifndef VEHICULO_H
#define VEHICULO_H

class Vehiculo {
    private:
        string matricula;

    public:
        static unsigned cont;
        Vehiculo() {}
        Vehiculo(int m) { matricula = to_string(m); }
        ~Vehiculo() {}
        Vehiculo& operator=(const Vehiculo& v) { matricula = v.matricula; cont++; return *this; }
        operator int() { return stoi(matricula); } // cambio de tipos (string to int)
        bool operator==(const Vehiculo& v) { return matricula == v.matricula; }
        bool operator()(const Vehiculo& v) { return matricula == v.matricula; }
        bool operator<(const Vehiculo& v) { return matricula < v.matricula; }
        bool operator>(const Vehiculo& v) { return matricula > v.matricula; }
        bool operator<=(const Vehiculo& v) { return matricula <= v.matricula; }
        bool operator>=(const Vehiculo& v) { return matricula >= v.matricula; }
        bool operator!=(const Vehiculo& v) { return matricula != v.matricula; }
        friend ostream& operator<<(ostream& os, const Vehiculo& v) {
            os << "{ " << v.matricula << " }";
            return os;
        }
        friend istream& operator>>(istream& is, Vehiculo& v) {
            cout << "Ingrese la matricula: "; is >> v.matricula; getchar();
            return is;
        }

};

#endif