#include "rectangle.h"


rectangle::rectangle(QPaintDevice* device, int id, shapeType s)
    :shape(device, id, s)
{

}
rectangle::rectangle(QPaintDevice* device, int id, shapeType s, int x1, int y1, int w, int h)
    :shape(device, id, s), w{w}, h{h}
{
    setCoords(x1, y1);
}
void rectangle::set_rect(const QRect& rect)
{
   this->rect=rect;

}
void rectangle::setWidth(int width)
{
    w = width;
}
void rectangle::setHeight(int height)
{
    h = height;
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
    area = 3.14*(static_cast<double>(rect.width())/2)*(static_cast<double>(rect.height())/2);
    return area;
}

double ellipse::perimeter()
{
    double perim;

    perim =2*3.14*sqrt((pow(static_cast<double>(rect.width()),2)+pow(static_cast<double>(rect.height()),2))/2);

    return perim;
}
