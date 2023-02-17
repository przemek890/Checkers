#include "Game_loop.h"
#include "Engine.h"
#include "Register.h"
#include "AI.h"
#include "Eng_boa.h"
//--------------------
Plansza::Plansza() {}

int Plansza ::Run(sf::RenderWindow &Wind){
///Atrybuty
    Builder build;
    Motyw motPion;                 // Motyw nr:1 (z enuma w LIBRARIESAndVariables)
    Motyw motPlansz;                // Motyw nr:2 (z enuma w LIBRARIESAndVariables)

    int tryb = OdczytModel();
    build.setModel(tryb);
    int pion = OdczytKolor();
    int plansz = OdczytMotyw();
    if(pion==1){
        motPion = BLEACH_WHITE_LIGHT_BROWN;
        build.setKolor(motPion);
    }else if(pion==0){
        motPion = BLACK_WHITE;
        build.setKolor(motPion);
    }
    if(plansz == 1){
        motPlansz = BLEACH_WHITE_LIGHT_BROWN;
        build.setMotyw(motPlansz);
    }else if(plansz == 0){
        motPlansz = BLACK_WHITE;
        build.setMotyw(motPlansz);
    }


    Atrybuty at = build.build();

//-------------------------------------------------------------------
/// Renderowanie startu gry: [ wszystkie potrzebne obeikty klas opisanych powyzej ]

    Wind.setFramerateLimit(60); // limit FPS'ów
    Inicjator_fontow fonty;
    sf::Font font = fonty.getter();
    Inicjator_tekstu texty(font);
    sf::Text text =  texty.getter();
    Inicjator_planszy plansze(at,text,Wind);
    sf::Sprite plansza = plansze.getter();
    Inicjalizator_tekstur textury(at,text,Wind);
    silnik::Pozycjer pozycja;
    silnik::Ruszer ruszacz;
    silnik::Inicjalizator_pol engine_1;
    silnik::Inicjalizator_pol engine_2(engine_1);
    Ruch aktualny_ruch;
    Reklamer reklama;
    Timer zegar;
    silnik::Obligator_bic bicia_obowiazkowe;
    Asseter assety;
    AI robocik; /// ---> sztuczna inteligencja
    AI_list kontener_1;
    AI_list kontener_2;

    Gra_na_czas czas_ucieka_player_1;
    Gra_na_czas czas_ucieka_player_2;
    zegar.inicjuj_timer(Wind);
    assety.getter_1().clear();
    assety.getter_2().clear();

    if(resolution_mode == 2) plansza.setScale(0.5,0.5);
    int poprawnosc_ruchu = 1;
    int czas_1 =1, czas_2=1;
    int exit = -1;
    int licznik_zakonczenia = 0;
    int start = 0;
    int pozycja_licz = 1;
    int mod_0 = 0;
    int mod_1 = 1;
    int twoj_czas_1 = 0;
    int twoj_czas_2 = 0;
    int licznik = 0;
    int poprawnosc_ruchu_2 = 1;
// 0,1 --> gracz_1
// 2,3 --> gracz_2

///-------------------------------------------------------------------

/////////////////////////////// Główna Metoda --> pętla gry ///////////////////////////////////////////
    while (Wind.isOpen()) {
        // Dla ponizszych wartosci licznika: ruch ma dany gracz --> z uwagi ze petla ta wykonuje sie ~60 razy na sekunde, mechanizm by przechwytywac interakcje z graczem

        // Bez tego to nam sie zakmnie okno odrazu wiec musi byc
        sf::Event event;
        while (Wind.pollEvent(event))
            if (event.type == sf::Event::Closed) Wind.close();

        Wyswietlacz_pol wyswietlacz_1;
        Wykonywacz_ruchu gracz;

        // Wyswietlanie po kolei poszczegolnych elementow w naszym oknie
        wyswietlacz_1.wyswietl_tlo(Wind);                                                        /// Wydrukuj tło
        Wind.draw(plansza);                                                             /// Wydrukuj plansze
        wyswietlacz_1.wyswietl_pola(engine_1,textury,Wind,aktualny_ruch,licznik);            /// Wyswietl pionki i puste pola
        zegar.odswierz_zegar(Wind,fonty);                                                    /// Odświeżamy zegar
        reklama.wyswietl_reklame(Wind);                                                         /// Wyświetlamy reklame
        assety.drukuj_przewage(Wind,engine_1,fonty);                                     /// Drukujemy wskazniki przewagi
        assety.kogo_tura(Wind,licznik);                                                         /// Drukujemy kogo tura

        if(at.getter_m_r() == 0) { // PvP
            if(exit != 0) gracz.wykonaj_ruch_1(ruszacz,Wind,aktualny_ruch,engine_1,pozycja,licznik,bicia_obowiazkowe,poprawnosc_ruchu,poprawnosc_ruchu_2);     /// Mechanizm wykonywania ruchu gracza_1
            assety.chat(Wind,pozycja,fonty,poprawnosc_ruchu,pozycja_licz);     // aktualizacja chatu
            if(exit != 0) gracz.wykonaj_ruch_2(ruszacz,Wind,aktualny_ruch,engine_2,pozycja,licznik,bicia_obowiazkowe,poprawnosc_ruchu,poprawnosc_ruchu_2);     /// Mechanizm wykonywania ruchu gracza_2
        }
        else if (at.getter_m_r() == 1) { // PvE
            if(exit != 0) gracz.wykonaj_ruch_1(ruszacz,Wind,aktualny_ruch,engine_1,pozycja,licznik,bicia_obowiazkowe,poprawnosc_ruchu,poprawnosc_ruchu_2);     /// Mechanizm wykonywania ruchu gracza_1
            assety.chat(Wind,pozycja,fonty,poprawnosc_ruchu,pozycja_licz);     // aktualizacja chatu             /// Mechanizm wykonywania ruchu gracza_2
            if(exit != 0) robocik.wykonaj_ruch_AI(ruszacz,engine_2,pozycja,licznik,poprawnosc_ruchu,kontener_1,kontener_2,poprawnosc_ruchu_2);
        }


        exit=silnik::Zakonczer_rozgrywki::sprawdz_czy_koniec(engine_1,engine_2,Wind,pozycja, czas_1, czas_2,poprawnosc_ruchu,licznik_zakonczenia,start);  // Sprawdzenie czy rozgrywka aby nie powinna sie zakonczyc --> są ku temu przesłanki



        czas_1 = czas_ucieka_player_1.odswierz_czas(Wind,fonty,twoj_czas_1,twoj_czas_2,mod_0,licznik,exit);
        czas_2 = czas_ucieka_player_2.odswierz_czas(Wind,fonty,twoj_czas_1,twoj_czas_2,mod_1,licznik,exit);

        int ex = assety.exit(Wind,at);

        Wind.display();

        if(ex == -777 || exit == -777) {
            change_filename();
            last_5_game();
            return 0;
        }

    }
}