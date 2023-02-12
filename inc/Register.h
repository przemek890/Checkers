#ifndef PROJEKT_IO_REGISTER_H
#define PROJEKT_IO_REGISTER_H
#include "LibrariesAndVariables.hpp"
#include <string>


class User  {
public:
    string login;
    string password;
    int point;
public:
    bool logowanie(User& user,string log, string pass);
    bool rejestracja(User& newUser,string login, string haslo);
    bool ZmianaPasow(User& user,string login, string haslo);
    void Punkty( int wynik);
    vector<User> WypiszTop5();
};

bool exists( string s );
void last_5_game();
void change_filename();
void Oneline(string a);
vector<string> Display_File(string name);

#endif //PROJEKT_IO_REGISTER_H
