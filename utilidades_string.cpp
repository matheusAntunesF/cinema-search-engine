#include <iostream>
#include <string>
#include "utilidades_string.hpp"
using namespace std;

string limpaString(const string& str) {
    const unsigned int primPos = str.find_first_not_of(" \t\n\r");
    if (std::string::npos == primPos) {
        return str;
    }
    const unsigned int ultimaPos = str.find_last_not_of(" \t\n\r");
    return str.substr(primPos, (ultimaPos - primPos + 1));
}