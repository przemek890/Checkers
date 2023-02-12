#include "font_menu.h"

font_menu::font_menu() {
    /// Ustawianie fontu
    if (!this->font.loadFromFile("../fonts/Manrope-Bold.ttf")) {
        std::cout << "Blad wczytywania czcionki!" << std::endl;
        exit(0);
    }
}
sf::Font& font_menu::g_font() {return this->font;}
