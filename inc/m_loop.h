#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "screen.h"


using namespace std;
using namespace sf;

class m_loop : public screen{
public:
    m_loop();
    int Run(RenderWindow &Wind);
};

class opcje_loop : public screen{
public:
    opcje_loop();
    int Run(RenderWindow &Wind);
};

class credits : public screen {

public:
    credits();
    int Run(RenderWindow &Wind);
};

class options : public screen{
public:
    options();
    int Run(RenderWindow &Wind);
};

class account : public screen {
public:
    account();
    int Run(RenderWindow &Wind);

};

class firstscreen : public screen{
public:
    firstscreen();
    int Run(RenderWindow &Wind);
};

class new_account: public screen {
    public:
    new_account();
    int Run(RenderWindow &Wind);
};

class ranking: public screen{
public:
    ranking();
    int Run(RenderWindow &Wind);

};

class arch: public screen{
public:
    arch();
    int Run(RenderWindow &Wind);

};

class a1: public screen{
    public:
    a1();
    int Run(RenderWindow &Wind);
};

class a2: public screen{
public:
    a2();
    int Run(RenderWindow &Wind);
};

class a3: public screen{
public:
    a3();
    int Run(RenderWindow &Wind);
};

class a4: public screen{
public:
    a4();
    int Run(RenderWindow &Wind);
};

class a5: public screen{
public:
    a5();
    int Run(RenderWindow &Wind);
};

void pom_f(string &x,string &y,string &z,string &x1,string &y1,string &z1,int &pom,vector<string> &a);