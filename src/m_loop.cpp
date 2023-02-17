#include "m_loop.h"
#include "LibrariesAndVariables.hpp"
#include "txt_menu.h"
#include "tekst_menu.h"
#include "pola_menu.h"
#include "Register.h"
#include "font_menu.h"
#include "Board.hpp"



m_loop::m_loop() {}

int m_loop::Run(RenderWindow &Wind) {
    //RenderWindow menu(sf::VideoMode(2000 / resolution_mode, 1600 / resolution_mode), "Simple Checkers",5);
    Wind.setFramerateLimit(60);

    txt_menu menu1;
    Sprite& menu_s= menu1.g_tl();
    if(resolution_mode==2)menu_s.setScale(0.5,0.5);

    //x: 1070, y: 255
    //856, 204
    //roznica wysokosci Origina: 145
    pola_menu pmenu1;
    Sprite p1,p2,p3,p4;
    p1.setTexture(pmenu1.g_p1());
    p1.setScale(0.8/resolution_mode,0.8/resolution_mode);
    p1.setPosition(572./resolution_mode,200./resolution_mode);
    p2.setTexture(pmenu1.g_p1());
    p2.setScale(0.8/resolution_mode,0.8/resolution_mode);
    p2.setPosition(572./resolution_mode,490./resolution_mode);
    p3.setTexture(pmenu1.g_p1());
    p3.setScale(0.8/resolution_mode,0.8/resolution_mode);
    p3.setPosition(572./resolution_mode,780./resolution_mode);
    p4.setTexture(pmenu1.g_p1());
    p4.setScale(0.8/resolution_mode,0.8/resolution_mode);
    p4.setPosition(572./resolution_mode,1070./resolution_mode);

    //logout
    //411x150
    Sprite lg;
    lg.setTexture(pmenu1.g_lg());
    lg.setScale(0.8/resolution_mode,0.8/resolution_mode);
    lg.setPosition(1646./resolution_mode,32./resolution_mode);

    //czcionka
    font_menu ft;
    Font font1= ft.g_font();

    //teksty menu glowne
    //145
    tekst_menu tekstmenu1(font1);
    sf::Text text1 = tekstmenu1.g_text_ga();
    text1.setPosition(820 / resolution_mode,220 / resolution_mode);
    sf::Text text2 = tekstmenu1.g_text_op();
    text2.setPosition(710 / resolution_mode,510 / resolution_mode);
    sf::Text text3 = tekstmenu1.g_text_cr();
    text3.setPosition(718 / resolution_mode,800 / resolution_mode);
    sf::Text text4 = tekstmenu1.g_text_ex();
    text4.setPosition(880 / resolution_mode,1090 / resolution_mode);
    sf::Text textlg = tekstmenu1.g_text_lg();
    textlg.setPosition(1676 / resolution_mode,56 / resolution_mode);


    Event event;

    while(Wind.isOpen()){

        Wind.clear(Color::Black);
        Wind.pollEvent(event);

        //txt
        Wind.draw(menu_s);
        Wind.draw(p1);
        Wind.draw(p2);
        Wind.draw(p3);
        Wind.draw(p4);
        Wind.draw(lg);

        //napisy menu
        Wind.draw(text1);
        Wind.draw(text2);
        Wind.draw(text3);
        Wind.draw(text4);
        Wind.draw(textlg);

        if(pmenu1.what_if(lg, Wind)){ //graj
            return 6;
        }

        if(pmenu1.what_if(p1, Wind)){ //graj
            return 5;
        }
        if(pmenu1.what_if(p2, Wind)){ //opcje
            return 3;
        }
        if(pmenu1.what_if(p3, Wind)){ //napisy
            return 2;
        }

        if(pmenu1.what_if(p4, Wind)) exit(0); //wyjdz

        Wind.display();
    }


    return 0;
}

//options

options::options() {}

int options::Run(sf::RenderWindow &Wind) {

    Wind.setFramerateLimit(60);

    txt_menu menu1;
    Sprite& menu_s= menu1.g_tl();
    if(resolution_mode==2)menu_s.setScale(0.5,0.5);

    pola_menu pmenu1;
    Sprite p1,p2,p3;
    p1.setTexture(pmenu1.g_p1());
    p1.setScale(0.8/resolution_mode,0.8/resolution_mode);
    p1.setPosition(572./resolution_mode,350./resolution_mode);
    p2.setTexture(pmenu1.g_p1());
    p2.setScale(0.8/resolution_mode,0.8/resolution_mode);
    p2.setPosition(572./resolution_mode,640./resolution_mode);
    p3.setTexture(pmenu1.g_p1());
    p3.setScale(0.8/resolution_mode,0.8/resolution_mode);
    p3.setPosition(572./resolution_mode,930./resolution_mode);

    Sprite lg, lg2;
    lg.setTexture(pmenu1.g_lg());
    lg.setScale(0.8/resolution_mode,0.8/resolution_mode);
    lg.setPosition(1646./resolution_mode,32./resolution_mode);
    lg2.setTexture(pmenu1.g_lg());
    lg2.setScale(0.8/resolution_mode,0.8/resolution_mode);
    lg2.setPosition(30./resolution_mode,32./resolution_mode);

    //napisy
    font_menu ft;
    Font font1= ft.g_font();

    tekst_menu tekstmenu1(font1);
    sf::Text text1 = tekstmenu1.g_text_return();
    text1.setPosition(70 / resolution_mode,54 / resolution_mode);
    sf::Text text2 = tekstmenu1.g_attr();
    text2.setPosition(604 / resolution_mode,370 / resolution_mode);
    sf::Text text3 = tekstmenu1.g_arch();
    text3.setPosition(670 / resolution_mode,660 / resolution_mode);
    sf::Text text4 = tekstmenu1.g_rank();
    text4.setPosition(708 / resolution_mode,950 / resolution_mode);
    sf::Text text5 = tekstmenu1.g_acca();
    text5.setPosition(1660 / resolution_mode,54 / resolution_mode);



    Event event;

    while(Wind.isOpen()){

        Wind.clear(Color::Black);
        Wind.pollEvent(event);

        //txt
        Wind.draw(menu_s);
        Wind.draw(p1);
        Wind.draw(p2);
        Wind.draw(p3);

        Wind.draw(lg);
        Wind.draw(lg2);

        Wind.draw(text1);
        Wind.draw(text2);
        Wind.draw(text3);
        Wind.draw(text4);
        Wind.draw(text5);

        //napisy menu

        if(pmenu1.what_if(p1, Wind)){
            return 1;
        }

        if(pmenu1.what_if(p2, Wind)){
            return 9;
        }

        if(pmenu1.what_if(p3, Wind)){
            return 8;
        }


        if(pmenu1.what_if(lg, Wind)){
            return 4;
        }

        if(pmenu1.what_if(lg2, Wind)){
            return 0;
        }
        Wind.display();
    }

}

//account

account::account() {}

