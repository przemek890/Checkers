#include <fstream>
#include "LibrariesAndVariables.hpp"
#include "Register.h"

string GLOBALogin = "";
string GLOBALpassword ="";
int GLOBALpoint = 0;



//metody do Usera
bool User::logowanie(User& user,string log, string pass) {

    // Otwieramy plik
   std::ifstream in(MY_DEFINE "../txt/USERS.txt",ios::in);

    while (!in.eof()) {
        // Odczytujemy linię z danymi użytkownika
        string line;
        getline(in, line);

        // Jeśli linia jest pusta, to przeskakujemy do kolejnej iteracji
        if (line.empty()) continue;

        // Rozdzielamy dane użytkownika na osobne pola (username i password)
        // korzystając z separatora ","

        size_t login_end = line.find(",");
        size_t password_start = login_end + 1;
        size_t password_end = line.find(":", password_start);
        size_t number_start = password_end + 1;
        size_t number_end = line.find(";", number_start);

        string fileUsername = line.substr(0, login_end);
        string filePassword = line.substr(password_start, (password_end - password_start));
        string filePoint = line.substr(number_start, (number_end - number_start));
        // Jeśli odczytane dane z pliku zgadzają się z podanymi przez użytkownika,
        // to zwracamy true (udane logowanie)
        if (log == "<xxx>" && pass == "<xxx>") return false; // nie mozna zalogowac sie na puste konto - sluzy jedynie do wyswietlania wynikow
        else if (fileUsername == log && filePassword == pass) {
            GLOBALogin = log;
            GLOBALpassword = pass;
            GLOBALpoint = stoi(filePoint);
            return true;
        }
    }
    return false;       //jesli po przejsciu calego pliku nie znajdziemy loginu i haslo zwracamy falsz
}

bool User::rejestracja(User& newUser,string login, string haslo) {
    int point=0;
    //sprawdzamy czy uzytkownik o takich danych istnieje
    // Otwieramy plik
    std::ifstream in(MY_DEFINE "../txt/USERS.txt",ios::in);
    while (!in.eof()) {
        // Odczytujemy linię z danymi użytkownika
        string line;
        getline(in, line);

        // Rozdzielamy dane użytkownika na osobne pola (username i password)
        // korzystając z separatora ","

        size_t login_end = line.find(",");
        string fileUsername = line.substr(0, login_end);

        // Jeśli odczytane dane z pliku zgadzają się z podanymi przez użytkownika,
        // to zwracamy true (udane logowanie)
        if (fileUsername == login) {
            return false;
        }
    }

    // Otwieramy plik
    ofstream out(MY_DEFINE "../txt/USERS.txt", ios::out|ios::app);
    // Zapisujemy dane użytkownika do pliku
    out << login << "," << haslo << ":" << point << ";" << endl;
    out.close();
    GLOBALogin=login;
    GLOBALpassword=haslo;
    GLOBALpoint=point;
    return true;
}

bool User::ZmianaPasow(User& user,string login, string haslo) {

    ifstream plik(MY_DEFINE "../txt/USERS.txt",ios::in);

    // Odczytanie całego pliku do wektora linii
    vector<string> ZawBazy;
    string linia;
    while (std::getline(plik, linia)) {
        ZawBazy.push_back(linia);
    }
    plik.close();

    string a,b;
    int newPoints;
    for (auto it = ZawBazy.begin(); it != ZawBazy.end();) {
        if (it->find(GLOBALogin) != string::npos && it->find(GLOBALpassword) != string::npos) {
            a=GLOBALogin;
            b=GLOBALpassword;
            newPoints = GLOBALpoint;
            it = ZawBazy.erase(it);
        }
        else {
            ++it;
        }
    }

    remove(MY_DEFINE "../txt/USERS.txt");

    // Otwieranie nowego pliku w trybie zapisu
    ofstream nowy_plik(MY_DEFINE "../txt/USERS.txt",ios::out);

    // Zapisanie pozostałych linii do nowego pliku
    for (const string& l : ZawBazy) {
        nowy_plik << l << endl;
    }
    nowy_plik.close();

    //jesli uzytkownik o takim loginie istnieje to odrzucamy zmiane i pozostaje takie samo haslo oraz login
    bool pom= true;
    std::ifstream in(MY_DEFINE "../txt/USERS.txt",ios::in);
    while (!in.eof()) {
        // Odczytujemy linię z danymi użytkownika
        string line;
        getline(in, line);

        size_t login_end = line.find(",");
        string fileUsername = line.substr(0, login_end);

        if (fileUsername == login) {
            pom= false;
            cout<<"takie same"<<endl;
            break;
        }
    }

    pom ? (GLOBALogin = login):(login=GLOBALogin);
    pom ? (GLOBALpassword = haslo):(haslo=GLOBALpassword);
    // Otwieramy plik
    ofstream out(MY_DEFINE "../txt/USERS.txt", ios::out|ios::app);
    // Zapisujemy dane użytkownika do pliku
    out << login << "," << haslo << ":" << newPoints << ";" << endl;
    out.close();
    return pom;

}

