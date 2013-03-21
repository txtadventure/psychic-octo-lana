#include "Tools.h"
#include <iostream>
#include <windows.h>
#include <sstream>
#include "Level.h"
#include "Item.h"
#include "Player.h"

#include "Player.h"

using namespace std;

const char* Tools::HOR_BAR = "-------------------------------------------------------------------------------";

void Tools::printMsg(const string& msg, const Player* p){
    printMsgSlow(msg);
    cout << endl;
}


//we don't print the status bar again until a variable changed in that bar
void Tools::printStatusBar(const Player* p){
        //Status bar
    cout << HOR_BAR << endl;
    cout << "Level: " << p->getCurrentLevel()->getName() << "\t\t";
    cout << "HP: " << p->getHP() << "\t\t\t";
    cout << '$' << p->getMoney() << "\t\t" << endl;
    cout << HOR_BAR << endl;

    //collected items
    cout << "Item1: " << p->getItem1()->getName() << "\t\t";
    cout << "Item2: " << p->getItem1()->getName() << "\t\t";
    cout << "Item3: " << p->getItem1()->getName() << "\t\t" << endl;
    cout << HOR_BAR << endl;
}

int Tools::printChoice(const string& msg, const vector<string>& choices, const Player* p){
    printMsgSlow(msg);
    cout << endl;
    for(int i=0;i<choices.size();i++){
        cout << '\t';
        printMsgInstant(toString(i) + ": " + choices.at(i));
    }
    cout << endl;
    cout << "choice: ";
    int input;
    cin >> input;
    cout << endl;
    if(input >= choices.size() || input < 0){
        printMsgSlow("Choice not supported. Please choose again.");
        input = printChoice(msg, choices, p);
    }
    return input;
}
string Tools::printInput(const string& msg, const Player* p){
    printMsgSlow(msg);
    cout << endl;
    cout << "input: ";
    string input;
    getline(cin, input);
    cout << endl;
    return input;
}
bool Tools::printQuestion(const string& msg, const Player* p){
    bool answer;
    printMsgSlow(msg);
    cout << endl;
    cout << "(y/n): ";
    char input;
    cin >> input;
    cout << endl;
    if(input != 'y' && input != 'n'){
        printMsgSlow("Invalid answer. Try again.");
        answer = printQuestion(msg, p);
    }else{
        answer = input == 'y';
    }
    return answer;
}

void Tools::printMsgSlow(const string& msg){
    for(int i=0;i<msg.length();i++){
        cout << msg.at(i);
        Sleep(CHAR_TIME);
    }
    cout << endl;
}

void Tools::printMsgInstant(const string& msg){
    cout << msg << endl;
}

string Tools::toString ( int number )
{
     ostringstream ss;
     ss << number;
     return ss.str();
}
