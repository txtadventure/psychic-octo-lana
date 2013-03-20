#include "ItemFactory.h"

ItemFactory::ItemFactory()
{
    //ctor
}

Item* ItemFactory::produceItem(int itemID)(){
    switch(itemID){
    case ItemFactory::PENIS: return new Item(itemID, "Penis");break;
    case ItemFactory::MAUS: return new Item(itemID, "Maus");break;
    }
}
