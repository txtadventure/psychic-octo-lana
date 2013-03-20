#include "Game.h"
#include <iostream>

using namespace std;

Game* Game::_instance = NULL; //initialize static member

int main(){
    Game* game = Game::instance();
    delete game;

    return 0;
}
