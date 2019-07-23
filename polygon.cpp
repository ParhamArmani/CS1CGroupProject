#include "polygon.h"

using namespace std;

Polygon::Polygon(vector<QPoint> points, const QBrush &brush, const QPen &pen)
        : PolyLine{move(points), brush, pen}
{

}

Polygon::Polygon(Polygon &&move) noexcept
{
    swap(move);
    swap(points, move.points);
}

void Polygon::draw(QPaintDevice* device) const
{
    auto paint = getPainter(device);
    paint->drawPolygon(points.data(), points.size());
}

double Polygon::getArea()const
{
    double area = 0;

    for(int i=points.start; i<points.end(); i++)
    {
        const QPoint &first = *i;
        const QPoint &second = points.end();

        area += ((start.x()*start.y())-(start.y()*start.x()));
    }
}

double Polygon::getPerimeter()const
{
    double perimeter = 0;

    for(int i=points.start; i<points.end(); i++)
    {
        const QPoint &first = *i;
        const QPoint &second = points.end();

        perimeter += sqrt((first-second), (first-second));
    }
}
