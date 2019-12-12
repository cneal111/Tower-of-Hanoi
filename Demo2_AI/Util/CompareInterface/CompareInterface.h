//CS4346
//AI Project 2
//Professor Dr. Ali
//Authors: Alhaeth Alomari, Mesut April, Cody Neal
//
#ifndef PROJECT2_COMPAREINTERFACE_H
#define PROJECT2_COMPAREINTERFACE_H


template <class Object>
class CompareInterface
{
    public:

        /* Virtual operator that must be implemented by any subclass */
        virtual bool operator == (Object&) = 0;
        virtual bool operator < (Object&) = 0;
        virtual bool operator > (Object&) = 0;
        virtual bool operator <= (Object&) = 0;
        virtual bool operator >= (Object&) = 0;
};


#endif //PROJECT2_COMPAREINTERFACE_H
