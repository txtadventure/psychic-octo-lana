#include "EventFactory.h"
#include <vector>
#include <memory>

#include "Dialog.h"
#include "Condition.h"
#include "Event.h"
#include "Game.h"

Event* EventFactory::produceEvent(int eventID)
{
    switch(eventID){
    case EVENT1 : {Event* evt = new Event(EVENT1);
                                Condition* cond = new Condition(new vector<int>{},new vector<int>{},0,0);
                                Dialog* d = new Dialog(evt);
                                std::shared_ptr<Dialog> ptr = std::shared_ptr<Dialog>(d);
                                d->setRunFunc(
                                                [ptr](){
                                                    Tools::printMsg("Welcome to your first Event!");
                                                }
                                                );
                                evt->setCondition(cond);
                                evt->setDialog(d);
                                return evt;
    }
    default:break;
    }
    return 0;
}
