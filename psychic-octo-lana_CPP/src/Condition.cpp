#include "Condition.h"
#include "Game.h"
#include "Player.h"
#include "Item.h"

Condition::Condition(vector<int>* _requiredItems, vector<int>* _requiredEvents, int _requiredMoney, int _requiredHP):
requiredItems(_requiredItems), requiredEvents(_requiredEvents), requiredMoney(_requiredMoney), requiredHP(_requiredHP)
{}

bool Condition::access(string& cndMsg){
    Game* game = Game::instance();
    Player* player = game->getPlayer();
    bool access = true;
    //check items
    for(int& itemIndex : *requiredItems){
        access = access &&(    player->getItem1()->getIndex() == itemIndex
                            || player->getItem2()->getIndex() == itemIndex
                            || player->getItem3()->getIndex() == itemIndex );
    }
    if(!access){
        cndMsg = "Missing required item/s";
        return false;
    }
    //check events
    for(int& eventIndex : *requiredEvents){
        access = access && game->passedEvent(eventIndex);
    }
    if(!access){
        cndMsg = "Missing required event/s";
        return false;
    }
    //check money and hp
    access = access && player->getHP() >= requiredHP;
    if(!access){
        cndMsg = "Need more HP";
        return false;
    }
    access = access && player->getMoney() >= requiredMoney;
    if(!access){
        cndMsg = "Need more money";
        return false;
    }

    return access;
}
