//CS4346
//AI Project 2
//Professor Dr. Ali
//Authors: Alhaeth Alomari, Mesut April, Cody Neal
//

#ifndef TOH_MYPRIORITYQUEUE_H
#define TOH_MYPRIORITYQUEUE_H

#include <iostream>
#include <queue>
#include <iterator>
#include "../MyCompare/MyCompare.h"

template<class Object>
class MyPriorityQueue : public std::priority_queue<Object, std::vector<Object>, MyCompare>
{
    public:
        bool remove(Object value);

        std::vector<Object>* getContainer();


        friend std::ostream& operator << (std::ostream& os, MyPriorityQueue& obj)
        {
            for(int i = 0; i < obj.size(); i++)
            {
                os << "index = " << i << std::endl;
                os << **(obj.getContainer()->begin() + i) << std::endl;
            }
            return os;
        }

};



#endif //TOH_MYPRIORITYQUEUE_H
