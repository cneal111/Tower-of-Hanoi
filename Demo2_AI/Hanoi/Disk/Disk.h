//CS4346
//AI Project 2
//Professor Dr. Ali
//Authors: Alhaeth Alomari, Mesut April, Cody Neal
//


#ifndef TOH_DISK_H
#define TOH_DISK_H

#include "../../Util/PrintInterface/PrintInterface.h"
#include "../../Util/CompareInterface/CompareInterface.h"

class Disk : public CompareInterface<Disk>, public PrintInterface
{
    public:
        Disk(int size);
        ~Disk();

        int getSize();

        bool operator == (Disk&) override;
        bool operator < (Disk&) override;
        bool operator > (Disk&) override;
        bool operator <= (Disk&) override;
        bool operator >= (Disk&) override;

        std::ostream& print(std::ostream& os) override;

    private:
        int size;
};


#endif //TOH_DISK_H
