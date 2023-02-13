#include "Engine.h"
#include "Register.h"
/// ---> silnik::Pozycjer:
int silnik::Pozycjer::getter_x1() {return this->x1;}
int silnik::Pozycjer::getter_x2() {return this->x2;}
int silnik::Pozycjer::getter_y1() {return this->y1;}
int silnik::Pozycjer::getter_y2() {return this->y2;}
void silnik::Pozycjer::setter_x1(int x1) {this->x1 = x1;}
void silnik::Pozycjer::setter_x2(int x2) {this->x2 = x2;}
void silnik::Pozycjer::setter_y1(int y1) {this->y1 = y1;}
void silnik::Pozycjer::setter_y2(int y2) {this->y2 = y2;}
silnik::Pozycjer::Pozycjer(int y1,int x1, int y2, int x2) {
    // Utworzenie pozycji (bieżącej) figury
    this->y1 = y1;
    this->x1 = x1;
    this->y2 = y2;
    this->x2 = x2;
}
silnik::Pozycjer::Pozycjer() {;}

/// ---> silnik::Inicjalizer_Pól:
silnik::Inicjalizator_pol::Inicjalizator_pol(){
    /// inicjalizacja pol w haskodzie --> na tej podstawie potem bedzie rysowana plansza w SFML
    /// {120,88,111,79,0} -> wyjasnienia w LIBRARIESAndVariables

    this->gracz = 120;
    this->gracz_king = 88;
    this->cpu = 111;
    this->cpu_king = 79;
    this->pole = 0;

    this->plansza = new char*[8];                                  // wizualizacja planszy
    for(int i=0;i<8;i++) {
        this->plansza[i] = new char[8];
        for (int j = 0; j < 8; j++) {
            if (i % 2 == 0 && j % 2 == 1 && (i<=2)) this->plansza[i][j] = cpu;          // wizualizacja pionkow_1
            else if (i % 2 == 1 && j % 2 == 0 && (i<=2)) this->plansza[i][j] = cpu;
            else if (i % 2 == 1 && j % 2 == 0 && (i>=5)) this->plansza[i][j] = gracz;    // wizualizacja pionkow_2
            else if (i % 2 == 0 && j % 2 == 1 && (i>=5)) this->plansza[i][j] = gracz;
            else this->plansza[i][j] = pole;
        }
    }
    //plansza[7][0] = gracz_king;
    //plansza[0][3] = cpu_king;

//    plansza[3][2] = gracz;
//    plansza[1][2] = gracz;
//    plansza[1][4] = cpu;
//    plansza[3][4] = gracz;
//    plansza[4][5] = cpu_king;
//    plansza[4][3] = gracz;
}
silnik::Inicjalizator_pol::Inicjalizator_pol(Inicjalizator_pol& engine) {
    // tworzenie silnika dla gracza 2 (odwracanie przeciwnika -> teraz to gracz staje się naszym cpu(oponentem))
    this->gracz = engine.cpu;
    this->gracz_king = engine.cpu_king;
    this->cpu = engine.gracz;
    this->cpu_king = engine.gracz_king;
    this->pole = engine.pole;
    this->plansza =  engine.plansza;
}

char silnik::Inicjalizator_pol::getter_gracz() {return this->gracz;}
char silnik::Inicjalizator_pol::getter_gracz_king() {return this->gracz_king;}
char silnik::Inicjalizator_pol::getter_cpu() {return this->cpu;}
char silnik::Inicjalizator_pol::getter_cpu_king() {return this->cpu_king;}
char silnik::Inicjalizator_pol::getter_pole() {return this->pole;}
char** silnik::Inicjalizator_pol::getter_plansza() {return this->plansza;}

