#include "Line.h"

Line::Line() : shape()
{

}

Line::Line(QPaintDevice* device, int id)
    :shape(device, id, shapeType::line)
{

}

Line::Line(QPaintDevice* device, int id, int x, int y)
    :shape(device, id, shapeType::line)
{
    setCoords(x, y);
}

void Line::draw(QPaintDevice* device)
{
    getQpainter().drawLine(startX, startY, endX, endY);
}

double Line::getArea()
{
    return -1;
}

double Line::getPerimeter()
{
    return -1;
}

void Line::move(const int x, const int y)
{
    setCoords(x,y);
}
