#include "upoint.h"

UPoint::UPoint() : use(1)
{
}

UPoint::UPoint(int x, int y) : pt(x, y), use(1)
{

}

UPoint::UPoint(const Point &p) : pt(p), use(1)
{

}