int account::Run(sf::RenderWindow &Wind) {

    //tekstury
    txt_menu menu1;
    Sprite& menu_s= menu1.g_op_tl();
    if(resolution_mode==2)menu_s.setScale(0.5,0.5);


    pola_menu pmenu1;
    Sprite p1,p2;
    p1.setTexture(pmenu1.g_lgw());
    p1.setScale(1./resolution_mode,1./resolution_mode);
    p1.setPosition(40./resolution_mode,1410./resolution_mode);
    p2.setTexture(pmenu1.g_lgw());
    p2.setScale(1./resolution_mode,1./resolution_mode);
    p2.setPosition(1549./resolution_mode,1410./resolution_mode);

    Sprite log, pas;
    log.setTexture(pmenu1.g_sa());
    log.setScale(1./resolution_mode,1./resolution_mode);
    log.setPosition(470./resolution_mode,490./resolution_mode);
    pas.setTexture(pmenu1.g_sa());
    pas.setScale(1./resolution_mode,1./resolution_mode);
    pas.setPosition(470./resolution_mode,900./resolution_mode);

    //napisy
    font_menu ft;
    Font font1= ft.g_font();

    tekst_menu tekstmenu1(font1);
    sf::Text text1 = tekstmenu1.g_chan_log();
    text1.setPosition(645 / resolution_mode,320  / resolution_mode);
    sf::Text text2 = tekstmenu1.g_chan_pass();
    text2.setPosition(540 / resolution_mode,730  / resolution_mode);
    sf::Text text4 = tekstmenu1.g_man_your_acc();
    text4.setPosition(370 / resolution_mode,110  / resolution_mode);
    sf::Text text5 = tekstmenu1.g_text_return();
    text5.setPosition(120 / resolution_mode,1450 / resolution_mode);
    sf::Text text6 = tekstmenu1.g_text_confirm();
    text6.setPosition(1614 / resolution_mode,1450 / resolution_mode);

    //login i haslo
    sf::Text login =tekstmenu1.g_login();
    login.setPosition(480./resolution_mode,510./resolution_mode);
    sf::Text haslo =tekstmenu1.g_password();
    haslo.setPosition(480./resolution_mode,920./resolution_mode);

    //wpisywanie symboli
    int pom=0,pom2=0;
    string a,b;
    int millis =500;
    //poprawnosc logowania
    User user;


    Event event;


    while(Wind.isOpen()) {

        Wind.clear(Color::Black);
        Wind.pollEvent(event);

        //rysujemy txt
        Wind.draw(menu_s);
        Wind.draw(p1);
        Wind.draw(p2);
        Wind.draw(log);
        Wind.draw(pas);

        //tekst
        Wind.draw(text1);
        Wind.draw(text2);
        Wind.draw(text4);
        Wind.draw(text5);
        Wind.draw(text6);


        //login i haslo
        Wind.draw(login);
        Wind.draw(haslo);

        //interakcje
        //wpisywanie loginu i hasla
        if(pmenu1.what_if(log, Wind)){pom=1; pom2=0;}

        if(pmenu1.what_if(pas,Wind)) {pom=0; pom2=1;}

        if (event.type == sf::Event::TextEntered && pom==1)
        {
            if (event.text.unicode < 128 && millis>=8) {
                //test czy pobiera
                std::cout << "ASCII character typed: " << static_cast<char>(event.text.unicode) << std::endl;
                //dodawanie do stringa
                if(event.text.unicode!=8 && a.length()<24) a+=event.text.unicode;
                    //usuwanie liter jesli backspace
                else if(event.text.unicode==8&&a.length()>0) a.pop_back();
                login.setString(a);
                millis=0;
            }
        }

        if (event.type == sf::Event::TextEntered && pom2==1)
        {
            if (event.text.unicode < 128 && millis>=8) {
                //test czy pobiera
                std::cout << "ASCII character typed: " << static_cast<char>(event.text.unicode) << std::endl;
                //dodawanie do stringa
                if(event.text.unicode!=8 && b.length()<24) b+=event.text.unicode;
                    //usuwanie liter jesli backspace
                else if(event.text.unicode==8&&b.length()>0) b.pop_back();
                haslo.setString(b);
                millis=0;
            }
        }

        if(pmenu1.what_if(p2, Wind)){
            if(user.ZmianaPasow(user,a,b)==true) return 3;
        }

        if(pmenu1.what_if(p1, Wind)){
            return 3;
        }

        millis++;
        Wind.display();
    }

    return 0;

}

//atrybuty

opcje_loop::opcje_loop() {}

int opcje_loop:: Run(RenderWindow &Wind){
    //Atrybuty
    Builder build;
    int plansz = OdczytMotyw();
    int pion = OdczytKolor();
    int tryb = OdczytModel();

    build.setModel(tryb);
    if(pion==1){
        build.setKolor(BLEACH_WHITE_LIGHT_BROWN);
    }
    else {
        build.setKolor(BLACK_WHITE);
    }
    if(plansz == 1){
        build.setMotyw(BLEACH_WHITE_LIGHT_BROWN);
    }
    else {
        build.setMotyw(BLACK_WHITE);
    }

    //okno
    Wind.setFramerateLimit(60);

    //tekstury
    txt_menu menu1;
    Sprite& menu_s= menu1.g_op_tl();
    if(resolution_mode==2)menu_s.setScale(0.5,0.5);

    pola_menu pmenu1;
    Sprite p1,p2,p3,p4,pion1,pion2, b1, b2;
    Sprite pod1,pod1b, pod2,pod2b, pod3,pod3b;

    //tryb gry
    p1.setTexture(pmenu1.g_p2());
    p1.setScale(1./resolution_mode,1./resolution_mode);
    p1.setPosition(730./resolution_mode,904./resolution_mode);
    p2.setTexture(pmenu1.g_p2());
    p2.setScale(1./resolution_mode,1./resolution_mode);
    p2.setPosition(1040./resolution_mode,904./resolution_mode);
            //tryb_gry - podswietlenia
            pod3.setTexture(pmenu1.g_pod3());
            pod3.setScale(1./resolution_mode,1./resolution_mode);
            pod3.setPosition(1035./resolution_mode,899./resolution_mode);
            pod3b.setTexture(pmenu1.g_pod3());
            pod3b.setScale(1./resolution_mode,1./resolution_mode);
            pod3b.setPosition(725./resolution_mode,899./resolution_mode);

    p3.setTexture(pmenu1.g_lgw());
    p3.setScale(1./resolution_mode,1./resolution_mode);
    p3.setPosition(40./resolution_mode,1410./resolution_mode);
    p4.setTexture(pmenu1.g_lgw());
    p4.setScale(1./resolution_mode,1./resolution_mode);
    p4.setPosition(1549./resolution_mode,1410./resolution_mode);


    //wybory atrybutow
    //pionki
    pion1.setTexture(pmenu1.g_pionl());
    pion1.setScale(1./resolution_mode,1./resolution_mode);
    pion1.setPosition(1240./resolution_mode,520./resolution_mode);
    pion2.setTexture(pmenu1.g_pionb());
    pion2.setScale(1./resolution_mode,1./resolution_mode);
    pion2.setPosition(1440./resolution_mode,520./resolution_mode);
            //podswietlenia
            pod2.setTexture(pmenu1.g_pod2());
            pod2.setScale(1./resolution_mode,1./resolution_mode);
            pod2.setPosition(1235./resolution_mode,515./resolution_mode);
            pod2b.setTexture(pmenu1.g_pod2());
            pod2b.setScale(1./resolution_mode,1./resolution_mode);
            pod2b.setPosition(1435./resolution_mode,515./resolution_mode);
    //plansze
    b1.setTexture(pmenu1.g_boardl());
    b1.setScale(1./resolution_mode,1./resolution_mode);
    b1.setPosition(435./resolution_mode,520./resolution_mode);
    b2.setTexture(pmenu1.g_boardb());
    b2.setScale(1./resolution_mode,1./resolution_mode);
    b2.setPosition(635./resolution_mode,520./resolution_mode);
            //podswietlenia
            pod1.setTexture(pmenu1.g_pod1());
            pod1.setScale(1./resolution_mode,1./resolution_mode);
            pod1.setPosition(430./resolution_mode,515./resolution_mode);
            pod1b.setTexture(pmenu1.g_pod1());
            pod1b.setScale(1./resolution_mode,1./resolution_mode);
            pod1b.setPosition(630./resolution_mode,515./resolution_mode);

    //napisy
    font_menu ft;
    Font font1= ft.g_font();

    tekst_menu tekstmenu1(font1);
    sf::Text text1 = tekstmenu1.g_text_op();
    text1.setPosition(710 / resolution_mode,110 / resolution_mode);
    sf::Text text2 = tekstmenu1.g_text_board();
    text2.setPosition(440 / resolution_mode,400 / resolution_mode);
    sf::Text text3 = tekstmenu1.g_text_pawns();
    text3.setPosition(1240 / resolution_mode,400 / resolution_mode);
    sf::Text text4 = tekstmenu1.g_text_game_mode();
    text4.setPosition(730 / resolution_mode,760 / resolution_mode);
    sf::Text text5 = tekstmenu1.g_text_return();
    text5.setPosition(120 / resolution_mode,1450 / resolution_mode);
    sf::Text text6 = tekstmenu1.g_text_confirm();
    text6.setPosition(1614 / resolution_mode,1450 / resolution_mode);
    sf::Text pvp = tekstmenu1.g_text_pvp();
    pvp.setPosition(790 / resolution_mode,924 / resolution_mode);
    sf::Text pve = tekstmenu1.g_text_pve();
    pve.setPosition(1100 / resolution_mode,924 / resolution_mode);


    Event event;

    while(Wind.isOpen()) {

        Wind.clear(Color::Black);
        Wind.pollEvent(event);

        //rysujemy txt
        Wind.draw(menu_s);
        Wind.draw(p1);
        Wind.draw(p2);
        Wind.draw(p3);
        Wind.draw(p4);
        Wind.draw(pion1);
        Wind.draw(pion2);
        Wind.draw(b1);
        Wind.draw(b2);

            //podswietlenia
            if(tryb==1)Wind.draw(pod3);
            else if(tryb == 0) Wind.draw(pod3b);
            if(pion==1)Wind.draw(pod2);
            else if(pion==0)Wind.draw(pod2b);
            if(plansz==1) Wind.draw(pod1);
            else if(plansz==0)Wind.draw(pod1b);
        //tekst
        Wind.draw(text1);
        Wind.draw(text2);
        Wind.draw(text3);
        Wind.draw(text4);
        Wind.draw(text5);
        Wind.draw(text6);
        Wind.draw(pvp);
        Wind.draw(pve);

        //interakcje

        //wybor atrybutow
        //plansza
        if(pmenu1.what_if(b2,Wind)){
            plansz=0;
            build.setMotyw(BLACK_WHITE);
        }
        if(pmenu1.what_if(b1,Wind)){
            plansz=1;
            build.setMotyw(BLEACH_WHITE_LIGHT_BROWN);
        }
        //piony
        if(pmenu1.what_if(pion2,Wind)){
            pion=0;
            build.setKolor(BLACK_WHITE);
        }
        if(pmenu1.what_if(pion1,Wind)){
            pion=1;
            build.setKolor(BLEACH_WHITE_LIGHT_BROWN);
        }
        //tryb gry
        if(pmenu1.what_if(p1,Wind)){
            tryb=0;
            build.setModel(tryb);
        }
        if(pmenu1.what_if(p2,Wind)){
            tryb=1;
            build.setModel(tryb);
        }
        //potwierdz wybor
        if(pmenu1.what_if(p4,Wind)){
            Atrybuty atrybut= build.build();
            return 3;
        }

        //powrot do menu
        if(pmenu1.what_if(p3, Wind)){
             return 3;
        }

        Wind.display();
    }
    return 0;
}

