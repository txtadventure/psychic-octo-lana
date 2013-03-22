#ifndef PLAYER_H
#define PLAYER_H

class Level;
class Item;
class LevelFactory;

class Player
{
    public:
        static const int maxHP = 100;
        Player();
        ~Player();
        void addItem(Item* item1);
        void removeItem(int itemID);
        Level* getCurrentLevel() const {return currentLevel;}
        int getHP() const {return hp;}
        void changeHP(int delta);
        int getMoney() const {return money;}
        void changeMoney(int delta);
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
