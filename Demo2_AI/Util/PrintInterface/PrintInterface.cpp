//CS4346
//AI Project 2
//Professor Dr. Ali
//Authors: Alhaeth Alomari, Mesut April, Cody Neal
//

#include "PrintInterface.h"

std::ostream& operator << (std::ostream &os, PrintInterface &obj)
{
    obj.print(os);
    return os;
}
