#ifndef PROJEKT_IO_LIBRARIESAndVariables_H
#define PROJEKT_IO_LIBRARIESAndVariables_H
//----------------------------
/// Oznaczenia poszczegolnych pionkow w tablicy hashcode:
/// 120 -> pionek_1
/// 88 -> krolowa_1
/// 111 - > pionek_2
/// 79 -> krolowa_2
/// 0  -> puste pole
#define resolution_mode 1 /// tryb 1 -> wysoka rozdzielczosc // tryb 2 -> niższa rozdzielczość (gdy nie mieści się okno na ekranie)
//----------------------------

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
//---

enum Motyw {BLACK_WHITE = 0,BLEACH_WHITE_LIGHT_BROWN = 1}; // enum z oznaczeniami danych motywow

#endif //PROJEKT_IO_LIBRARIESAndVariables_H
