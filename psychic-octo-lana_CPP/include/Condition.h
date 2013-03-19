#ifndef CONDITION_H
#define CONDITION_H

#include <string>
#include <vector>

using namespace std;

class Condition
{
    public:
        Condition(vector<int>* _requiredItems, vector<int>* _requiredEvents, int _requiredMoney, int _requiredHP);
        bool access(string& cndMsg);
    private:
        vector<int>* requiredItems;
        vector<int>* requiredEvents;
        int requiredMoney;
        int requiredHP;
};

#endif // CONDITION_H
