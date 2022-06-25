#ifndef COLORS_H
#define COLORS_H

#define BOLD_REDD  "\033[1;31m"
#define BOLD_GREN  "\033[1;32m"
#define BOLD_YELL  "\033[1;33m"
#define BOLD_CLAI  "\033[1;34m"
#define BOLD_VIOL  "\033[1;35m"
#define BOLD_CYAN  "\033[1;36m"

#define BGRO_REDD   "\033[41m"
#define BGRO_GREN   "\033[42m" 
#define BGRO_YELL   "\033[43m" 
#define BGRO_CLAI   "\033[44m" 
#define BGRO_VIOL   "\033[45m" 
#define BGRO_CYAN   "\033[46m"
#define RESET      "\033[0m"

#include <iostream>
#include <string>

using namespace std;

inline string color(const char* s, const char* color) {
    string b(color);
    b.append(s).append(RESET);
    return b;
}

#endif 