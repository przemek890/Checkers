#ifndef PROJEKT_IO_AI_H
#define PROJEKT_IO_AI_H
#include "LibrariesAndVariables.hpp"
#include "Engine.h"
class AI_ruch {
    int x1;
    int y1;
    int x2;
    int y2;
public:
    AI_ruch(int y1,int x1, int y2, int x2);
    AI_ruch();
    int getter_x1();
    int getter_x2();
    int getter_y1();
    int getter_y2();
};

struct AI_list {
    list<AI_ruch> lista_ruchow_pionek;
    list<AI_ruch> lista_ruchow_krolowa;
    list<AI_ruch> bicia_pionek;
    list<AI_ruch> bicia_krolowa;
    AI_list();
};

class AI {
    static void pobierz_ruchy_dla_pionka(silnik::Inicjalizator_pol& engine,AI_list& lista,int i, int j,int& poprawnosc_ruchu_2,silnik::Pozycjer& pozycja);
    static void pobierz_ruchy_dla_krolowej(silnik::Inicjalizator_pol &engine,AI_list& lista, int i, int j,int& poprawnosc_ruchu_2,silnik::Pozycjer& pozycja);
public:
    static void pobierz_mozliwe_ruchy(silnik::Inicjalizator_pol& engine,AI_list& lista,int& poprawnosc_ruchu_2,silnik::Pozycjer& pozycja);

    static void Grupowanie_sie_pionkow(AI_ruch& ruch,silnik::Inicjalizator_pol& engine,float& ocena);
    static void Prosta_droga_do_krolowki(AI_ruch& ruch,silnik::Inicjalizator_pol& engine,float& ocena);
    static void Unikaj_zbic(AI_ruch& ruch,silnik::Inicjalizator_pol& engine,float& ocena);
    static void Szukaj_bic_wielokrotnych_pionek(AI_ruch& ruch,silnik::Inicjalizator_pol& engine,float& ocena);
    static void Szukaj_bic_wielokrotnych_krolowa(AI_ruch &ruch, silnik::Inicjalizator_pol &engine, float &ocena);
    static float ocen_ruch(AI_ruch& ruch,silnik::Inicjalizator_pol& engine);
    static void Podazaj_za_krolowa(AI_ruch& ruch,silnik::Inicjalizator_pol& engine,float& ocena);
    static void Lap_pionka(AI_ruch &ruch, silnik::Inicjalizator_pol &engine, float &ocena);

    void wykonaj_ruch_AI(silnik::Ruszer& ruszacz,silnik::Inicjalizator_pol& engine,silnik::Pozycjer& pozycja,int& licznik,int& poprawnosc_ruchu,AI_list& lista_1,AI_list& lista_2,int& poprawnosc_ruchu_2);
};

class AI_gracz {
    static void pobierz_ruchy_dla_pionka(silnik::Inicjalizator_pol& engine,AI_list& lista,int i, int j);
    static void pobierz_ruchy_dla_krolowej(silnik::Inicjalizator_pol &engine,AI_list& lista, int i, int j);
public:
    static void pobierz_mozliwe_ruchy(silnik::Inicjalizator_pol& engine,AI_list& lista);

    static void Grupowanie_sie_pionkow(AI_ruch& ruch,silnik::Inicjalizator_pol& engine,float& ocena);
    static void Prosta_droga_do_krolowki(AI_ruch& ruch,silnik::Inicjalizator_pol& engine,float& ocena);
    static void Unikaj_zbic(AI_ruch& ruch,silnik::Inicjalizator_pol& engine,float& ocena);
    static void Szukaj_bic_wielokrotnych_pionek(AI_ruch& ruch,silnik::Inicjalizator_pol& engine,float& ocena);
    static void Szukaj_bic_wielokrotnych_krolowa(AI_ruch &ruch, silnik::Inicjalizator_pol &engine, float &ocena);
    static float ocen_ruch(AI_ruch& ruch,silnik::Inicjalizator_pol& engine);
    static void Podazaj_za_krolowa(AI_ruch& ruch,silnik::Inicjalizator_pol& engine,float& ocena);
    static void Lap_pionka(AI_ruch &ruch, silnik::Inicjalizator_pol &engine, float &ocena);


};


AI_ruch wybierz_najlepszy_ruch(list<AI_ruch>& lista_ruchow_1,silnik::Inicjalizator_pol& engine,float& genaral_rate,list<AI_ruch>& lista_ruchow_2);

#endif //PROJEKT_IO_AI_H
