#ifndef WARCABY_ENG_BOA_H
#include "Board.hpp"
#include "Engine.h"
class Asseter{
    list<silnik::Pozycjer> lista; // struktura danych do przetrzymywania 10 ostatnio wykonanych ruchow
    list<int> lista_pom; // Jezeli 1 to gracz nr_1// Jezeli 2to gracz numer 2
public:
    void drukuj_przewage(sf::RenderWindow& window,silnik::Inicjalizator_pol& engine_1,Inicjator_fontow& font);
    void kogo_tura(sf::RenderWindow& window,int& licznik);
    void chat(sf::RenderWindow& window,silnik::Pozycjer& pozycja,Inicjator_fontow& font,int& poprawnosc_ruchu,int& pozycja_licz);
    int exit(sf::RenderWindow& window,Atrybuty& atrybuty);

    list<silnik::Pozycjer> getter_1();
    list<int> getter_2();
};
class Wyswietlacz_pol {
public:
    Wyswietlacz_pol();
    void wyswietl_pola(silnik::Inicjalizator_pol& engine, Inicjalizator_tekstur &textury, sf::RenderWindow &window,Ruch &aktualny_ruch, int& licznik);
    void wyswietl_tlo(sf::RenderWindow &window);
};
#define WARCABY_ENG_BOA_H

#endif //WARCABY_ENG_BOA_H
