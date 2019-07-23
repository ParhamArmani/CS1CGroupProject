#include "Line.h"

//Line::Line() : shape()
//{}

Line::Line(QPaintDevice* device, int id, shapeType s)
    :shape(device, id, s)
{

}

Line::Line(QPaintDevice* device, int id, shapeType s, int x, int y)
    :shape(device, id, s)
{
    setCoords(x, y);
}

Line::~Line(){}

void Line::draw()
{
    getQpainter().drawLine(startX, startY, endX, endY);
}

double Line::area()
{
    return -1;
}

double Line::perimeter()
{
    return -1;
}

void Line::move(const int x, const int y)
{
    setCoords(x,y);
}