//credits

credits::credits() {}

int credits::Run(sf::RenderWindow &Wind) {

    Wind.setFramerateLimit(60);

    //tekstury

    txt_menu menu1;
    Sprite& menu_s= menu1.g_op_tl();
    if(resolution_mode==2)menu_s.setScale(0.5,0.5);

    pola_menu pmenu1;
    Sprite p3;

    p3.setTexture(pmenu1.g_lgw());
    p3.setScale(1./resolution_mode,1./resolution_mode);
    p3.setPosition(40./resolution_mode,1410./resolution_mode);

    //napisy
    font_menu ft;
    Font font1= ft.g_font();

    tekst_menu tekstmenu1(font1);
    sf::Text text1 = tekstmenu1.g_text_cr();
    text1.setPosition(718  / resolution_mode,110 /resolution_mode);
    sf::Text text2 = tekstmenu1.g_text_return();
    text2.setPosition(120 / resolution_mode,1450 / resolution_mode);

    sf::Text text3 = tekstmenu1.g_authors();
    text3.setPosition(400 / resolution_mode,340 / resolution_mode);
    sf::Text text4 = tekstmenu1.g_prze();
    text4.setPosition(400 / resolution_mode,440 / resolution_mode);
    sf::Text text5 = tekstmenu1.g_jul();
    text5.setPosition(400 / resolution_mode,540 / resolution_mode);
    sf::Text text6 = tekstmenu1.g_kuba();
    text6.setPosition(400 / resolution_mode,640 / resolution_mode);


    Event event;

    while(Wind.isOpen()) {
        Wind.clear(Color::Black);
        Wind.pollEvent(event);

        Wind.draw(menu_s);
        Wind.draw(p3);

        Wind.draw(text1);
        Wind.draw(text2);
        Wind.draw(text3);
        Wind.draw(text4);
        Wind.draw(text5);
        Wind.draw(text6);

        //interakcje

        if(pmenu1.what_if(p3, Wind)){
            return 0;
        }

        Wind.display();
    }
}

//pierwszy ekran po wejsciu do gry
firstscreen::firstscreen() {}

