#include "Game.h"
#include <iostream>
#include <vector>

using namespace std;

Game* Game::_instance = NULL; //initialize static member

int main(){
    Game* game = Game::instance();
    game->enterFirstLevel();
    Tools::gameOver();
    return 0;
}
