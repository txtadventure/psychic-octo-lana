#ifndef GAME_H
#define GAME_H

#include <string>
#include <vector>
#include <algorithm>

#include "Player.h"
#include "LevelFactory.h"
#include "Tools.h"

using namespace std;

class Game
{
public:
        static Game* instance ()
        {
            if (!_instance)
                _instance = new Game ();
            return _instance;
        }
        Player* getPlayer(){return player;}
        bool passedEvent(int id){return (find(passedEvents.begin(), passedEvents.end(), id) != passedEvents.end());}
        void addPassedEvent(int id){passedEvents.push_back(id);}
        void enterFirstLevel(){startingLevel->enter();}

        static void startGame(){
            Game* inst = instance();
            inst->enterFirstLevel();
        }
        static void restartGame(){
            if(_instance != NULL){
                _instance = NULL;
            }
            startGame();
        }
private:
        Player* player;
        //if an event is passed, its index will be saved in passedEvents
        vector<int> passedEvents;
        Level* startingLevel;
        //initialize game
        Game():player(new Player()), startingLevel(LevelFactory::buildLevel1())
        {}
        ~Game(){
            delete player;
            delete startingLevel;
        }
        static Game* _instance;
};

#endif // GAME_H
