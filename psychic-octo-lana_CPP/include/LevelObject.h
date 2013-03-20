#ifndef LEVELOBJECT_H
#define LEVELOBJECT_H

class Dialog;

class LevelObject
{
    public:
        LevelObject(char* _name, Dialog* _dialog):name(_name),dialog(_dialog),_isPresent(true){}
        bool isPresent() const {return _isPresent;}
        void setPresence(bool presence) {_isPresent = presence;}
        char* getName() const {return name;}
        void startDialog();
    private:
        char* name;
        bool _isPresent;
        Dialog* dialog;
};

#endif // LEVELOBJECT_H
