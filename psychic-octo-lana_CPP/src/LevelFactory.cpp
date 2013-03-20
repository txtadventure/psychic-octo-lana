#include "LevelFactory.h"
#include <vector>
#include "Event.h"
#include "LevelObject.h"
#include "Level.h"
#include "Condition.h"
#include "EventFactory.h"

using namespace std;

Level* LevelFactory::buildLevel1(){
    Level* level1 = new Level("FMI Building", new vector<LevelObject>{},
                            new vector<Event*>{
                                EventFactory::produceEvent(EventFactory::EVENT1)
                            },
                            new Condition(new vector<int>{}, new vector<int>{}, 0, 0));
    return level1;
}

