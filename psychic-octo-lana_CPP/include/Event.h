#ifndef EVENT_H
#define EVENT_H

#include "Condition.h"
#include "Dialog.h"

class Event
{
    public:
        Event(int _eventID):eventID(_eventID){}
        bool trigger();
        void startDialog();
        void setCondition(Condition* cond){condition = cond;}
        void setDialog(Dialog* dia){dialog = dia;}
    private:
        int eventID;
        Condition* condition;
        Dialog* dialog;
};

#endif // EVENT_H
