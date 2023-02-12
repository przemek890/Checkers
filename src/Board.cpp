#include <fstream>
#include "LibrariesAndVariables.hpp"

// Każdą metodę umieszczamy w odpowiedniej, odrębnej sekcji!
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//odczyt kazdego atrybutu
int OdczytModel() {

    // Otwieramy plik

    std::ifstream in("../txt/Atrybuty.txt",ios::out);
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
    ifstream in("../txt/Atrybuty.txt");
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
    ifstream in("../txt/Atrybuty.txt");
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
    ofstream out("../txt/Atrybuty.txt", ios::trunc);
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
    Atrybuty* atr = new Atrybuty(_model_rozgrywki,_motyw,_kolor_pionkow);
    return *atr;
}


/// ---> Inicjator_fontow
Inicjator_fontow::Inicjator_fontow() {
    /// Ustawianie fontu
    if (!this->font.loadFromFile("../fonts/manrope.ttf")) {
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
        this->pionek_2.loadFromFile("../data/pawn_1/black_pawn.png");
        this->pionek_2_queen.loadFromFile("../data/pawn_1/black_queen.png");
        this->pionek_1.loadFromFile("../data/pawn_1/white_pawn.png");
        this->pionek_1_queen.loadFromFile("../data/pawn_1/white_queen.png");
    } else if (atrybuty.getter_k_p()== 1) {
        this->pionek_1.loadFromFile("../data/pawn_2/beige_pawn.png");
        this->pionek_1_queen.loadFromFile("../data/pawn_2/beige_queen.png");
        this->pionek_2.loadFromFile("../data/pawn_2/brown_pawn.png");
        this->pionek_2_queen.loadFromFile("../data/pawn_2/brown_queen.png");
    } else {
        window.draw(text);  // Informacja o wystąpieniu błędu
    }

    this->puste_pole.loadFromFile("../data/puste_pole.png");
    this->podswietl.loadFromFile("../data/podswietlenie.png");
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
            this->plansza_tex.loadFromFile("../data/plansza_1.png");
            break;
        }
        case 1: {
            this->plansza_tex.loadFromFile("../data/plansza_2.png");
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
/// ---> Wyswietlacz_pol
Wyswietlacz_pol::Wyswietlacz_pol() {;}
void Wyswietlacz_pol::wyswietl_pola(silnik::Inicjalizator_pol& engine, Inicjalizator_tekstur &textury, sf::RenderWindow &window,Ruch &aktualny_ruch, int& licznik) {
    /// Drukowanie na ekranie Pionkow / Krolowych / podswietlenia pola /
    for (int i = 0; i < 8 ; i++) {
        for(int j=0;j<8;j++) {      // Wyswietlenie tekstur w oparciu o tablice w hashkodzie
            if(engine.getter_plansza()[i][j] == 120 ) {
                sf::Sprite sprite_pom;
                sprite_pom.setTexture(textury.getter_p_1());
                sprite_pom.setPosition(175 / resolution_mode * j,175 / resolution_mode * (i));
                if(resolution_mode == 2) sprite_pom.setScale(0.5,0.5);
                window.draw(sprite_pom);
            }
            if(engine.getter_plansza()[i][j] == 88 ) {
                sf::Sprite sprite_pom;
                sprite_pom.setTexture(textury.getter_q_1());
                sprite_pom.setPosition(175 / resolution_mode * j,175 / resolution_mode * (i));
                if(resolution_mode == 2) sprite_pom.setScale(0.5,0.5);
                window.draw(sprite_pom);
            }
            if(engine.getter_plansza()[i][j] == 111 ) {
                sf::Sprite sprite_pom;
                sprite_pom.setTexture(textury.getter_p_2());
                sprite_pom.setPosition(175 / resolution_mode * j,175 / resolution_mode * (i ));
                if(resolution_mode == 2) sprite_pom.setScale(0.5,0.5);
                window.draw(sprite_pom);
            }
            if(engine.getter_plansza()[i][j] == 79 ) {
                sf::Sprite sprite_pom;
                sprite_pom.setTexture(textury.getter_q_2());
                sprite_pom.setPosition(175 / resolution_mode * j,175 / resolution_mode * (i));
                if(resolution_mode == 2) sprite_pom.setScale(0.5,0.5);
                window.draw(sprite_pom);
            }
            if(engine.getter_plansza()[i][j] == 0 ) {
                sf::Sprite sprite_pom;
                sprite_pom.setTexture(textury.getter_p_p());
                sprite_pom.setPosition(175 / resolution_mode * j,175 / resolution_mode * (i));
                if(resolution_mode == 2) sprite_pom.setScale(0.5,0.5);
                window.draw(sprite_pom);
            }
        }
    }
    //------------------------------------------------------
    sf::Sprite sprite_pom; // static ?
    sprite_pom.setTexture(textury.getter_p());

    sprite_pom.setPosition(175 / resolution_mode * aktualny_ruch.getter_x() ,175 / resolution_mode * (aktualny_ruch.getter_y()));
    if(175 / resolution_mode *  aktualny_ruch.getter_x() <= (1225 / resolution_mode) && 175 / resolution_mode * aktualny_ruch.getter_x() >= 0 &&  175 / resolution_mode * aktualny_ruch.getter_y() <= (1225 / resolution_mode) && 175 / resolution_mode * aktualny_ruch.getter_y() >= 0) {
        if (licznik == 0 || licznik == 2) sprite_pom.setTexture(textury.getter_p_p()); // zgaś pole
        else if (licznik == 1 || licznik == 3) sprite_pom.setTexture(textury.getter_p()); // zgaś podswietl pole

        if(resolution_mode == 2) sprite_pom.setScale(0.5,0.5);
        window.draw(sprite_pom);
    }

    //------------------------------------------------------
}
void Wyswietlacz_pol::wyswietl_tlo(sf::RenderWindow &window) {
    /// Drukowanie na ekranie tła
    //------------------------------------------------------
    sf::Texture tlo;
    tlo.loadFromFile("../data/tlo.png");
    sf::Sprite tloo;
    tloo.setTexture(tlo);

    if(resolution_mode == 2) tloo.setScale(0.5,0.5);
    window.draw(tloo);
    //------------------------------------------------------
}

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

/// ---> Reklamer:
void Reklamer::wyswietl_reklame(sf::RenderWindow& window) {
    /// ładuje reklamy do bufora i je wyswietla
    static int licznik; // jezeli licznik osiagnie okreslona wartosc --> zmiana reklamy lub wyzerowanie licznika

    this->reklama_1.loadFromFile("../data/ads/reklama_1.png");
    this->reklama_2.loadFromFile("../data/ads/reklama_2.png");
    this->reklama_3.loadFromFile("../data/ads/reklama_3.png");
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
    this->zegarek.loadFromFile("../data/accesories/zegar.png");
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


/// ---> Asseter:
void Asseter::drukuj_przewage(sf::RenderWindow& window,silnik::Inicjalizator_pol& engine,Inicjator_fontow& font) {
    /// Drukowanie ilosci pionkow, jaka posiada okreslony gracz (po jej sprawdzeniu)
    int licznik_gracz_1 = 0;
    int licznik_gracz_2 = 0;
    for(int i=0;i<8;i++) {
        for(int j=0;j<8;j++) {
            if(engine.getter_plansza()[i][j] == engine.getter_gracz() || engine.getter_plansza()[i][j] == engine.getter_gracz_king()  ) licznik_gracz_1++;
            else if(engine.getter_plansza()[i][j] == engine.getter_cpu() || engine.getter_plansza()[i][j] == engine.getter_cpu_king() ) licznik_gracz_2++;
        }
    }

    sf::Sprite asset_1;
    if(resolution_mode == 2) asset_1.setScale(0.5,0.5);

    sf::Texture tx;
    tx.loadFromFile("../data/assets/asset_1.png");
    asset_1.setTexture(tx);
    asset_1.setPosition(1435 / resolution_mode , 250 / resolution_mode);
    window.draw(asset_1);

    sf::Text gracz_1;
    sf::Text gracz_2;
    gracz_1.setFont(font.getter());
    gracz_2.setFont(font.getter());
    gracz_1.setString(to_string(licznik_gracz_1));
    gracz_2.setString(to_string(licznik_gracz_2));
    gracz_1.setCharacterSize(50 / resolution_mode);
    gracz_2.setCharacterSize(50 / resolution_mode);
    gracz_1.setFillColor(sf::Color::White);
    gracz_2.setFillColor(sf::Color::White);
    gracz_1.setStyle(sf::Text::Bold);
    gracz_2.setStyle(sf::Text::Bold);

    if(licznik_gracz_1 >= 10)
        gracz_1.setPosition(1522 / resolution_mode , 450 / resolution_mode);
    else
        gracz_1.setPosition(1537 / resolution_mode , 450 / resolution_mode);

    if(licznik_gracz_2 >= 10)
        gracz_2.setPosition(1828 / resolution_mode , 450 / resolution_mode);
    else
        gracz_2.setPosition(1837 / resolution_mode , 450 / resolution_mode);

    window.draw(gracz_1);
    window.draw(gracz_2);

}
void Asseter::kogo_tura(sf::RenderWindow& window,int& licznik) {
    /// Drukowanie informacji (w oknie gry) kogo obecnie jest tura
    sf::Sprite tura;
    sf::Texture textt;
    if (licznik == 0 || licznik == 1) textt.loadFromFile("../data/assets/tura_1.png");
    else if (licznik == 2 || licznik == 3) textt.loadFromFile("../data/assets/tura_2.png");

    if(resolution_mode == 2) tura.setScale(0.5,0.5);

    tura.setTexture(textt);
    tura.setPosition(1560 / resolution_mode,675 / resolution_mode);
    window.draw(tura);

    //------------------------------------------------------
}
void Asseter::chat(sf::RenderWindow& window,silnik::Pozycjer& pozycja,Inicjator_fontow& font,int& poprawnosc_ruchu,int& pozycja_licz) {
    /// Obsluga chatu --> 10 ostatnio wykonanych ruchow
    sf::Text chat;
    sf::Font fira;
    fira.loadFromFile("fonts/fira.ttf");
    chat.setFont(fira);
    chat.setString("CHAT");
    chat.setCharacterSize(60 / resolution_mode);
    chat.setFillColor(sf::Color::White);
    chat.setStyle(sf::Text::Bold);
    chat.setPosition(1620 / resolution_mode,830 / resolution_mode);
    window.draw(chat);
    //--------------------------------------------------------------------

    silnik::Pozycjer pozycja_(pozycja.getter_y1(),pozycja.getter_x1(),pozycja.getter_y2(),pozycja.getter_x2()); // otworz pozycje

    string tofile; //obsluga archiwum
    // sprawdz czy pozycja odpowiada poprawnemu ruchowi:
    if((poprawnosc_ruchu == 1 || poprawnosc_ruchu == 2) && lista.size() < 11){  // TAK i nie przepelnienie listy (wiecej niz 10 elementow)
        lista.push_back(pozycja_);
        string tekst_1 = "";
        string tekst_2 = "";
        char znak_1 = static_cast<char>(pozycja_.getter_x1() + 65);
        char znak_2 = static_cast<char>(pozycja_.getter_x2() + 65);
        tekst_1 += znak_1;
        tekst_2 += znak_2;
        if(lista.size() > 1) {
            tofile= tekst_1  + to_string(7 - pozycja_.getter_y1() + 1) + "  -->  " + tekst_2 + to_string(7 - pozycja_.getter_y2() + 1);
            Oneline(tofile);
        }
        if(pozycja_licz == 0) {
            lista_pom.push_back(1);
            if(poprawnosc_ruchu != 2) pozycja_licz++;
        }
        else if(pozycja_licz == 1) {
            lista_pom.push_back(2);
            if(poprawnosc_ruchu != 2) pozycja_licz--;
        }
        poprawnosc_ruchu = -1; // zmien by nie wczytwalo tego samego ruchu jeszcze raz do listy
    }
    else if (poprawnosc_ruchu == 1 || poprawnosc_ruchu == 2) { // TAK i lista jest przepelniona
        lista.pop_front();
        lista_pom.pop_front();
        lista.push_back(pozycja_);

        string tekst_1 = "";
        string tekst_2 = "";
        char znak_1 = static_cast<char>(pozycja_.getter_x1() + 65);
        char znak_2 = static_cast<char>(pozycja_.getter_x2() + 65);
        tekst_1 += znak_1;
        tekst_2 += znak_2;

        tofile = tekst_1 + to_string(7 -pozycja_.getter_y1() + 1)+ "  -->  " + tekst_2 +to_string(7 -pozycja_.getter_y2() + 1);
        Oneline(tofile);

        if(pozycja_licz == 0) {
            lista_pom.push_back(1);
            if(poprawnosc_ruchu != 2) pozycja_licz++;
        }
        else if(pozycja_licz == 1) {
            lista_pom.push_back(2);
            if(poprawnosc_ruchu != 2) pozycja_licz--;
        }
        poprawnosc_ruchu = -1; // zmien by nie wczytwalo tego samego ruchu jeszcze raz do listy
    }

    int licz = 0;
    int licznik_petli = 0; // licznik pomocniczy do drukowania ostatnich 10 pozycji

    std::list<int>::iterator iter_pom = ++lista_pom.begin();
    for(std::list<silnik::Pozycjer>::iterator iter= ++lista.begin(); iter != lista.end(); iter++) {

        sf::Text ruch;
        ruch.setCharacterSize(45 / resolution_mode);
        ruch.setFillColor(sf::Color::White);
        ruch.setStyle(sf::Text::Bold);
        ruch.setFont(fira);
        string zmiana_pozycji;

        string tekst_1 = "";
        string tekst_2 = "";
        char znak_1 = static_cast<char>((*iter).getter_x1() + 65);
        char znak_2 = static_cast<char>((*iter).getter_x2() + 65);
        tekst_1 += znak_1;
        tekst_2 += znak_2;
        if((*iter_pom) == 1) {
            zmiana_pozycji = "Gracz-1: " + tekst_1  + to_string(7 -(*iter).getter_y1() + 1) + " --> " + tekst_2 + to_string(7 - (*iter).getter_y2() + 1);

        }
        else if((*iter_pom) == 2) {
            zmiana_pozycji = "Gracz-2: " + tekst_1  + to_string(7 -(*iter).getter_y1() + 1) + " --> " + tekst_2  + to_string(7 -(*iter).getter_y2() + 1);
        }

        iter_pom++;
        ruch.setString(zmiana_pozycji);
        ruch.setPosition(1450 / resolution_mode,(930 + 50 * licznik_petli) / resolution_mode);
        licznik_petli++;
        window.draw(ruch);
    }
}
list<silnik::Pozycjer> Asseter::getter_1() {return this->lista;}
list<int> Asseter::getter_2() {return this->lista_pom;}
int Asseter::exit(sf::RenderWindow& window) {
    sf::Sprite exit_button;
    sf::Texture textt;

    textt.loadFromFile("../data/assets/exit.png");
    exit_button.setTexture(textt);
    if(resolution_mode == 2) exit_button.setScale(0.5,0.5);
    int x = 1590 / resolution_mode;
    int y = 1470 / resolution_mode;
    exit_button.setPosition(x, y);

    window.draw(exit_button);

    int x1 = textt.getSize().x;
    int y1 = textt.getSize().y;

    int xx = (sf::Mouse::getPosition(window).x);
    int yy = (sf::Mouse::getPosition(window).y);

    if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && (x <= xx && x + x1 >= xx) && (y <= yy && y + y1 >= yy)) {
        return -777;
    }
    else return 1000;
}
