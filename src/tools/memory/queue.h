#pragma once

#include <functional>

template <typename T>
class Queue
{
public:
    inline Queue(int maxSize);
    inline ~Queue();

    T& operator[](int index);
    const T& at(int index);
    int indexOf(T t);
    int indexIf(std::function<bool(T& element, int index)> function);

    T& push(T t);
    inline void shift();

    inline void clear();
    inline void clear(T t);
    inline int  size();
    inline int  totalReserve();
private:
    int count = 0;
    int maxSize = 0;
    T*  pQueue = nullptr;
};

#include <tools/memory/queue.tpp>