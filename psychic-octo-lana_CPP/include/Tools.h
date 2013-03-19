#ifndef TOOLS_H
#define TOOLS_H
#include <string>

#include "Player.h"

using namespace std;

class Tools
{
    public:
        static void printMsg(const string& msg, const Player* p);
    protected:
    private:
        static void printMsgSlow(const string& msg);
};

#endif // TOOLS_H
