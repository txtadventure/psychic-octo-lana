#ifndef TOOLS_H
#define TOOLS_H
#include <string>

class Player;

using namespace std;

class Tools
{
    public:
        static const char* HOR_BAR;
        static void printMsg(const string& msg, const Player* p);
        static int printChoice(const string& msg, const Player* p);
        static char* printInput(const string& msg, const Player* p);
        static bool printQuestion(const string& msg, const Player* p);
    private:
        static const int CHAR_TIME = 5;
        static void printMsgSlow(const string& msg);
};

#endif // TOOLS_H
