#include "polyline.h"

using namespace std;

Polyline::Polyline(vector<QPoint> points, const QBrush &brush, const QPen &pen)
                   :Shape{QPoint{}, brush, pen}, points{}}
{
    setCenter();
}

    Polyline::Polyline(Polyline &&move)noexcept
    {
        swap(move);
        swap(points, move.points);
    }

    void Polyline::draw(QPaintDevice *device) const
    {
        auto paint = getPainter(device);
        paint->drawPolyline(points.data(), points.size());
    }

    double Polyline::getArea() const
    {
        return -1;
    }

    double Polyline::getPerimeter() const
    {
        return -1;
    }

    void Polyline::setPoint(const QPoint &point)
    {
        points[i] = point - getPos();
    }

    void Polyline::insertPoint(const QPoint &point)
    {
        points.insert(points.begin() + before, point - getPos());
    }

    void Polyline::clearPoint()
    {
        points.clear();
    }
