#include "font_menu.h"
#include "unistd.h"
#include "LibrariesAndVariables.hpp"

font_menu::font_menu() {
    /// Ustawianie fontu
    if (!this->font.loadFromFile(MY_DEFINE "../font/Manrope-Bold.ttf")) {
        std::cout << "Blad wczytywania czcionki!" << std::endl;
        exit(0);
    }
}
sf::Font& font_menu::g_font() {return this->font;}
