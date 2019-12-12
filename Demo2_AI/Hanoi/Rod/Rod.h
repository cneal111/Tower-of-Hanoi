//CS4346
//AI Project 2
//Professor Dr. Ali
//Authors: Alhaeth Alomari, Mesut April, Cody Neal
//

#ifndef TOH_ROD_H
#define TOH_ROD_H

#include <stack>
#include "../Disk/Disk.h"
#include "../../Util/PrintInterface/PrintInterface.h"

class Rod : public PrintInterface
{
    public:
        Rod();
        Rod(int numberOfDisks);
        Rod(Rod* other);

        ~Rod();

        Disk* top();

        void pop();

        bool push(Disk* disk);

        bool canPush(Disk* disk);

        int getNumberOfDisksInRod();

        int getIndexOfDisk(int size);

        Disk* getDiskAtIndex(int index);

        int getNumberOfDisksSmallerThan(int size);

        bool operator == (Rod& other);

        std::ostream& print(std::ostream& os) override;



    private:
        std::stack<Disk>* rod;
};


#endif //TOH_ROD_H
