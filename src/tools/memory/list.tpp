#include <tools/memory/list.h>
#include <algorithm>

template <typename T>
List<T>::List(int maxSize)
    : total(maxSize)
{
    list = new T[maxSize];
    help_list = new T[maxSize];
}

template <typename T>
List<T>::~List()
{
    delete[] list;
    delete[] help_list;
}


template <typename T>
T& List<T>::push()
{
    return list[count++];
}

template <typename T>
T& List<T>::push(int index)
{
    copyListToHelpList(index);

    for (int i = index; i < count; i++)
    {
        list[i+1] = help_list[i];
    }

    count++;
    return list[index];
}

template <typename T>
void List<T>::pop()
{
    count--;
}

template <typename T>
void List<T>::pop(int index)
{
    for (int i = index; i < count; i++)
    {
        list[i] = help_list[i+1];
    }

    count--;
}

template <typename T>
int List<T>::size()
{
    return count;
}

template <typename T>
int List<T>::totalReserve()
{
    return total;   
}

template <typename T>
void List<T>::copyListToHelpList(int index)
{
    for (int i = index; i < count; i++)
    {
        help_list[i] = list[i+1];
    }
}

template <typename T>
void List<T>::clear()
{
    count = 0;
}