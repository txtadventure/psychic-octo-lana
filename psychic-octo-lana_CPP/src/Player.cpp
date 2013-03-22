#include "Player.h"
#include "Item.h"
#include "LevelFactory.h"
#include "Game.h"

Player::Player():hp(100),money(0),item1(0),item2(0),item3(0)
{}

Player::~Player()
{
    delete item1;
    delete item2;
    delete item3;
}

void Player::addItem(Item* item){
    if(item1 == 0 || item2 == 0 || item3 == 0){
        if(item1 == 0) item1 = item;
            else if(item2 == 0) item2 = item;
                else if(item3 == 0) item3 = item;
        Tools::printMsg("Collected item: " + item->getName());
        Tools::printStatusBar();
    }else{
        Tools::printMsg("No free slot available!");
    }
}

void Player::removeItem(int itemID){
    if(item1->getIndex() == itemID) item1 = 0;
    if(item2->getIndex() == itemID) item2 = 0;
    if(item3->getIndex() == itemID) item3 = 0;
    Tools::printStatusBar();
}

void Player::changeMoney(int delta){
    money = money + delta;
    Tools::printStatusBar();
}

void Player::changeHP(int delta){
    if(hp + delta > 0 && hp + delta <= 100) hp += delta;
    else if(hp + delta <= 0) Tools::gameOver();
            else if(hp + delta > 100) hp = 100;
    Tools::printStatusBar();
}

