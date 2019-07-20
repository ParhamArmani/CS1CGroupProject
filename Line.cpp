#include "line.h"

Line::Line() : shape()
{

}

Line::Line(QPaintDevice* device, int id, shapeType::line)
{

}

Line::Line(QPaintDevice* device, int id, shapeType::line, int x, int y)
{
    setCoords(x, y);
}

void Line::draw(QPaintDevice* device)
{
    auto paint = getPainter(device);
    paint -> drawLine(startX, startY, endX, endY)
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
