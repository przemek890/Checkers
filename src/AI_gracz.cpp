#include "AI.h"
#include "AI_wagi.h"

/// ---> AI_gracz:
void AI_gracz::pobierz_ruchy_dla_pionka(silnik::Inicjalizator_pol& engine,AI_list& lista,int i, int j) {
    int a = silnik::Sprawdzacz_ruchu_pionka::czy_dozwolone_pionek(i,j,i-1,j+1,engine); // Jezeli ruch w prawo
    if(a == 1) {AI_ruch R(i,j,i-1,j+1); lista.lista_ruchow_pionek.push_front(R);}

    int b = silnik::Sprawdzacz_ruchu_pionka::czy_dozwolone_pionek(i,j,i-1,j-1,engine); // Jezeli ruch w lewo
    if(b == 1) {AI_ruch R(i,j,i-1,j-1); lista.lista_ruchow_pionek.push_front(R);}

    int c = silnik::Sprawdzacz_ruchu_pionka::czy_dozwolone_pionek(i,j,i-2,j+2,engine); // Jezeli bicie na prawo
    if(c == 2)  {AI_ruch R(i,j,i-2,j+2); lista.bicia_pionek.push_front(R);}

    int d = silnik::Sprawdzacz_ruchu_pionka::czy_dozwolone_pionek(i,j,i-2,j-2,engine); // Jezeli bicie na lewo
    if(d == 3)  {AI_ruch R(i,j,i-2,j-2); lista.bicia_pionek.push_front(R);}
}
void AI_gracz::pobierz_ruchy_dla_krolowej(silnik::Inicjalizator_pol &engine,AI_list& lista, int i, int j) {
    int ypom_1 = i; int xpom_1 = j;
    while((++xpom_1 < 7 && --ypom_1 > 0) && (engine.getter_plansza()[ypom_1][xpom_1] == engine.getter_pole())) {  // Szukamy na linii NE potencjalnych bic
        if(silnik::Sprawdzacz_ruchu_krolowej::czy_dozwolone_krolowa(i,j,ypom_1,xpom_1,engine) == 1) {AI_ruch R(i,j,ypom_1,xpom_1); lista.lista_ruchow_krolowa.push_front(R);} // Jeżeli dozwolony ruch
    }
    ++xpom_1; // x -> pozycja albo za mapa (niedozwolona) albo (pole na ktorym wyladuje krolowka po biciu)
    --ypom_1; // y -> pozycja albo za mapa (niedozwolona) albo (pole na ktorym wyladuje krolowka po biciu)
    if(silnik::Sprawdzacz_ruchu_krolowej::czy_dozwolone_krolowa(i,j,ypom_1,xpom_1,engine) == 2) {AI_ruch R(i,j,ypom_1,xpom_1); lista.bicia_krolowa.push_front(R);}     // Jezeli mamy bicie NE
    //////////////
    int ypom_2 = i; int xpom_2 = j;
    while(++xpom_2 < 7 && ++ypom_2 < 7 && (engine.getter_plansza()[ypom_2][xpom_2] == engine.getter_pole())) {
        if(silnik::Sprawdzacz_ruchu_krolowej::czy_dozwolone_krolowa(i,j,ypom_2,xpom_2,engine) == 1) {AI_ruch R(i,j,ypom_2,xpom_2); lista.lista_ruchow_krolowa.push_front(R);} // Jeżeli dozwolony ruch
    }
    ++xpom_2; // x -> pozycja albo za mapa (niedozwolona) albo (pole na ktorym wyladuje krolowka po biciu)
    ++ypom_2; // y -> pozycja albo za mapa (niedozwolona) albo (pole na ktorym wyladuje krolowka po biciu)
    if(silnik::Sprawdzacz_ruchu_krolowej::czy_dozwolone_krolowa(i,j,ypom_2,xpom_2,engine) == 3) {AI_ruch R(i,j,ypom_2,xpom_2); lista.bicia_krolowa.push_front(R);}   // Jezeli mamy bicie SE
    //////////////
    int ypom_3 = i; int xpom_3 = j;
    while(--xpom_3 > 0 && --ypom_3 > 0 && (engine.getter_plansza()[ypom_3][xpom_3] == engine.getter_pole())) {
        if(silnik::Sprawdzacz_ruchu_krolowej::czy_dozwolone_krolowa(i,j,ypom_3,xpom_3,engine) == 1) {AI_ruch R(i,j,ypom_3,xpom_3); lista.lista_ruchow_krolowa.push_front(R);}
    }
    --xpom_3; // x -> pozycja albo za mapa (niedozwolona) albo (pole na ktorym wyladuje krolowka po biciu)
    --ypom_3; // y -> pozycja albo za mapa (niedozwolona) albo (pole na ktorym wyladuje krolowka po biciu)
    if(silnik::Sprawdzacz_ruchu_krolowej::czy_dozwolone_krolowa(i,j,ypom_3,xpom_3,engine) == 4) {AI_ruch R(i,j,ypom_3,xpom_3); lista.bicia_krolowa.push_front(R);}   // Jezeli mamy bicie NW
    //////////////
    int ypom_4 = i; int xpom_4 = j;
    while(--xpom_4 > 0 && ++ypom_4 < 7 &&(engine.getter_plansza()[ypom_4][xpom_4] == engine.getter_pole())) {
        if(silnik::Sprawdzacz_ruchu_krolowej::czy_dozwolone_krolowa(i,j,ypom_4,xpom_4,engine) == 1) {AI_ruch R(i,j,ypom_4,xpom_4); lista.lista_ruchow_krolowa.push_front(R);}
    }
    --xpom_4; // x -> pozycja albo za mapa (niedozwolona) albo (pole na ktorym wyladuje krolowka po biciu)
    ++ypom_4; // y -> pozycja albo za mapa (niedozwolona) albo (pole na ktorym wyladuje krolowka po biciu)
    if(silnik::Sprawdzacz_ruchu_krolowej::czy_dozwolone_krolowa(i,j,ypom_4,xpom_4,engine) == 5) {AI_ruch R(i,j,ypom_4,xpom_4); lista.bicia_krolowa.push_front(R);}  // Jezeli mamy bicie SW
}
void AI_gracz::pobierz_mozliwe_ruchy(silnik::Inicjalizator_pol& engine,AI_list& lista) {
    silnik::Inicjalizator_pol eng_temp(engine);
    for(int i=0;i<8;i++) {
        for(int j=0;j<8;j++) {
            if(eng_temp.getter_plansza()[i][j] == eng_temp.getter_gracz()) pobierz_ruchy_dla_pionka(eng_temp,lista,i,j);
            else if (eng_temp.getter_plansza()[i][j] == eng_temp.getter_gracz_king()) pobierz_ruchy_dla_krolowej(eng_temp,lista,i,j);
        }
    }
}
//--------------------------------------------------------------------------------------------------------
/// ---> Ocenianie:
void AI_gracz::Grupowanie_sie_pionkow(AI_ruch& ruch,silnik::Inicjalizator_pol& engine,float& ocena) {
    int licznik = 0;
    if((ruch.getter_y2() - 1 >= 0 && ruch.getter_y2() - 1 <= 7) && (ruch.getter_x2() - 1 >= 0 && ruch.getter_x2() - 1 <= 7)) {
        if(engine.getter_plansza()[ruch.getter_y2() - 1][ruch.getter_x2() - 1] == engine.getter_gracz()) {
            licznik++;
        }
    }
    if((ruch.getter_y2() - 1 >= 0 && ruch.getter_y2() - 1 <= 7) && (ruch.getter_x2() + 1 >= 0 && ruch.getter_x2() + 1 <= 7)) {
        if(engine.getter_plansza()[ruch.getter_y2() - 1][ruch.getter_x2() + 1] == engine.getter_gracz()) {
            licznik++;
        }
    }
    if(licznik == 2) ocena += wg_1;
    else if(licznik == 1) ocena += wg_2;
}
void AI_gracz::Prosta_droga_do_krolowki(AI_ruch& ruch,silnik::Inicjalizator_pol& engine,float& ocena) {
    ///  Jezeli wydzielony kwadrat przed pionkiem  jest pusty to boost by pchać do przodu pionka - by zostac krolowa
    int zlicz = 0;
    if((ruch.getter_y2() - 1 >= 0 && ruch.getter_y2() - 1 <= 7) && (ruch.getter_x2() + 1 >= 0 && ruch.getter_x2() + 1 <= 7)) {
        if(engine.getter_plansza()[ruch.getter_y2() - 1][ruch.getter_x2() + 1] == engine.getter_pole()) {
            zlicz++;
        }
    }
    else zlicz++;
    /////////////
    if((ruch.getter_y2() - 1 >= 0 && ruch.getter_y2() - 1 <= 7) && (ruch.getter_x2() - 1 >= 0 && ruch.getter_x2() - 1 <= 7)) {
        if(engine.getter_plansza()[ruch.getter_y2() - 1][ruch.getter_x2() - 1] == engine.getter_pole()) {
            zlicz++;
        }
    }
    else zlicz++;
    /////////////
    if((ruch.getter_y2() - 2 >= 0 && ruch.getter_y2() - 2 <= 7) && (ruch.getter_x2() >= 0 && ruch.getter_x2() <= 7)) {
        if(engine.getter_plansza()[ruch.getter_y2() - 2][ruch.getter_x2()] == engine.getter_pole()) {
            zlicz++;
        }
    }
    else zlicz++;

    if(zlicz == 3)
        ocena += wg_3;

}
void AI_gracz::Szukaj_bic_wielokrotnych_pionek(AI_ruch& ruch,silnik::Inicjalizator_pol& engine,float& ocena) {
    if(engine.getter_plansza()[ruch.getter_y1()][ruch.getter_x1()] == engine.getter_gracz()) {
        int b = silnik::Sprawdzacz_ruchu_pionka::czy_dozwolone_pionek(ruch.getter_y1(),ruch.getter_x1(),ruch.getter_y2(),ruch.getter_x2(),engine);
        engine.getter_plansza()[ruch.getter_y2()][ruch.getter_x2()] = engine.getter_gracz(); ////// SYMULACJA!
        int a = silnik::Sprawdzacz_ruchu_pionka::sprawdzenie_ruchu_wielokrotnego_pionka(ruch.getter_y2(),ruch.getter_x2(),engine);
        if(a == 1 && (b == 2 || b == 3))
            ocena += wg_4;
        engine.getter_plansza()[ruch.getter_y2()][ruch.getter_x2()] = engine.getter_pole(); ////// DESYMULACJA!
    }
}
void AI_gracz::Szukaj_bic_wielokrotnych_krolowa(AI_ruch &ruch, silnik::Inicjalizator_pol &engine, float &ocena) {
    if(engine.getter_plansza()[ruch.getter_y1()][ruch.getter_x1()] == engine.getter_gracz_king()) {
        int b = silnik::Sprawdzacz_ruchu_krolowej::czy_dozwolone_krolowa(ruch.getter_y1(),ruch.getter_x1(),ruch.getter_y2(),ruch.getter_x2(),engine);
        engine.getter_plansza()[ruch.getter_y2()][ruch.getter_x2()] = engine.getter_gracz_king(); ////// SYMULACJA!
        engine.getter_plansza()[ruch.getter_y1()][ruch.getter_x1()] = engine.getter_pole(); ////// SYMULACJA!
        int a = silnik::Sprawdzacz_ruchu_krolowej::sprawdzenie_ruchu_wielokrotnego_krolowej(ruch.getter_y2(),ruch.getter_x2(),engine);
        if(a == 1 && (b == 2 || b == 3 || b ==4 || b == 5)) ocena += wg_5; // Jezeli na danej linii masz bicie wielokrotne
        else if (b == 1 && a == 1) ocena += wg_5/2; // Znalezłeś bicie na danej linii
        engine.getter_plansza()[ruch.getter_y2()][ruch.getter_x2()] = engine.getter_pole(); ////// SYMULACJA!
        engine.getter_plansza()[ruch.getter_y1()][ruch.getter_x1()] = engine.getter_gracz_king(); ////// SYMULACJA!
    }
}
void AI_gracz::Unikaj_zbic(AI_ruch &ruch, silnik::Inicjalizator_pol &engine, float &ocena) {
    int zbicia_jednokrotne = 0;
    int zbicia_wielokrotne = 0;
    silnik::Inicjalizator_pol eng_temp(engine);
    // Brak obslugi ruchow ktore sa biciami
    char pom = engine.getter_plansza()[ruch.getter_y1()][ruch.getter_x1()]; // pobierz informacje o figurze by potem odsymulowac
    if(pom == engine.getter_gracz() && silnik::Sprawdzacz_ruchu_pionka::sprawdzenie_ruchu_wielokrotnego_pionka(ruch.getter_y1(),ruch.getter_x1(),engine) == 1) return;
    if(pom == engine.getter_gracz_king() && silnik::Sprawdzacz_ruchu_krolowej::sprawdzenie_ruchu_wielokrotnego_krolowej(ruch.getter_y1(),ruch.getter_x1(),engine) == 1) return;
    ////////// Symulujemy ruch
    engine.getter_plansza()[ruch.getter_y1()][ruch.getter_x1()] = engine.getter_pole();
    engine.getter_plansza()[ruch.getter_y2()][ruch.getter_x2()] = pom;
    //////////
    for(int i =0;i<8;i++) {
        for(int j=0;j<8;j++) {
            if(eng_temp.getter_plansza()[i][j] == eng_temp.getter_gracz()) { // sprawdzamy jakie bicie ma przeciwnik
                int a = silnik::Sprawdzacz_ruchu_pionka::sprawdzenie_ruchu_wielokrotnego_pionka(i,j,eng_temp);
                if(a == 1) { // jezeli bicie
                    int pom_1 = silnik::Sprawdzacz_ruchu_pionka::czy_dozwolone_pionek(i,j,i+2,j-2,eng_temp);
                    int pom_2 = silnik::Sprawdzacz_ruchu_pionka::czy_dozwolone_pionek(i,j,i+2,j+2,eng_temp);
                    if(pom_1 == 2) { // na prawo
                        /////
                        eng_temp.getter_plansza()[i][j] = eng_temp.getter_pole();
                        eng_temp.getter_plansza()[i+2][j-2] = eng_temp.getter_gracz();
                        /////
                        int b = silnik::Sprawdzacz_ruchu_pionka::sprawdzenie_ruchu_wielokrotnego_pionka(i+2,j-2,eng_temp);
                        if(b == 1) zbicia_wielokrotne++;
                        else zbicia_jednokrotne++;
                        /////---->
                        eng_temp.getter_plansza()[i+2][j-2] = eng_temp.getter_pole();
                        eng_temp.getter_plansza()[i][j] = eng_temp.getter_gracz();
                        /////---->
                    }
                    if (pom_2 == 3) { // na lewo
                        /////
                        eng_temp.getter_plansza()[i][j] = eng_temp.getter_pole();
                        eng_temp.getter_plansza()[i+2][j+2] = eng_temp.getter_gracz();
                        /////
                        int b = silnik::Sprawdzacz_ruchu_pionka::sprawdzenie_ruchu_wielokrotnego_pionka(i + 2,j + 2,eng_temp);
                        if(b == 1) zbicia_wielokrotne++;
                        else zbicia_jednokrotne++;
                        /////---->
                        eng_temp.getter_plansza()[i+2][j+2] = eng_temp.getter_pole();
                        eng_temp.getter_plansza()[i][j] = eng_temp.getter_gracz();
                    }
                }
            }
            else if (eng_temp.getter_plansza()[i][j] == eng_temp.getter_gracz_king()) {
                int a = silnik::Sprawdzacz_ruchu_krolowej::sprawdzenie_ruchu_wielokrotnego_krolowej(i,j,eng_temp);
                if(a == 1) { // jezeli bicie

                    int xpom_1 = j; int ypom_1 = i;
                    while((++xpom_1 < 7 && --ypom_1 > 0) && (eng_temp.getter_plansza()[ypom_1][xpom_1] != eng_temp.getter_cpu() && eng_temp.getter_plansza()[ypom_1][xpom_1] != eng_temp.getter_cpu_king()));
                    ++xpom_1; --ypom_1;
                    int p1 = silnik::Sprawdzacz_ruchu_krolowej::czy_dozwolone_krolowa(i,j,ypom_1,xpom_1,eng_temp);

                    int xpom_2 = j; int ypom_2 = i;
                    while(++xpom_2 < 7 && ++ypom_2 < 7 && (eng_temp.getter_plansza()[ypom_2][xpom_2] != eng_temp.getter_cpu() && eng_temp.getter_plansza()[ypom_2][xpom_2] != eng_temp.getter_cpu_king()));
                    ++xpom_2; ++ypom_2;
                    int p2 = silnik::Sprawdzacz_ruchu_krolowej::czy_dozwolone_krolowa(i,j,ypom_2,xpom_2,eng_temp);

                    int xpom_3 = j; int ypom_3 = i;
                    while(--xpom_3 > 0 && --ypom_3 > 0 && (eng_temp.getter_plansza()[ypom_3][xpom_3] != eng_temp.getter_cpu() && eng_temp.getter_plansza()[ypom_3][xpom_3] != eng_temp.getter_cpu_king()));
                    --xpom_3; --ypom_3;
                    int p3 = silnik::Sprawdzacz_ruchu_krolowej::czy_dozwolone_krolowa(i,j,ypom_3,xpom_3,eng_temp);

                    int xpom_4 = j; int ypom_4 = i;
                    while(--xpom_4 > 0 && ++ypom_4 < 7 && (eng_temp.getter_plansza()[ypom_4][xpom_4] != eng_temp.getter_cpu() && eng_temp.getter_plansza()[ypom_4][xpom_4] != eng_temp.getter_cpu_king()));
                    --xpom_4; ++ypom_4;
                    int p4 = silnik::Sprawdzacz_ruchu_krolowej::czy_dozwolone_krolowa(i,j,ypom_4,xpom_4,eng_temp);

                    if(p1 == 2) { // na NE
                        char pp = eng_temp.getter_plansza()[ypom_1 + 1][xpom_1 - 1];
                        /////
                        eng_temp.getter_plansza()[i][j] = eng_temp.getter_pole();
                        eng_temp.getter_plansza()[ypom_1][xpom_1] = eng_temp.getter_gracz_king();
                        eng_temp.getter_plansza()[ypom_1 + 1][xpom_1 - 1] = eng_temp.getter_pole();
                        /////
                        int b = silnik::Sprawdzacz_ruchu_krolowej::sprawdzenie_ruchu_wielokrotnego_krolowej(ypom_1,xpom_1,eng_temp);
                        if(b == 1)
                            zbicia_wielokrotne++;
                        else
                            zbicia_jednokrotne++;
                        /////---->
                        eng_temp.getter_plansza()[i][j] = eng_temp.getter_gracz_king();
                        eng_temp.getter_plansza()[ypom_1][xpom_1] = eng_temp.getter_pole();
                        eng_temp.getter_plansza()[ypom_1 + 1][xpom_1 - 1] = pp;
                        /////---->
                    }
                    if(p2 == 3) { // na SE
                        char pp = eng_temp.getter_plansza()[ypom_2 - 1][xpom_2 - 1];
                        /////
                        eng_temp.getter_plansza()[i][j] = eng_temp.getter_pole();
                        eng_temp.getter_plansza()[ypom_2][xpom_2] = eng_temp.getter_gracz_king();
                        eng_temp.getter_plansza()[ypom_2 - 1][xpom_2 - 1] = eng_temp.getter_pole();
                        /////
                        int b = silnik::Sprawdzacz_ruchu_krolowej::sprawdzenie_ruchu_wielokrotnego_krolowej(ypom_2,xpom_2,eng_temp);
                        if(b == 1) zbicia_wielokrotne++;
                        else zbicia_jednokrotne++;
                        /////---->
                        eng_temp.getter_plansza()[i][j] = eng_temp.getter_gracz_king();
                        eng_temp.getter_plansza()[ypom_2][xpom_2] = eng_temp.getter_pole();
                        eng_temp.getter_plansza()[ypom_2 - 1][xpom_2 - 1] = pp;
                        /////---->
                    }
                    if (p3 == 4) { // na NW
                        char pp = eng_temp.getter_plansza()[ypom_3 + 1][xpom_3 + 1];
                        /////
                        eng_temp.getter_plansza()[i][j] = eng_temp.getter_pole();
                        eng_temp.getter_plansza()[ypom_3][xpom_3] = eng_temp.getter_gracz_king();
                        eng_temp.getter_plansza()[ypom_3 + 1][xpom_3 + 1] = eng_temp.getter_pole();
                        /////
                        int b = silnik::Sprawdzacz_ruchu_krolowej::sprawdzenie_ruchu_wielokrotnego_krolowej(ypom_3,xpom_3,eng_temp);
                        if(b == 1) zbicia_wielokrotne++;
                        else zbicia_jednokrotne++;
                        /////---->
                        eng_temp.getter_plansza()[i][j] = eng_temp.getter_gracz_king();
                        eng_temp.getter_plansza()[ypom_3][xpom_3] = eng_temp.getter_pole();
                        eng_temp.getter_plansza()[ypom_3 + 1][xpom_3 + 1] = pp;
                        /////---->
                    }
                    if (p4 == 5) { // na SW
                        char pp = eng_temp.getter_plansza()[ypom_4 - 1][xpom_4 + 1];
                        /////
                        eng_temp.getter_plansza()[i][j] = eng_temp.getter_pole();
                        eng_temp.getter_plansza()[ypom_4][xpom_4] = eng_temp.getter_gracz_king();
                        eng_temp.getter_plansza()[ypom_4 - 1][xpom_4 + 1] = eng_temp.getter_pole();
                        /////
                        int b = silnik::Sprawdzacz_ruchu_krolowej::sprawdzenie_ruchu_wielokrotnego_krolowej(ypom_4,xpom_4,eng_temp);
                        if(b == 1) zbicia_wielokrotne++;
                        else zbicia_jednokrotne++;
                        /////---->
                        eng_temp.getter_plansza()[i][j] = eng_temp.getter_gracz_king();
                        eng_temp.getter_plansza()[ypom_4][xpom_4] = eng_temp.getter_pole();
                        eng_temp.getter_plansza()[ypom_4 - 1][xpom_4 + 1] = pp;
                        /////---->
                    }
                }
            }
        }
    }
    ////////// DESymulujemy ruch
    engine.getter_plansza()[ruch.getter_y1()][ruch.getter_x1()] = pom;
    engine.getter_plansza()[ruch.getter_y2()][ruch.getter_x2()] = engine.getter_pole();
    //////////
    ocena +=  (zbicia_jednokrotne * wg_13) + (zbicia_wielokrotne  * wg_14);
}
void AI_gracz::Podazaj_za_krolowa(AI_ruch& ruch,silnik::Inicjalizator_pol& engine,float& ocena) {
    /// Jezeli na planszy jest krolowa to ją śledz by uniknac z nia konfrontacji (czy nie jestes z nia na jednej przekatnej)
    int  licznik = 0;
    for(int i=0;i<8;i++) {
        for(int j=0;j<8;j++){
            if(engine.getter_plansza()[i][j] == engine.getter_cpu_king()){
                int diagonal_up_king = i+j; // identyfikator przekatnej górnej
                int diagonal_down_king = i-j; // identyfikator przekatnej dolnej

                int diagonal_up_pawn_2 = ruch.getter_y2() + ruch.getter_x2();
                int diagonal_down_pawn_2 = ruch.getter_y2() - ruch.getter_x2();

                if(diagonal_up_king == diagonal_up_pawn_2 || diagonal_down_king == diagonal_down_pawn_2) licznik++;

                if(licznik != 1) { /// Jezeli po wykonanym ruchu nie jestes na jednej linii z królową
                    if(engine.getter_plansza()[ruch.getter_y1()][ruch.getter_x1()] == engine.getter_gracz()) ocena += wg_15;
                    else if(engine.getter_plansza()[ruch.getter_y1()][ruch.getter_x1()]  == engine.getter_gracz_king()) ocena += wg_16;
                }
            }
        }
    }
}
void AI_gracz::Lap_pionka(AI_ruch &ruch, silnik::Inicjalizator_pol &engine, float &ocena) {
    if(engine.getter_plansza()[ruch.getter_y1()][ruch.getter_x1()] == engine.getter_gracz_king()) {
        int licznik = 0;
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if (engine.getter_plansza()[i][j] == engine.getter_cpu()) {
                    int diagonal_up_pawn = i + j; // identyfikator przekatnej górnej potencjalnej ofiary
                    int diagonal_down_pawn = i - j; // identyfikator przekatnej dolnej potencjalnej ofiary

                    int diagonal_up_king = ruch.getter_y2() + ruch.getter_x2(); // zmodyfikowany identyfikator przekatnej górnej mojej krolowej
                    int diagonal_down_king = ruch.getter_y2() - ruch.getter_x2(); // zmodyfikowny identyfikator przekatnej dolnej mojej krolowej

                    if (diagonal_up_king - 2  == diagonal_up_pawn || diagonal_down_king - 2 == diagonal_down_pawn) licznik++;

                    if (licznik == 1) { /// Jezeli zastawiles polapke na piona przeciwnika
                        ocena += wg_12;
                    }
                }
            }
        }
    }
}
float AI_gracz::ocen_ruch(AI_ruch& ruch,silnik::Inicjalizator_pol& engine) {
    silnik::Inicjalizator_pol eng_temp(engine);
    float ocena = 0;
    if(eng_temp.getter_plansza()[ruch.getter_y1()][ruch.getter_x1()] == eng_temp.getter_gracz()) {
        if((ruch.getter_x2() == 4 || ruch.getter_x2() == 3) && (ruch.getter_y2() == 4 || ruch.getter_y2() == 3)) ocena += wg_6; // Bonus za ruch do środka planszy
        if((ruch.getter_x2() == 0 || ruch.getter_x2() == 7)) ocena += wg_7; // Kara za ruch na krańce planszy
        if(ruch.getter_y1() == 7 && ruch.getter_y2() == 6) ocena += wg_9;  // Kara za nie bronienie pola
        Grupowanie_sie_pionkow(ruch,eng_temp,ocena);
        Prosta_droga_do_krolowki(ruch,eng_temp,ocena);
        Szukaj_bic_wielokrotnych_pionek(ruch,eng_temp,ocena);
    }
    else if(eng_temp.getter_plansza()[ruch.getter_y1()][ruch.getter_x1()] == eng_temp.getter_gracz_king()) {
        if((ruch.getter_x2() == 4 || ruch.getter_x2() == 3) && (ruch.getter_y2() == 4 || ruch.getter_y2() == 3)) ocena += wg_10; // Bonus za ruch do środka planszy
        if((ruch.getter_x2() == 0 || ruch.getter_x2() == 7)) ocena += wg_11; // Kara za ruch na krańce planszy
        Szukaj_bic_wielokrotnych_krolowa(ruch,eng_temp,ocena);
        Lap_pionka(ruch,eng_temp,ocena);
    }

    Unikaj_zbic(ruch,eng_temp,ocena);
    Podazaj_za_krolowa(ruch,eng_temp,ocena); // Do przesledzenia czy poprawnie dziala

    return ocena;

}
//---------------------------------------------------------------------------------------------------------