int firstscreen::Run(sf::RenderWindow &Wind) {
    //ustawianie okna
    Wind.setFramerateLimit(60);

    //ustawianie tla
    txt_menu menu1;
    Sprite& menu_s= menu1.g_tl();
    if(resolution_mode==2)menu_s.setScale(0.5,0.5);

    //ustawianie przyciskow
    pola_menu pmenu1;
    Sprite lg, lg2;
    lg.setTexture(pmenu1.g_lg());
    lg.setScale(1./resolution_mode,1./resolution_mode);
    lg.setPosition(1559./resolution_mode,1410./resolution_mode);
    lg2.setTexture(pmenu1.g_lg());
    lg2.setScale(1./resolution_mode,1./resolution_mode);
    lg2.setPosition(30./resolution_mode,1410./resolution_mode);
    //create account
    Sprite nwac;
    nwac.setTexture(pmenu1.g_login());
    nwac.setScale(1./resolution_mode,1./resolution_mode);
    nwac.setPosition(701./resolution_mode,1410./resolution_mode);
    //przyciski login, haslo
    Sprite log, pas;
    log.setTexture(pmenu1.g_sa());
    log.setScale(1./resolution_mode,1./resolution_mode);
    log.setPosition(470./resolution_mode,490./resolution_mode);
    pas.setTexture(pmenu1.g_sa());
    pas.setScale(1./resolution_mode,1./resolution_mode);
    pas.setPosition(470./resolution_mode,900./resolution_mode);

    font_menu ft;
    Font font1= ft.g_font();

    //tekst
    tekst_menu tekstmenu1(font1);
    sf::Text text1 = tekstmenu1.g_fs_title();
    text1.setPosition(413.  / resolution_mode,80. /resolution_mode);
    sf::Text text2 = tekstmenu1.g_fs_log();
    text2.setPosition(856.  / resolution_mode,320. /resolution_mode);
    sf::Text text3 = tekstmenu1.g_fs_pas();
    text3.setPosition(745.  / resolution_mode,730. /resolution_mode);
    sf::Text text4 = tekstmenu1.g_fs_ex();
    text4.setPosition(155 / resolution_mode,1440 / resolution_mode);
    sf::Text text5 = tekstmenu1.g_fs_na();
    text5.setPosition(735 / resolution_mode,1440 / resolution_mode);
    sf::Text text6 = tekstmenu1.g_fs_con();
    text6.setPosition(1605 / resolution_mode,1440 / resolution_mode);

    //login i haslo
    sf::Text login =tekstmenu1.g_login();
    login.setPosition(480./resolution_mode,510./resolution_mode);
    sf::Text haslo =tekstmenu1.g_password();
    haslo.setPosition(480./resolution_mode,920./resolution_mode);

    //wpisywanie symboli
    int pom=0,pom2=0;
    string a,b,gwiazdki;
    int millis =500;
    //poprawnosc logowania
    User user;

    Event event;

    while(Wind.isOpen()) {
        Wind.clear(Color::Black);
        Wind.pollEvent(event);

        //txt
        Wind.draw(menu_s);
        Wind.draw(lg);
        Wind.draw(lg2);
        Wind.draw(nwac);
        Wind.draw(log);
        Wind.draw(pas);
        //text
        Wind.draw(text1);
        Wind.draw(text2);
        Wind.draw(text3);
        Wind.draw(text4);
        Wind.draw(text5);
        Wind.draw(text6);

        //login i haslo
        Wind.draw(login);
        Wind.draw(haslo);

        //interakcje
        //wpisywanie loginu i hasla
        if(pmenu1.what_if(log, Wind)){pom=1; pom2=0;}

        if(pmenu1.what_if(pas,Wind)) {pom=0; pom2=1;}

        if (event.type == sf::Event::TextEntered && pom==1)
        {
            if (event.text.unicode < 128 && millis>=8) {
                //test czy pobiera
               // std::cout << "ASCII character typed: " << static_cast<char>(event.text.unicode) << std::endl;
                //dodawanie do stringa
                if(event.text.unicode!=8 && a.length()<24) a+=event.text.unicode;
                //usuwanie liter jesli backspace - TEST JEDNOSTKOWY czy dziala
                else if(event.text.unicode==8&&a.length()>0){
                    if(event.text.unicode==8&&a.length()>0){
                        a.pop_back();
                    }
                }
                login.setString(a);
                millis=0;
            }
        }

        if (event.type == sf::Event::TextEntered && pom2==1)
        {
            if (event.text.unicode < 128 && millis>=8) {
                //test czy pobiera
               // std::cout << "ASCII character typed: " << static_cast<char>(event.text.unicode) << std::endl;
                //dodawanie do stringa - TEST JEDNOTKOWY czy dziala
                if(event.text.unicode!=8 && b.length()<24){
                    if(event.text.unicode!=8 && b.length()<24){
                    b+=event.text.unicode;
                    gwiazdki+='*';
                    }
                }
                //usuwanie liter jesli backspace
                else if(event.text.unicode==8&& b.length()>0) {b.pop_back();gwiazdki.pop_back();}
                haslo.setString(gwiazdki);
                millis=0;
            }
        }


        if(pmenu1.what_if(lg2, Wind)){
            return -1;
        }

        if(pmenu1.what_if(lg, Wind)){
            if(user.logowanie(user,a,b))
            return 0;
        }

        if(pmenu1.what_if(nwac, Wind)){
            return 7;
        }

        millis++;
        Wind.display();
    }
}

//new account

new_account::new_account() {}

int new_account::Run(sf::RenderWindow &Wind) {

    //ustawianie okna
    Wind.setFramerateLimit(60);

    //ustawianie tla
    txt_menu menu1;
    Sprite& menu_s= menu1.g_tl();
    if(resolution_mode==2)menu_s.setScale(0.5,0.5);

    //ustawianie przyciskow
    pola_menu pmenu1;
    Sprite lg, lg2;
    lg.setTexture(pmenu1.g_lg());
    lg.setScale(1./resolution_mode,1./resolution_mode);
    lg.setPosition(1559./resolution_mode,1410./resolution_mode);
    lg2.setTexture(pmenu1.g_lg());
    lg2.setScale(1./resolution_mode,1./resolution_mode);
    lg2.setPosition(30./resolution_mode,1410./resolution_mode);

    //przyciski login, haslo
    Sprite log, pas;
    log.setTexture(pmenu1.g_sa());
    log.setScale(1./resolution_mode,1./resolution_mode);
    log.setPosition(470./resolution_mode,490./resolution_mode);
    pas.setTexture(pmenu1.g_sa());
    pas.setScale(1./resolution_mode,1./resolution_mode);
    pas.setPosition(470./resolution_mode,900./resolution_mode);

    //napisy
    font_menu ft;
    Font font1= ft.g_font();

    tekst_menu tekstmenu1(font1);
    sf::Text text1 =tekstmenu1.g_na_tit();
    text1.setPosition(251.  / resolution_mode,80. /resolution_mode);
    sf::Text text2 = tekstmenu1.g_fs_log();
    text2.setPosition(856.  / resolution_mode,320. /resolution_mode);
    sf::Text text3 = tekstmenu1.g_fs_pas();
    text3.setPosition(745.  / resolution_mode,730. /resolution_mode);
    sf::Text text5 = tekstmenu1.g_na_ret();
    text5.setPosition(92 / resolution_mode,1440 / resolution_mode);
    sf::Text text6 = tekstmenu1.g_fs_con();
    text6.setPosition(1605 / resolution_mode,1440 / resolution_mode);

    //login i haslo
    sf::Text login =tekstmenu1.g_login();
    login.setPosition(480./resolution_mode,510./resolution_mode);
    sf::Text haslo =tekstmenu1.g_password();
    haslo.setPosition(480./resolution_mode,920./resolution_mode);

    User user;

    //wpisywanie symboli
    int pom=0,pom2=0;
    string a,b;
    int millis =500;


    Event event;

    while(Wind.isOpen()) {
        Wind.clear(Color::Black);
        Wind.pollEvent(event);

        //txt
        Wind.draw(menu_s);
        Wind.draw(lg);
        Wind.draw(lg2);
        Wind.draw(log);
        Wind.draw(pas);
        //text
        Wind.draw(text1);
        Wind.draw(text2);
        Wind.draw(text3);
//        Wind.draw(text4);
        Wind.draw(text5);
        Wind.draw(text6);

        //login i haslo
        Wind.draw(login);
        Wind.draw(haslo);

        //interakcje
        //wpisywanie loginu i hasla
        if(pmenu1.what_if(log, Wind)){pom=1; pom2=0;}

        if(pmenu1.what_if(pas,Wind)) {pom=0; pom2=1;}

        if (event.type == sf::Event::TextEntered && pom==1)
        {
            if (event.text.unicode < 128 && millis>=8) {
                //test czy pobiera
                std::cout << "ASCII character typed: " << static_cast<char>(event.text.unicode) << std::endl;
                //dodawanie do stringa
                if(event.text.unicode!=8 && a.length()<24) a+=event.text.unicode;
                    //usuwanie liter jesli backspace
                else if(event.text.unicode==8&&a.length()>0) a.pop_back();
                login.setString(a);
                millis=0;
            }
        }

        if (event.type == sf::Event::TextEntered && pom2==1)
        {
            if (event.text.unicode < 128 && millis>=8) {
                //test czy pobiera
                std::cout << "ASCII character typed: " << static_cast<char>(event.text.unicode) << std::endl;
                //dodawanie do stringa
                if(event.text.unicode!=8 && b.length()<24) b+=event.text.unicode;
                    //usuwanie liter jesli backspace
                else if(event.text.unicode==8&&b.length()>0) b.pop_back();
                haslo.setString(b);
                millis=0;
            }
        }


        if(pmenu1.what_if(lg2, Wind)){
            return 6;
        }

        if(pmenu1.what_if(lg, Wind)&&user.rejestracja(user,a,b)){
            return 0;
        }

        millis++;
        Wind.display();
    }

}

