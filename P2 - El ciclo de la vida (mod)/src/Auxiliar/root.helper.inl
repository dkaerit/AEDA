template<typename Class, typename type>
inline bool instanceof(type *ptr) {
   return dynamic_cast<const Class*>(ptr) != nullptr;
}