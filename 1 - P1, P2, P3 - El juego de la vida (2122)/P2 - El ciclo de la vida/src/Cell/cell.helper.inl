/**
 * @brief Permite imprimir un instancia de célula por salida estándar
 * @param os Secuencia de crácteres por salida ostream
 * @param cell célula objetivo
 * @return std::ostream& 
 */

inline std::ostream& operator<<(std::ostream& os, const Cell& cell) {
    os << cell.getState();
    return os;
}

