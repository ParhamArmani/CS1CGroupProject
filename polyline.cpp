#include "polyline.h"

using namespace std;

    /**
     * @brief Construct a new Polyline:: Polyline object
     * 
     * @param points : is a parameter of type QPoint
     * @param brush : is a parameter of type Qbrush
     * @param pen  : is parameter of the type QPen
     */
    Polyline::Polyline(vector<QPoint> points, const QBrush &brush, const QPen &pen)
                    :Shape{QPoint{}, brush, pen}, points{}}
    {
        setCenter();
    }


    /**
     * @brief Construct a new Polyline:: Polyline object (Move constructor)
     * 
     * @param move : is a parameter of type Object Polyline
     */
    Polyline::Polyline(Polyline &&move)noexcept
    {
        swap(move);
        swap(points, move.points);
    }

    /**
     * @brief Function to draw the Polyline
     * 
     * @param device : is a parameter of the QpaintDevice Type
     */
    void Polyline::draw(QPaintDevice *device) const
    {
        auto paint = getPainter(device);
        paint->drawPolyline(points.data(), points.size());
    }

    /**
     * @brief Function to return the Area of the polyline (Default -1)
     * 
     * @return -1 :cPolyline has no area since it's not enclosed. 
     */
    double Polyline::area() const
    {
        return -1;
    }

    /**
     * @brief Function to return the perimeter of the poliline object
     * 
     * @return -1 : Polyline has no perimeter since it's not enclosed. 
     */
    double Polyline::perimeter() const
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
