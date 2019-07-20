#ifndef SHAPES_H
#define SHAPES_H

#include "shapes.h"

class Line : public Shape
{
public:
    Line();
    Line(QPaintDevice* device = nullptr, int id = -1);
    Line(QPaintDevice* device = nullptr, int id = -1, int x =0, int y=0);
    ~Line();

    void setEnd(int endX, int endY);
    void setStart(int startX, int startY);

    void move(const int x, const int y);

    void draw(QPaintDevice* device);

    double getArea();
    double getPerimeter();

private:
    int startX;
    int startY;
    int endX;
    int endY;

};

#endif // LINE_H
