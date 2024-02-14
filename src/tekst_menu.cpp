#include "tekst_menu.h"
extern unsigned int SCR_W;
extern unsigned int SCR_H;
extern double resolution_mode;


tekst_menu::tekst_menu(sf::Font& font) {
    this->text_game.setFont(font);
    this->text_game.setString("GAME");
    this->text_game.setCharacterSize(130);
    if(resolution_mode != 1) this->text_game.setScale(1./resolution_mode,1./resolution_mode);
    this->text_game.setFillColor(sf::Color::White);
    this->text_game.setStyle(sf::Text::Bold);

    this->text_options.setFont(font);
    this->text_options.setString("OPTIONS");
    this->text_options.setCharacterSize(130);
    if(resolution_mode != 1) this->text_options.setScale(1./resolution_mode,1./resolution_mode);
    this->text_options.setFillColor(sf::Color::White);
    this->text_options.setStyle(sf::Text::Bold);

    this->text_credits.setFont(font);
    this->text_credits.setString("CREDITS");
    this->text_credits.setCharacterSize(130);
    if(resolution_mode != 1) this->text_credits.setScale(1./resolution_mode,1./resolution_mode);
    this->text_credits.setFillColor(sf::Color::White);
    this->text_credits.setStyle(sf::Text::Bold);

    this->text_exit.setFont(font);
    this->text_exit.setString("EXIT");
    this->text_exit.setCharacterSize(130);
    if(resolution_mode != 1) this->text_exit.setScale(1./resolution_mode,1./resolution_mode);
    this->text_exit.setFillColor(sf::Color::White);
    this->text_exit.setStyle(sf::Text::Bold);

    this->text_lg.setFont(font);
    this->text_lg.setString("LOG OUT");
    this->text_lg.setCharacterSize(60);
    if(resolution_mode != 1) this->text_lg.setScale(1./resolution_mode,1./resolution_mode);
    this->text_lg.setFillColor(sf::Color::White);
    this->text_lg.setStyle(sf::Text::Bold);

    //atrybuty
    this->text_board.setFont(font);
    this->text_board.setString("BOARD");
    this->text_board.setCharacterSize(90);
    if(resolution_mode != 1) this->text_board.setScale(1./resolution_mode,1./resolution_mode);
    this->text_board.setFillColor(sf::Color::White);
    this->text_board.setStyle(sf::Text::Bold);

    this->text_pawns.setFont(font);
    this->text_pawns.setString("PAWNS");
    this->text_pawns.setCharacterSize(90);
    if(resolution_mode != 1) this->text_pawns.setScale(1./resolution_mode,1./resolution_mode);
    this->text_pawns.setFillColor(sf::Color::White);
    this->text_pawns.setStyle(sf::Text::Bold);

    this->text_game_mode.setFont(font);
    this->text_game_mode.setString("GAME MODE");
    this->text_game_mode.setCharacterSize(90);
    if(resolution_mode != 1) this->text_game_mode.setScale(1./resolution_mode,1./resolution_mode);
    this->text_game_mode.setFillColor(sf::Color::White);
    this->text_game_mode.setStyle(sf::Text::Bold);


    this->text_return.setFont(font);
    this->text_return.setString("RETURN");
    this->text_return.setCharacterSize(60);
    if(resolution_mode != 1) this->text_return.setScale(1./resolution_mode,1./resolution_mode);
    this->text_return.setFillColor(sf::Color::White);
    this->text_return.setStyle(sf::Text::Bold);

    this->text_confirm.setFont(font);
    this->text_confirm.setString("CONFIRM");
    this->text_confirm.setCharacterSize(60);
    if(resolution_mode != 1) this->text_confirm.setScale(1./resolution_mode,1./resolution_mode);
    this->text_confirm.setFillColor(sf::Color::White);
    this->text_confirm.setStyle(sf::Text::Bold);

    this->text_pvp.setFont(font);
    this->text_pvp.setString("PvP");
    this->text_pvp.setCharacterSize(60);
    if(resolution_mode != 1)this->text_pvp.setScale(1./resolution_mode,1./resolution_mode);
    this->text_pvp.setFillColor(sf::Color::White);
    this->text_pvp.setStyle(sf::Text::Bold);

    this->text_pve.setFont(font);
    this->text_pve.setString("PvE");
    this->text_pve.setCharacterSize(60);
    if(resolution_mode != 1) this->text_pve.setScale(1./resolution_mode,1./resolution_mode);
    this->text_pve.setFillColor(sf::Color::White);
    this->text_pve.setStyle(sf::Text::Bold);

    //credits
    this->authors.setFont(font);
    this->authors.setString("AUTHORS:");
    this->authors.setCharacterSize(60);
    if(resolution_mode != 1) this->authors.setScale(1./resolution_mode,1./resolution_mode);
    this->authors.setFillColor(sf::Color::White);
    this->authors.setStyle(sf::Text::Bold);

    this->prze.setFont(font);
    this->prze.setString("Przemyslaw Janiszewski");
    this->prze.setCharacterSize(60);
    if(resolution_mode != 1) this->prze.setScale(1./resolution_mode,1./resolution_mode);
    this->prze.setFillColor(sf::Color::White);
    this->prze.setStyle(sf::Text::Bold);

    this->jul.setFont(font);
    this->jul.setString("Julia Kluk");
    this->jul.setCharacterSize(60);
    if(resolution_mode != 1) this->jul.setScale(1./resolution_mode,1./resolution_mode);
    this->jul.setFillColor(sf::Color::White);
    this->jul.setStyle(sf::Text::Bold);

    this->kuba.setFont(font);
    this->kuba.setString("Jakub Kleszcz");
    this->kuba.setCharacterSize(60);
    if(resolution_mode != 1) this->kuba.setScale(1./resolution_mode,1./resolution_mode);
    this->kuba.setFillColor(sf::Color::White);
    this->kuba.setStyle(sf::Text::Bold);

    //options
    this->text_attr.setFont(font);
    this->text_attr.setString("ATTRIBUTES");
    this->text_attr.setCharacterSize(130);
    if(resolution_mode != 1) this->text_attr.setScale(1./resolution_mode,1./resolution_mode);
    this->text_attr.setFillColor(sf::Color::White);
    this->text_attr.setStyle(sf::Text::Bold);

    this->text_arch.setFont(font);
    this->text_arch.setString("ARCHIVES");
    this->text_arch.setCharacterSize(130);
    if(resolution_mode != 1) this->text_arch.setScale(1./resolution_mode,1./resolution_mode);
    this->text_arch.setFillColor(sf::Color::White);
    this->text_arch.setStyle(sf::Text::Bold);

    this->text_rank.setFont(font);
    this->text_rank.setString("RANKING");
    this->text_rank.setCharacterSize(130);
    if(resolution_mode != 1) this->text_rank.setScale(1./resolution_mode,1./resolution_mode);
    this->text_rank.setFillColor(sf::Color::White);
    this->text_rank.setStyle(sf::Text::Bold);

    this->text_acca.setFont(font);
    this->text_acca.setString("ACCOUNT");
    this->text_acca.setCharacterSize(60);
    if(resolution_mode != 1) this->text_acca.setScale(1./resolution_mode,1./resolution_mode);
    this->text_acca.setFillColor(sf::Color::White);
    this->text_acca.setStyle(sf::Text::Bold);

    //account
    this->text_man_your_acc.setFont(font);
    this->text_man_your_acc.setString("MANAGE YOUR ACCOUNT");
    this->text_man_your_acc.setCharacterSize(100);
    if(resolution_mode != 1) this->text_man_your_acc.setScale(1./resolution_mode,1./resolution_mode);
    this->text_man_your_acc.setFillColor(sf::Color::White);
    this->text_man_your_acc.setStyle(sf::Text::Bold);

    //first screen
    this->fs_title.setFont(font);
    this->fs_title.setString("SIMPLE CHECKERS");
    this->fs_title.setCharacterSize(130);
    if(resolution_mode != 1) this->fs_title.setScale(1./resolution_mode,1./resolution_mode);
    this->fs_title.setFillColor(sf::Color::White);
    this->fs_title.setStyle(sf::Text::Bold);

    this->fs_log.setFont(font);
    this->fs_log.setString("LOGIN");
    this->fs_log.setCharacterSize(90);
    if(resolution_mode != 1) this->fs_log.setScale(1./resolution_mode,1./resolution_mode);
    this->fs_log.setFillColor(sf::Color::White);
    this->fs_log.setStyle(sf::Text::Bold);

    this->fs_pas.setFont(font);
    this->fs_pas.setString("PASSWORD");
    this->fs_pas.setCharacterSize(90);
    if(resolution_mode != 1) this->fs_pas.setScale(1./resolution_mode,1./resolution_mode);
    this->fs_pas.setFillColor(sf::Color::White);
    this->fs_pas.setStyle(sf::Text::Bold);

    this->fs_ex.setFont(font);
    this->fs_ex.setString("EXIT");
    this->fs_ex.setCharacterSize(70);
    if(resolution_mode != 1) this->fs_ex.setScale(1./resolution_mode,1./resolution_mode);
    this->fs_ex.setFillColor(sf::Color::White);
    this->fs_ex.setStyle(sf::Text::Bold);

    this->fs_con.setFont(font);
    this->fs_con.setString("CONFIRM");
    this->fs_con.setCharacterSize(70);
    if(resolution_mode != 1) this->fs_con.setScale(1./resolution_mode,1./resolution_mode);
    this->fs_con.setFillColor(sf::Color::White);
    this->fs_con.setStyle(sf::Text::Bold);

    this->fs_na.setFont(font);
    this->fs_na.setString("NEW ACCOUNT");
    this->fs_na.setCharacterSize(70);
    if(resolution_mode != 1) this->fs_na.setScale(1./resolution_mode,1./resolution_mode);
    this->fs_na.setFillColor(sf::Color::White);
    this->fs_na.setStyle(sf::Text::Bold);

    //new account
    this->na_ret.setFont(font);
    this->na_ret.setString("RETURN");
    this->na_ret.setCharacterSize(70);
    if(resolution_mode != 1) this->na_ret.setScale(1./resolution_mode,1./resolution_mode);
    this->na_ret.setFillColor(sf::Color::White);
    this->na_ret.setStyle(sf::Text::Bold);

    this->na_tit.setFont(font);
    this->na_tit.setString("CREATE NEW ACCOUNT");
    this->na_tit.setCharacterSize(130);
    if(resolution_mode != 1) this->na_tit.setScale(1./resolution_mode,1./resolution_mode);
    this->na_tit.setFillColor(sf::Color::White);
    this->na_tit.setStyle(sf::Text::Bold);

    //login i haslo

    this->login.setFont(font);
    this->login.setString("");
    this->login.setCharacterSize(90);
    if(resolution_mode != 1) this->login.setScale(1./resolution_mode,1./resolution_mode);
    this->login.setFillColor(sf::Color::White);
    this->login.setStyle(sf::Text::Bold);

    this->password.setFont(font);
    this->password.setString("");
    this->password.setCharacterSize(90);
    if(resolution_mode != 1) this->password.setScale(1./resolution_mode,1./resolution_mode);
    this->password.setFillColor(sf::Color::White);
    this->password.setStyle(sf::Text::Bold);

    //zmiana loginu i hasla
    this->chan_log.setFont(font);
    this->chan_log.setString("CHANGE LOGIN");
    this->chan_log.setCharacterSize(90);
    if(resolution_mode != 1) this->chan_log.setScale(1./resolution_mode,1./resolution_mode);
    this->chan_log.setFillColor(sf::Color::White);
    this->chan_log.setStyle(sf::Text::Bold);

    this->chan_pass.setFont(font);
    this->chan_pass.setString("CHANGE PASSWORD");
    this->chan_pass.setCharacterSize(90);
    if(resolution_mode != 1) this->chan_pass.setScale(1./resolution_mode,1./resolution_mode);
    this->chan_pass.setFillColor(sf::Color::White);
    this->chan_pass.setStyle(sf::Text::Bold);

    //ranking
    this->ranking.setFont(font);
    this->ranking.setString("RANKING");
    this->ranking.setCharacterSize(130);
    if(resolution_mode != 1) this->ranking.setScale(1./resolution_mode,1./resolution_mode);
    this->ranking.setFillColor(sf::Color::White);
    this->ranking.setStyle(sf::Text::Bold);

    this->position.setFont(font);
    this->position.setString("POSITION");
    this->position.setCharacterSize(70);
    if(resolution_mode != 1) this->position.setScale(1./resolution_mode,1./resolution_mode);
    this->position.setFillColor(sf::Color::White);
    this->position.setStyle(sf::Text::Bold);

    this->nickname.setFont(font);
    this->nickname.setString("NICKNAME");
    this->nickname.setCharacterSize(70);
    if(resolution_mode != 1) this->nickname.setScale(1./resolution_mode,1./resolution_mode);
    this->nickname.setFillColor(sf::Color::White);
    this->nickname.setStyle(sf::Text::Bold);

    this->point.setFont(font);
    this->point.setString("POINTS");
    this->point.setCharacterSize(70);
    if(resolution_mode != 1) this->point.setScale(1./resolution_mode,1./resolution_mode);
    this->point.setFillColor(sf::Color::White);
    this->point.setStyle(sf::Text::Bold);


}

