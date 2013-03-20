#include "Game.h"
#include <iostream>

using namespace std;

Game* Game::_instance = NULL; //initialize static member

void Game::gameOver(){
}

int main(){
    Game* game = Game::instance();
    game->printMsg("hello.....");
    delete game;

    return 0;
}
