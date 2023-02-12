#ifndef PROJEKT_IO_GAME_LOOP_H
#define PROJEKT_IO_GAME_LOOP_H
#include "LibrariesAndVariables.hpp"
#include "Board.hpp"
#include "AI.h"
#include "screen.h"

//---
class Plansza : public screen {
public:
    Plansza();
    int Run(sf::RenderWindow &Wind);
};
//---

#endif //PROJEKT_IO_GAME_LOOP_H
