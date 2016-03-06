#ifndef HANDLE_H
#define HANDLE_H

#include "point.h"
#include "upoint.h"

class Handle
{
public:
    Handle();
    Handle(int xv, int yv);
    Handle(const Point &p);
    ~Handle();

    Handle(const Handle &other);
    Handle &operator=(const Handle &other);

    int x() const;
    int y() const;

    // 值语义
    Handle &x_v(int xv);
    Handle &y_v(int yv);

    // 指针语义
    Handle &x(int xv);
    Handle &y(int yv);

private:
    UPoint *up;

    void copy_on_write();
};

#endif // HANDLE_H
