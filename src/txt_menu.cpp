#include "txt_menu.h"

txt_menu::txt_menu(){
    this->tl.loadFromFile("../data/mp.as/tlo2.png");
    this->op_tl.loadFromFile("../data/mp.as/tlo3.png");
}

sf::Sprite& txt_menu:: g_tl(){
    this->tl_sp.setTexture(this->tl);
    return tl_sp;
}

sf::Sprite& txt_menu::g_op_tl() {
    this->op_tl_sp.setTexture(this->op_tl);
    return op_tl_sp;
}