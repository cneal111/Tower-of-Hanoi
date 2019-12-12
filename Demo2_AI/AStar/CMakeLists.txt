cmake_minimum_required(VERSION 3.14)
project(TOH)

set(CMAKE_CXX_STANDARD 14)

add_executable(TOH main.cpp Util/CompareInterface/CompareInterface.h Util/CompareInterface/CompareInterface.cpp Util/PrintInterface/PrintInterface.h Util/PrintInterface/PrintInterface.cpp Hanoi/Disk/Disk.cpp Hanoi/Disk/Disk.h Hanoi/Rod/Rod.cpp Hanoi/Rod/Rod.h Hanoi/Hanoi.cpp Hanoi/Hanoi.h AStar/AStar.cpp AStar/AStar.h Util/MyCompare/MyCompare.cpp Util/MyCompare/MyCompare.h Util/MyPriorityQueue/MyPriorityQueue.cpp Util/MyPriorityQueue/MyPriorityQueue.h RBRS/RBRS.cpp RBRS/RBRS.h)
