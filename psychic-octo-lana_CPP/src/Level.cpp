#include "Level.h"
#include <sstream>

#include "Game.h"
#include "Tools.h"
#include "Player.h"

using namespace std;

Level::Level(char* _name, vector<LevelObject>* _levelObjects, vector<Event>* _events, Condition* _levelCondition)
:name(_name), levelObjects(_levelObjects), events(_events), levelCondition(_levelCondition)
{}

bool Level::accessible(string& msg){
    return levelCondition->access(msg);
}

void Level::enter(){
    Game* game = Game::instance();
    //set new current level of player
    game->getPlayer()->setCurrentLevel(this);

    //first check if there are events to be triggered
    for(Event& evt : *events){
        evt.trigger();
    }

    //then list all LevelObjects
    ostringstream ss;
    for(int i=0;i<levelObjects->size();i++){
        ss << i << ": " << Level::levelObjects->at(i).getName() << endl;
    }
    string str = ss.str();

    int choice = game->printChoice(str);
    LevelObject& lvlObj = Level::levelObjects->at(choice);
    lvlObj.startDialog();

    //finally list neighbours
    ss.clear();
    ss << "Choose where to go:" << endl;
    for(int i=0;i<Level::getNeighbourLevels()->size();i++){
        ss << i << ": " << Level::levelObjects->at(i).getName() << endl;
    }
    str = ss.str();
    choice = game->printChoice(str);
    Level& lvl = Level::getNeighbourLevels()->at(choice);
    lvl.enter();
}
