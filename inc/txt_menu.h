#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class txt_menu{
    sf::Texture tl;
    sf::Texture op_tl;

    sf::Sprite op_tl_sp;
    sf::Sprite tl_sp;
public:
    txt_menu();
    sf::Sprite& g_tl();
    sf::Sprite& g_op_tl();
};
