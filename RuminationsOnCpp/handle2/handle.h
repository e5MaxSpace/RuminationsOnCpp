#ifndef HANDLE_H
#define HANDLE_H

#include "point.h"
#include "usecount.h"

class Handle
{
public:
    Handle();
    Handle(int xv, int yv);
    Handle(const Point &p0);
    ~Handle();

    Handle(const Handle &other);
    Handle &operator=(const Handle &other);

    int x() const;
    int y() const;

    // ÷µ”Ô“Â
    Handle &x_v(int xv);
    Handle &y_v(int yv);

private:
    Point *p;
    UseCount u;
};

#endif // HANDLE_H
