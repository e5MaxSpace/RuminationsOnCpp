#ifndef UPOINT_H
#define UPOINT_H

#include "point.h"

class UPoint
{
private:
    UPoint();
    UPoint(int x, int y);
    UPoint(const Point &p);

    Point pt;
    int use;

    friend class Handle;
};

#endif // UPOINT_H
