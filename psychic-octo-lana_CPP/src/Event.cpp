#include "Event.h"
#include "Game.h"

Event::~Event(){
    delete condition;
    delete dialog;
}

bool Event::trigger(){
    string msg;
    Game* game = Game::instance();
    if(!game->passedEvent(eventID)){
        if(condition->access(msg)){
            startDialog();
            game->addPassedEvent(eventID);
            return true;
        }else{
            Tools::printMsg(msg);
            return false;
        }
    }else{
        return false;
    }
}

void Event::startDialog(){
    dialog->execute();
}
