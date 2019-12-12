//CS4346
//AI Project 2
//Professor Dr. Ali
//Authors: Alhaeth Alomari, Mesut April, Cody Neal
//

#include "Disk.h"

Disk::Disk(int size)
{
    this->size = size;
}

Disk::~Disk()
{

}

int Disk::getSize()
{
    return size;
}

bool Disk::operator == (Disk &other)
{
    return (this->size == other.size);
}
bool Disk::operator < (Disk &other)
{
    return (this->size < other.size);
}
bool Disk::operator > (Disk &other)
{
    return (this->size > other.size);
}
bool Disk::operator <= (Disk &other)
{
    return (this->size <= other.size);
}
bool Disk::operator >= (Disk &other)
{
    return (this->size >= other.size);
}


std::ostream& Disk::print(std::ostream &os)
{
    os << size;
    return os;
}
