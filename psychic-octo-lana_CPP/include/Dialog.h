#ifndef DIALOG_H
#define DIALOG_H

#include <functional>

class LevelObject;
class Event;

using namespace std;

class Dialog
{
public:
    Dialog():lvlObjParent(0), evtParent(0){}
    Dialog(Event* evt):lvlObjParent(0), evtParent(evt){}
    Dialog(LevelObject* lvlObj):lvlObjParent(lvlObj), evtParent(0){}
    LevelObject* lvlObjParent;
    Event* evtParent;
    void setRunFunc(function<void()> handler_func){
        _handler_func = handler_func;
    }
    void execute(){_handler_func();}
    void setParentLevelObject(LevelObject* lvlObj){lvlObjParent = lvlObj;}
    void setParentEvent(Event* evtPtr){evtParent = evtPtr;}
private:
    function<void()> _handler_func;
};

#endif // DIALOG_H
