#ifndef ITEMFACTORY_H
#define ITEMFACTORY_H

#include "Item.h"

class ItemFactory
{
    public:
        static const int ITEM1=0;
        static Item* produceItem(int itemID);
    private:
};

#endif // ITEMFACTORY_H
