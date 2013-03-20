#ifndef ITEM_H
#define ITEM_H

#include <string>

using namespace std;

class Item
{
    public:
        Item(int itemID, string _name):index(itemID), name(_name){};
        int getIndex(){return index;}
        string getName(){return name;}
    private:
        int index;
        string name;
};

#endif // ITEM_H
