#include "Game.h"
#include <iostream>
#include <vector>

using namespace std;

Game* Game::_instance = NULL; //initialize static member

void Game::gameOver(){
}

int main(){
    Game* game = Game::instance();
    game->enterFirstLevel();
    return 0;
}
