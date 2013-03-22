#ifndef LEVEL_H
#define LEVEL_H
#include <vector>
#include "LevelObject.h"
#include "Event.h"
#include "Condition.h"

using namespace std;

class Level
{
    public:
        Level(char* _name, vector<LevelObject*>* _levelObjects, vector<Event*>* _events, Condition* _levelCondition);
        ~Level();
        vector<LevelObject*>* getLevelObjects(){return levelObjects;}
        vector<Event*>* getEvents(){return events;}
        vector<Level*>* getNeighbourLevels(){return neighbourLevels;}
        void addNeighbourLevel(Level* neighbourLevel){neighbourLevels->push_back(neighbourLevel);}
        //msg is the message returned if the level is not accessible
        bool accessible(string& msg);
        char* getName(){return name;}
        void enter();
    private:
        char* name;
        vector<LevelObject*>* levelObjects;
        vector<Event*>* events;
        vector<Level*>* neighbourLevels;
        Condition* levelCondition;
};

#endif // LEVEL_H
