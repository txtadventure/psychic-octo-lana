#ifndef LEVELOBJECT_H
#define LEVELOBJECT_H

class Dialog;

class LevelObject
{
public :
    LevelObject(char* _name, Dialog* _dialog):name(_name),dialog(_dialog), present(true){}
    bool isPresent();
    void setPresence(bool presence);
    char* getName() { return name;}
    void startDialog();

private:
    char* name;
    bool present;
    Dialog* dialog;
};

#endif // LEVELOBJECT_H