//zliczanie punktow
void User::Punkty( int wynik) {

    ifstream plik(MY_DEFINE "../txt/USERS.txt",ios::in);
    // Odczytanie całego pliku do wektora linii
    vector<string> ZawBazy;
    string linia;
    while (std::getline(plik, linia)) {
        ZawBazy.push_back(linia);
    }
    plik.close();

    int newPoints;
    for (auto it = ZawBazy.begin(); it != ZawBazy.end();) {
        if (it->find(GLOBALogin) != string::npos && it->find(GLOBALpassword) != string::npos) {
            newPoints = GLOBALpoint;
            it = ZawBazy.erase(it);
        }
        else {
            ++it;
        }
    }

    remove(MY_DEFINE "../txt/USERS.txt");

    // Otwieranie nowego pliku w trybie zapisu
    ofstream nowy_plik(MY_DEFINE "../txt/USERS.txt",ios::out);

    // Zapisanie pozostałych linii do nowego pliku
    for (const string& l : ZawBazy) {
        nowy_plik << l << endl;
    }
    nowy_plik.close();

    if(wynik==2) newPoints+=10; //wygrana
    else if(wynik==1) newPoints+=5; //remis
    else { newPoints+=-10; //przegrana
    cout<<"Przegrales"<<endl; }

    GLOBALpoint=newPoints;
    // Otwieramy plik
    ofstream out(MY_DEFINE "../txt/USERS.txt", ios::out|ios::app);
    // Zapisujemy dane użytkownika do pliku
    out << GLOBALogin << "," << GLOBALpassword << ":" << GLOBALpoint << ";" << endl;
    out.close();

}

//do metody WypiszTop5
bool compare(const User& a, const User& b) {
    if(a.login == "<xxx>") return false;
    else if (b.login == "<xxx>") return true;
    else return a.point > b.point;
}

vector<User> User::WypiszTop5() {

    vector <User> uzyt;

    ifstream file(MY_DEFINE "../txt/USERS.txt",ios::out);
    string line;
    while (getline(file, line)) {

        //Wyciagamy dane: login i point
        size_t login_end = line.find(",");
        size_t password_start = login_end + 1;
        size_t password_end = line.find(":", password_start);
        size_t number_start = password_end + 1;
        size_t number_end = line.find(";", number_start);

        string fileLogin = line.substr(0, login_end);
        string filePoint = line.substr(number_start, (number_end - number_start));
        int punkty = stoi(filePoint);

        //dodajemy uzytkownika do vectora
        User user;
        user.login = fileLogin;
        user.point = punkty;
        uzyt.push_back(user);
    }
    //sortujemy wpisanych do vectora uzytkownikow wedlug ilosci punktow
    sort(uzyt.begin(), uzyt.end(), compare);


    for (int i = 0; i < 5;i++) {
        cout << "[" << i + 1 << "] " << uzyt[i].login << ": " << uzyt[i].point << endl;
    }
    return uzyt;
}

bool exists( string s ) {
    ifstream ifs( s );
    if( !ifs.good() ) return false;

    ifs.close();
    return true;
}

void last_5_game(){
    if(exists(MY_DEFINE "../txt/a6.txt")){
        remove(MY_DEFINE "../txt/a1.txt");
        rename(MY_DEFINE "../txt/a2.txt",MY_DEFINE "../txt/a1.txt"); //stara nazwa, nowa nazwa
        rename(MY_DEFINE "../txt/a3.txt",MY_DEFINE "../txt/a2.txt");
        rename(MY_DEFINE "../txt/a4.txt",MY_DEFINE "../txt/a3.txt");
        rename(MY_DEFINE "../txt/a5.txt",MY_DEFINE "../txt/a4.txt");
        rename(MY_DEFINE "../txt/a6.txt",MY_DEFINE "../txt/a5.txt");
    }

}

void change_filename(){//do testu

  if(!exists(MY_DEFINE "../txt/a1.txt")) rename(MY_DEFINE "../txt/test1.txt",MY_DEFINE "../txt/a1.txt");
  else {
      if (!exists(MY_DEFINE "../txt/a2.txt")) rename(MY_DEFINE "../txt/test1.txt", MY_DEFINE "../txt/a2.txt");
      else{
          if (!exists(MY_DEFINE "../txt/a3.txt")) rename(MY_DEFINE "../txt/test1.txt", MY_DEFINE "../txt/a3.txt");
          else{
              if (!exists(MY_DEFINE "../txt/a4.txt")) rename(MY_DEFINE "../txt/test1.txt", MY_DEFINE "../txt/a4.txt");
              else{
                  if (!exists(MY_DEFINE "../txt/a5.txt")) rename(MY_DEFINE "../txt/test1.txt", MY_DEFINE "../txt/a5.txt");
                  else{
                      if (!exists(MY_DEFINE "../txt/a6.txt")) rename(MY_DEFINE "../txt/test1.txt", MY_DEFINE "../txt/a6.txt");
                  }
              }
          }


      }
  }
    remove(MY_DEFINE "../txt/test1.txt");
}


void Oneline(string a){ //linijka do dodania



    //dodanie linii
    ofstream nowy_plik(MY_DEFINE "../txt/test1.txt",ios::out|ios::app);

    nowy_plik << a << endl;

    nowy_plik.close();
}

vector<string> Display_File(string name){
    vector <string> linie;

    ifstream file(name,ios::out);
    string line;
    while (getline(file, line)) {
        cout<<line<<endl;
        linie.push_back(line);
    }
    return linie;
}