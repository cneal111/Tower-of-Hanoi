//CS4346
//AI Project 2
//Professor Dr. Ali
//Authors: Alhaeth Alomari, Mesut April, Cody Neal
//

#include "Rod.h"

Rod::Rod()
{
    rod = new std::stack<Disk>();
}
Rod::Rod(int numberOfDisks)
{
    rod = new std::stack<Disk>();

    for(int i = numberOfDisks; i >= 1; i--)
    {
        this->push(new Disk(i));
    }
}
Rod::Rod(Rod *other)
{
    rod = new std::stack<Disk>();

    for(int i = other->getNumberOfDisksInRod() - 1; i >= 0; i--)
    {
        push(new Disk(*(other->top() - i)));
    }
}

Rod::~Rod()
{
    for(int i = 0; i < rod->size(); i++)
    {
        //delete rod->top();
        rod->pop();
    }
}

Disk* Rod::top()
{
    if(rod->empty() == false)
    {
        return &rod->top();
    }
    else
    {
        return nullptr;
    }
}

bool Rod::push(Disk* disk)
{
    if(rod->empty() == false)
    {
        Disk* currentTop = this->top();

        if (*disk < *currentTop)
        {
            rod->push(*disk);

            return true;
        }
        else
        {
            std::cout << "Cannot insert " << *disk << std::endl;
            std::cout << "It is larger than " << *currentTop << std::endl;

            return false;
        }
    }
    else
    {
        rod->push(*disk);

        return true;
    }
}

bool Rod::canPush(Disk *disk)
{
    if(disk == nullptr)
    {
        return false;
    }

    if(rod->empty() == false)
    {
        Disk* currentTop = this->top();

        if (*disk < *currentTop)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return true;
    }
}

void Rod::pop()
{
    rod->pop();
}

int Rod::getNumberOfDisksInRod()
{
    return rod->size();
}

int Rod::getNumberOfDisksSmallerThan(int size)
{
    int count = 0;

    for(int s = 0; s <= rod->size() - 1; s++)
    {
        if((&rod->top() - s)->getSize() < size)
        {
            count++;
        }
        else
        {
            break;
        }
    }

    return count;
}

int Rod::getIndexOfDisk(int size)
{

    for(int s = rod->size() - 1; s >= 0; s--)
    {
        if((&rod->top() - s)->getSize() == size)
        {
            return rod->size() - 1 - s;
        }
    }

    return -1;
}

Disk* Rod::getDiskAtIndex(int index)
{
    if(index < rod->size())
    {
        return (&rod->top() - (rod->size() - 1) + index);
    }
    else
    {
        return nullptr;
    }
}

bool Rod::operator == (Rod& other)
{
    if(getNumberOfDisksInRod() != other.getNumberOfDisksInRod())
    {
        return false;
    }

    for(int i = 0; i < getNumberOfDisksInRod(); i++)
    {
        if((*(&rod->top() - i) == (*(other.top() - i))) == false)
        {
            return false;
        }
    }

    return true;
}

std::ostream& Rod::print(std::ostream &os)
{
    os << "bottom - top" << std::endl;

    for(int s = rod->size() - 1; s >= 0; s--)
    {
        os << *(&rod->top() - s) << " ";
    }

    return os;
}
