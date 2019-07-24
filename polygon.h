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
public:
    polygon(QPaintDevice* device = nullptr,int id=-1) : shape(device,id,shapeType::polygon){}

    void set_point(const QPoint& point);

    void draw(QPainter &p, QPaintDevice* device) override;
    void move(const int newX, const int newY)override;
    double area() const override;
    double perimeter() const override;

private:
    CS1C::vector<QPoint> points;
};
}

#endif // POLYGON_H
