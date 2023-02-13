#include "Eng_boa.h"
#include "Register.h"
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
    fira.loadFromFile("../fonts/fira.ttf");
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
        User user;
        user.Punkty(0);
        return -777;
    }
    else return 1000;
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