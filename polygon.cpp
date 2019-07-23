#include "polygon.h"

using namespace std;

/**
 * @brief Construct a new Polygon:: Polygon object (Default Constructor)
 * 
 * @param points : is a parameter of QPoint
 * @param brush : is a parameter of Qbrush
 * @param pen : is a parameter of Qpen
 */
Polygon::Polygon(vector<QPoint> points, const QBrush &brush, const QPen &pen)
        : PolyLine{move(points), brush, pen}
{

}

/**
 * @brief Construct a new Polygon:: Polygon object (Move Constructor)
 * 
 * @param move : is a parameter of type Polygon
 */

Polygon::Polygon(Polygon &&move) noexcept
{
    swap(move);
    swap(points, move.points);
}

/**
 * @brief Function to draw the Polygon Object
 * 
 * @param device: is a parameter of type QpaintDevice
 */
void Polygon::draw(QPaintDevice* device) const
{
    auto paint = getPainter(device);
    paint->drawPolygon(points.data(), points.size());
}

/**
 * @brief Function to retyrn the Area of a Polygon
 * Pre: Recieves no parameters
 * @return Area(Double) : Area of a polygon
 */

double Polygon::area()const
{
    double area = 0;

    for(int i=points.start; i<points.end(); i++)
    {
        const QPoint &first = *i;
        const QPoint &second = points.end();

        area += ((start.x()*start.y())-(start.y()*start.x()));
    }
    return area;
}

/**
 * @brief Function to return the Perimeter of the Polygon
 * 
 * @return Perimeter:  is value of type Double , represents the Perimeter of the Polygon.
 */
double Polygon::perimeter()const
{
    double perimeter = 0;

    for(int i=points.start; i<points.end(); i++)
    {
        const QPoint &first = *i;
        const QPoint &second = points.end();

        perimeter += sqrt((first-second), (first-second));
    }
    return perimeter;
}
