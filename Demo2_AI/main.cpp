//CS4346
//AI Project 2
//Professor Dr. Ali
//Authors: Alhaeth Alomari, Mesut April, Cody Neal
//

#include <iostream>
#include <chrono>
#include <algorithm>
#include <queue>
#include <limits>
#include <time.h>
#include "AStar/AStar.h"
#include "RBFS/RBFS.h"
#include "Hanoi/Hanoi.h"


int main()
{
    std::cout << "Hello, World!" << std::endl;

    std::chrono::time_point<std::chrono::system_clock> aStart, aEnd, rbfsStart, rbfsEnd;
    
    int numOfDisk;
    std::cout << "Enter number of disks: ";
    std::cin >> numOfDisk;

    Hanoi start(numOfDisk);
    Hanoi goal(true, numOfDisk);

    std::cout << start << std::endl;

    AStar aStar;
    int aOpen = 0;
    int aExpand = 0;

    aStart = std::chrono::system_clock::now();
    aStar.search(&start, &goal, aOpen, aExpand);
    aEnd = std::chrono::system_clock::now();

    RBRS rbrs;
    int rbfsOpen = 0;
    int rbfsExpand = 0;

    rbfsStart = std::chrono::system_clock::now();
    rbrs.search(&start, &goal, rbfsOpen, rbfsExpand);
    rbfsEnd = std::chrono::system_clock::now();

    std::chrono::duration<double> aStartSeconds = aEnd - aStart;
    std::chrono::duration<double> rbfsSeconds = rbfsEnd - rbfsStart;

    std::cout << "Astar time     = " << aStartSeconds.count() << std::endl;
    std::cout << "nodes opened   = " << aOpen << std::endl;
    std::cout << "nodes expanded = " << aExpand << std::endl;
    std::cout << "RBFS  time     = " << rbfsSeconds.count() << std::endl;
    std::cout << "nodes opened   = " << rbfsOpen << std::endl;
    std::cout << "nodes expanded = " << rbfsExpand << std::endl;

    std::cout << "End Program" << std::endl;
    return 0;
}
