#pragma once

#include <eventSystem/events/areaEvent.h>

class AreaListener
{
public:
    AreaListener(){}
    virtual void inArea(AreaEvent areaEvent) {};
    virtual void outArea(AreaEvent areaEvent) {};
};
