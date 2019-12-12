//CS4346
//AI Project 2
//Professor Dr. Ali
//Authors: Alhaeth Alomari, Mesut April, Cody Neal
//

#ifndef TOH_HANOI_H
#define TOH_HANOI_H


#include <vector>
#include <limits>
#include <math.h>
#include "Disk/Disk.h"
#include "Rod/Rod.h"
#include "../Util/PrintInterface/PrintInterface.h"

class Hanoi : public PrintInterface
{
    public:
        /* Use this constructor for starting node */
        Hanoi(int numberOfDisks);

        /* Use this constructor for goal node */
        Hanoi(bool isGoal, int numberOfDisks);

        /* Use this constructor for all nodes that are not starting node
         * or goal node */
        Hanoi(Rod* one, Rod* two, Rod* three, int cost, Hanoi* parent);

        ~Hanoi();

        void setG(int cost);
        void setH(int heuristic);
        void setF(int f);

        int getG();
        int getH();

        const int getFValue();

        std::vector<Hanoi*>* getAllChildren();

        bool operator == (Hanoi& other);

        bool operator < (Hanoi& other);
        bool operator > (Hanoi& other);

        std::ostream& print(std::ostream& os) override;

        //int getHValue(int current);

    private:
        Hanoi* parent;
        int numberOfDisks;
        int g;
        int h;
        int f;
        Rod* one;
        Rod* two;
        Rod* three;

        void setNumberOfDisks(int numberOfDisks);
        void buildStart(int numberOfDisks);
        void buildGoal(int numberOfDisks);

        int calcHValue(int diskSize);

        int heuristicOne(int diskSize);
        int heuristicTwo(int diskSize);
        int heuristicThree(int diskSize);
        int heuristicFour(int diskSize);

};


#endif //TOH_HANOI_H
