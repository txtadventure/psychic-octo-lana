#include "Game.h"
#include <iostream>

using namespace std;

Game* Game::_instance = NULL; //initialize static member

int main(){
    Game* game = Game::instance();
    Item* verysexy = ItemFactory::produceItem(ItemFactory::PENIS);
    delete game;

    return 0;
}
