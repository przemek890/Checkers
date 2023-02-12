#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "LibrariesAndVariables.hpp"

class tekst_menu {
    //menu glowne
    sf::Text text_game;
    sf::Text text_options;
    sf::Text text_credits;
    sf::Text text_exit;
    sf::Text text_lg;

    //atrybuty
    sf::Text text_board;
    sf::Text text_pawns;
    sf::Text text_game_mode;
    sf::Text text_return;
    sf::Text text_confirm;
    sf::Text text_pvp;
    sf::Text text_pve;

    //napisy
    sf::Text authors;
    sf::Text prze;
    sf::Text jul;
    sf::Text kuba;

    //options
    sf::Text text_attr;
    sf::Text text_arch;
    sf::Text text_rank;
    sf::Text text_acca;

    //account
    sf::Text text_man_your_acc;
    sf::Text chan_log;
    sf::Text chan_pass;

    //first screen
    sf::Text fs_title;
    sf::Text fs_log;
    sf::Text fs_pas;
    sf::Text fs_na;
    sf::Text fs_ex;
    sf::Text fs_con;

    //new account
    sf::Text na_ret;
    sf::Text na_tit;

    //login i haslo
    sf::Text login;
    sf::Text password;

    //ranking
    sf::Text ranking;
    sf::Text position;
    sf::Text nickname;
    sf::Text point;


public:
    tekst_menu(sf::Font& font);

    //menu glowne
    sf::Text& g_text_ga();
    sf::Text& g_text_op();
    sf::Text& g_text_cr();
    sf::Text& g_text_ex();
    sf::Text& g_text_lg();

    //atrybuty
    sf::Text& g_text_board();
    sf::Text& g_text_pawns();
    sf::Text& g_text_game_mode();
    sf::Text& g_text_return();
    sf::Text& g_text_confirm();
    sf::Text& g_text_pvp();
    sf::Text& g_text_pve();

    //napisy
    sf::Text& g_authors();
    sf::Text& g_prze();
    sf::Text& g_jul();
    sf::Text& g_kuba();

    //options
    sf::Text& g_attr();
    sf::Text& g_arch();
    sf::Text& g_rank();
    sf::Text& g_acca();

    //account
    sf::Text& g_man_your_acc();
    sf::Text& g_chan_log();
    sf::Text& g_chan_pass();

    //first screen
    sf::Text& g_fs_title();
    sf::Text& g_fs_log();
    sf::Text& g_fs_pas();
    sf::Text& g_fs_na();
    sf::Text& g_fs_ex();
    sf::Text& g_fs_con();

    //new account
    sf::Text& g_na_ret();
    sf::Text& g_na_tit();

    //login i haslo
    sf::Text& g_login();
    sf::Text& g_password();

    //ranking
    sf::Text& g_ranking();
    sf::Text& g_position();
    sf::Text& g_nickname();
    sf::Text& g_point();

};


