#include "polyline.h"

namespace Shapes{

void polyline::set_point(const QPoint& point)
{
   points.push_back(point);
}

void polyline::draw(QPainter &p, QPaintDevice* device)
{
    getQpainter().setPen(getPen());
    getQpainter().setBrush(getBrush());
    getQpainter().save();
    getQpainter().drawPolyline(points.begin(),points.size());
    getQpainter().restore();
    p.drawPolyline(points.begin(), points.size());
}

void polyline::move(const int newX, const int newY)
{
    for(int i =0;i < points.size();i++)
    {
       points[i].setX(newX+ points[i].x());
       points[i].setY(newY+ points[i].y());
    }
}

double polyline::area()const
{
    double area=0;

    return area;
}

double polyline::perimeter()const
{
   double perim=0;
   double hold=0;

   for(int i = 0;i < points.size()-1;i++)
   {
       //distance formula
       hold = sqrt(pow(points[i+1].x()- points[i].x(),2)+ pow(points[i+1].y()- points[i].y(),2));
       perim+=hold;
   }

   return perim;
}
}