//ranking

ranking::ranking() {}

int ranking::Run(sf::RenderWindow &Wind) {
    Wind.setFramerateLimit(60);

    //tekstury

    txt_menu menu1;
    Sprite& menu_s= menu1.g_op_tl();
    if(resolution_mode==2)menu_s.setScale(0.5,0.5);

    pola_menu pmenu1;
    Sprite p3;

    p3.setTexture(pmenu1.g_lgw());
    p3.setScale(1./resolution_mode,1./resolution_mode);
    p3.setPosition(40./resolution_mode,1410./resolution_mode);

    //napisy
    font_menu ft;
    Font font1= ft.g_font();

    tekst_menu tekstmenu1(font1);
    sf::Text text1 = tekstmenu1.g_ranking();
    text1.setPosition(705 / resolution_mode,40 / resolution_mode);
    sf::Text text2 = tekstmenu1.g_text_return();
    text2.setPosition(120 / resolution_mode,1450 / resolution_mode);
    sf::Text text3 = tekstmenu1.g_position();
    text3.setPosition(200 / resolution_mode,200 / resolution_mode);
    sf::Text text4 = tekstmenu1.g_nickname();
    text4.setPosition(806. / resolution_mode,200 / resolution_mode);
    sf::Text text5 = tekstmenu1.g_point();
    text5.setPosition(1450 / resolution_mode,200 / resolution_mode);


    //wypisywanie miejsc
    User user;
    vector<User> a =user.WypiszTop5();
    //cout<<a[1].login<<endl;
    string s=a[0].login,s2=a[1].login,s3=a[2].login, s4=a[3].login, s5=a[4].login;
    //loginy
    sf::Text nick1 = tekstmenu1.g_nickname(); nick1.setString(s); nick1.setOrigin(nick1.getLocalBounds().width/2,0);
    nick1.setPosition(1000. / resolution_mode,320 / resolution_mode);
    sf::Text nick2 = tekstmenu1.g_nickname(); nick2.setString(s2); nick2.setOrigin(nick2.getLocalBounds().width/2,0);
    nick2.setPosition(1000. / resolution_mode,440 / resolution_mode);
    sf::Text nick3 = tekstmenu1.g_nickname(); nick3.setString(s3); nick3.setOrigin(nick3.getLocalBounds().width/2,0);
    nick3.setPosition(1001. / resolution_mode,560 / resolution_mode);
    sf::Text nick4 = tekstmenu1.g_nickname(); nick4.setString(s4);  nick4.setOrigin(nick4.getLocalBounds().width/2,0);
    nick4.setPosition(1000. / resolution_mode,680 / resolution_mode);
    sf::Text nick5 = tekstmenu1.g_nickname(); nick5.setString(s5); nick5.setOrigin(nick5.getLocalBounds().width/2,0);
    nick5.setPosition(1000. / resolution_mode,800 / resolution_mode);

    //punkty
    int pp1=a[0].point,pp2=a[1].point, pp3=a[2].point, pp4=a[3].point, pp5=a[4].point;
    sf::Text pnick1 = tekstmenu1.g_nickname(); pnick1.setString(std::to_string(pp1)); pnick1.setOrigin(pnick1.getLocalBounds().width/2,0);
    pnick1.setPosition(1580. / resolution_mode,320 / resolution_mode);
    sf::Text pnick2 = tekstmenu1.g_nickname(); pnick2.setString(std::to_string(pp2)); pnick2.setOrigin(pnick2.getLocalBounds().width/2,0);
    pnick2.setPosition(1580. / resolution_mode,440 / resolution_mode);
    sf::Text pnick3 = tekstmenu1.g_nickname(); pnick3.setString(std::to_string(pp3)); pnick3.setOrigin(pnick3.getLocalBounds().width/2,0);
    pnick3.setPosition(1580. / resolution_mode,560 / resolution_mode);
    sf::Text pnick4 = tekstmenu1.g_nickname(); pnick4.setString(std::to_string(pp4));  pnick4.setOrigin(pnick4.getLocalBounds().width/2,0);
    pnick4.setPosition(1580. / resolution_mode,680 / resolution_mode);
    sf::Text pnick5 = tekstmenu1.g_nickname(); pnick5.setString(std::to_string(pp5)); pnick5.setOrigin(pnick5.getLocalBounds().width/2,0);
    pnick5.setPosition(1580. / resolution_mode,800 / resolution_mode);


    //pozycje
    sf::Text pos1 = tekstmenu1.g_position(); pos1.setString("1.");
    pos1.setPosition(340 / resolution_mode,320 / resolution_mode);
    sf::Text pos2 = tekstmenu1.g_position(); pos2.setString("2.");
    pos2.setPosition(340 / resolution_mode,440 / resolution_mode);
    sf::Text pos3 = tekstmenu1.g_position(); pos3.setString("3.");
    pos3.setPosition(340 / resolution_mode,560 / resolution_mode);
    sf::Text pos4 = tekstmenu1.g_position(); pos4.setString("4.");
    pos4.setPosition(340 / resolution_mode,680 / resolution_mode);
    sf::Text pos5 = tekstmenu1.g_position(); pos5.setString("5.");
    pos5.setPosition(340 / resolution_mode,800 / resolution_mode);

    Event event;

    while(Wind.isOpen()) {
        Wind.clear(Color::Black);
        Wind.pollEvent(event);
        //txt
        Wind.draw(menu_s);
        Wind.draw(p3);
        //napisy
        Wind.draw(text1);
        Wind.draw(text2);
        Wind.draw(text3);
        Wind.draw(text4);
        Wind.draw(text5);

            //miejsca
            Wind.draw(pos1);
            Wind.draw(pos2);
            Wind.draw(pos3);
            Wind.draw(pos4);
            Wind.draw(pos5);

            //nicki
            Wind.draw(nick1);
            Wind.draw(nick2);
            Wind.draw(nick3);
            Wind.draw(nick4);
            Wind.draw(nick5);

            //punkty
            Wind.draw(pnick1);
            Wind.draw(pnick2);
            Wind.draw(pnick3);
            Wind.draw(pnick4);
            Wind.draw(pnick5);


        //interakcje

        if(pmenu1.what_if(p3, Wind)){
            return 3;
        }

        Wind.display();
    }
}

//archiwum

arch::arch() {}

