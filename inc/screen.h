#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#ifndef WARCABY_SCREEN_H
#define WARCABY_SCREEN_H


class screen {
public :
    virtual int Run (sf::RenderWindow &Wind) = 0;
};


#endif //WARCABY_SCREEN_H
