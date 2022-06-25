#pragma once
using namespace std;

class Dummy {
    public:
        int clave;
        static unsigned cont;

        Dummy(int clave): clave(clave) {}
        ~Dummy() {}

        bool operator<=(const Dummy& d) const { bool comp = (clave <= d.clave); cont++; return comp; }
        bool operator>=(const Dummy& d) const { bool comp = (clave >= d.clave); cont++; return comp; }
        bool operator<(const Dummy& d) const { bool comp = (clave < d.clave); cont++; return comp; }
        bool operator>(const Dummy& d) const { bool comp = (clave > d.clave); cont++; return comp; }
        bool operator==(const Dummy& d) const { bool comp = (clave == d.clave); cont++; return comp; }
        bool operator!=(const Dummy& d) const { bool comp = (clave != d.clave); cont++; return comp; }
        Dummy& operator=(const Dummy& d) { clave = d.clave; cont++; return *this; }
        operator int() { return clave; }
        friend ostream& operator<<(ostream& os, const Dummy& d) {
            os << d.clave;
            return os;
        }

        friend istream& operator>>(istream& is, Dummy& d) {
            cout << "Ingrese la clave: "; is >> d.clave; getchar();
            return is;
        }
};