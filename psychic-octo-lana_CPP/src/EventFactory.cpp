#include "EventFactory.h"
#include <vector>

#include "Dialog.h"
#include "Condition.h"
#include "Event.h"
#include "Game.h"

Event* EventFactory::produceEvent(int eventID)
{
    switch(eventID){
    case EventFactory::EVENT1 : {Event* evt = new Event(0);
                                Condition* cond = new Condition(new vector<int>{},new vector<int>{},0,0);
                                Dialog* dia = new Dialog(evt);
                                dia->setRunFunc(
                                                [&dia](){
                                                    Game::instance()->printMsg("Welcome to your first Event!");
                                                }
                                                );
                                evt->setCondition(cond);
                                evt->setDialog(dia);
                                return evt;
    }
    default:break;
    }
    return 0;
}