/// ---> silnik::Ruszer
int silnik::Ruszer::wykonaj_ruch_bierka(Inicjalizator_pol& engine,Pozycjer& pozycja) {
    if((pozycja.getter_y2()< 0 || pozycja.getter_y2() > 7) || (pozycja.getter_x2() < 0 || pozycja.getter_x2() > 7) ||  (pozycja.getter_y1()< 0 || pozycja.getter_y1() > 7) || (pozycja.getter_x1()< 0 || pozycja.getter_x1() > 7) ) return 0;
    if (engine.getter_plansza()[pozycja.getter_y1()][pozycja.getter_x1()] == engine.getter_gracz()) {                                     ///////////////////////// zwykly pionek///////////////////////
        if (Sprawdzacz_ruchu_pionka::czy_dozwolone_pionek(pozycja.getter_y1(), pozycja.getter_x1(), pozycja.getter_y2(), pozycja.getter_x2(),engine) == 1) {               // normalny ruch bez bic
            engine.getter_plansza()[pozycja.getter_y1()][pozycja.getter_x1()] = engine.getter_pole();    // wyzeruj pozycje
            engine.getter_plansza()[pozycja.getter_y2()][pozycja.getter_x2()] = engine.getter_gracz();   // ustaw pozycje na nowa
            Sprawdzacz_ruchu_pionka::czy_promocja_pionka(pozycja.getter_y2(), pozycja.getter_x2(),engine);
            cout << "ruch przeciwnika" << endl;
            return 1;
        }
        else if (Sprawdzacz_ruchu_pionka::czy_dozwolone_pionek(pozycja.getter_y1(), pozycja.getter_x1(), pozycja.getter_y2(), pozycja.getter_x2(),engine) == 2) {          // na prawo bicie - NE
            engine.getter_plansza()[pozycja.getter_y1()][pozycja.getter_x1()] = engine.getter_pole();
            engine.getter_plansza()[pozycja.getter_y2()][pozycja.getter_x2()] = engine.getter_gracz();
            if(engine.getter_gracz() == 120) engine.getter_plansza()[pozycja.getter_y2() + 1][pozycja.getter_x2() - 1] = engine.getter_pole();   // Eliminacja przeciwnika
            else if (engine.getter_gracz() == 111) engine.getter_plansza()[pozycja.getter_y2() - 1][pozycja.getter_x2() + 1] = engine.getter_pole();   // Eliminacja przeciwnika
            Sprawdzacz_ruchu_pionka::czy_promocja_pionka(pozycja.getter_y2(), pozycja.getter_x2(),engine);
            if (Sprawdzacz_ruchu_pionka::sprawdzenie_ruchu_wielokrotnego_pionka(pozycja.getter_y2(), pozycja.getter_x2(),engine) == 1) { // Jezeli masz ruch wielokrotny
                return 2;
            }
            else { cout << "ruch przeciwnika" << endl;return 1;  }
        }
        else if (Sprawdzacz_ruchu_pionka::czy_dozwolone_pionek(pozycja.getter_y1(), pozycja.getter_x1(), pozycja.getter_y2(), pozycja.getter_x2(),engine) == 3) {              // na lewo bicie - NW
            engine.getter_plansza()[pozycja.getter_y1()][pozycja.getter_x1()] = engine.getter_pole();
            engine.getter_plansza()[pozycja.getter_y2()][pozycja.getter_x2()] = engine.getter_gracz();
            if (engine.getter_gracz() == 120) engine.getter_plansza()[pozycja.getter_y2() + 1][pozycja.getter_x2() + 1] = engine.getter_pole();   // Eliminacja przeciwnika
            else if (engine.getter_gracz() == 111) engine.getter_plansza()[pozycja.getter_y2() - 1][pozycja.getter_x2() - 1] = engine.getter_pole();   // Eliminacja przeciwnika
            Sprawdzacz_ruchu_pionka::czy_promocja_pionka(pozycja.getter_y2(), pozycja.getter_x2(),engine);
            if (Sprawdzacz_ruchu_pionka::sprawdzenie_ruchu_wielokrotnego_pionka(pozycja.getter_y2(), pozycja.getter_x2(),engine) == 1) {   // Jezeli masz ruch wielokrotny
                return 2;
            }
            else { cout << "ruch przeciwnika" << endl;return 1;  }
        }
        else if (Sprawdzacz_ruchu_pionka::czy_dozwolone_pionek(pozycja.getter_y1(), pozycja.getter_x1(), pozycja.getter_y2(), pozycja.getter_x2(),engine) == 0) {return 0; } // --> zly ruch
    }
    else if (engine.getter_plansza()[pozycja.getter_y1()][pozycja.getter_x1()] == engine.getter_gracz_king()) {            ///////////////////////// krolowa ///////////////////////
        if (Sprawdzacz_ruchu_krolowej::czy_dozwolone_krolowa(pozycja.getter_y1(), pozycja.getter_x1(), pozycja.getter_y2(), pozycja.getter_x2(),engine) == 1) {               // normalny ruch bez bic
            engine.getter_plansza()[pozycja.getter_y1()][pozycja.getter_x1()] = engine.getter_pole();    // wyzeruj pozycje
            engine.getter_plansza()[pozycja.getter_y2()][pozycja.getter_x2()] = engine.getter_gracz_king();   // ustaw pozycje na nowa
            cout << "ruch przeciwnika" << endl;
            return 1;
        }
        else if ((Sprawdzacz_ruchu_krolowej::czy_dozwolone_krolowa(pozycja.getter_y1(), pozycja.getter_x1(), pozycja.getter_y2(), pozycja.getter_x2(),engine) == 2)) {          // bicie w kierunku NE
            engine.getter_plansza()[pozycja.getter_y1()][pozycja.getter_x1()] = engine.getter_pole();
            engine.getter_plansza()[pozycja.getter_y2()][pozycja.getter_x2()] = engine.getter_gracz_king();
            engine.getter_plansza()[pozycja.getter_y2() + 1][pozycja.getter_x2() - 1] = engine.getter_pole();   // Eliminacja przeciwnika
            if (Sprawdzacz_ruchu_krolowej::sprawdzenie_ruchu_wielokrotnego_krolowej(pozycja.getter_y2(), pozycja.getter_x2(),engine) == 1) { // Jezeli masz ruch wielokrotny
                return 2;
            }
            else { cout << "ruch przeciwnika" << endl;return 1;  }
        }
        else if ((Sprawdzacz_ruchu_krolowej::czy_dozwolone_krolowa(pozycja.getter_y1(), pozycja.getter_x1(), pozycja.getter_y2(), pozycja.getter_x2(),engine) == 3)) {              // bicie w kierunku SE
            engine.getter_plansza()[pozycja.getter_y1()][pozycja.getter_x1()] = engine.getter_pole();
            engine.getter_plansza()[pozycja.getter_y2()][pozycja.getter_x2()] = engine.getter_gracz_king();
            engine.getter_plansza()[pozycja.getter_y2() - 1][pozycja.getter_x2() - 1] = engine.getter_pole();   // Eliminacja przeciwnika
            if (Sprawdzacz_ruchu_krolowej::sprawdzenie_ruchu_wielokrotnego_krolowej(pozycja.getter_y2(), pozycja.getter_x2(),engine) == 1) {   // Jezeli masz ruch wielokrotny
                return 2;
            }
            else { cout << "ruch przeciwnika" << endl;return 1;  }
        }
        else if ((Sprawdzacz_ruchu_krolowej::czy_dozwolone_krolowa(pozycja.getter_y1(), pozycja.getter_x1(), pozycja.getter_y2(), pozycja.getter_x2(),engine) == 4)) {          // bicie w kierunku NW
            engine.getter_plansza()[pozycja.getter_y1()][pozycja.getter_x1()] = engine.getter_pole();
            engine.getter_plansza()[pozycja.getter_y2()][pozycja.getter_x2()] = engine.getter_gracz_king();
            engine.getter_plansza()[pozycja.getter_y2() + 1][pozycja.getter_x2() + 1] = engine.getter_pole();   // Eliminacja przeciwnika
            if (Sprawdzacz_ruchu_krolowej::sprawdzenie_ruchu_wielokrotnego_krolowej(pozycja.getter_y2(), pozycja.getter_x2(),engine) == 1) { // Jezeli masz ruch wielokrotny
                return 2;
            }
            else { cout << "ruch przeciwnika" << endl;return 1;  }
        }
        else if ((Sprawdzacz_ruchu_krolowej::czy_dozwolone_krolowa(pozycja.getter_y1(), pozycja.getter_x1(), pozycja.getter_y2(), pozycja.getter_x2(),engine) == 5)) {              // bicie w kierunku SW
            engine.getter_plansza()[pozycja.getter_y1()][pozycja.getter_x1()] = engine.getter_pole();
            engine.getter_plansza()[pozycja.getter_y2()][pozycja.getter_x2()] = engine.getter_gracz_king();
            engine.getter_plansza()[pozycja.getter_y2() - 1][pozycja.getter_x2() + 1] = engine.getter_pole();   // Eliminacja przeciwnika
            if (Sprawdzacz_ruchu_krolowej::sprawdzenie_ruchu_wielokrotnego_krolowej(pozycja.getter_y2(), pozycja.getter_x2(),engine) == 1) {   // Jezeli masz ruch wielokrotny
                return 2;
            }
            else { cout << "ruch przeciwnika" << endl;return 1; }
        }
        else if (Sprawdzacz_ruchu_krolowej::czy_dozwolone_krolowa(pozycja.getter_y1(), pozycja.getter_x1(), pozycja.getter_y2(), pozycja.getter_x2(),engine) == 0) {return 0; } // --> zly ruch
    }
    {return 0;}       // wszystkie inne przypadki nieprzewidziane
}
int silnik::Ruszer::pobierz_pozycje_bierki(sf::RenderWindow& window,Ruch& aktualny_ruch,Inicjalizator_pol& engine,Pozycjer& pozycja,int& licznik){
    int x1,x2,y1,y2;
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        if(licznik % 2 == 0) {
            x1 = static_cast<int>((sf::Mouse::getPosition(window).x) / (175/resolution_mode)); /// pobranie pozycji poczatkowej
            y1 = static_cast<int>((sf::Mouse::getPosition(window).y) / (175/resolution_mode)); /// pobranie pozycji poczatkowej

            if(x1 < 0 || x1 > 7 || y1 < 0 || y1 > 7) return 0; /// pole poza plansza

            pozycja.setter_x1(x1); // ustawienie pozycji
            pozycja.setter_y1(y1); // ustawienie pozycji

            aktualny_ruch.setter_x(x1); // inicjacja aktualnego ruchu
            aktualny_ruch.setter_y(y1); // inicjacja aktualnego ruchu
            cout << "poz_1: " << y1 << " " << x1 << endl;
            while (sf::Mouse::isButtonPressed(sf::Mouse::Left));  /// <---------
            return 1;
        }
        else if(licznik % 2 == 1) {
            x2 = static_cast<int>((sf::Mouse::getPosition(window).x) / (175/resolution_mode)); /// pobranie pozycji koncowej
            y2 = static_cast<int>((sf::Mouse::getPosition(window).y) / (175/resolution_mode)); /// pobranie pozycji koncowej

            if(x2 < 0 || x2 > 7 || y2 < 0 || y2 > 7) return 0; /// pole poza plansza

            pozycja.setter_x2(x2); // ustawienie pozycji
            pozycja.setter_y2(y2); // ustawienie pozycji

            aktualny_ruch.setter_x(x2); // inicjacja aktualnego ruchu
            aktualny_ruch.setter_y(y2); // inicjacja aktualnego ruchu
            cout << "poz_2:" << y2 << " " << x2 << endl;
            while (sf::Mouse::isButtonPressed(sf::Mouse::Left)); /// <---------
            return 1;
        }
    }
    return 0; // nie udalo sie pobrac poprawnego ruchu
}
silnik::Ruszer::Ruszer() {;}

