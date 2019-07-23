#ifndef POLYLINE_H
#define POLYLINE_H

#include "shapes.h"

using namespace std;


class Polyline : public shape
{
public:
    Polyline(vector<QPoint> points = {}, const QBrush &brush = {}, const QPen &pen ={});
    ~Polyline();

    Polyline(Polyline &&move)noexcept;


    void draw();

    double area()const override;
    double perimeter()const override;

    void setPoint(const QPoint &point);
    void insertPoint(const QPoint &point);
    void clearPoint();


private:
    vector<QPoint> points;
    int pts;

};

#endif // POLYLINE_H