int arch::Run(sf::RenderWindow &Wind) {

    Wind.setFramerateLimit(60);

    //tekstury

    txt_menu menu1;
    Sprite& menu_s= menu1.g_op_tl();
    if(resolution_mode==2)menu_s.setScale(0.5,0.5);

    pola_menu pmenu1;
    Sprite p2,p3,p4,p5,p6,p7;

    p2.setTexture(pmenu1.g_arch());
    p2.setScale(1./resolution_mode,1./resolution_mode);
    p2.setPosition(800./resolution_mode,250./resolution_mode);
    p4.setTexture(pmenu1.g_arch());
    p4.setScale(1./resolution_mode,1./resolution_mode);
    p4.setPosition(800./resolution_mode,420./resolution_mode);
    p5.setTexture(pmenu1.g_arch());
    p5.setScale(1./resolution_mode,1./resolution_mode);
    p5.setPosition(800./resolution_mode,610./resolution_mode);
    p6.setTexture(pmenu1.g_arch());
    p6.setScale(1./resolution_mode,1./resolution_mode);
    p6.setPosition(800./resolution_mode,790./resolution_mode);
    p7.setTexture(pmenu1.g_arch());
    p7.setScale(1./resolution_mode,1./resolution_mode);
    p7.setPosition(800./resolution_mode,970./resolution_mode);
    p3.setTexture(pmenu1.g_lgw());
    p3.setScale(1./resolution_mode,1./resolution_mode);
    p3.setPosition(40./resolution_mode,1410./resolution_mode);

    //napisy
    font_menu ft;
    Font font1= ft.g_font();

    tekst_menu tekstmenu1(font1);
    sf::Text text1 = tekstmenu1.g_arch();
    text1.setPosition(675 / resolution_mode,40 / resolution_mode);
    sf::Text text2 = tekstmenu1.g_text_return();
    text2.setPosition(120 / resolution_mode,1450 / resolution_mode);

    sf::Text game1 = tekstmenu1.g_text_pve();
    game1.setString("GAME 1");
    game1.setPosition(895 / resolution_mode,265 / resolution_mode);
    sf::Text game2 = tekstmenu1.g_text_pve();
    game2.setString("GAME 2");
    game2.setPosition(895 / resolution_mode,435 / resolution_mode);
    sf::Text game3 = tekstmenu1.g_text_pve();
    game3.setString("GAME 3");
    game3.setPosition(895 / resolution_mode,625 / resolution_mode);
    sf::Text game4 = tekstmenu1.g_text_pve();
    game4.setString("GAME 4");
    game4.setPosition(895 / resolution_mode,805 / resolution_mode);
    sf::Text game5 = tekstmenu1.g_text_pve();
    game5.setString("GAME 5");
    game5.setPosition(895 / resolution_mode,985 / resolution_mode);



    Event event;

    while(Wind.isOpen()) {
        Wind.clear(Color::Black);
        Wind.pollEvent(event);
        //txt
        Wind.draw(menu_s);
        Wind.draw(p2);
        Wind.draw(p3);
        Wind.draw(p4);
        Wind.draw(p5);
        Wind.draw(p6);
        Wind.draw(p7);


        //napisy
        Wind.draw(text1);
        Wind.draw(text2);

        Wind.draw(game1);
        Wind.draw(game2);
        Wind.draw(game3);
        Wind.draw(game4);
        Wind.draw(game5);


        //interakcje
            //wywietlanie archiwum
            ///a1
            if(pmenu1.what_if(p2, Wind)){
               return 14;
            }
            ///a2
            if(pmenu1.what_if(p4, Wind)){
                return 13;
            }
            ///a3
            if(pmenu1.what_if(p5, Wind)){
                return 12;
            }
            ///a4
            if(pmenu1.what_if(p6, Wind)){
                return 11;
            }
            ///a5
            if(pmenu1.what_if(p7, Wind)){
                return 10;
            }

        if(pmenu1.what_if(p3, Wind)){
            return 3;
        }

        Wind.display();

    }
}

//a1

a1::a1() {}

int a1::Run(sf::RenderWindow &Wind) {

    Wind.setFramerateLimit(60);

    //tekstury

    txt_menu menu1;
    Sprite& menu_s= menu1.g_op_tl();
    if(resolution_mode==2)menu_s.setScale(0.5,0.5);

    pola_menu pmenu1;
    Sprite p3;

    p3.setTexture(pmenu1.g_lgw());
    p3.setScale(1./resolution_mode,1./resolution_mode);
    p3.setPosition(40./resolution_mode,1410./resolution_mode);

    //napisy
    font_menu ft;
    Font font1;
    font1.loadFromFile(MY_DEFINE "../font/Manrope-Bold.ttf");

    tekst_menu tekstmenu1(font1);
    sf::Text text2 = tekstmenu1.g_text_return();
    text2.setPosition(120 / resolution_mode,1450 / resolution_mode);

    //wyswietl archiwum
    int pom=0;
    string x,y,z,x1,y1,z1;
    vector<string> a = Display_File(MY_DEFINE "../txt/a1.txt");
    int n=a.size();
    pom_f(x,y,z,x1,y1,z1,pom,a);
    sf::Font ff; ff.loadFromFile(MY_DEFINE "../font/fira.ttf");
    //wyswietlanie ruchow
    sf::Text ruch1 = tekstmenu1.g_text_pve();
    ruch1.setFont(ff);
    ruch1.setCharacterSize(30);
    ruch1.setString(x);
    ruch1.setPosition(120 / resolution_mode,150 / resolution_mode);
    sf::Text ruch2 = tekstmenu1.g_text_pve();
    ruch2.setFont(ff);
    ruch2.setCharacterSize(30);
    ruch2.setString(y);
    ruch2.setPosition(120 / resolution_mode,700 / resolution_mode);
    sf::Text ruch3 = tekstmenu1.g_text_pve();
    ruch3.setFont(ff);
    ruch3.setCharacterSize(30);
    ruch3.setString(z);
    ruch3.setPosition(740/ resolution_mode,150 / resolution_mode);
    sf::Text ruch4 = tekstmenu1.g_text_pve();
    ruch4.setFont(ff);
    ruch4.setCharacterSize(30);
    ruch4.setString(x1);
    ruch4.setPosition(740/ resolution_mode,700 / resolution_mode);
    sf::Text ruch5 = tekstmenu1.g_text_pve();
    ruch5.setFont(ff);
    ruch5.setCharacterSize(30);
    ruch5.setString(y1);
    ruch5.setPosition(1360 / resolution_mode,150 / resolution_mode);
    sf::Text ruch6 = tekstmenu1.g_text_pve();
    ruch6.setFont(ff);
    ruch6.setCharacterSize(30);
    ruch6.setString(z1);
    ruch6.setPosition(1360  / resolution_mode,700 / resolution_mode);

    Event event;

    while(Wind.isOpen()) {
        Wind.clear(Color::Black);
        Wind.pollEvent(event);
        //txt
        Wind.draw(menu_s);
        Wind.draw(p3);

        //napisy
        Wind.draw(text2);

        //wywietlanie archiwum
        if(x.size()>0)Wind.draw(ruch1);
        if(y.size()>0) Wind.draw(ruch2);
        if(z.size()>0) Wind.draw(ruch3);
        if(x1.size()>0) Wind.draw(ruch4);
        if(y1.size()>0) Wind.draw(ruch5);
        if(z1.size()>0) Wind.draw(ruch6);

        //interakcje

        if(pmenu1.what_if(p3, Wind)){
            return 9;
        }

        Wind.display();
    }
}

//a2

a2::a2() {}

