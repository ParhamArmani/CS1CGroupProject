#ifndef POLYGON_H
#define POLYGON_H
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

class polygon : public shape
{
    polygon(QPaintDevice* device = nullptr,int id=-1) : shape(device,id,shapeType::polygon){}

    void set_point(const QPoint& point);

    void draw(QPainter &p);
    void move(const int newX, const int newY);
    double area() const;
    double perimeter() const;

private:
    CS1C::vector<QPoint> points;
};
}

#endif // POLYGON_H
