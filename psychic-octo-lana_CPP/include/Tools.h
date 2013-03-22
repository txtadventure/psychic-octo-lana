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
        static void printMsg(const string& msg);
        static void printStatusBar();
        static int printChoice(const string& msg, const vector<string>& choices);
        static string printInput(const string& msg);
        static bool printQuestion(const string& msg);
        static string toString ( int number );
        static void gameOver();
        static void titleScreen();
    private:
        static const int CHAR_TIME_FAST = 5;
        static const int CHAR_TIME_SLOW = 30;
        static void printMsgFast(const string& msg);
        static void printMsgSlow(const string& msg);
        static void printMsgInstant(const string& msg);
        static void printMsgSpeed(const string& msg, int speed);
};

#endif // TOOLS_H
