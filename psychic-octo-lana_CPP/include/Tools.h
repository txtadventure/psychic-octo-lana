#ifndef TOOLS_H
#define TOOLS_H
#include <string>

#include "Player.h"

using namespace std;

class Tools
{
    public:
        static const char* HOR_BAR = "-------------------------------------------------------------------------------";
        static void printMsg(const string& msg, const Player* p);
    private:
        static const int charTime = 5;
        static void printMsgSlow(const string& msg);
};

#endif // TOOLS_H
