//CS4346
//AI Project 2
//Professor Dr. Ali
//Authors: Alhaeth Alomari, Mesut April, Cody Neal
//

#ifndef TOH_MYCOMPARE_H
#define TOH_MYCOMPARE_H


class MyCompare
{
    public:
        template<class Object>
        bool operator()(Object *a, Object *b)
        {
            return (*a) > (*b);
        }
};


#endif //TOH_MYCOMPARE_H
