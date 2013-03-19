#include "Level.h"

Level::Level(char* _name, vector<LevelObject>* _levelObjects, vector<Event>* _events, Condition* _levelCondition)
:name(_name), levelObjects(_levelObjects), events(_events), levelCondition(_levelCondition)
{}

bool Level::accessible(string& msg){
    return levelCondition->access(msg);
}

void Level::enter(){
    //first check if there are events to be triggered
    for(Event& evt : *events){

    }
}
