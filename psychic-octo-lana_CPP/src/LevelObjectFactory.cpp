#include "LevelObjectFactory.h"
#include "ItemFactory.h"
#include "LevelObject.h"
#include "Dialog.h"
#include "Tools.h"
#include "Game.h"
#include "Player.h"

#include <memory>
#include <string>

LevelObject* LevelObjectFactory::produceLvlObj(int objID){
    switch(objID){
    case OBJ1:{
        LevelObject* lvlObj = new LevelObject(OBJ1, "Chair");
                                Dialog* dia = new Dialog(lvlObj);
                                std::shared_ptr<Dialog> ptr = std::shared_ptr<Dialog>(dia);
                                dia->setRunFunc(
                                                [ptr](){
                                                    LevelObject* parent = (*ptr).lvlObjParent;
                                                    if(parent->isPresent()){
                                                        Tools::printMsg("Hello, I am a chair!");
                                                        bool choice = Tools::printQuestion("Do you want to pick me up?");
                                                        if(choice){
                                                            parent->setPresence(false);
                                                            Game::instance()->getPlayer()->addItem(ItemFactory::produceItem(ItemFactory::ITEM1));
                                                        }
                                                    }
                                                }
                                                );
                                lvlObj->setDialog(dia);
                                return lvlObj;

    }
    default:break;
    }
    return 0;
}
