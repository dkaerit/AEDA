#include <iomanip>

/**
 * @brief Permite imprimir un instancia de célula por salida estándar
 * @param os Secuencia de crácteres por salida ostream
 * @param cell célula objetivo
 * @return std::ostream& 
 */

inline std::ostream& operator<<(std::ostream& os, const Cell& cell) {
    if(cell.getState() == 'X') os << "◼";
    else os << " ";
    //os << cell.getState();
    //os << "(" << std::setw(2) << cell._i << "," << std::setw(2) << cell._j << ")";
    return os;
}

