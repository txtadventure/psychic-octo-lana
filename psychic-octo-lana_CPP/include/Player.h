#ifndef PLAYER_H
#define PLAYER_H

class Level;
class Item;

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
        void setCurrentLevel(Level* newCurrentLevel){currentLevel = newCurrentLevel;}
    private:
        Level* currentLevel;
        Item* item1;
        Item* item2;
        Item* item3;
        int hp;
        int money;
};

#endif // PLAYER_H
