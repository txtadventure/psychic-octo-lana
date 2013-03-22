#include "ItemFactory.h"

Item* ItemFactory::produceItem(int itemID){
    switch(itemID){
    case ITEM1:{ return new Item(itemID, "Chair");break;}
    default:break;
    }
    return 0;
}
