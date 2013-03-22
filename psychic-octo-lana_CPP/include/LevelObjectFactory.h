#ifndef LEVELOBJECTFACTORY_H
#define LEVELOBJECTFACTORY_H

class LevelObject;

class LevelObjectFactory
{
    public:
        static const int OBJ1=1;
        static LevelObject* produceLvlObj(int objID);
};

#endif // LEVELOBJECTFACTORY_H