sf::Text& tekst_menu::g_text_ga() { return this->text_game;}
sf::Text& tekst_menu::g_text_op() {return this->text_options;}
sf::Text& tekst_menu::g_text_cr() {return this->text_credits;}
sf::Text& tekst_menu::g_text_ex() {return this->text_exit;}
sf::Text& tekst_menu::g_text_lg(){return this->text_lg;}

sf::Text& tekst_menu::g_text_board() {return this->text_board;}
sf::Text& tekst_menu::g_text_pawns() {return  this->text_pawns;}
sf::Text& tekst_menu::g_text_game_mode() {return this->text_game_mode;}
sf::Text& tekst_menu::g_text_return() { return this->text_return; }
sf::Text& tekst_menu::g_text_confirm() { return this->text_confirm;}
sf::Text& tekst_menu::g_text_pvp() { return this->text_pvp;}
sf::Text& tekst_menu::g_text_pve() { return this->text_pve;}

sf::Text& tekst_menu::g_authors() {return this->authors;}
sf::Text& tekst_menu::g_prze() {return this->prze;}
sf::Text& tekst_menu::g_jul() {return this->jul;}
sf::Text& tekst_menu::g_kuba() {return this->kuba;}

sf::Text& tekst_menu::g_attr() {return this->text_attr;}
sf::Text& tekst_menu::g_arch() {return this->text_arch;}
sf::Text& tekst_menu::g_rank() {return this->text_rank;}
sf::Text& tekst_menu::g_acca() {return this->text_acca;}

