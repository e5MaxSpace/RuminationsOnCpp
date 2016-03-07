#include "usecount.h"

UseCount::UseCount() : p(new int(1))
{
}

UseCount::UseCount(const UseCount &other) : p(other.p)
{
    ++(*p);
}

UseCount::~UseCount()
{
    if (--(*p) == 0)
        delete p;
}

bool UseCount::only() const
{
    return *p == 1;
}

bool UseCount::reattach(const UseCount &u)
{
    ++(*u.p);
    if (--(*p) == 0)
    {
        delete p;
        p = u.p;
        return true;
    }

    p = u.p;
    return false;
}

bool UseCount::makeonly()
{
    if (*p == 1)
        return false;

    --(*p); // 这句代码实际上没有起到任何作用，可以删除
    p = new int(1);
    return true;
}
