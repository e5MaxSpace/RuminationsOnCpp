#include "handle.h"

Handle::Handle() : up(new UPoint())
{
}

Handle::Handle(int xv, int yv) : up(new UPoint(xv, yv))
{

}

Handle::Handle(const Point &p) : up(new UPoint(p))
{

}

Handle::~Handle()
{
    --up->use;
    if (up->use == 0)
        delete up;
}

Handle::Handle(const Handle &other) : up(other.up)
{
    ++up->use;
}

Handle &Handle::operator=(const Handle &other)
{
    if (this != &other)
    {
        ++other.up->use;
        if (--up->use == 0)
            delete up;

        up = other.up;
    }

    return *this;
}

int Handle::x() const
{
    return up->pt.x();
}

int Handle::y() const
{
    return up->pt.y();
}

void Handle::copy_on_write()
{
    if (up->use != 1)
    {
        --up->use;
        up = new UPoint(up->pt);
    }
}

Handle &Handle::x_v(int xv)
{
    copy_on_write();
    up->pt.x(xv);
    return *this;
}

Handle &Handle::y_v(int yv)
{
    copy_on_write();
    up->pt.y(yv);
    return *this;
}

Handle &Handle::x(int xv)
{
    up->pt.x(xv);
    return *this;
}

Handle &Handle::y(int yv)
{
    up->pt.y(yv);
    return *this;
}