sf::Text& tekst_menu::g_man_your_acc() {return  this->text_man_your_acc;}
sf::Text& tekst_menu::g_chan_log() {return this->chan_log;}
sf::Text& tekst_menu::g_chan_pass() {return this->chan_pass;}

sf::Text& tekst_menu::g_fs_title(){return  this->fs_title;}
sf::Text& tekst_menu:: g_fs_log(){return this->fs_log;};
sf::Text& tekst_menu::g_fs_pas(){return this->fs_pas; };
sf::Text& tekst_menu::g_fs_na() {return this->fs_na;}
sf::Text& tekst_menu::g_fs_con() {return this->fs_con;}
sf::Text& tekst_menu::g_fs_ex() {return this->fs_ex;}

sf::Text& tekst_menu::g_na_tit() {return this->na_tit;}
sf::Text& tekst_menu::g_na_ret() {return this->na_ret;}

sf::Text& tekst_menu::g_login() {return this->login;}
sf::Text& tekst_menu::g_password() {return this->password;}

sf::Text& tekst_menu::g_ranking() {return  this->ranking;}
sf::Text& tekst_menu::g_position() {return this->position;}
sf::Text& tekst_menu::g_nickname() {return this->nickname;}
sf::Text& tekst_menu::g_point() {return this->point;}
