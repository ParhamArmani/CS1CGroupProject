#include "polygon.h"

namespace Shapes {

void polygon::set_point(const QPoint& point)
{
   points.push_back(point);
}

void polygon::draw(QPainter &p)
{
    getQpainter().setPen(getPen());
    getQpainter().setBrush(getBrush());
    getQpainter().save();
    getQpainter().drawPolygon(points.begin(),points.size());
    getQpainter().restore();
}

void polygon::move(const int newX, const int newY)
{
    for(int i =0;i < points.size();i++)
    {
       points[i].setX(newX+ points[i].x());
       points[i].setY(newY+ points[i].y());
    }
}

double polygon::area()const
{
    //area of rectangle formed by largest and smallest x & y values
    int smallx = points[0].x();
    int bigx = points[0].x();
    int smally =points[0].y();
    int bigy = points[0].y();;
    double area=0;


    for(int i =0;i < points.size();i++)
    {
         //min x
        if(points[i].x ()< smallx)
        {
            smallx=points[i].x();
        }

        //max x
        if(points[i].x ()>bigx)
        {
            bigx=points[i].x();
        }

        //min y
        if(points[i].y ()< smally)
        {
            smally=points[i].y();
        }

        //max y
        if(points[i].y ()>bigy)
        {
            bigy=points[i].y();
        }
     }
    //area of rectangle formed
    area=(bigx-smallx)*(bigy-smally);

    return area;
}

double polygon::perimeter()const
{
    double perim=0;
    double hold;

    for(int i = 0;i < points.size()-1;i++)
    {
        // distance formula
        hold = sqrt(pow(points[i+1].x()- points[i].x(),2)+ pow(points[i+1].y()- points[i].y(),2));
        perim+=hold;
    }

    return perim;
}
}
