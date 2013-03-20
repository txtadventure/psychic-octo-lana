#ifndef ITEM_H
#define ITEM_H


class Item
{
    public:
        Item(int itemID, char* _name):index(itemID), name(_name){};
        int getIndex(){return index;}
    private:
        int index;
        char* name;
};

#endif // ITEM_H
