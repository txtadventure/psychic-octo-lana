#ifndef LEVELOBJECT_H
#define LEVELOBJECT_H

class Dialog;

class LevelObject
{
    public:
        LevelObject(int _objectID, char* _name):objectID(_objectID), name(_name), _isPresent(true){}
        ~LevelObject();
        bool isPresent() const {return _isPresent;}
        void setPresence(int presence) {_isPresent = presence;}
        char* getName() const {return name;}
        void setDialog(Dialog* dia){dialog = dia;}
        void startDialog();
    private:
        char* name;
        int objectID;
        bool _isPresent;
        Dialog* dialog;
};

#endif // LEVELOBJECT_H
