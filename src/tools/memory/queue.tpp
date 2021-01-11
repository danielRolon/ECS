#include <tools/memory/queue.h>
#include <stdio.h>
#include <stdlib.h>

#define ASSERT_VALID_SIZE(x) if (x < 0 || x > maxSize-1) {                                   \
                                 printf("Error! size out bounds || line: %d\n", __LINE__);   \
                                 exit(0);                                                    \
                             }

template <typename T>
Queue<T>::Queue(int maxSize)
    : maxSize(maxSize)
{
    count = 0;
    pQueue = new T[maxSize];
}

template <typename T>
Queue<T>::~Queue()
{
    delete[] pQueue;
}

template <typename T>
T& Queue<T>::operator[](int index)
{
    ASSERT_VALID_SIZE(index);
    return pQueue[index];
}

template <typename T>
const T& Queue<T>::at(int index)
{
    ASSERT_VALID_SIZE(index);
    return pQueue[index];
}

template <typename T>
int Queue<T>::indexOf(T t)
{
    /*for (int i = 0; i < maxSize; i++)
    {
        if (pQueue[i] == t)
        {
            return i;
        }
    }*/

    return -1;
}

template <typename T>
int Queue<T>::indexIf(std::function<bool(T& element, int index)> function)
{
    for (int i = 0; i < maxSize; i++)
    {
        if (function(pQueue[i], i))
        {
            return i;
        }
    }
}

template <typename T>
T& Queue<T>::push(T t)
{
    pQueue[count] = t;
    return pQueue[count++];
}

template <typename T>
void Queue<T>::shift()
{
    ASSERT_VALID_SIZE(0);

    // Move all elements to left
    int j = 1;
    for (int i = 0; j < count; i++)
    {
        pQueue[i] = pQueue[j];
        j++;
    }

    count--;
}

template <typename T>
void Queue<T>::clear()
{
    count = 0;
}

template <typename T>
void Queue<T>::clear(T t)
{
    for (int i = 0; i < maxSize; i++)
    {
        pQueue[i] = t;
    }

    count = 0;
}


template <typename T>
int Queue<T>::size()
{
    return count;

}

template <typename T>
int Queue<T>::totalReserve()
{
    return maxSize;
}
