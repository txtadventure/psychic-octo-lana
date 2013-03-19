#ifndef GAME_H
#define GAME_H

#include <string>

#include "Player.h"

using namespace std;

class Game
{
public:
        void printMsg(const string& msg);
        static Game* instance ()
        {
            static CGuard g;   // memory management
            if (!_instance)
                _instance = new Game ();
            return _instance;
        }
private:
        Player* player;

        //initialize game
        Game():player(new Player())
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

Game* Game::_instance = NULL; //initialize static member

#endif // GAME_H
