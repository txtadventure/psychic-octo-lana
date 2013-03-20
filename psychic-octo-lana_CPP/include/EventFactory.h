#ifndef EVENTFACTORY_H
#define EVENTFACTORY_H

#include "Event.h"

class EventFactory
{
    public:
        static const int EVENT1 = 0;
        static Event* produceEvent(int eventID);
};

#endif // EVENTFACTORY_H
