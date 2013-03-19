#ifndef PLAYER_H
#define PLAYER_H

#include "Level.h"
#include "Item.h"

class Player
{
    public:
        Player();
        Level* getCurrentLevel() const {return currentLevel;}
        int getHP() const {return hp;}
        int getMoney() const {return money;}
        Item* getItem1() const {return item1;}
        Item* getItem2() const {return item2;}
        Item* getItem3() const {return item3;}
    private:
        Level* currentLevel;
        Item* item1;
        Item* item2;
        Item* item3;
        int hp;
        int money;
};

#endif // PLAYER_H
