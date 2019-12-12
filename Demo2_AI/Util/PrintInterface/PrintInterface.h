//CS4346
//AI Project 2
//Professor Dr. Ali
//Authors: Alhaeth Alomari, Mesut April, Cody Neal
//

#ifndef PROJECT2_PRINTINTERFACE_H
#define PROJECT2_PRINTINTERFACE_H


#include <iostream>

class PrintInterface
{
    public:

        /* Virtual print function that must be implemented by any subclass */
        virtual std::ostream& print(std::ostream& os) = 0;

        /* MUST BE FRIEND AS IT IS NOT A MEMEBER OF THIS CLASS OFFICIALLY */
        /* << operator is a member of ostream class, so we create a virtual
         * function print above that is a member of this class that we have
         * implemented by children classes. Then this friend function here can
         * do its job normally. This is implemented in the PrintInterface.cpp
         * file. But we do not need to specify PrintInterface there.
         */
        friend std::ostream& operator << (std::ostream& os, PrintInterface& obj);
};



#endif //PROJECT2_PRINTINTERFACE_H