/// ---> silnik::Sprawdzacz_ruchu_krolowej:
int silnik::Sprawdzacz_ruchu_krolowej::sprawdzanie_linii(int y1,int x1,int y2,int x2,Inicjalizator_pol& engine) {
    if(y2<y1 && x2>x1) { // kierunek NE
        while(++x1 != x2 && --y1 != y2) {   // sprawdzamy linie po ktorej sie ruszyla krolowa
            if(engine.getter_plansza()[y1][x1] == engine.getter_gracz() || engine.getter_plansza()[y1][x1] == engine.getter_gracz_king()) return 0;                                         // Nie mozna przeskakiwac/ bic wlasnych pionkow
            else if((engine.getter_plansza()[y1][x1] == engine.getter_cpu() || engine.getter_plansza()[y1][x1] == engine.getter_cpu_king()) && ((x1 + 1 != x2) && (y1 - 1 != y2)) ) return 0; // Jezeli po zbiciu przeciwnika twoj pionek nie jest za nim -> bicie niedozwolone
        }
        return 2; // Bicie w kierunku NE
    }
    else if(y2>y1 && x2>x1) { // kierunek SE
        while(++x1 != x2 && ++y1 != y2) {   // sprawdzamy linie po ktorej sie ruszyla krolowa
            if(engine.getter_plansza()[y1][x1] == engine.getter_gracz() || engine.getter_plansza()[y1][x1] == engine.getter_gracz_king()) return 0;                                         // Nie mozna przeskakiwac/ bic wlasnych pionkow
            else if((engine.getter_plansza()[y1][x1] == engine.getter_cpu() || engine.getter_plansza()[y1][x1] == engine.getter_cpu_king()) && ((x1 + 1 != x2) && (y1 + 1 != y2)) ) return 0; // Jezeli po zbiciu przeciwnika twoj pionek nie jest za nim -> bicie niedozwolone
        }
        return 3; // Bicie w kierunku SE
    }
    else if(y2<y1 && x2<x1) { // kierunek NW
        while(--x1 != x2 && --y1 != y2) {   // sprawdzamy linie po ktorej sie ruszyla krolowa
            if(engine.getter_plansza()[y1][x1] == engine.getter_gracz() || engine.getter_plansza()[y1][x1] == engine.getter_gracz_king()) return 0;                                         // Nie mozna przeskakiwac/ bic wlasnych pionkow
            else if((engine.getter_plansza()[y1][x1] == engine.getter_cpu() ||engine.getter_plansza()[y1][x1] == engine.getter_cpu_king()) && ((x1 - 1 != x2) && (y1 - 1 != y2)) ) return 0; // Jezeli po zbiciu przeciwnika twoj pionek nie jest za nim -> bicie niedozwolone

        }
        return 4; // Bicie w kierunku NW
    }
    else if(y2>y1 && x2<x1) { // kierunek SW
        while(--x1 != x2 && ++y1 != y2) {   // sprawdzamy linie po ktorej sie ruszyla krolowa
            if(engine.getter_plansza()[y1][x1] == engine.getter_gracz() || engine.getter_plansza()[y1][x1] == engine.getter_gracz_king()) return 0;                                        // Nie mozna przeskakiwac/ bic wlasnych pionkow
            else if((engine.getter_plansza()[y1][x1] == engine.getter_cpu() || engine.getter_plansza()[y1][x1] == engine.getter_cpu_king()) && ((x1 - 1 != x2) && (y1 + 1 != y2)) ) return 0; // Jezeli po zbiciu przeciwnika twoj pionek nie jest za nim -> bicie niedozwolone
        }
        return 5; // Bicie w kierunku SW
    }
}
bool silnik::Sprawdzacz_ruchu_krolowej::sprawdzenie_ruchu_wielokrotnego_krolowej(int y2,int x2,Inicjalizator_pol& engine) {

    int xpom_1 = x2; int ypom_1 = y2;
    while((++xpom_1 < 7 && --ypom_1 > 0) && (engine.getter_plansza()[ypom_1][xpom_1] != engine.getter_cpu() && engine.getter_plansza()[ypom_1][xpom_1] != engine.getter_cpu_king()));  // Szukamy na linii NE potencjalnych bic
    ++xpom_1; // x -> pozycja albo za mapa (niedozwolona) albo (pole na ktorym wyladuje krolowka po biciu)
    --ypom_1; // y -> pozycja albo za mapa (niedozwolona) albo (pole na ktorym wyladuje krolowka po biciu)
    if(czy_dozwolone_krolowa(y2,x2,ypom_1,xpom_1,engine) == 2) return 1;       // Jezeli mamy bicie NE

    int xpom_2 = x2; int ypom_2 = y2;
    while(++xpom_2 < 7 && ++ypom_2 < 7 && (engine.getter_plansza()[ypom_2][xpom_2] != engine.getter_cpu() && engine.getter_plansza()[ypom_2][xpom_2] != engine.getter_cpu_king()));
    ++xpom_2; // x -> pozycja albo za mapa (niedozwolona) albo (pole na ktorym wyladuje krolowka po biciu)
    ++ypom_2; // y -> pozycja albo za mapa (niedozwolona) albo (pole na ktorym wyladuje krolowka po biciu)
    if(czy_dozwolone_krolowa(y2,x2,ypom_2,xpom_2,engine) == 3) return 1;  // Jezeli mamy bicie SE

    int xpom_3 = x2; int ypom_3 = y2;
    while(--xpom_3 > 0 && --ypom_3 > 0 && (engine.getter_plansza()[ypom_3][xpom_3] != engine.getter_cpu() && engine.getter_plansza()[ypom_3][xpom_3] != engine.getter_cpu_king()));
    --xpom_3; // x -> pozycja albo za mapa (niedozwolona) albo (pole na ktorym wyladuje krolowka po biciu)
    --ypom_3; // y -> pozycja albo za mapa (niedozwolona) albo (pole na ktorym wyladuje krolowka po biciu)
    if(czy_dozwolone_krolowa(y2,x2,ypom_3,xpom_3,engine) == 4) return 1;  // Jezeli mamy bicie NW

    int xpom_4 = x2; int ypom_4 = y2;
    while(--xpom_4 > 0 && ++ypom_4 < 7 && (engine.getter_plansza()[ypom_4][xpom_4] != engine.getter_cpu() && engine.getter_plansza()[ypom_4][xpom_4] != engine.getter_cpu_king()));
    --xpom_4; // x -> pozycja albo za mapa (niedozwolona) albo (pole na ktorym wyladuje krolowka po biciu)
    ++ypom_4; // y -> pozycja albo za mapa (niedozwolona) albo (pole na ktorym wyladuje krolowka po biciu)
    if(czy_dozwolone_krolowa(y2,x2,ypom_4,xpom_4,engine) == 5) return 1;  // Jezeli mamy bicie SW

    return 0; // nie ma po wykonanym ruchu żadnych bić dodatkowych dla krolowej
}
int silnik::Sprawdzacz_ruchu_krolowej::czy_dozwolone_krolowa(int y1,int x1,int y2,int x2,Inicjalizator_pol& engine) {
    if((y2 < 0 || y2 > 7) || (x2 < 0 || x2 > 7)) return 0;                                                  // ruch na niedozwolona pozycje - poza mape
    else if ((y1 % 2 == 1 && x1 % 2 == 1) || (y1 % 2 == 0 && x1 % 2 == 0) ) return 0;                       // ruch z pola niedozwolonego - białe pole #1
    else if ((y2 % 2 == 1 && x2 % 2 == 1) || (y2 % 2 == 0 && x2 % 2 == 0) ) return 0;                        // ruch na pole niedozwolone - białe pole #2
    else if (engine.getter_plansza()[y1][x1] != engine.getter_gracz_king()) return 0;                                                       // ruch nie swoim pionkiem
    else if (engine.getter_plansza()[y2][x2] == engine.getter_gracz_king() || engine.getter_plansza()[y2][x2] == engine.getter_cpu() || engine.getter_plansza()[y2][x2] == engine.getter_gracz() || engine.getter_plansza()[y2][x2] == engine.getter_cpu_king()) return 0; // ruch na pole zajete

    else if ((abs(y1 - y2) != abs(x1 - x2))) return 0;                                                      // jezeli nie poruszasz sie po tej samej przekatnej

    else if ((sprawdzanie_linii(y1,x1,y2,x2,engine) == 0)) return 0;    // Ruch jest niezgodny z zasadami bicia krolowej po przekatnej (bicie wlasnego pionka lub twoj pionek nie jest za przeciwnikiem po biciu)
    else if ((sprawdzanie_linii(y1,x1,y2,x2,engine) == 2) && (engine.getter_plansza()[y2+1][x2-1] == engine.getter_cpu() || engine.getter_plansza()[y2+1][x2-1] == engine.getter_cpu_king()) ) return 2;   // Bicie w kierunku NE
    else if ((sprawdzanie_linii(y1,x1,y2,x2,engine) == 3) && (engine.getter_plansza()[y2-1][x2-1] == engine.getter_cpu() || engine.getter_plansza()[y2-1][x2-1] == engine.getter_cpu_king())) return 3;   // Bicie w kierunku SE
    else if ((sprawdzanie_linii(y1,x1,y2,x2,engine) == 4) && (engine.getter_plansza()[y2+1][x2+1] == engine.getter_cpu() || engine.getter_plansza()[y2+1][x2+1] == engine.getter_cpu_king())) return 4;  // Bicie w kierunku NW
    else if ((sprawdzanie_linii(y1,x1,y2,x2,engine) == 5) && (engine.getter_plansza()[y2-1][x2+1] == engine.getter_cpu() || engine.getter_plansza()[y2-1][x2+1] == engine.getter_cpu_king())) return 5;  // Bicie w kierunku SW

    else return 1;   // Jezeli zwykly ruch (bez bicia)
}

