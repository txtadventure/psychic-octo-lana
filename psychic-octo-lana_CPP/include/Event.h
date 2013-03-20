#ifndef EVENT_H
#define EVENT_H

#include "Condition.h"

class Event
{
    public:
        Event();
    private:
        Condition* condition;
};

#endif // EVENT_H