int a2::Run(sf::RenderWindow &Wind) {

    Wind.setFramerateLimit(60);

    //tekstury

    txt_menu menu1;
    Sprite& menu_s= menu1.g_op_tl();
    if(resolution_mode==2)menu_s.setScale(0.5,0.5);

    pola_menu pmenu1;
    Sprite p3;

    p3.setTexture(pmenu1.g_lgw());
    p3.setScale(1./resolution_mode,1./resolution_mode);
    p3.setPosition(40./resolution_mode,1410./resolution_mode);

    //napisy
    font_menu ft;
    Font font1;
    font1.loadFromFile(MY_DEFINE "../font/Manrope-Bold.ttf");

    tekst_menu tekstmenu1(font1);
    sf::Text text2 = tekstmenu1.g_text_return();
    text2.setPosition(120 / resolution_mode,1450 / resolution_mode);

    //wyswietl archiwum
    int pom=0;
    string x,y,z,x1,y1,z1;
    vector<string> a = Display_File(MY_DEFINE "../txt/a2.txt");
    int n=a.size();
    pom_f(x,y,z,x1,y1,z1,pom,a);
    sf::Font ff; ff.loadFromFile(MY_DEFINE "../font/fira.ttf");
    //wyswietlanie ruchow
    sf::Text ruch1 = tekstmenu1.g_text_pve();
    ruch1.setFont(ff);
    ruch1.setCharacterSize(30);
    ruch1.setString(x);
    ruch1.setPosition(120 / resolution_mode,150 / resolution_mode);
    sf::Text ruch2 = tekstmenu1.g_text_pve();
    ruch2.setFont(ff);
    ruch2.setCharacterSize(30);
    ruch2.setString(y);
    ruch2.setPosition(120 / resolution_mode,700 / resolution_mode);
    sf::Text ruch3 = tekstmenu1.g_text_pve();
    ruch3.setFont(ff);
    ruch3.setCharacterSize(30);
    ruch3.setString(z);
    ruch3.setPosition(740 / resolution_mode,150 / resolution_mode);
    sf::Text ruch4 = tekstmenu1.g_text_pve();
    ruch4.setFont(ff);
    ruch4.setCharacterSize(30);
    ruch4.setString(x1);
    ruch4.setPosition(740 / resolution_mode,700 / resolution_mode);
    sf::Text ruch5 = tekstmenu1.g_text_pve();
    ruch5.setFont(ff);
    ruch5.setCharacterSize(30);
    ruch5.setString(y1);
    ruch5.setPosition(1360 / resolution_mode,150 / resolution_mode);
    sf::Text ruch6 = tekstmenu1.g_text_pve();
    ruch6.setFont(ff);
    ruch6.setCharacterSize(30);
    ruch6.setString(z1);
    ruch6.setPosition(1360  / resolution_mode,700 / resolution_mode);

    Event event;

    while(Wind.isOpen()) {
        Wind.clear(Color::Black);
        Wind.pollEvent(event);
        //txt
        Wind.draw(menu_s);
        Wind.draw(p3);

        //napisy
        Wind.draw(text2);

        //wywietlanie archiwum
        if(x.size()>0)Wind.draw(ruch1);
        if(y.size()>0) Wind.draw(ruch2);
        if(z.size()>0) Wind.draw(ruch3);
        if(x1.size()>0) Wind.draw(ruch4);
        if(y1.size()>0) Wind.draw(ruch5);
        if(z1.size()>0) Wind.draw(ruch6);

        //interakcje

        if(pmenu1.what_if(p3, Wind)){
            return 9;
        }
        Wind.display();
    }
}

//a3

a3::a3() {}

int a3::Run(sf::RenderWindow &Wind) {

    Wind.setFramerateLimit(60);

    //tekstury

    txt_menu menu1;
    Sprite& menu_s= menu1.g_op_tl();
    if(resolution_mode==2)menu_s.setScale(0.5,0.5);

    pola_menu pmenu1;
    Sprite p3;

    p3.setTexture(pmenu1.g_lgw());
    p3.setScale(1./resolution_mode,1./resolution_mode);
    p3.setPosition(40./resolution_mode,1410./resolution_mode);

    //napisy
    font_menu ft;
    Font font1;
    font1.loadFromFile(MY_DEFINE "../font/Manrope-Bold.ttf");

    tekst_menu tekstmenu1(font1);
    sf::Text text2 = tekstmenu1.g_text_return();
    text2.setPosition(120 / resolution_mode,1450 / resolution_mode);

    //wyswietl archiwum
    int pom=0;
    string x,y,z,x1,y1,z1;
    vector<string> a = Display_File(MY_DEFINE "../txt/a3.txt");
    int n=a.size();
    pom_f(x,y,z,x1,y1,z1,pom,a);
    sf::Font ff; ff.loadFromFile(MY_DEFINE "../font/fira.ttf");
    //wyswietlanie ruchow
    sf::Text ruch1 = tekstmenu1.g_text_pve();
    ruch1.setFont(ff);
    ruch1.setCharacterSize(30);
    ruch1.setString(x);
    ruch1.setPosition(120 / resolution_mode,150 / resolution_mode);
    sf::Text ruch2 = tekstmenu1.g_text_pve();
    ruch2.setFont(ff);
    ruch2.setCharacterSize(30);
    ruch2.setString(y);
    ruch2.setPosition(120 / resolution_mode,700 / resolution_mode);
    sf::Text ruch3 = tekstmenu1.g_text_pve();
    ruch3.setFont(ff);
    ruch3.setCharacterSize(30);
    ruch3.setString(z);
    ruch3.setPosition(740 / resolution_mode,150 / resolution_mode);
    sf::Text ruch4 = tekstmenu1.g_text_pve();
    ruch4.setFont(ff);
    ruch4.setCharacterSize(30);
    ruch4.setString(x1);
    ruch4.setPosition(740 / resolution_mode,700 / resolution_mode);
    sf::Text ruch5 = tekstmenu1.g_text_pve();
    ruch5.setFont(ff);
    ruch5.setCharacterSize(30);
    ruch5.setString(y1);
    ruch5.setPosition(1360 / resolution_mode,150 / resolution_mode);
    sf::Text ruch6 = tekstmenu1.g_text_pve();
    ruch6.setFont(ff);
    ruch6.setCharacterSize(30);
    ruch6.setString(z1);
    ruch6.setPosition(1360  / resolution_mode,700 / resolution_mode);

    Event event;

    while(Wind.isOpen()) {
        Wind.clear(Color::Black);
        Wind.pollEvent(event);
        //txt
        Wind.draw(menu_s);
        Wind.draw(p3);

        //napisy
        Wind.draw(text2);

        //wywietlanie archiwum
        if(x.size()>0)Wind.draw(ruch1);
        if(y.size()>0) Wind.draw(ruch2);
        if(z.size()>0) Wind.draw(ruch3);
        if(x1.size()>0) Wind.draw(ruch4);
        if(y1.size()>0) Wind.draw(ruch5);
        if(z1.size()>0) Wind.draw(ruch6);

        //interakcje

        if(pmenu1.what_if(p3, Wind)){
            return 9;
        }
        Wind.display();
    }
}

//a4

a4::a4() {}

int a4::Run(sf::RenderWindow &Wind) {

    Wind.setFramerateLimit(60);

    //tekstury

    txt_menu menu1;
    Sprite& menu_s= menu1.g_op_tl();
    if(resolution_mode==2)menu_s.setScale(0.5,0.5);

    pola_menu pmenu1;
    Sprite p3;

    p3.setTexture(pmenu1.g_lgw());
    p3.setScale(1./resolution_mode,1./resolution_mode);
    p3.setPosition(40./resolution_mode,1410./resolution_mode);

    //napisy
    font_menu ft;
    Font font1;
    font1.loadFromFile(MY_DEFINE "../font/Manrope-Bold.ttf");

    tekst_menu tekstmenu1(font1);
    sf::Text text2 = tekstmenu1.g_text_return();
    text2.setPosition(120 / resolution_mode,1450 / resolution_mode);

    //wyswietl archiwum
    int pom=0;
    string x,y,z,x1,y1,z1;
    vector<string> a = Display_File(MY_DEFINE "../txt/a4.txt");
    int n=a.size();
    pom_f(x,y,z,x1,y1,z1,pom,a);
    sf::Font ff; ff.loadFromFile(MY_DEFINE "../font/fira.ttf");
    //wyswietlanie ruchow
    sf::Text ruch1 = tekstmenu1.g_text_pve();
    ruch1.setFont(ff);
    ruch1.setCharacterSize(30);
    ruch1.setString(x);
    ruch1.setPosition(120 / resolution_mode,150 / resolution_mode);
    sf::Text ruch2 = tekstmenu1.g_text_pve();
    ruch2.setFont(ff);
    ruch2.setCharacterSize(30);
    ruch2.setString(y);
    ruch2.setPosition(120 / resolution_mode,700 / resolution_mode);
    sf::Text ruch3 = tekstmenu1.g_text_pve();
    ruch3.setFont(ff);
    ruch3.setCharacterSize(30);
    ruch3.setString(z);
    ruch3.setPosition(740 / resolution_mode,150 / resolution_mode);
    sf::Text ruch4 = tekstmenu1.g_text_pve();
    ruch4.setCharacterSize(30);
    ruch4.setString(x1);
    ruch4.setPosition(740 / resolution_mode,700 / resolution_mode);
    sf::Text ruch5 = tekstmenu1.g_text_pve();
    ruch5.setFont(ff);
    ruch5.setCharacterSize(30);
    ruch5.setString(y1);
    ruch5.setPosition(1360 / resolution_mode,150 / resolution_mode);
    sf::Text ruch6 = tekstmenu1.g_text_pve();
    ruch6.setFont(ff);
    ruch6.setCharacterSize(30);
    ruch6.setString(z1);
    ruch6.setPosition(1360  / resolution_mode,700 / resolution_mode);

    Event event;

    while(Wind.isOpen()) {
        Wind.clear(Color::Black);
        Wind.pollEvent(event);
        //txt
        Wind.draw(menu_s);
        Wind.draw(p3);

        //napisy
        Wind.draw(text2);

        //wywietlanie archiwum
        if(x.size()>0)Wind.draw(ruch1);
        if(y.size()>0) Wind.draw(ruch2);
        if(z.size()>0) Wind.draw(ruch3);
        if(x1.size()>0) Wind.draw(ruch4);
        if(y1.size()>0) Wind.draw(ruch5);
        if(z1.size()>0) Wind.draw(ruch6);

        //interakcje

        if(pmenu1.what_if(p3, Wind)){
            return 9;
        }

        Wind.display();
    }
}

