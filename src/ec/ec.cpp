#include <ec/ec.h>

#define MAX_SYSTEMS 32

int countSystems = 0;

void (*pFuncs[MAX_SYSTEMS])();

void addSystem(void (*pFunc)())
{
    pFuncs[countSystems++] = pFunc;
}

void updateAllSystems()
{
    for (int i = 0; i < countSystems; ++i)
    {
        pFuncs[i]();
    }
}