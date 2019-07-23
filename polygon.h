#ifndef POLYGON_H
#define POLYGON_H

#include "Polyline.h"

using namespace std;

class Polygon : public Polyline
{
public:

    Polygon(vector<QPoint> points={}, const QBrush &brush={}, const QPen &pen={});
    Polygon(Polygon &&move) noexcept;
    Polygon();

    void draw(QPaintDevice* device);

    double getPerimeter();
    double getArea();



};

#endif // POLYGON_H
