#include "Level.h"
#include <sstream>
#include <vector>

#include "Game.h"
#include "Tools.h"
#include "Player.h"

using namespace std;

Level::Level(char* _name, vector<LevelObject*>* _levelObjects, vector<Event*>* _events, Condition* _levelCondition)
:name(_name), levelObjects(_levelObjects), events(_events), levelCondition(_levelCondition), neighbourLevels(new vector<Level*>{})
{}

Level::~Level(){
    for(LevelObject* lvlObj : *levelObjects){delete lvlObj;}
    for(Event* evt : *events){delete evt;}
    delete levelCondition;
    delete neighbourLevels;
}

bool Level::accessible(string& msg){
    return levelCondition->access(msg);
}

void Level::enter(){
    Game* game = Game::instance();
    //set new current level of player
    game->getPlayer()->setCurrentLevel(this);
    Tools::printStatusBar();
    //first check if there are events to be triggered
    while(true){
    if(!events->empty()){
        for(Event* evt : *events){
            evt->trigger();
        }
    }


    //give the player a choice of levelObjects to interact with
    if(!levelObjects->empty()){
        vector<string> levelObjs;
        for(int i=0;i<levelObjects->size();i++){
            if(levelObjects->at(i)->isPresent())
                levelObjs.push_back(levelObjects->at(i)->getName());
        }

        int choice = Tools::printChoice("Choose an object to interact with:", levelObjs);
        LevelObject* lvlObj = levelObjects->at(choice);
        lvlObj->startDialog();
    }else{
        Tools::printMsg("There are no objects in this level...");
    }

    //finally list neighbours
    if(!neighbourLevels->empty()){
        vector<string> neighLvls;
        for(int i=0;i<neighbourLevels->size();i++){
            neighLvls.push_back(neighbourLevels->at(i)->getName());
        }
        int choice = Tools::printChoice("Go to:", neighLvls);
        Level* lvl = getNeighbourLevels()->at(choice);
        lvl->enter();
    }else{
        Tools::printMsg("You can go nowhere...");
    }
    }
}
