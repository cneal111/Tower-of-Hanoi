//CS4346
//AI Project 2
//Professor Dr. Ali
//Authors: Alhaeth Alomari, Mesut April, Cody Neal
//

#ifndef TOH_ASTAR_H
#define TOH_ASTAR_H

#include <vector>
#include <algorithm>
#include "../Hanoi/Hanoi.h"
#include "../Util/MyCompare/MyCompare.h"
#include "../Util/MyPriorityQueue/MyPriorityQueue.h"
#include "../Util/MyPriorityQueue/MyPriorityQueue.cpp"


class AStar
{
    public:
        AStar();

        void search(Hanoi* start, Hanoi* goal, int& nodeOpened, int& expand);

        Hanoi* isInOpen(MyPriorityQueue<Hanoi*>* open, Hanoi* searched);
        Hanoi* isInClosed(MyPriorityQueue<Hanoi*>* closed, Hanoi* searched);

};


#endif //TOH_ASTAR_H
