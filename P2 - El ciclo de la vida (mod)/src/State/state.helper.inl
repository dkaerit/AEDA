inline std::ostream& operator<<(std::ostream& os, const State* state) {
    os << state->getState();
    return os;
}
