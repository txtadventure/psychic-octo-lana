#include "Level.h"
#include <sstream>

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

    //first check if there are events to be triggered
    if(!events->empty()){
        for(Event* evt : *events){
            evt->trigger();
        }
    }


    //then list all LevelObjects
    if(!levelObjects->empty()){
        ostringstream ss;
        for(int i=0;i<levelObjects->size();i++){
            ss << i << ": " << Level::levelObjects->at(i).getName() << endl;
        }
        string str = ss.str();

        int choice = game->printChoice(str);
        LevelObject& lvlObj = Level::levelObjects->at(choice);
        lvlObj.startDialog();
    }else{
        game->printMsg("There are no objects in this level...");
    }

    //finally list neighbours
    if(!neighbourLevels->empty()){
        ostringstream ss;
        ss.clear();
        ss << "Choose where to go:" << endl;
        for(int i=0;i<neighbourLevels->size();i++){
            ss << i << ": " << neighbourLevels->at(i).getName() << endl;
        }
        string str = ss.str();
        int choice = game->printChoice(str);
        Level& lvl = Level::getNeighbourLevels()->at(choice);
        lvl.enter();
    }else{
        game->printMsg("You can go nowhere...");
    }
}
