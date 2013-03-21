#ifndef TOOLS_H
#define TOOLS_H
#include <string>
#include <vector>

class Player;

using namespace std;

class Tools
{
    public:
        static const char* HOR_BAR;
        static void printMsg(const string& msg, const Player* p);
        static void printStatusBar(const Player* p);
        static int printChoice(const string& msg, const vector<string>& choices, const Player* p);
        static string printInput(const string& msg, const Player* p);
        static bool printQuestion(const string& msg, const Player* p);
        static string toString ( int number );
    private:
        static const int CHAR_TIME = 5;
        static void printMsgSlow(const string& msg);
        static void printMsgInstant(const string& msg);
};

#endif // TOOLS_H
