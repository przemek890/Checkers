#ifndef PROJEKT_IO_Class_H
#define PROJEKT_IO_Class_H
#include "LibrariesAndVariables.hpp"
#include "Engine.h"
class Plansza;
class Inicjalizator_tekstur;
class Wyswietlacz_pol;
class Ruch;
class Atrybuty;
// Konstruktory i metody zaprzyjaźnione umieszczamy na samym początku, zaraz po atrybutach!
//-----------------------------------
///--- Klasy:
// do odczytu atrybutow

int OdczytModel();
int OdczytKolor();
int OdczytMotyw();

class Builder{
private:
    bool _model_rozgrywki;
    Motyw _motyw;                        // LibrariesAndVariables -> enum Motywy
    Motyw _kolor_pionkow;
public:
    Builder& setModel(bool mod);
    Builder& setMotyw(Motyw _mot);
    Builder& setKolor(Motyw _kolorPion);
    Atrybuty build();
};

class Atrybuty : public Builder{
private:
    bool model_rozgrywki;
    short int motyw;                        // LibrariesAndVariables -> enum Motywy
    short int kolor_pionkow;                // LibrariesAndVariables -> enum Motywy
public:
    Atrybuty(bool model,Motyw mot,Motyw kol);
    bool getter_m_r();
    short int getter_m();
    short int getter_k_p();
};




class Ruch {
    int x;
    int y;
public:
    Ruch();
    Ruch(int x, int y);
    void setter_x(int x);
    void setter_y(int y);
    int getter_x();
    int getter_y();
};

class Inicjator_fontow {
    sf::Font font;
public:
    Inicjator_fontow();
    sf::Font& getter();
};
class Inicjator_tekstu{
    sf::Text text;
public:
    Inicjator_tekstu(sf::Font& font);
    sf::Text& getter();
};
class Inicjalizator_tekstur {
    sf::Texture pionek_1;
    sf::Texture pionek_2;
    sf::Texture pionek_1_queen;
    sf::Texture pionek_2_queen;
    sf::Texture puste_pole;
    sf::Texture podswietl;
public:
    Inicjalizator_tekstur(Atrybuty& atrybuty,sf::Text& text,sf::RenderWindow& window);
    sf::Texture& getter_p_1();
    sf::Texture& getter_p_2();
    sf::Texture& getter_q_1();
    sf::Texture& getter_q_2();
    sf::Texture& getter_p_p();
    sf::Texture& getter_p();
};
class Inicjator_planszy {
    sf::Texture plansza_tex;
    sf::Sprite plansza_obj;
public:
    Inicjator_planszy(Atrybuty& atrybuty, sf::Text& text,sf::RenderWindow& window);
    sf::Sprite& getter();
};

class Gra_na_czas {
        int czas_gry_h = 0;
        int czas_gry_m = 0;
        int czas_gry_s = 0;
        sf::Time timer;
        sf::Clock clock;
        public:
        int odswierz_czas(sf::RenderWindow &window,Inicjator_fontow& font,int& twoj_czas,int& czas_przeciwnika,int& mod,int& licznik,int& exit);
        Gra_na_czas();
};

class Wyswietlacz_pol {
public:
    Wyswietlacz_pol();
    void wyswietl_pola(silnik::Inicjalizator_pol& engine, Inicjalizator_tekstur &textury, sf::RenderWindow &window,Ruch &aktualny_ruch, int& licznik);
    void wyswietl_tlo(sf::RenderWindow &window);
};
class Reklamer {
    sf::Texture reklama_1;
    sf::Texture reklama_2;
    sf::Texture reklama_3;
public:
    void wyswietl_reklame(sf::RenderWindow& window);
    Reklamer();
};
class Timer {
    int czas_gry_h;
    int czas_gry_m;
    int czas_gry_s;
    sf::Time timer;
    sf::Clock clock;
    sf::Texture zegarek;
public:
    void inicjuj_timer(sf::RenderWindow& window);
    void odswierz_zegar(sf::RenderWindow &window,Inicjator_fontow& font);
    Timer();
};
class Asseter{
    list<silnik::Pozycjer> lista; // struktura danych do przetrzymywania 10 ostatnio wykonanych ruchow
    list<int> lista_pom; // Jezeli 1 to gracz nr_1// Jezeli 2to gracz numer 2
public:
    void drukuj_przewage(sf::RenderWindow& window,silnik::Inicjalizator_pol& engine_1,Inicjator_fontow& font);
    void kogo_tura(sf::RenderWindow& window,int& licznik);
    void chat(sf::RenderWindow& window,silnik::Pozycjer& pozycja,Inicjator_fontow& font,int& poprawnosc_ruchu,int& pozycja_licz);
    int exit(sf::RenderWindow& window);

    list<silnik::Pozycjer> getter_1();
    list<int> getter_2();
};





//-----------------------------------
#endif //PROJEKT_IO_Class_H


