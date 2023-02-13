#ifndef PROJEKT_IO_LIBRARIESAndVariables_H
#define PROJEKT_IO_LIBRARIESAndVariables_H
#include <iostream>
#include <ctime>
#include <cmath>
#include <list>
#include <chrono>
#include <vector>
#include <limits>
#include <algorithm>
#include <tuple>
#include <unistd.h> // jak nie dziala to zmienic na <windows.h> (tylko sleep dac wartosc nie 1 tylko 1000) --> ale chyba nie ma nawet tego bo debouncing jest zamiast
#include <SFML/Graphics.hpp>
using namespace std;
#ifdef _WIN32
    #define resolution_mode 2
#elif __APPLE__
    #define resolution_mode 1
#endif
//---
enum Motyw {BLACK_WHITE = 0,BLEACH_WHITE_LIGHT_BROWN = 1}; // enum z oznaczeniami danych motywow
//----------------------------
/// Oznaczenia poszczegolnych pionkow w tablicy hashcode:
/// 120 -> pionek_1
/// 88 -> krolowa_1
/// 111 - > pionek_2
/// 79 -> krolowa_2
/// 0  -> puste pole
//----------------------------
#endif //PROJEKT_IO_LIBRARIESAndVariables_H
