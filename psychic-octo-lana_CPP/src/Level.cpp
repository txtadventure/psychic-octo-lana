#include "Level.h"
#include <sstream>
#include <vector>

#include "Game.h"
#include "Tools.h"
#include "Player.h"

using namespace std;

Level::Level(char* _name, vector<LevelObject>* _levelObjects, vector<Event*>* _events, Condition* _levelCondition)
:name(_name), levelObjects(_levelObjects), events(_events), levelCondition(_levelCondition), neighbourLevels(new vector<Level>{})
{}

bool Level::accessible(string& msg){
    return levelCondition->access(msg);
}

void Level::enter(){
    Game* game = Game::instance();
    //set new current level of player
    game->getPlayer()->setCurrentLevel(this);
    game->printStatusBar();
    //first check if there are events to be triggered
    if(!events->empty()){
        for(Event* evt : *events){
            evt->trigger();
        }
    }


    //give the player a choice of levelObjects to interact with
    if(!levelObjects->empty()){
        vector<string> levelObjs;
        for(int i=0;i<levelObjects->size();i++){
            levelObjs.push_back(levelObjects->at(i).getName());
        }

        int choice = game->printChoice("Choose an object to interact with:", levelObjs);
        LevelObject& lvlObj = Level::levelObjects->at(choice);
        lvlObj.startDialog();
    }else{
        game->printMsg("There are no objects in this level...");
    }

    //finally list neighbours
    if(!neighbourLevels->empty()){
        vector<string> neighLvls;
        for(int i=0;i<neighbourLevels->size();i++){
            neighLvls.push_back(neighbourLevels->at(i).getName());
        }
        int choice = game->printChoice("Go to:", neighLvls);
        Level& lvl = Level::getNeighbourLevels()->at(choice);
        lvl.enter();
    }else{
        game->printMsg("You can go nowhere...");
    }
}
