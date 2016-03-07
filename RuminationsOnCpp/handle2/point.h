#ifndef POINT_H
#define POINT_H

class Point
{
public:
    Point();
    Point(int x, int y);

    int x() const { return xval; }
    int y() const { return yval; }

    Point &x(int xv) { xval = xv; return *this; }
    Point &y(int yv) { yval = yv; return *this; }

private:
    int xval, yval;
};

#endif // POINT_H
