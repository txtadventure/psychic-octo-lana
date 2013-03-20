#ifndef DIALOG_H
#define DIALOG_H

#include <functional>

#include "LevelObject.h"

using namespace std;

class Dialog
{
public:
    LevelObject* parent;
    Dialog(LevelObject* _levelObject):parent(_levelObject){}
    void setRunFunc(function<void()> handler_func){
        _handler_func = handler_func;
    }
    void execute(){_handler_func();}
private:
    function<void()> _handler_func;
};

#endif // DIALOG_H