/// ---> silnik::Sprawdzacz_ruchu_pionka:
int silnik::Sprawdzacz_ruchu_pionka::czy_dozwolone_pionek(int y1,int x1,int y2,int x2,Inicjalizator_pol& engine) {

    if((y2 < 0 || y2 > 7) || (x2 < 0 || x2 > 7)) return 0;                                  // ruch na niedozwolona pozycje - poza mape
    else if ((y1 % 2 == 1 && x1 % 2 == 1) || (y1 % 2 == 0 && x1 % 2 == 0) ) return 0;      // ruch z pola niedozwolonego - białe pole
    else if ((y2 % 2 == 1 && x2 % 2 == 1) || (y2 % 2 == 0 && x2 % 2 == 0) ) return 0;      // ruch na pole niedozwolone - białe pole
    else if (engine.getter_plansza()[y1][x1] != engine.getter_gracz()) {return 0;}         // ruch nie swoim pionkiem
    else if (engine.getter_plansza()[y2][x2] == engine.getter_gracz() || engine.getter_plansza()[y2][x2] == engine.getter_cpu() || engine.getter_plansza()[y2][x2] == engine.getter_gracz_king() || engine.getter_plansza()[y2][x2] == engine.getter_cpu_king()) return 0;  // ruch na pole zajete
    else if (y2<y1 && engine.getter_gracz() == 111)     return 0;                                                       /////////// ruch do tyłu (gracz)
    else if (y2>y1 && engine.getter_gracz() == 120)     return 0;                                                       /////////// ruch do tyłu (cpu)

    else if ((abs(x2-x1) > 2 || abs(y2-y1) > 2)  && engine.getter_plansza()[y1][x1] == engine.getter_gracz()) return 0;              // ruch o wiecej niz 2 pola (niedozwolone zawsze dla pionka)

    else if (engine.getter_gracz() == 120 && (engine.getter_plansza()[y2+1][x2-1] == engine.getter_cpu() || engine.getter_plansza()[y2+1][x2-1] == engine.getter_cpu_king()) && x2>x1) return 2;                     // przeskoczenie pionka na prawo
    else if (engine.getter_gracz() == 120 && (engine.getter_plansza()[y2+1][x2+1] == engine.getter_cpu() || engine.getter_plansza()[y2+1][x2+1] == engine.getter_cpu_king()) && x2<x1) return 3;                     // przeskoczenie pionka na lewo

    else if (engine.getter_gracz() == 111 && (engine.getter_plansza()[y2-1][x2+1] == engine.getter_cpu() || engine.getter_plansza()[y2-1][x2+1] == engine.getter_cpu_king()) && x2<x1) return 2;                     // przeskoczenie pionka na prawo
    else if (engine.getter_gracz()== 111 && (engine.getter_plansza()[y2-1][x2-1] == engine.getter_cpu() || engine.getter_plansza()[y2-1][x2-1] == engine.getter_cpu_king()) && x2>x1) return 3;                     // przeskoczenie pionka na lewo

    else if ((abs(x2-x1) > 1 || abs(y2-y1) > 1)  && engine.getter_plansza()[y1][x1] == engine.getter_gracz() ) return 0;             // ruch o wiecej niz 1 pole (niedozwolone jesli nie bijesz)

    else return 1;   // Jezeli zwykly ruch
}
bool silnik::Sprawdzacz_ruchu_pionka::sprawdzenie_ruchu_wielokrotnego_pionka(int y2,int x2,Inicjalizator_pol& engine) {
    if(engine.getter_gracz() == 120 && (czy_dozwolone_pionek(y2,x2,y2-2,x2+2,engine) == 2)) return 1;       // Jezeli mamy bicie na prawo
    else if(engine.getter_gracz()  == 120 && (czy_dozwolone_pionek(y2,x2,y2-2,x2-2,engine) == 3)) return 1;  // Jezeli mamy bicie na lewo

    if(engine.getter_gracz()  == 111 && (czy_dozwolone_pionek(y2,x2,y2+2,x2-2,engine) == 2)) return 1;       // Jezeli mamy bicie na prawo
    else if(engine.getter_gracz()  == 111 && (czy_dozwolone_pionek(y2,x2,y2+2,x2+2,engine) == 3)) return 1;  // Jezeli mamy bicie na lewo

    else return 0;
}
void silnik::Sprawdzacz_ruchu_pionka::czy_promocja_pionka(int y2, int x2,Inicjalizator_pol& engine) {
    if(engine.getter_gracz() == 120 && (y2 == 0)) engine.getter_plansza()[y2][x2] = engine.getter_gracz_king(); // jezeli gracz 1 i koniec mapy to promocja na krolowa
    else if(engine.getter_gracz() == 111 && (y2 == 7)) engine.getter_plansza()[y2][x2] = engine.getter_gracz_king(); // jezeli gracz 2 i koniec mapy to promocja na krolowa
}

