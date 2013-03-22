#include "Game.h"
#include <iostream>
#include <vector>

using namespace std;

Game* Game::_instance = NULL; //initialize static member

int main(){
    Game::startGame();
    Tools::gameOver();
    return 0;
}
