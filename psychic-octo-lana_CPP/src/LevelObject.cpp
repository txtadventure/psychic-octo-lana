#include "LevelObject.h"

#include"Dialog.h"

void LevelObject::startDialog(){
    dialog->execute();
}

LevelObject::~LevelObject(){
    delete dialog;
}
