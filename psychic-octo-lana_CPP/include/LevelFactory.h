#ifndef LEVELFACTORY_H
#define LEVELFACTORY_H

#include "Level.h"

class LevelFactory
{
    public:
        static Level* buildLevel1();
    private:
        static Level* buildLevel2();
        static Level* buildLevel3();
        static Level* buildLevel4();
        static Level* buildLevel5();
        static Level* buildLevel6();
        static Level* buildLevel7();
        static Level* buildLevel8();
        static Level* buildLevel9();
        static Level* buildLevel10();
};

#endif // LEVELFACTORY_H
