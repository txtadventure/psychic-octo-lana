#include "Tools.h"
#include <iostream>
#include <windows.h>
#include <sstream>
#include <stdlib.h>

#include "Level.h"
#include "Item.h"
#include "Player.h"
#include "Game.h"

using namespace std;

const char* Tools::HOR_BAR = "-------------------------------------------------------------------------------";

void Tools::printMsg(const string& msg){
    printMsgSlow(msg);
    cout << endl;
}


//we don't print the status bar again until a variable changed in that bar
void Tools::printStatusBar(){
    Player* p = Game::instance()->getPlayer();
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

int Tools::printChoice(const string& msg, const vector<string>& choices){
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
        input = printChoice(msg, choices);
    }
    return input;
}
string Tools::printInput(const string& msg){
    printMsgSlow(msg);
    cout << endl;
    cout << "input: ";
    string input;
    getline(cin, input);
    cout << endl;
    return input;
}
bool Tools::printQuestion(const string& msg){
    bool answer;
    printMsgSlow(msg);
    cout << endl;
    cout << "(y/n): ";
    char input;
    cin >> input;
    cout << endl;
    if(input != 'y' && input != 'n'){
        printMsgSlow("Invalid answer. Try again.");
        answer = printQuestion(msg);
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

void Tools::gameOver(){
    printMsgSlow("   _____                                 ____ ");
    printMsgSlow("  / ____|                               / __ \\                       ");
    printMsgSlow(" | |  __    __ _   _ __ ___     ___    | |  | | __   __   ___   _ __ ");
    printMsgSlow(" | | |_ |  / _` | | '_ ` _ \\   / _ \\   | |  | | \\ \\ / /  / _ \\ | '__|");
    printMsgSlow(" | |__| | | (_| | | | | | | | |  __/   | |__| |  \\   /  |  __/ | |   ");
    printMsgSlow("  \\_____|  \\__,_| |_| |_| |_|  \\___|    \\____/    \\_/    \\___| |_|   ");

    cout << endl;
    bool again = printQuestion("Try again?");
    if(again){
        Game::restartGame();
    }else{
        exit (EXIT_SUCCESS);
    }
}

string Tools::toString ( int number )
{
     ostringstream ss;
     ss << number;
     return ss.str();
}
