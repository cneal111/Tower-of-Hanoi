//CS4346
//AI Project 2
//Professor Dr. Ali
//Authors: Alhaeth Alomari, Mesut April, Cody Neal
//


#include "Hanoi.h"

Hanoi::Hanoi(int numberOfDisks)
{
    buildStart(numberOfDisks);
}

Hanoi::Hanoi(bool isGoal, int numberOfDisks)
{
    if(isGoal)
    {
        buildGoal(numberOfDisks);
    }
    else
    {
        buildStart(numberOfDisks);
    }
}

Hanoi::Hanoi(Rod *one, Rod *two, Rod *three, int cost, Hanoi *parent)
{
    this->parent = parent;

    this->one = one;
    this->two = two;
    this->three = three;

    int numOne = this->one->getNumberOfDisksInRod();
    int numTwo = this->two->getNumberOfDisksInRod();
    int numThree = this->three->getNumberOfDisksInRod();

    setNumberOfDisks(numOne + numTwo + numThree);

    setG(cost);
    setH(calcHValue(numberOfDisks));
    setF(g + h);
}

Hanoi::~Hanoi()
{
    delete one;
    delete two;
    delete three;

    parent = nullptr;
}

void Hanoi::buildStart(int numberOfDisks)
{
    this->parent = nullptr;

    this->one = new Rod(numberOfDisks);
    this->two = new Rod();
    this->three = new Rod();

    setNumberOfDisks(numberOfDisks);

    setG(0);
    setH((int) pow(2, this->numberOfDisks) - 1);
    setF(g + h);
}

void Hanoi::buildGoal(int numberOfDisks)
{
    this->parent = nullptr;

    this->one = new Rod();
    this->two = new Rod();
    this->three = new Rod(numberOfDisks);

    setNumberOfDisks(numberOfDisks);

    setG(std::numeric_limits<int>::max());
    setH(0);
    setF(g + h);
}

void Hanoi::setNumberOfDisks(int numberOfDisks)
{
    this->numberOfDisks = numberOfDisks;
}

void Hanoi::setG(int cost)
{
    this->g = cost;
}

void Hanoi::setH(int heuristic)
{
    this->h = heuristic;
}

int Hanoi::getG()
{
    return g;
}
int Hanoi::getH()
{
    return h;
}

void Hanoi::setF(int f)
{
    this->f = f;
}

const int Hanoi::getFValue()
{
    return f;
}

int Hanoi::calcHValue(int diskSize)
{
    //return heuristicOne(diskSize);
    return heuristicTwo(diskSize);
    //return heuristicThree(diskSize);
 
    

}

std::vector<Hanoi*>* Hanoi::getAllChildren()
{
    std::vector<Hanoi*>* children = new std::vector<Hanoi*>();

    Disk* diskOne = one->top();
    Disk* diskTwo = two->top();
    Disk* diskThree = three->top();

    Rod* childOne = nullptr;
    Rod* childTwo = nullptr;
    Rod* childThree = nullptr;

    // move disk from rod one to two
    if(two->canPush(diskOne))
    {
        childOne = new Rod(one);
        childTwo = new Rod(two);
        childThree = new Rod(three);

        childOne->pop();
        childTwo->push(diskOne);

        Hanoi* child = new Hanoi(childOne, childTwo, childThree, g + 1, this);

        children->push_back(child);
    }

    // move disk from rod one to three
    if(three->canPush(diskOne))
    {
        childOne = new Rod(one);
        childTwo = new Rod(two);
        childThree = new Rod(three);

        childOne->pop();
        childThree->push(diskOne);

        Hanoi* child = new Hanoi(childOne, childTwo, childThree, g + 1, this);

        children->push_back(child);
    }
    // move disk from rod two to one
    if(one->canPush(diskTwo))
    {
        childOne = new Rod(one);
        childTwo = new Rod(two);
        childThree = new Rod(three);

        childTwo->pop();
        childOne->push(diskTwo);

        Hanoi* child = new Hanoi(childOne, childTwo, childThree, g + 1, this);

        children->push_back(child);
    }
    // move disk from rod two to three
    if(three->canPush(diskTwo))
    {
        childOne = new Rod(one);
        childTwo = new Rod(two);
        childThree = new Rod(three);

        childTwo->pop();
        childThree->push(diskTwo);

        Hanoi* child = new Hanoi(childOne, childTwo, childThree, g + 1, this);

        children->push_back(child);
    }
    // move disk from rod three to one
    if(one->canPush(diskThree))
    {
        childOne = new Rod(one);
        childTwo = new Rod(two);
        childThree = new Rod(three);

        childThree->pop();
        childOne->push(diskThree);

        Hanoi* child = new Hanoi(childOne, childTwo, childThree, g + 1, this);

        children->push_back(child);
    }
    // move disk from rod three to two
    if(two->canPush(diskThree))
    {
        childOne = new Rod(one);
        childTwo = new Rod(two);
        childThree = new Rod(three);

        childThree->pop();
        childTwo->push(diskThree);

        Hanoi* child = new Hanoi(childOne, childTwo, childThree, g + 1, this);

        children->push_back(child);

    }

    // remove grandparent
    for(int c = 0; c < children->size(); c++)
    {
        if(this->parent == nullptr)
        {
            break;
        }

        if(*children->at(c) == *this->parent)
        {
            children->erase(children->begin() + c);
        }
    }

    return children;
}


