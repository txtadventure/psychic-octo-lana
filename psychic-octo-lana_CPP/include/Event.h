#ifndef EVENT_H
#define EVENT_H

#include "Condition.h"
#include "Dialog.h"

class Event
{
    public:
        Event(Condition* cond, Dialog* dia, int _eventID):condition(cond), dialog(dia), eventID(_eventID){}
        bool trigger();
        void startDialog();
    private:
        int eventID;
        Condition* condition;
        Dialog* dialog;
};

#endif // EVENT_H