/// ---> silnik::Druker_planszy:
void silnik::Druker_planszy::drukuj_plansze(Inicjalizator_pol& engine) {
    /// Drukowanie schematu planszy w hashcodzie (plansza w terminalu) --> na jej podstawie bedzie drukowana plansza w sfml
    static int licznik;
    cout << licznik << ") -----------------------------------" <<endl;
    cout <<"   0  1  2  3  4  5  6  7" << endl;
    for(int i=0;i<8;i++) {
        cout << i  << "  ";
        for (int j = 0; j < 8; j++) {
            if (i % 2 == 1 && j % 2 == 0 && (engine.getter_plansza()[i][j] != engine.getter_gracz() || engine.getter_plansza()[i][j] != engine.getter_cpu())) cout << engine.getter_plansza()[i][j] << "  ";        // Zasady drukowania pol pustych
            else if (i % 2 == 0 && j % 2 == 1 && (engine.getter_plansza()[i][j] != engine.getter_gracz() || engine.getter_plansza()[i][j] != engine.getter_cpu())) cout << engine.getter_plansza()[i][j] << "  ";  // Zasady drukowania pol pustych
            else cout << "   ";
        }
        cout << endl;
    }
    licznik++;
}

/// ---> silnik::Obligator_bic:
void silnik::Obligator_bic::sprawdz_bicia(Inicjalizator_pol& engine,int& poprawnosc_ruchu_2,silnik::Pozycjer& pozycja) {
    /// Określenie zbioru ruchow możliwych do wykonania, gdy wystepuja bicia
    this->obowiazek_bic_krolowa.clear();
    this->obowiazek_bic_pionek.clear();
    for(int i=0;i<8;i++) {
        for(int j=0;j<8;j++) {
            if(engine.getter_plansza()[i][j] == engine.getter_gracz()) {
                bool a = silnik::Sprawdzacz_ruchu_pionka::sprawdzenie_ruchu_wielokrotnego_pionka(i,j,engine);
                if(a == 1 && poprawnosc_ruchu_2 != 2) { Ruch r_1(j,i); this->obowiazek_bic_pionek.push_front(r_1);}   // lista koniecznych ruchow do wykoniania pionkiem - gracz wybiera sobie jeden z nich
                if(a == 1 && poprawnosc_ruchu_2 == 2 && pozycja.getter_x1() == j && pozycja.getter_y1() == i)
                { Ruch r_1(j,i); this->obowiazek_bic_pionek.push_front(r_1);}   // lista koniecznych ruchow do wykoniania pionkiem - gracz wybiera sobie jeden z nich
            }
            else if(engine.getter_plansza()[i][j] == engine.getter_gracz_king()) {
                bool b = silnik::Sprawdzacz_ruchu_krolowej::sprawdzenie_ruchu_wielokrotnego_krolowej(i,j,engine);
                if(b == 1 && poprawnosc_ruchu_2 != 2) {Ruch r_2(j,i); this->obowiazek_bic_krolowa.push_front(r_2);} // lista koniecznych ruchow do wykoniania krolowa - gracz wybiera sobie jeden z nich (wyższy priorytet od ruchu pionkiem)
                if(b == 1 && poprawnosc_ruchu_2 == 2 && pozycja.getter_x1() == j && pozycja.getter_y1() == i)
                {Ruch r_2(j,i); this->obowiazek_bic_krolowa.push_front(r_2);} // lista koniecznych ruchow do wykoniania krolowa - gracz wybiera sobie jeden z nich (wyższy priorytet od ruchu pionkiem)
            }
        }
    }
}
void silnik::Obligator_bic::wymus_bicie_pionek(silnik::Ruszer &ruszacz, int &licznik,silnik::Inicjalizator_pol& engine,silnik::Pozycjer& pozycja,int& poprawnosc_ruchu,int& poprawnosc_ruchu_2) {
    int zlicz = 0; // cel --> sprawdzic czy wykonany zostal ruch obowiazkowy
    for (std::list<Ruch>::iterator it = this->obowiazek_bic_pionek.begin();it != this->obowiazek_bic_pionek.end(); it++) {
        if ((*it).getter_x() == pozycja.getter_x1() && (*it).getter_y() == pozycja.getter_y1()) {
            int c = silnik::Sprawdzacz_ruchu_pionka::czy_dozwolone_pionek(pozycja.getter_y1(),pozycja.getter_x1(),pozycja.getter_y2(),pozycja.getter_x2(),engine);
            if(c == 2 || c == 3) { // Jezeli bicie pionkiem w prawo lub lewo
                int a = ruszacz.wykonaj_ruch_bierka(engine, pozycja);  /// sprawdzenie ruchu wielokrotnego i wykonanie ruchu
                poprawnosc_ruchu = a; // zwroc do programu wartosc okreslajaca to czy ruch byl poprawny
                poprawnosc_ruchu_2 = a;
                if (a != 0) silnik::Druker_planszy::drukuj_plansze(engine); // Plansza na ekranie konsoli (nie ta w oknie) --> jezeli poprawny ruch --> czyli z biciem
                if ((a != 1) && engine.getter_gracz() == 120) licznik = 0; // ruch wielokrotny lub błędny --> jeszcze raz ten sam gracz
                if ((a != 1) && engine.getter_gracz() == 111) licznik = 2; // ruch wielokrotny lub błędny --> jeszcze raz ten sam gracz
                zlicz++;
            }
        }
    }
    if(zlicz == 0 && engine.getter_gracz() == 120) licznik = 0; // Nie wykonano ruchu obowiązkowego --> w takim razie każ go powtorzyc graczowi nr 1
    if(zlicz == 0 && engine.getter_gracz() == 111) licznik = 2; // Nie wykonano ruchu obowiązkowego --> w takim razie każ go powtorzyc graczowi nr 2
}
void silnik::Obligator_bic::wymus_bicie_krolowa_1(silnik::Ruszer &ruszacz, int &licznik,silnik::Inicjalizator_pol& engine,silnik::Pozycjer& pozycja,int& poprawnosc_ruchu,int& poprawnosc_ruchu_2) {
    int zlicz = 0; // cel --> sprawdzic czy wykonany zostal ruch obowiazkowy
    for (std::list<Ruch>::iterator it = this->obowiazek_bic_krolowa.begin();it != this->obowiazek_bic_krolowa.end(); it++) {
        if ((*it).getter_x() == pozycja.getter_x1() && (*it).getter_y() == pozycja.getter_y1()) {
            int c = silnik::Sprawdzacz_ruchu_krolowej::czy_dozwolone_krolowa(pozycja.getter_y1(),pozycja.getter_x1(),pozycja.getter_y2(),pozycja.getter_x2(),engine);
            if(c == 2 || c == 3 || c == 4 || c == 5) { // Jezeli bicie krolowa na ktorejkolwiek przekatnej
                int a = ruszacz.wykonaj_ruch_bierka(engine, pozycja);  /// sprawdzenie ruchu wielokrotnego i wykonanie ruchu
                poprawnosc_ruchu = a; // zwroc do programu wartosc okreslajaca to czy ruch byl poprawny
                poprawnosc_ruchu_2 = a;
                if (a != 0) silnik::Druker_planszy::drukuj_plansze(engine); // Plansza na ekranie konsoli (nie ta w oknie) --> jezeli poprawny ruch --> czyli z biciem
                if (a != 1) licznik = 0; // ruch wielokrotny lub błędny --> jeszcze raz ten sam gracz
                zlicz++;
            }
        }
    }
    if(zlicz == 0) licznik = 0; // Nie wykonano ruchu obowiązkowego --> w takim razie każ go powtorzyc graczowi nr 1 (przechwyci takze niedozwolony ruch pionkiem - z wzgledu na priorytet)
}
void silnik::Obligator_bic::wymus_bicie_krolowa_2(silnik::Ruszer &ruszacz, int &licznik,silnik::Inicjalizator_pol& engine,silnik::Pozycjer& pozycja,int& poprawnosc_ruchu,int& poprawnosc_ruchu_2) {
    int zlicz = 0; // cel --> sprawdzic czy wykonany zostal ruch obowiazkowy
    for (std::list<Ruch>::iterator it = this->obowiazek_bic_krolowa.begin();it != this->obowiazek_bic_krolowa.end(); it++) {
        if ((*it).getter_x() == pozycja.getter_x1() && (*it).getter_y() == pozycja.getter_y1()) {
            int c = silnik::Sprawdzacz_ruchu_krolowej::czy_dozwolone_krolowa(pozycja.getter_y1(),pozycja.getter_x1(),pozycja.getter_y2(),pozycja.getter_x2(),engine);
            if(c == 2 || c == 3 || c == 4 || c == 5) { // Jezeli bicie krolowa na ktorejkolwiek przekatnej
                int a = ruszacz.wykonaj_ruch_bierka(engine, pozycja);  /// sprawdzenie ruchu wielokrotnego i wykonanie ruchu
                poprawnosc_ruchu = a; // zwroc do programu wartosc okreslajaca to czy ruch byl poprawny
                poprawnosc_ruchu_2 = a;
                if (a != 0) silnik::Druker_planszy::drukuj_plansze(engine); // Plansza na ekranie konsoli (nie ta w oknie) --> jezeli poprawny ruch --> czyli z biciem
                if (a != 1) licznik = 2; // ruch wielokrotny lub błędny --> jeszcze raz ten sam gracz
                zlicz++;
            }
        }
    }
    if(zlicz == 0) licznik = 2; // Nie wykonano ruchu obowiązkowego --> w takim razie każ go powtorzyc graczowi nr 2 (przechwyci takze niedozwolony ruch pionkiem - z wzgledu na priorytet)
}
list<Ruch> silnik::Obligator_bic::getter_krolowa_list() {return obowiazek_bic_krolowa;}
list<Ruch> silnik::Obligator_bic::getter_pionek_list() { return obowiazek_bic_pionek;}

