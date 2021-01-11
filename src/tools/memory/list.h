#pragma once

template <typename T>
class List
{
public:
    inline List(int maxSize);
    inline ~List();

    inline T& push();
    inline T& push(int index);
    inline void pop();
    inline void pop(int index);

    inline int size();
    inline int totalReserve();
    inline void clear();
private:
    inline void copyListToHelpList(int index);
private:
    int total = 0;
    int count = 0;
    T*  list = nullptr;
    T*  help_list = nullptr;
};

#include <tools/memory/list.h>