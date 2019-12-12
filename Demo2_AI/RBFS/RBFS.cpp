//CS4346
//AI Project 2
//Professor Dr. Ali
//Authors: Alhaeth Alomari, Mesut April, Cody Neal
//

#include "RBFS.h"


RBRS::RBRS()
{

}

void RBRS::search(Hanoi *start, Hanoi *goal, int& nodesOpened, int& expanded)
{
    bool found = false;

    rbfs(start, goal, std::numeric_limits<int>::max(), found, nodesOpened, expanded);

}

void RBRS::rbfs(Hanoi *current, Hanoi *goal, int fLimit, bool &found, int& nodesOpened, int& expanded)
{
    nodesOpened++;
    expanded++;

    if(found)
    {
        return;
    }

    std::cout << "current = " << current->getFValue() << std::endl;
    std::cout << *current << std::endl;


    if(*current == *goal)
    {
        found = true;
        std::cout << "found solution" << std::endl;
        std::cout << *current << std::endl;
        return;
    }

    MyPriorityQueue<Hanoi*>* successors = new MyPriorityQueue<Hanoi*>();

    std::vector<Hanoi*>* children = current->getAllChildren();

    for(int c = 0; c < children->size(); c++)
    {
        successors->push(children->at(c));
    }

    if(successors->empty() == true)
    {
        std::cout << "fail" << std::endl;
        expanded--;
        return;
    }


    Hanoi* best = nullptr;
    Hanoi* second = nullptr;

    while(successors->empty() == false && found == false)
    {
        std::make_heap(successors->getContainer()->begin(), successors->getContainer()->end(), MyCompare());

        best = successors->top();
        successors->pop();

       

        if(successors->empty() == false)
        {
            second = successors->top();
        }
        else
        {
            second = nullptr;
        }

        successors->push(best);

        if(best->getFValue() > fLimit)
        {
            std::cout << "fail go back" << std::endl;
            current->setF(best->getFValue());
            expanded--;

            return;
        }

        int min = fLimit;

        if(second != nullptr)
        {
            min = std::min(fLimit, second->getFValue());
        }

        rbfs(best, goal, min, found, nodesOpened, expanded);
    }
}
