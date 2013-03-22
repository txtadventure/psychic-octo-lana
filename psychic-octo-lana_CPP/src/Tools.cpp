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
    printMsgFast(msg);
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
    if(p->getItem1() == NULL){cout << "Item1: empty\t\t";}
    else cout << "Item1: " << p->getItem1()->getName() << "\t\t";
    if(p->getItem2() == NULL){cout << "Item2: empty\t\t";}
    else cout << "Item2: " << p->getItem1()->getName() << "\t\t";
    if(p->getItem3() == NULL){cout << "Item3: empty\t\t\n";}
    else cout << "Item3: " << p->getItem1()->getName() << "\t" << endl;
    cout << HOR_BAR << endl;
}

int Tools::printChoice(const string& msg, const vector<string>& choices){
    printMsgFast(msg);
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
        printMsgFast("Choice not supported. Please choose again.");
        input = printChoice(msg, choices);
    }
    return input;
}
string Tools::printInput(const string& msg){
    printMsgFast(msg);
    cout << endl;
    cout << "input: ";
    string input;
    getline(cin, input);
    cout << endl;
    return input;
}
bool Tools::printQuestion(const string& msg){
    bool answer;
    printMsgFast(msg);
    cout << endl;
    cout << "(y/n): ";
    char input;
    cin >> input;
    cout << endl;
    if(input != 'y' && input != 'n'){
        printMsgFast("Invalid answer. Try again.");
        answer = printQuestion(msg);
    }else{
        answer = input == 'y';
    }
    return answer;
}

void Tools::printMsgFast(const string& msg){
    printMsgSpeed(msg, CHAR_TIME_FAST);
}

void Tools::printMsgSlow(const string& msg){
    printMsgSpeed(msg, CHAR_TIME_SLOW);
}

void Tools::printMsgSpeed(const string& msg, int speed){
    for(int i=0;i<msg.length();i++){
        cout << msg.at(i);
        Sleep(speed);
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

void Tools::titleScreen(){
printMsgSlow("\t\t\t         ___^___");
printMsgSlow("\t\t\t        / O    O\\");
printMsgSlow("\t\t\t        \\_    __/       ______");
printMsgSlow("\t\t\t          |   |        / -o-o-o()");
printMsgSlow("\t\t\t     _____|   |_______/ /");
printMsgSlow("\t\t\t    / -o-o| 0 |o--o-o- /");
printMsgSlow("\t\t\t   / /   // ||\\\\            PSYCHIC-");
printMsgSlow("\t\t\t  / /   (( // ||");
printMsgSlow("\t\t\t  ||     \\\\))  \\\\           OCTO-");
printMsgSlow("\t\t\t  ||    //||    ))");
printMsgSlow("\t\t\t  ()    ( ))   //           LANA");
printMsgSlow("\t\t\t        //   ((");

cout << "\n\n\n";
}

string Tools::toString ( int number )
{
     ostringstream ss;
     ss << number;
     return ss.str();
}
