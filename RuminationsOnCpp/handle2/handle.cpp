#include "handle.h"

Handle::Handle() : p(new Point())
{
}

Handle::Handle(int xv, int yv) : p(new Point(xv, yv))
{

}

Handle::Handle(const Point &p0) : p(new Point(p0))
{

}

Handle::~Handle()
{
    if (u.only())
    {
        delete p;
    }
}

Handle::Handle(const Handle &other) : p(other.p), u(other.u)
{

}

Handle &Handle::operator=(const Handle &other)
{
    if (this != &other)
    {
        if (u.reattach(other.u))
            delete p;

        p = other.p;
    }

    return *this;
}

int Handle::x() const
{
    return p->x();
}

int Handle::y() const
{
    return p->y();
}

Handle &Handle::x_v(int xv)
{
    if (u.makeonly())
        p = new Point(*p);
    p->x(xv);
    return *this;
}

Handle &Handle::y_v(int yv)
{
    if (u.makeonly())
        p = new Point(*p);
    p->y(yv);
    return *this;
}
