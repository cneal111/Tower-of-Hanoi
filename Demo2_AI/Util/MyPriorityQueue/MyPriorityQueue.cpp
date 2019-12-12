//CS4346
//AI Project 2
//Professor Dr. Ali
//Authors: Alhaeth Alomari, Mesut April, Cody Neal
//

#include "MyPriorityQueue.h"


template <class Object>
bool MyPriorityQueue<Object>::remove(Object value)
{

    auto myIterator = std::find(this->c.begin(), this->c.end(), value);

    if (myIterator != this->c.end())
    {
        this->c.erase(myIterator);

       

        return true;
    }

    return false;

}

template <class Object>
std::vector<Object>* MyPriorityQueue<Object>::getContainer()
{
    return &this->c;
}

