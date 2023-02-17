#include <fstream>
#include "LibrariesAndVariables.hpp"
#include "Board.hpp"

// Każdą metodę umieszczamy w odpowiedniej, odrębnej sekcji!
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//odczyt kazdego atrybutu
int OdczytModel() {

    // Otwieramy plik

    std::ifstream in(MY_DEFINE"../txt/Atrybuty.txt",ios::out);
    while (!in.eof()) {

        string line;
        getline(in, line);
        // Rozdzielamy dane użytkownika na osobne pola (username i password)
        // korzystając z separatora ","

        size_t model_end = line.find(",");
        string modelGry = line.substr(0, model_end);
        int c = stoi(modelGry);
        return c;

    }
}
int OdczytKolor() {

    // Otwieramy plik
    ifstream in(MY_DEFINE"../txt/Atrybuty.txt");
    while (!in.eof()) {

        string line;
        getline(in, line);
        // Rozdzielamy dane użytkownika na osobne pola (username i password)
        // korzystając z separatora ","

        size_t model_end = line.find(",");
        size_t kolor_start = model_end + 1;
        size_t kolor_end = line.find(":", kolor_start);

        string kolorPion = line.substr(kolor_start, (kolor_end - kolor_start));

        int b = stoi(kolorPion);
        return b;
    }
}
int OdczytMotyw() {

    // Otwieramy plik
    ifstream in(MY_DEFINE"../txt/Atrybuty.txt");
    while (!in.eof()) {

        string line;
        getline(in, line);
        // Rozdzielamy dane użytkownika na osobne pola (username i password)
        // korzystając z separatora ","

        size_t model_end = line.find(",");
        size_t kolor_start = model_end + 1;
        size_t kolor_end = line.find(":", kolor_start);
        size_t motyw_start = kolor_end + 1;
        size_t motyw_end = line.find(";", motyw_start);

        string kolorPlansz = line.substr(motyw_start, (motyw_end - motyw_start));
        int a = stoi(kolorPlansz);
        return a;
    }
}

/// ---> Atrybuty:
Atrybuty::Atrybuty(bool model, Motyw kol, Motyw mot) {
    /// Własciwosci generowanej rozgrywki
    this->model_rozgrywki = model;
    this->motyw = mot;
    this->kolor_pionkow = kol;

    // Otwieramy plik
    ofstream out(MY_DEFINE"../txt/Atrybuty.txt", ios::trunc);
    // Zapisujemy dane użytkownika do pliku
    out << model << "," << kol << ":" << mot << ";" << endl;
    out.close();
}
short Atrybuty::getter_k_p() {return this->kolor_pionkow;}
short Atrybuty::getter_m() {return this->motyw;}
bool Atrybuty::getter_m_r() {return this->model_rozgrywki;}

Builder& Builder::setModel(bool mod){
    _model_rozgrywki = mod;
    return *this;
}
Builder& Builder::setMotyw(Motyw _mot){
    _motyw = _mot;
    return *this;
}
Builder& Builder::setKolor(Motyw _kolorPion){
    _kolor_pionkow = _kolorPion;
    return *this;
}
Atrybuty Builder::build(){
    Atrybuty* atr = new Atrybuty(_model_rozgrywki,_kolor_pionkow,_motyw);
    return *atr;
}


/// ---> Inicjator_fontow
Inicjator_fontow::Inicjator_fontow() {
    /// Ustawianie fontu
    if (!this->font.loadFromFile(MY_DEFINE"../font/manrope.ttf")) {
        cout << "Blad wczytywania czcionki!" << endl;
        exit(0);
    }
}
sf::Font& Inicjator_fontow::getter() {return this->font;}

/// ---> Inicjator_tekstu
Inicjator_tekstu::Inicjator_tekstu(sf::Font& font) {
    /// Inicjalizacja tekstu do wypisywania informacja o błędzie
    this->text.setFont(font);
    this->text.setString("Blad wczytywania tekstury");
    this->text.setCharacterSize(300);
    if(resolution_mode == 2) this->text.setScale(0.5,0.5);
    this->text.setFillColor(sf::Color::White);
    this->text.setStyle(sf::Text::Bold);
}
sf::Text& Inicjator_tekstu::getter() {return this->text;}

