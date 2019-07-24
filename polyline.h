#ifndef POLYLINE_H
#define POLYLINE_H

#include <QPoint>
#include <string>
#include <cmath>
#include <QBrush>
#include <QPoint>
#include <QPen>
#include <QPainter>
#include "vector.h"
#include "shapes.h"


namespace Shapes {

class polyline : public shape
{
public:
    polyline(QPaintDevice* device = nullptr,int id=-1) : shape(device,id,shapeType::polyline){}
    ~polyline() {}
    void set_point(const QPoint& point);
    void draw(QPainter &p, QPaintDevice* device);
    void move(const int newX, const int newY);

    double area()const;
    double perimeter()const;

private:
    CS1C::vector<QPoint> points;
};
}

#endif // POLYLINE_H
