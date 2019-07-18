#include "rectangle.h"

void rectangle::set_rect(const QRect& rect)
{
   this->rect=rect;

}
void rectangle::draw()
{
    getQpainter().setPen(getPen());
    getQpainter().setBrush(getBrush());
    getQpainter().save();
    getQpainter().drawRect(rect);
    getQpainter().restore();
}

void rectangle::move(const int newX, const int newY)
{
    rect.setRect(newX,newY,rect.height(),rect.width());
    setCoords(newX, newY);
}

double rectangle::area()
{
    double area;
    rect.width();
    rect.height();
    area=static_cast<double>(rect.width())*(static_cast<double>(rect.height()));
    return area;
}

double rectangle::perimeter()
{
    double perim;
    perim = (rect.width() * 2) + (rect.height()*2);
    perim = static_cast<double>(perim);

    return perim;
}

//ellipse
void ellipse::set_ellipse(const QRect& rect)
{
     this->rect=rect;
}
void ellipse::draw()
{
    getQpainter().setPen(getPen());
    getQpainter().setBrush(getBrush());
    getQpainter().save();

    getQpainter().drawEllipse(rect);
    getQpainter().restore();
}

void ellipse::move(const int newX, const int newY)
{
    rect.setRect(newX,newY,rect.height(),rect.width());
}


double ellipse::area()
{
    double area;
    //rect.width();
    //rect.height();

    area=static_cast<double>(rect.width())*(static_cast<double>(rect.height()));
    area = 3.14*(static_cast<double>(rect.width())/2)*(static_cast<double>(rect.height())/2);
    return area;
}

double ellipse::perimeter()
{
    double perim;

    perim =2*3.14*sqrt((pow(static_cast<double>(rect.width()),2)+pow(static_cast<double>(rect.height()),2))/2);

    return perim;
}
