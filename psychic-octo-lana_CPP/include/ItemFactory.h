#ifndef ITEMFACTORY_H
#define ITEMFACTORY_H



class ItemFactory
{
    public:
        static const int PENIS=0, MAUS=1;
        static Item* produceItem(int itemID)();
        ItemFactory();
    private:
};

#endif // ITEMFACTORY_H
