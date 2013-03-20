#include "Event.h"
#include "Game.h"

bool Event::trigger(){
    string msg;
    Game* game = Game::instance();
    if(!game->passedEvent(eventID)){
        if(condition->access(msg)){
            startDialog();
            game->addPassedEvent(eventID);
            return true;
        }else{
            game->printMsg(msg);
            return false;
        }
    }else{
        return false;
    }
}

void Event::startDialog(){
    dialog->execute();
}