///  ---> silnik::Zakonczer_rozgrywki:
int silnik::Zakonczer_rozgrywki::sprawdz_czy_koniec(Inicjalizator_pol& engine_1,Inicjalizator_pol& engine_2,sf::RenderWindow& window,silnik::Pozycjer& pozycja,int& czas_1,int& czas_2,int& poprawnosc_ruchu,int& licznik_zakonczenia,int& start) {
    int zakleszczenie_1 = silnik::Zakonczer_rozgrywki::sprawdz_zakleszczenie(engine_1); // zakleszczenie_1 == 0 gdy dany gracz nie ma wolnego ruchu
    int zakleszczenie_2 = silnik::Zakonczer_rozgrywki::sprawdz_zakleszczenie(engine_2); // zakleszczenie_2 == 0 gdy dany gracz nie ma wolnego ruchu
    int remis = silnik::Zakonczer_rozgrywki::sprawdz_remis(engine_1,pozycja,poprawnosc_ruchu,start);
//    User user;
//    user.Punkty(0); //przegrana
//    user.Punkty(1); //remis
//    user.Punkty(2); //wygrana
    if(zakleszczenie_1 == 0 || zakleszczenie_2 == 0 || remis == 0 || czas_1 == 0 || czas_2 == 0 ) {  // brak pionkow lub zakleszczenie
        sf::Sprite pole_wynikowe;
        sf::Texture text;
        if(zakleszczenie_1 == 0 || czas_1 == 0) // wygral gracz 2
            text.loadFromFile(MY_DEFINE "../data/win/win_2.png");
        else if (remis == 0)    // remis (15 ruchow bez bicia)
            text.loadFromFile(MY_DEFINE "../data/win/remis.png");
        else // wygral gracz 1
            text.loadFromFile(MY_DEFINE "../data/win/win_1.png");

        pole_wynikowe.setTexture(text);

        int x = window.getView().getCenter().x;
        int y = window.getView().getCenter().y;

        pole_wynikowe.setPosition(x - ((440 + 300) / resolution_mode) ,y - (226 / resolution_mode));
        if(resolution_mode == 2) pole_wynikowe.setScale(0.5,0.5);
        window.draw(pole_wynikowe); // wyswietl komunikat o wygranej
        if(licznik_zakonczenia++ >= 100) {
            User user;
            if(zakleszczenie_2 == 0 || czas_2 == 0 ) user.Punkty(2);
            else if (remis == 0) user.Punkty(1);
            else user.Punkty(0);

            return -777; // po x czasu zakoncz program ( x wywolan petli gry)
        }
        return 0;
    }
    return 1; // Nie ma konca gry

}
int silnik::Zakonczer_rozgrywki::sprawdz_zakleszczenie(Inicjalizator_pol& engine) {
    int licznik_zakleszczen = 0; // jesli ten licznik bedzie 0 na koncu funkcji to mamy zakleszczenie jednego z graczy
    for(int i=0;i<8;i++) {
        for(int j=0;j<8;j++) {
            if(engine.getter_plansza()[i][j] == engine.getter_gracz()) {
                bool a = silnik::Sprawdzacz_ruchu_pionka::sprawdzenie_ruchu_wielokrotnego_pionka(i,j,engine);
                if(a == 1) licznik_zakleszczen++; // Masz ruch, ktorym jest bicie

                if(engine.getter_gracz() == 120 && silnik::Sprawdzacz_ruchu_pionka::czy_dozwolone_pionek(i,j,i-1,j+1,engine) != 0) licznik_zakleszczen++; // mozesz ruszyc sie pionkiem na prawo (gracz 1)
                if(engine.getter_gracz() == 120 && silnik::Sprawdzacz_ruchu_pionka::czy_dozwolone_pionek(i,j,i-1,j-1,engine) != 0) licznik_zakleszczen++; // mozesz ruszyc sie pionkiem na lewo (gracz 1)

                if(engine.getter_gracz() == 111 && silnik::Sprawdzacz_ruchu_pionka::czy_dozwolone_pionek(i,j,i+1,j+1,engine) != 0) licznik_zakleszczen++; // mozesz ruszyc sie pionkiem na lewo (gracz 2)
                if(engine.getter_gracz() == 111 && silnik::Sprawdzacz_ruchu_pionka::czy_dozwolone_pionek(i,j,i+1,j-1,engine) != 0) licznik_zakleszczen++; // mozesz ruszyc sie pionkiem na prawo (gracz 2)
            }
            else if (engine.getter_plansza()[i][j] == engine.getter_gracz_king()) {
                bool b = silnik::Sprawdzacz_ruchu_krolowej::sprawdzenie_ruchu_wielokrotnego_krolowej(i,j,engine);
                if (b == 1) licznik_zakleszczen++;

                if(engine.getter_gracz_king() == 88 && silnik::Sprawdzacz_ruchu_krolowej::czy_dozwolone_krolowa(i,j,i-1,j+1,engine) != 0) licznik_zakleszczen++; // masz ruch krolowa w kierunku NE (gracz 1)
                if(engine.getter_gracz_king() == 88 && silnik::Sprawdzacz_ruchu_krolowej::czy_dozwolone_krolowa(i,j,i-1,j-1,engine) != 0) licznik_zakleszczen++; // masz ruch krolowa w kierunku NW (gracz 1)
                if(engine.getter_gracz_king() == 88 && silnik::Sprawdzacz_ruchu_krolowej::czy_dozwolone_krolowa(i,j,i+1,j+1,engine) != 0) licznik_zakleszczen++; // masz ruch krolowa w kierunku SE (gracz 1)
                if(engine.getter_gracz_king() == 88 && silnik::Sprawdzacz_ruchu_krolowej::czy_dozwolone_krolowa(i,j,i+1,j-1,engine) != 0) licznik_zakleszczen++; // masz ruch krolowa w kierunku SW (gracz 1)

                if(engine.getter_gracz_king() == 79 && silnik::Sprawdzacz_ruchu_krolowej::czy_dozwolone_krolowa(i,j,i-1,j+1,engine) != 0) licznik_zakleszczen++; // masz ruch krolowa w kierunku NE (gracz 2)
                if(engine.getter_gracz_king() == 79 && silnik::Sprawdzacz_ruchu_krolowej::czy_dozwolone_krolowa(i,j,i-1,j-1,engine) != 0) licznik_zakleszczen++; // masz ruch krolowa w kierunku NW (gracz 2)
                if(engine.getter_gracz_king() == 79 && silnik::Sprawdzacz_ruchu_krolowej::czy_dozwolone_krolowa(i,j,i+1,j+1,engine) != 0) licznik_zakleszczen++; // masz ruch krolowa w kierunku SE (gracz 2)
                if(engine.getter_gracz_king() == 79 && silnik::Sprawdzacz_ruchu_krolowej::czy_dozwolone_krolowa(i,j,i+1,j-1,engine) != 0) licznik_zakleszczen++; // masz ruch krolowa w kierunku SW (gracz 2)
            }
        }
    }
    if(licznik_zakleszczen == 0) return 0; // Dany gracz nie ma ruchu pionkiem (zakleszczenie)
    else return 1; // Brak zakleszczenia
}
int silnik::Zakonczer_rozgrywki::sprawdz_remis(silnik::Inicjalizator_pol& engine,silnik::Pozycjer& pozycja,int& poprawnosc_ruchu,int& start) {
    static int x = -1;
    static int y = -1;
    static int licznik_od_ostatniego_zbicia = 0;
    static int liczba_pionkow = 0;
    if(start == 0) {
        x = -1;
        y = -1;
        licznik_od_ostatniego_zbicia = 0;
        liczba_pionkow = 0;
        start++;
    }
    if(x != pozycja.getter_x2() && y != pozycja.getter_y2() && poprawnosc_ruchu != 0) {
        x = pozycja.getter_x2();
        y = pozycja.getter_y2();
        int zlicz = 0;
        for(int i=0;i<8;i++) {
            for(int j =0;j<8;j++) {
                if(engine.getter_plansza()[i][j] != engine.getter_pole()) zlicz++;
            }
        }
        if(liczba_pionkow != zlicz) {
            liczba_pionkow = zlicz;
            licznik_od_ostatniego_zbicia = 0;
        }
        else {
            licznik_od_ostatniego_zbicia++;
        }
    }

    if(licznik_od_ostatniego_zbicia == 15) return 0;
    else return 1;
}

