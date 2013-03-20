#include "LevelFactory.h"
#include <vector>
#include "Event.h"
#include "LevelObject.h"
#include "Level.h"
#include "Condition.h"

using namespace std;

Level* LevelFactory::buildLevel1(){
    Level* level1 = new Level("FMI Building", new vector<LevelObject>{}, new vector<Event>{}, new Condition(new vector<int>(0), new vector<int>(0), 0, 0));
    return level1;
}