/// ---> Inicjator_tekstur
Inicjalizator_tekstur::Inicjalizator_tekstur(Atrybuty& atrybuty,sf::Text& text,sf::RenderWindow& window) {
    /// Ustawianie tekstur Pionków
    if (atrybuty.getter_k_p() == 0) {
        this->pionek_2.loadFromFile(MY_DEFINE"../data/pawn_1/black_pawn.png");
        this->pionek_2_queen.loadFromFile(MY_DEFINE"../data/pawn_1/black_queen.png");
        this->pionek_1.loadFromFile(MY_DEFINE"../data/pawn_1/white_pawn.png");
        this->pionek_1_queen.loadFromFile(MY_DEFINE"../data/pawn_1/white_queen.png");
    } else if (atrybuty.getter_k_p()== 1) {
        this->pionek_1.loadFromFile(MY_DEFINE"../data/pawn_2/beige_pawn.png");
        this->pionek_1_queen.loadFromFile(MY_DEFINE"../data/pawn_2/beige_queen.png");
        this->pionek_2.loadFromFile(MY_DEFINE"../data/pawn_2/brown_pawn.png");
        this->pionek_2_queen.loadFromFile(MY_DEFINE"../data/pawn_2/brown_queen.png");
    } else {
        window.draw(text);  // Informacja o wystąpieniu błędu
    }

    this->puste_pole.loadFromFile(MY_DEFINE"../data/puste_pole.png");
    this->podswietl.loadFromFile(MY_DEFINE"../data/podswietlenie.png");
}
sf::Texture& Inicjalizator_tekstur::getter_p() {return this->podswietl;}
sf::Texture& Inicjalizator_tekstur::getter_p_1() {return this->pionek_1;}
sf::Texture& Inicjalizator_tekstur::getter_p_2() {return this->pionek_2;}
sf::Texture& Inicjalizator_tekstur::getter_q_1() {return this->pionek_1_queen;}
sf::Texture& Inicjalizator_tekstur::getter_q_2() {return this->pionek_2_queen;}
sf::Texture& Inicjalizator_tekstur::getter_p_p() {return this->puste_pole;}

/// ---> Inicjator_planszy
Inicjator_planszy::Inicjator_planszy(Atrybuty& atrybuty, sf::Text& text,sf::RenderWindow& window) {
    /// Ładowanie tekstury planszy
    switch (atrybuty.getter_m()) {
        case 0: {
            this->plansza_tex.loadFromFile(MY_DEFINE"../data/plansza_1.png");
            break;
        }
        case 1: {
            this->plansza_tex.loadFromFile(MY_DEFINE"../data/plansza_2.png");
            break;
        }
        default: {
            window.draw(text);  // Informacja o wystąpieniu błędu
            break;
        }
    }
    this->plansza_obj.setTexture(this->plansza_tex);
}
sf::Sprite& Inicjator_planszy::getter() {return this->plansza_obj;}

