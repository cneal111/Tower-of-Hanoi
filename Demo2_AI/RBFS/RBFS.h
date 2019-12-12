//CS4346
//AI Project 2
//Professor Dr. Ali
//Authors: Alhaeth Alomari, Mesut April, Cody Neal
//

#ifndef TOH_RBRS_H
#define TOH_RBRS_H

#include <limits>
#include "../Hanoi/Hanoi.h"
#include "../Util/MyCompare/MyCompare.h"
#include "../Util/MyPriorityQueue/MyPriorityQueue.h"

class RBRS
{
    public:
        RBRS();

        void search(Hanoi* start, Hanoi* goal, int& nodesOpened, int& expanded);

        void rbfs(Hanoi* current, Hanoi* goal, int fLimit, bool &found, int& nodesOpened, int& expanded);
};


#endif //TOH_RBRS_H
