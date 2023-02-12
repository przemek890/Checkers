#include "Board.hpp"
#include "Board.cpp"
#include "Functions.cpp"
#include "Game_loop.cpp"
#include "Engine.cpp"
#include "AI.cpp"
#include "m_loop.h"
#include "screen.h"

///komentować zamykanie okna z uzyciem sfmla w Mac Os'ie, w pliku m_loop.cpp
//if(event.type == Event::Closed){
//return -1;
//}

int main() {

    vector<screen*> Ss;
    int okno = 6;

    //generowanie okna gry
    RenderWindow wind(sf::VideoMode(2000 / resolution_mode, 1600 / resolution_mode), "Simple Checkers",5);

   //menu_glowne -0
   m_loop men;
   Ss.push_back(&men);

   //atrybuty -1
   opcje_loop opc;
   Ss.push_back(&opc);

   //credits -2
   credits cre;
   Ss.push_back(&cre);

   //options -3
   options opt;
   Ss.push_back(&opt);

   //account -4
   account acc;
   Ss.push_back(&acc);

   //play -5
   Plansza pl;
   Ss.push_back(&pl);

   //pierwszy ekran -6
   firstscreen fs;
   Ss.push_back(&fs);

   //create new account -7
   new_account na;
   Ss.push_back(&na);

   //ranking -8
   ranking rk;
   Ss.push_back(&rk);

   //archiwum -9
   arch ar;
   Ss.push_back(&ar);

    //archiwum a1 -10
    a1 arch1;
    Ss.push_back(&arch1);

    //archiwum a2 -11
    a2 arch2;
    Ss.push_back(&arch2);

    //archiwum a3 -12
    a3 arch3;
    Ss.push_back(&arch3);

    //archiwum a4 -13
    a4 arch4;
    Ss.push_back(&arch4);

    //archiwum a5 -14
    a5 arch5;
    Ss.push_back(&arch5);

   //zmiana okien
   while(okno>=0){

       okno = Ss[okno]->Run(wind);

   }

}