//a5

a5::a5() {}

int a5::Run(sf::RenderWindow &Wind) {

    Wind.setFramerateLimit(60);

    //tekstury

    txt_menu menu1;
    Sprite& menu_s= menu1.g_op_tl();
    if(resolution_mode==2)menu_s.setScale(0.5,0.5);

    pola_menu pmenu1;
    Sprite p3;

    p3.setTexture(pmenu1.g_lgw());
    p3.setScale(1./resolution_mode,1./resolution_mode);
    p3.setPosition(40./resolution_mode,1410./resolution_mode);

    //napisy
    font_menu ft;
    Font font1;
    font1.loadFromFile(MY_DEFINE "../font/Manrope-Bold.ttf");

    tekst_menu tekstmenu1(font1);
    sf::Text text2 = tekstmenu1.g_text_return();
    text2.setPosition(120 / resolution_mode,1450 / resolution_mode);

    //wyswietl archiwum
    ///

    ///
    vector<string> a = Display_File(MY_DEFINE "../txt/a5.txt");
    int pom=0;
    string x,y,z,x1,y1,z1;
    int n=a.size();
    pom_f(x,y,z,x1,y1,z1,pom,a);
    sf::Font ff; ff.loadFromFile(MY_DEFINE "../font/fira.ttf");
    //wyswietlanie ruchow
    sf::Text ruch1 = tekstmenu1.g_text_pve();
    ruch1.setFont(ff);
    ruch1.setCharacterSize(30);
    ruch1.setString(x);
    ruch1.setPosition(120 / resolution_mode,150 / resolution_mode);
    sf::Text ruch2 = tekstmenu1.g_text_pve();
    ruch2.setFont(ff);
    ruch2.setCharacterSize(30);
    ruch2.setString(y);
    ruch2.setPosition(120 / resolution_mode,700 / resolution_mode);
    sf::Text ruch3 = tekstmenu1.g_text_pve();
    ruch3.setFont(ff);
    ruch3.setCharacterSize(30);
    ruch3.setString(z);
    ruch3.setPosition(740 / resolution_mode,150 / resolution_mode);
    sf::Text ruch4 = tekstmenu1.g_text_pve();
    ruch4.setFont(ff);
    ruch4.setCharacterSize(30);
    ruch4.setString(x1);
    ruch4.setPosition(740 / resolution_mode,700 / resolution_mode);
    sf::Text ruch5 = tekstmenu1.g_text_pve();
    ruch1.setFont(ff);
    ruch5.setCharacterSize(30);
    ruch5.setString(y1);
    ruch5.setPosition(1360 / resolution_mode,150 / resolution_mode);
    sf::Text ruch6 = tekstmenu1.g_text_pve();
    ruch1.setFont(ff);
    ruch6.setCharacterSize(30);
    ruch6.setString(z1);
    ruch6.setPosition(1360  / resolution_mode,700 / resolution_mode);

    Event event;

    while(Wind.isOpen()) {
        Wind.clear(Color::Black);
        Wind.pollEvent(event);
        //txt
        Wind.draw(menu_s);
        Wind.draw(p3);

        //napisy
        Wind.draw(text2);

        //wywietlanie archiwum
        if(x.size()>0)Wind.draw(ruch1);
        if(y.size()>0) Wind.draw(ruch2);
        if(z.size()>0) Wind.draw(ruch3);
        if(x1.size()>0) Wind.draw(ruch4);
        if(y1.size()>0) Wind.draw(ruch5);
        if(z1.size()>0) Wind.draw(ruch6);

        //interakcje
        if(pmenu1.what_if(p3, Wind)){
            return 9;
        }
        Wind.display();
    }
}
///-----------------------------------
void pom_f(string &x,string &y,string &z,string &x1,string &y1,string &z1,int &pom,vector<string> &a) {
    if(a.size()<=20)
        for(int i =0;i<a.size();i++) {
            pom=i;
            x += a[i];
            if(pom%2==1)x+='\n';
            if(pom%2==0)x+="    ";
        }
    else{
        for(int i =0;i<20;i++) {
            pom=i;
            x += a[i];
            if(pom%2==1)x+='\n';
            if(pom%2==0)x+="    ";
        }

        if(a.size()<=40)
            for(int k =20;k<a.size();k++) {
                pom=k;
                y += a[k];
                if(pom%2==1)y+='\n';
                if(pom%2==0)y+="    ";
            }
        else{
            for(int k =20;k<40;k++) {
                pom=k;
                y += a[k];
                if(pom%2==1)y+='\n';
                if(pom%2==0)y+="    ";
            }

            if(a.size()<=60)
                for(int k =40;k<a.size();k++) {
                    pom=k;
                    z += a[k];
                    if(pom%2==1)z+='\n';
                    if(pom%2==0)z+="    ";
                }
            else{
                for(int k =40;k<60;k++) {
                    pom=k;
                    z += a[k];
                    if(pom%2==1)z+='\n';
                    if(pom%2==0)z+="    ";

                }
                if(a.size()<=80)
                    for(int k =60;k<a.size();k++) {
                        pom=k;
                        x1 += a[k];
                        if(pom%2==1)x1+='\n';
                        if(pom%2==0)x1+="    ";
                    }
                else{
                    for(int k =60;k<80;k++) {
                        pom=k;
                        x1 += a[k];
                        if(pom%2==1)x1+='\n';
                        if(pom%2==0)x1+="    ";
                    }
                    if(a.size()<=100)
                        for(int k =80;k<a.size();k++) {
                            pom=k;
                            y1 += a[k];
                            if(pom%2==1)y1+='\n';
                            if(pom%2==0)y1+="    ";
                        }
                    else{
                        for(int k =80;k<100;k++) {
                            pom=k;
                            y1 += a[k];
                            if(pom%2==1)y1+='\n';
                            if(pom%2==0)y1+="    ";
                        }
                        if(a.size()<=120)
                            for(int k =100;k<a.size();k++) {
                                pom=k;
                                z1 += a[k];
                                if(pom%2==1)z1+='\n';
                                if(pom%2==0)z1+="    ";
                            }
                        else {
                            for (int k = 100; k < 120; k++) {
                                pom = k;
                                z1 += a[k];
                                if (pom % 2 == 1)z1 += '\n';
                                if (pom % 2 == 0)z1 += "    ";
                            }
                        }
                    }
                }
            }
        }
    }
}
