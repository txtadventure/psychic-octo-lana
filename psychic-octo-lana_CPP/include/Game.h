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
		void gameOver();
        void printMsg(const string& msg){Tools::printMsg(msg, player);}
		int printChoice(const string& msg){return Tools::printChoice(msg, player);}
        bool printQuestion(const string& msg){return Tools::printQuestion(msg, player);}
        char* printInput(const string& msg){return Tools::printInput(msg, player);}
        static Game* instance ()
        {
            static CGuard g;   // memory management
            if (!_instance)
                _instance = new Game ();
            return _instance;
        }
        Player* getPlayer(){return player;}
        bool passedEvent(int id){return (find(passedEvents.begin(), passedEvents.end(), id) != passedEvents.end());}
        void addPassedEvent(int id){passedEvents.push_back(id);}
        void enterFirstLevel(){startingLevel->enter();}
private:
        Player* player;
        //if an event is passed, its index will be saved in passedEvents
        vector<int> passedEvents;
        Level* startingLevel;
        //initialize game
        Game():player(new Player()), startingLevel(LevelFactory::buildLevel1())
        {};
        static Game* _instance;

        class CGuard
        {
            public:
                ~CGuard()
                {
                    if( NULL != Game::_instance )
                    {
                        delete Game::_instance;
                        Game::_instance = NULL;
                    }
                }
        };
        friend class CGuard;
};

#endif // GAME_H
