#ifndef CHECKERS_MODE_H
#define CHECKERS_MODE_H
#include <cmath>
#include <SFML/Window/VideoMode.hpp>
//---------------------
//#ifdef _WIN32
//    #define resolution_mode 2
//#elif __APPLE__
//    #define resolution_mode 1
//#endif
//---------------------
double SCR_W = static_cast<double>(sf::VideoMode::getDesktopMode().width);
double SCR_H = static_cast<double>(sf::VideoMode::getDesktopMode().height);
double res = (sqrt(pow(SCR_H,2) + pow(SCR_W,2))) / (sqrt(pow(2000,2) + pow(1600,2)));
double resolution_mode = res + 0.25 * res;
//---------------------
#endif //CHECKERS_MODE_H
