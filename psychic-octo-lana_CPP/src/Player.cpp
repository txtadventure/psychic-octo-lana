#include "Player.h"
#include "Item.h"
#include "LevelFactory.h"
#include "Game.h"

Player::Player()
{
    currentLevel = LevelFactory::buildLevel1();
    hp = 100;
    money = 0;
    //instancing default item with index 0?
    item1 = new Item(0, "empty");
    item2 = new Item(0, "empty");
    item3 = new Item(0, "empty");
}

void Player::addItem(Item* item){
    if(item1 == 0 || item2 == 0 || item3 == 0){
        if(item1 == 0) item1 = item;
            else if(item2 == 0) item2 = item;
                else if(item3 == 0) item3 = item;
        Game::instance()->printMsg("Collected item: " + item->getName());
        Game::instance()->printStatusBar();
    }else{
        Game::instance()->printMsg("No free slot available!");
    }
}

void Player::removeItem(int itemID){
    if(item1->getIndex() == itemID) item1 = 0;
    if(item2->getIndex() == itemID) item2 = 0;
    if(item3->getIndex() == itemID) item3 = 0;
    Game::instance()->printStatusBar();
}

void Player::changeMoney(int delta){
    money = money + delta;
    Game::instance()->printStatusBar();
}

void Player::changeHP(int delta){
    if(hp + delta > 0 && hp + delta <= 100) hp += delta;
    else if(hp + delta <= 0) Game::instance()->gameOver();
            else if(hp + delta > 100) hp = 100;
    Game::instance()->printStatusBar();
}

