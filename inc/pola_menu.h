#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
class pola_menu {
    sf::Texture p1;

    sf:: Texture lgw;
    sf::Texture lg;

    sf::Texture pionl;
    sf::Texture pionb;
    sf::Texture boardl;
    sf::Texture boardb;
    sf::Texture p2;
    //podswietlenia
    sf::Texture pod1;
    sf::Texture pod2;
    sf::Texture pod3;

    //logowanie
    sf::Texture login;
    sf::Texture sa;

    //archiwum
    sf::Texture arch;

public:
    pola_menu();
    sf::Texture& g_p1();
    sf::Texture& g_p2();
    sf::Texture& g_lgw();
    sf::Texture& g_lg();
    sf::Texture& g_pionl();
    sf::Texture& g_pionb();
    sf::Texture& g_boardl();
    sf::Texture& g_boardb();
    sf::Texture& g_pod1();
    sf::Texture& g_pod2();
    sf::Texture& g_pod3();
    sf::Texture& g_login();
    sf::Texture& g_sa();
    sf::Texture& g_arch();
    bool what_if(sf::Sprite& sprite, sf::RenderWindow& window);
};