bool Hanoi::operator == (Hanoi& other)
{
    if(*one == *other.one && *two == *other.two && *three == *other.three)
        return true;

    return false;
}

int Hanoi::heuristicOne(int diskSize)
{
    if(three->getIndexOfDisk(diskSize) != -1)
    {
        return calcHValue(diskSize - 1);
    }

    return (int) pow(2, diskSize) - 1;
}

int Hanoi::heuristicTwo(int diskSize)
{
    if(three->getIndexOfDisk(diskSize) != -1)
    {
        return calcHValue(diskSize - 1);
    }

    return diskSize * diskSize;
}

int Hanoi::heuristicThree(int diskSize)
{
    if(diskSize <= 0)
    {
        return 0;
    }

    if(three->getIndexOfDisk(diskSize) != -1)
    {
        return calcHValue(diskSize - 1);
    }

    if(diskSize == 1)
    {
        return 1;
    }


    if(one->getIndexOfDisk(diskSize) != -1)
    {
        if(two->getIndexOfDisk(diskSize - 1) != -1)
        {
            return ((int) pow(2, diskSize) - 1) - ((int) pow(2, diskSize - 1) - 1) + ((int) pow(2, diskSize - 2) - 1);
        }
        else
        {
            return (int) pow(2, diskSize) - 1;
        }
    }
    if(two->getIndexOfDisk(diskSize) != -1)
    {
        if(one->getIndexOfDisk(diskSize - 1) != -1)
        {
            return ((int) pow(2, diskSize) - 1) - ((int) pow(2, diskSize - 1) - 1) + ((int) pow(2, diskSize - 2) - 1);
        }
        else
        {
            return (int) pow(2, diskSize) - 1;
        }
    }
    return 0;
}




bool Hanoi::operator > (Hanoi &other)
{
    return this->getFValue() > other.getFValue();
}
bool Hanoi::operator < (Hanoi &other)
{
    return this->getFValue() < other.getFValue();
}

std::ostream& Hanoi::print(std::ostream &os)
{
    int length = std::max(one->getNumberOfDisksInRod(), two->getNumberOfDisksInRod());
    length = std::max(length, three->getNumberOfDisksInRod());

    for(int i = length - 1; i >= 0; i--)
    {
        Disk* a = one->getDiskAtIndex(i);
        Disk* b = two->getDiskAtIndex(i);
        Disk* c = three->getDiskAtIndex(i);

        if(a != nullptr)
        {
            os << *a << "  ";
        }
        else
        {
            os << "   ";
        }
        if(b != nullptr)
        {
            os << *b << "  ";
        }
        else
        {
            os << "   ";
        }
        if(c != nullptr)
        {
            os << *c << "  ";
        }
        else
        {
            os << "   ";
        }

        os << std::endl;
    }

    os << "--------" << std::endl;
    os << "A  B  C " << std::endl;

    return os;
}
