#ifndef PROJEKT_IO_ENGINE_H
#define PROJEKT_IO_ENGINE_H
//-------------------------
#include "LibrariesAndVariables.hpp"
#include "Board.hpp"
#include "Register.h"
class Ruch;
//---------------------------------
namespace silnik {
    class Pozycjer {
        int y1;
        int x1;
        int y2;
        int x2;
    public:
        Pozycjer();
        Pozycjer(int y1,int x1, int y2, int x2);
        int getter_x1();
        int getter_x2();
        int getter_y1();
        int getter_y2();
        void setter_x1(int x1);
        void setter_x2(int x2);
        void setter_y1(int y1);
        void setter_y2(int y2);
    };
    class Inicjalizator_pol {
        char **plansza;
        char gracz;
        char gracz_king;
        char cpu;
        char cpu_king;
        char pole;
    public:
        char **getter_plansza();
        char getter_gracz();
        char getter_gracz_king();
        char getter_cpu();
        char getter_cpu_king();
        char getter_pole();

        Inicjalizator_pol();
        Inicjalizator_pol(Inicjalizator_pol &engine);

    };
    class Ruszer {
    public:
        int pobierz_pozycje_bierki(sf::RenderWindow &window, Ruch &aktualny_ruch, Inicjalizator_pol &engine,Pozycjer &pozycja,int& licznik);
        int wykonaj_ruch_bierka(Inicjalizator_pol &engine, Pozycjer &pozycja);
        Ruszer();
    };
    class Sprawdzacz_ruchu_pionka {
    public:
        static int czy_dozwolone_pionek(int y1, int x1, int y2, int x2, Inicjalizator_pol &engine);
        static void czy_promocja_pionka(int y2, int x2, Inicjalizator_pol &engine);
        static bool sprawdzenie_ruchu_wielokrotnego_pionka(int y2, int x2, Inicjalizator_pol &engine);
    };
    class Sprawdzacz_ruchu_krolowej {
    public:
        static int czy_dozwolone_krolowa(int y1, int x1, int y2, int x2, Inicjalizator_pol &engine);
        static bool sprawdzenie_ruchu_wielokrotnego_krolowej(int y2, int x2, Inicjalizator_pol &engine);
        static int sprawdzanie_linii(int y1, int x1, int y2, int x2, Inicjalizator_pol &engine);
    };
    class Druker_planszy {
    public:
        void static drukuj_plansze(Inicjalizator_pol &engine);
    };
    class Obligator_bic {
        list<Ruch> obowiazek_bic_pionek;
        list<Ruch> obowiazek_bic_krolowa;
    public:
        void sprawdz_bicia(Inicjalizator_pol& engine,int& poprawnosc_ruchu_2,silnik::Pozycjer& pozycja);
        void wymus_bicie_pionek(silnik::Ruszer& ruszacz,int& licznik,silnik::Inicjalizator_pol& engine,silnik::Pozycjer& pozycja,int& poprawnosc_ruchu,int& poprawnosc_ruchu_2);
        void wymus_bicie_krolowa_1(silnik::Ruszer &ruszacz, int &licznik,silnik::Inicjalizator_pol& engine,silnik::Pozycjer& pozycja,int& poprawnosc_ruchu,int& poprawnosc_ruchu_2);
        void wymus_bicie_krolowa_2(silnik::Ruszer &ruszacz, int &licznik,silnik::Inicjalizator_pol& engine,silnik::Pozycjer& pozycja,int& poprawnosc_ruchu,int& poprawnosc_ruchu_2);
        list<Ruch> getter_pionek_list() ;
        list<Ruch> getter_krolowa_list();

    };
    class Zakonczer_rozgrywki{
    public:
        static int sprawdz_czy_koniec(Inicjalizator_pol& engine_1,Inicjalizator_pol& engine_2,sf::RenderWindow& window,silnik::Pozycjer& pozycja,int& czas_1,int& czas_2,int& poprawnosc_ruchu,int& licznik_zakonczenia,int& start);
        static int sprawdz_zakleszczenie(Inicjalizator_pol& engine_1);
        static int sprawdz_remis(silnik::Inicjalizator_pol& engine,silnik::Pozycjer& pozycja,int& poprawnosc_ruchu,int& start);
    };
}
class Wykonywacz_ruchu {
public:
    void wykonaj_ruch_1(silnik::Ruszer& ruszacz,sf::RenderWindow& window,Ruch& aktualny_ruch,silnik::Inicjalizator_pol& engine,silnik::Pozycjer& pozycja,int& licznik,silnik::Obligator_bic& bicia_obowiazkowe,int& poprawnosc_ruchu,int& poprawnosc_ruchu_2);
    void wykonaj_ruch_2(silnik::Ruszer& ruszacz,sf::RenderWindow& window,Ruch& aktualny_ruch,silnik::Inicjalizator_pol& engine,silnik::Pozycjer& pozycja,int& licznik,silnik::Obligator_bic& bicia_obowiazkowe,int& poprawnosc_ruchu,int& poprawnosc_ruchu_2);
    Wykonywacz_ruchu();
};

#endif //PROJEKT_IO_ENGINE_H
