#include "LevelFactory.h"
#include <vector>
#include "Event.h"
#include "LevelObject.h"
#include "Level.h"
#include "Condition.h"
#include "EventFactory.h"
#include "LevelObjectFactory.h"

using namespace std;

Level* LevelFactory::buildLevel1(){
    Level* level1 = new Level("FMI Building", new vector<LevelObject*>{
                                LevelObjectFactory::produceLvlObj(LevelObjectFactory::OBJ1),
                              LevelObjectFactory::produceLvlObj(LevelObjectFactory::OBJ1),
                              LevelObjectFactory::produceLvlObj(LevelObjectFactory::OBJ1)
                              },
                            new vector<Event*>{
                                EventFactory::produceEvent(EventFactory::EVENT1)
                            },
                            new Condition(new vector<int>{}, new vector<int>{}, 0, 0));
    return level1;
}

