#include "Game.h"
#include <iostream>
#include "Tools.h"

using namespace std;

void Game::printMsg(const string& msg){
    Tools::printMsg(msg, player);
}

int main(){
    Game* game = Game::instance();
    game->printMsg("But are you using Unix or Windows? Because #include <windows.h> with Sleep(milliseconds) in Windows or #include <unistd.h> with sleep(milliseconds) in Unix is simpler and more reliable. The sleep function you show that uses clock_t instead of time_t does not count in seconds or milliseconds but in system clock ticks. This varies from system to system so the pause duration is not consistent across systems (if consistency matters).");
    return 0;
}
