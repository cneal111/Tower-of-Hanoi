//CS4346
//AI Project 2
//Professor Dr. Ali
//Authors: Alhaeth Alomari, Mesut April, Cody Neal
//
#include "AStar.h"

AStar::AStar()
{

}

void AStar::search(Hanoi *start, Hanoi* goal, int& nodeOpened, int& expand)
{
    MyPriorityQueue<Hanoi*> open;
    MyPriorityQueue<Hanoi*> closed;

    nodeOpened++;
    open.push(start);

    while(open.empty() == false)
    {
        Hanoi* current = open.top();
        open.pop();

        std::cout << "current = " << current->getFValue() << std::endl << std::endl;
        std::cout << *current << std::endl;

        if(*current == *goal)
        {
            std::cout << "Found goal" << std::endl;
            return;
        }

        std::vector<Hanoi*> *children = current->getAllChildren();

        if(children->size() > 0)
        {
            expand++;
        }


        for(int c = 0; c < children->size(); c++)
        {
            Hanoi* child = children->at(c);

            std::cout << "Child = " << child->getFValue() << std::endl << std::endl;
            std::cout << *child << std::endl;

            Hanoi* openHanoi = isInOpen(&open, child);

            Hanoi* closedHanoi = isInClosed(&closed, child);


            if(openHanoi == nullptr && closedHanoi == nullptr)
            {
                nodeOpened++;
                open.push(child);
            }
            else
            {
                if(openHanoi != nullptr)
                {
                    if(*child < *openHanoi)
                    {
                        openHanoi->setG(child->getG());
                    }
                }
                if(closedHanoi != nullptr)
                {
                    expand--;
                    if(*child < *closedHanoi)
                    {
                        closed.remove(closedHanoi);
                        open.push(closedHanoi);
                    }
                }
            }
        }
        //expand++;
        closed.push(current);
    }

    std::cout << "fail" << std::endl;
}

Hanoi* AStar::isInOpen(MyPriorityQueue<Hanoi*>* open, Hanoi* searched)
{
    for(int i = 0; i < open->size(); i++)
    {
        if(*searched == **(open->getContainer()->begin() + i))
        {
            return *(open->getContainer()->begin() + i);
        }
    }

    return nullptr;
}

Hanoi* AStar::isInClosed(MyPriorityQueue<Hanoi*>* closed, Hanoi* searched)
{
    for(int i = 0; i < closed->size(); i++)
    {
        if(*searched == **(closed->getContainer()->begin() + i))
        {
            return *(closed->getContainer()->begin() + i);
        }
    }

    return nullptr;
}