///---------------------------------------------------------------------------------
/// ---> Gra_na_czas :
Gra_na_czas::Gra_na_czas() {;}
int Gra_na_czas::odswierz_czas(sf::RenderWindow &window,Inicjator_fontow& font,int& twoj_czas,int& czas_przeciwnika, int& mod,int& licznik,int& exit) {

    int const czas_na_gre = 60 * 5; /// 5 min
    this->timer = clock.getElapsedTime();

    if(mod == 0) { // Gracz 1
        if((licznik == 0 || licznik == 1) && exit == 1) { // Tura gracza 1 /// exit -> -777/0 to koniec gry
            twoj_czas = this->timer.asSeconds() - czas_przeciwnika;
            this->czas_gry_s = czas_na_gre - (twoj_czas); // [s]
        }
        else this->czas_gry_s = czas_na_gre - twoj_czas;
    }
    else if (mod == 1) { // Gracz 2
        if((licznik == 2 || licznik == 3) && exit == 1) { // Tura gracza 2 /// exit -> -777/0 to koniec gry
            czas_przeciwnika = this->timer.asSeconds() - twoj_czas;
            this->czas_gry_s = czas_na_gre - (czas_przeciwnika); // [s]
        }
        else this->czas_gry_s = czas_na_gre - czas_przeciwnika;
    }

    int a = this->czas_gry_s / 3600;
    int b = (czas_gry_s - 3600 * a) / 60;
    int c = (czas_gry_s - 3600 * a - 60 * b);

    this->czas_gry_h = a;
    this->czas_gry_m = b;
    this->czas_gry_s = c;

    if(a <= 0 && b <= 0 && c <= 0) czas_gry_s = 0;



    sf::Text godziny;
    sf::Text minuty;
    sf::Text sekundy;
    godziny.setFont(font.getter());
    minuty.setFont(font.getter());
    sekundy.setFont(font.getter());
    if(this->czas_gry_h < 10)
        godziny.setString( "0" + to_string(czas_gry_h) + ":");
    else
        godziny.setString(to_string(czas_gry_h) + ":");
    if(this->czas_gry_m < 10)
        minuty.setString( "0" + to_string(czas_gry_m) + ":");
    else
        minuty.setString(to_string(czas_gry_m) + ":");
    if(this->czas_gry_s < 10)
        sekundy.setString( "0" + to_string(czas_gry_s));
    else
        sekundy.setString(to_string(czas_gry_s));

    godziny.setCharacterSize(45 / resolution_mode);
    minuty.setCharacterSize(45 / resolution_mode);
    sekundy.setCharacterSize(45 / resolution_mode);
    godziny.setFillColor(sf::Color::White);
    minuty.setFillColor(sf::Color::White);
    sekundy.setFillColor(sf::Color::White);
    godziny.setStyle(sf::Text::Bold);
    minuty.setStyle(sf::Text::Bold);
    sekundy.setStyle(sf::Text::Bold);

    if(mod == 0) {
        godziny.setPosition(1447/ resolution_mode,560 / resolution_mode);
        minuty.setPosition(1522 / resolution_mode,560 / resolution_mode);
        sekundy.setPosition(1597 / resolution_mode,560 / resolution_mode);
    }
    if(mod == 1) {
        godziny.setPosition(1753 / resolution_mode,560 / resolution_mode);
        minuty.setPosition(1828 / resolution_mode,560 / resolution_mode);
        sekundy.setPosition(1903 / resolution_mode,560 / resolution_mode);
    }

    window.draw(godziny);
    window.draw(minuty);
    window.draw(sekundy);

    if(a <= 0 && b <= 0 && c <= 0) return 0; /// Gracz  przegral przez brak czasu

    return 1; /// Gracz ma jeszcze czas

}

/// ---> Reklamer:
void Reklamer::wyswietl_reklame(sf::RenderWindow& window) {
    /// ładuje reklamy do bufora i je wyswietla
    static int licznik; // jezeli licznik osiagnie okreslona wartosc --> zmiana reklamy lub wyzerowanie licznika

    this->reklama_1.loadFromFile(MY_DEFINE"../data/ads/reklama_1.png");
    this->reklama_2.loadFromFile(MY_DEFINE"../data/ads/reklama_2.png");
    this->reklama_3.loadFromFile(MY_DEFINE"../data/ads/reklama_3.png");
    sf::Sprite sp1, sp2, sp3;
    sp1.setTexture(reklama_1);
    sp2.setTexture(reklama_2);
    sp3.setTexture(reklama_3);

    sp1.setPosition(0,1400 / resolution_mode);
    sp2.setPosition(0,1400 / resolution_mode);
    sp3.setPosition(0,1400 / resolution_mode);
    if(resolution_mode == 2) {
        sp1.setScale(0.5,0.5);
        sp2.setScale(0.5,0.5);
        sp3.setScale(0.5,0.5);
    }

    if(licznik>=0 && licznik <= 200) {window.draw(sp1);licznik++;}    /// jezeli petla gry wywolala sie [0,300] razy
    else if(licznik>200 && licznik <=400) {window.draw(sp3);licznik++;} /// jezeli petla gry wywolala sie [300,600] razy
    else if(licznik>400 && licznik <=600) {window.draw(sp2);licznik++;} /// jezeli petla gry wywolala sie [600,900] razy
    else {licznik = 0;} /// jezeli petla gry wywolala sie > 900 razy to zacznij odliczac od nowa

}
Reklamer::Reklamer() {;}

