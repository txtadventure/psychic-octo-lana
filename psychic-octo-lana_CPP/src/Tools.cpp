#include "Tools.h"
#include <iostream>
#include <windows.h>

using namespace std;

const char* Tools::HOR_BAR = "-------------------------------------------------------------------------------";

void Tools::printMsg(const string& msg, const Player* p){
    //Status bar
    cout << HOR_BAR << endl;
    cout << "Level: " << p->getCurrentLevel() << "\t\t";
    cout << "HP: " << p->getHP() << "\t\t\t";
    cout << '$' << p->getMoney() << "\t\t" << endl;
    cout << HOR_BAR << endl << endl;

    //Message
    printMsgSlow(msg);
    cout << endl;

    //collected items
    cout << HOR_BAR << endl;
    cout << "Item1: " << p->getItem1() << "\t\t";
    cout << "Item2: " << p->getItem1() << "\t\t";
    cout << "Item3: " << p->getItem1() << "\t\t" << endl;
    cout << HOR_BAR << endl;
}

void Tools::printMsgSlow(const string& msg){
    for(int i=0;i<msg.length();i++){
        cout << msg.at(i);
        Sleep(CHAR_TIME);
    }
    cout << endl;
}
