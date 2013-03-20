#include "Event.h"
#include "Game.h"

bool Event::trigger(){
    string msg;
    Game* game = Game::instance();
    if(!game->passedEvent(eventID)){
        if(condition->access(msg)){
            startDialog();
            game->addPassedEvent(eventID);
        }else{
            game->printMsg(msg);
        }
    }
}

void Event::startDialog(){
    dialog->execute();
}