//-------------------------------------------------------------------------------------------------------------------------------------------

/// ---> Wykonywacz_ruchu:
void Wykonywacz_ruchu::wykonaj_ruch_1(silnik::Ruszer& ruszacz,sf::RenderWindow& window,Ruch& aktualny_ruch,silnik::Inicjalizator_pol& engine,silnik::Pozycjer& pozycja,int& licznik,silnik::Obligator_bic& bicia_obowiazkowe,int& poprawnosc_ruchu,int& poprawnosc_ruchu_2) {
    if(licznik == 0) { // Gracz_1 [ pobieranie pozycji poczatkowej figury ]
        int b = ruszacz.pobierz_pozycje_bierki(window,aktualny_ruch,engine,pozycja,licznik);
        if (b == 1) licznik++; // Jezeli udalo sie pobrac ruch
    }

    else if (licznik == 1) {  // Gracz_1 [ pobieranie pozycji koncowej figury ]

        int x = pozycja.getter_x2();
        int y = pozycja.getter_y2();

        int b = ruszacz.pobierz_pozycje_bierki(window,aktualny_ruch,engine,pozycja,licznik);


        if( b == 1 && (x == pozycja.getter_x1() && y == pozycja.getter_y1()) && poprawnosc_ruchu_2 == 2) { // Jezeli ruch jest poprawny i udalo sie pobrac pozycje
            if (engine.getter_plansza()[pozycja.getter_y1()][pozycja.getter_x1()] == engine.getter_gracz()) { // jezeli gracz
                int a = silnik::Sprawdzacz_ruchu_pionka::czy_dozwolone_pionek(pozycja.getter_y1(),pozycja.getter_x1(),pozycja.getter_y2(),pozycja.getter_x2(),engine);
                if(a == 1 || a == 0) {
                    b = 0;
                    licznik = 0;
                }
            }
            else if (engine.getter_plansza()[pozycja.getter_y1()][pozycja.getter_x1()] == engine.getter_gracz_king()) {
                int a = silnik::Sprawdzacz_ruchu_krolowej::czy_dozwolone_krolowa(pozycja.getter_y1(),pozycja.getter_x1(),pozycja.getter_y2(),pozycja.getter_x2(),engine);
                if(a == 1 || a == 0)  {
                    b = 0;
                    licznik = 0;
                }
            }
        }

        if(b == 1 && ((x != pozycja.getter_x1() || y != pozycja.getter_y1()) && poprawnosc_ruchu_2 == 2)) { // Jezeli ruch jest niepoprawny
            b = 0;
            licznik = 0;
        }

        if(b == 0 && poprawnosc_ruchu_2 == 2) { // Jezeli ruch jest niepoprawny
            pozycja.setter_x2(x);
            pozycja.setter_y2(y);
            return;
        }

        if (b == 1) {         // Jezeli udalo sie pobrac ruch
            licznik++;        // Oddaj ruch drugiemu graczowi
            bicia_obowiazkowe.sprawdz_bicia(engine,poprawnosc_ruchu_2,pozycja); // sprawdz czy masz jakies bicia (bo one sa obowiązkowe)
            if(bicia_obowiazkowe.getter_krolowa_list().empty() && bicia_obowiazkowe.getter_pionek_list().empty()) { // Jezeli nie masz bic
                int a = ruszacz.wykonaj_ruch_bierka(engine,pozycja);  /// sprawdzenie ruchu wielokrotnego i wykonanie ruchu
                poprawnosc_ruchu = a; // zwroc do programu wartosc okreslajaca to czy ruch byl poprawny
                poprawnosc_ruchu_2 = a;
                if(a != 0) silnik::Druker_planszy::drukuj_plansze(engine); // Plansza na ekranie konsoli (nie ta w oknie) --> jezeli poprawny ruch
                if (a == 2 || a == 0) licznik = 0; // ruch wielokrotny lub błędny --> jeszcze raz ten sam gracz
            }
            else if(!bicia_obowiazkowe.getter_krolowa_list().empty()) { // Bicia krolowa maja wyzszy priorytet wiec jesli takowe masz
                bicia_obowiazkowe.wymus_bicie_krolowa_1(ruszacz,licznik,engine,pozycja,poprawnosc_ruchu,poprawnosc_ruchu_2); // wymuszasz bicie krolowa
            }
            else if(!bicia_obowiazkowe.getter_pionek_list().empty()) { // Jesli masz bicie pionkiem
                bicia_obowiazkowe.wymus_bicie_pionek(ruszacz,licznik,engine,pozycja,poprawnosc_ruchu,poprawnosc_ruchu_2); // wymuszasz bicie pionkiem
            }
        }
    }

}
void Wykonywacz_ruchu::wykonaj_ruch_2(silnik::Ruszer& ruszacz,sf::RenderWindow& window,Ruch& aktualny_ruch,silnik::Inicjalizator_pol& engine,silnik::Pozycjer& pozycja,int& licznik,silnik::Obligator_bic& bicia_obowiazkowe,int& poprawnosc_ruchu,int& poprawnosc_ruchu_2) {
    if(licznik == 2) { // Gracz_2 [ pobieranie pozycji poczatkowej figury ]
        int b = ruszacz.pobierz_pozycje_bierki(window,aktualny_ruch,engine,pozycja,licznik);
        if (b == 1) licznik++; // Jezeli udalo sie pobrac ruch
    }
    else if (licznik == 3) {  // Gracz_2 [ pobieranie pozycji koncowej figury ]

        int x = pozycja.getter_x2();
        int y = pozycja.getter_y2();


        int b = ruszacz.pobierz_pozycje_bierki(window,aktualny_ruch,engine,pozycja,licznik);

        if( b == 1 && (x == pozycja.getter_x1() && y == pozycja.getter_y1()) && poprawnosc_ruchu_2 == 2) { // Jezeli ruch jest poprawny i udalo sie pobrac pozycje
            if (engine.getter_plansza()[pozycja.getter_y1()][pozycja.getter_x1()] == engine.getter_gracz()) { // jezeli gracz
                int a = silnik::Sprawdzacz_ruchu_pionka::czy_dozwolone_pionek(pozycja.getter_y1(),pozycja.getter_x1(),pozycja.getter_y2(),pozycja.getter_x2(),engine);
                if(a == 1 || a == 0) {
                    b = 0;
                    licznik = 2;
                }
            }
            else if (engine.getter_plansza()[pozycja.getter_y1()][pozycja.getter_x1()] == engine.getter_gracz_king()) {
                int a = silnik::Sprawdzacz_ruchu_krolowej::czy_dozwolone_krolowa(pozycja.getter_y1(),pozycja.getter_x1(),pozycja.getter_y2(),pozycja.getter_x2(),engine);
                if(a == 1 || a == 0)  {
                    b = 0;
                    licznik = 2;
                }
            }
        }

        if(b == 1 && ((x != pozycja.getter_x1() || y != pozycja.getter_y1()) && poprawnosc_ruchu_2 == 2)) { // Jezeli ruch jest niepoprawny
            b = 0;
            licznik = 2;
        }

        if(b == 0 && poprawnosc_ruchu_2 == 2) { // Jezeli ruch jest niepoprawny
            pozycja.setter_x2(x);
            pozycja.setter_y2(y);
            return;
        }

        if (b == 1) {         // Jezeli udalo sie pobrac ruch
            licznik = 0;      // Oddaj ruch drugiemu graczowi
            bicia_obowiazkowe.sprawdz_bicia(engine,poprawnosc_ruchu_2,pozycja); // sprawdz czy masz jakies bicia (bo one sa obowiązkowe)
            if(bicia_obowiazkowe.getter_krolowa_list().empty() && bicia_obowiazkowe.getter_pionek_list().empty()) { // Jezeli nie masz bic
                int a = ruszacz.wykonaj_ruch_bierka(engine,pozycja);  /// sprawdzenie ruchu wielokrotnego i wykonanie ruchu
                poprawnosc_ruchu = a; // zwroc do programu wartosc okreslajaca to czy ruch byl poprawny
                poprawnosc_ruchu_2 = a;
                if(a != 0) silnik::Druker_planszy::drukuj_plansze(engine); // Plansza na ekranie konsoli (nie ta w oknie) --> jezeli poprawny ruch
                if (a == 2 || a == 0) licznik = 2; // ruch wielokrotny lub błędny --> jeszcze raz ten sam gracz
            }
            else if(!bicia_obowiazkowe.getter_krolowa_list().empty()) { // Bicia krolowa maja wyzszy priorytet wiec jesli takowe masz
                bicia_obowiazkowe.wymus_bicie_krolowa_2(ruszacz,licznik,engine,pozycja,poprawnosc_ruchu,poprawnosc_ruchu_2); // wymuszasz bicie krolowa
            }
            else if(!bicia_obowiazkowe.getter_pionek_list().empty()) { // Jesli masz bicie pionkiem
                bicia_obowiazkowe.wymus_bicie_pionek(ruszacz,licznik,engine,pozycja,poprawnosc_ruchu,poprawnosc_ruchu_2);  // wymuszasz bicie pionkiem
            }
        }
    }
}
Wykonywacz_ruchu::Wykonywacz_ruchu() {;}

/// ---> Ruch:
Ruch::Ruch() {
    // Poczatkowa inicjalizacja ruchu (wartosci dobrane tak by nie podswietlilo pola odrazu po rozpoczęciu partii)
    this->x = 1;
    this->y = 1;
}
Ruch::Ruch(int x, int y)  {
    // Pobieranie pola na ktore wykonany zostal ruch
    this->x = x;
    this->y = y;
}
int Ruch::getter_x() {return this->x;}
int Ruch::getter_y() {return this->y;}
void Ruch::setter_x(int x) {this->x = x;}
void Ruch::setter_y(int y) {this->y = y;}