/// ---> Timer:
void Timer::inicjuj_timer(sf::RenderWindow& window) {
    /// Inicjuje teksture timera // ustawia jego pozycje // rysuje go na planszy

    this->czas_gry_s = 0;
    this->czas_gry_m = 0;
    this->czas_gry_h = 0;

    sf::Sprite zeg;
    this->zegarek.loadFromFile(MY_DEFINE"../data/accesories/zegar.png");
    zeg.setTexture(zegarek);
    zeg.setPosition(1430 / resolution_mode,43 / resolution_mode);
    if(resolution_mode == 2) zeg.setScale(0.5,0.5);
    window.draw(zeg);

}
void Timer::odswierz_zegar(sf::RenderWindow &window,Inicjator_fontow& font) {
    /// Obsługa zegara --> zmiana liczb i wyswietlanie ich na ekranie
    sf::Sprite zegar_;
    zegar_.setTexture(this->zegarek);
    zegar_.setPosition(1430 / resolution_mode,43 / resolution_mode);
    if (resolution_mode == 2) zegar_.setScale(0.5,0.5);
    window.draw(zegar_);
    ///-------------------------

    this->timer = clock.getElapsedTime();
    this->czas_gry_s = this->timer.asSeconds(); // [s]

    if(this->czas_gry_s >= 60) {this->czas_gry_s = 0;this->timer = clock.restart(); this->czas_gry_m++;}
    if(this->czas_gry_m >= 60) {this->czas_gry_m = 0; this->czas_gry_h++;}
    if(this->czas_gry_h >= 24) {this->czas_gry_h = 0;}

    sf::Text godziny;
    sf::Text minuty;
    sf::Text sekundy;
    godziny.setFont(font.getter());
    minuty.setFont(font.getter());
    sekundy.setFont(font.getter());
    if(this->czas_gry_h < 10)
        godziny.setString( "0" + to_string(czas_gry_h) + ":");
    else
        godziny.setString(to_string(czas_gry_h) + ":");
    if(this->czas_gry_m < 10)
        minuty.setString( "0" + to_string(czas_gry_m) + ":");
    else
        minuty.setString(to_string(czas_gry_m) + ":");
    if(this->czas_gry_s < 10)
        sekundy.setString( "0" + to_string(czas_gry_s));
    else
        sekundy.setString(to_string(czas_gry_s));

    godziny.setCharacterSize(90 / resolution_mode);
    minuty.setCharacterSize(90 / resolution_mode);
    sekundy.setCharacterSize(90 / resolution_mode);
    godziny.setFillColor(sf::Color::White);
    minuty.setFillColor(sf::Color::White);
    sekundy.setFillColor(sf::Color::White);
    godziny.setStyle(sf::Text::Bold);
    minuty.setStyle(sf::Text::Bold);
    sekundy.setStyle(sf::Text::Bold);

    godziny.setPosition(1600 / resolution_mode,78 / resolution_mode);
    minuty.setPosition(1730 / resolution_mode,78 / resolution_mode);
    sekundy.setPosition(1860 / resolution_mode,78 / resolution_mode);
    window.draw(godziny);
    window.draw(minuty);
    window.draw(sekundy);


}
Timer::Timer(){;}



