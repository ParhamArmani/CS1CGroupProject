#include "ellipse.h"


namespace Shapes {

/**
 * @brief Function to set the height of the ellipes
 *
 * @param newH : is the parameter of type int (Height of the Ellipse)
 */
void ellipse::setHeight(int newH)
{
    h = newH;
}

/**
 * @brief Function to set the width of the ellipes
 *
 * @param newW : is the parameter of type int (Width of the Ellipse)
 */
void ellipse::setWidth(int newW)
{
    w = newW;
}

/**
 * @brief Function to Draw an ellipse.
 *
 *This function will be using QT painter and Shape Functions to draw the Ellipse.
 */
void ellipse::draw(QPainter &p, QPaintDevice* device)
{
    getQpainter().setPen(getPen());
    getQpainter().setBrush(getBrush());
    getQpainter().save();

    getQpainter().drawEllipse(rect);
    getQpainter().restore();
    p.drawEllipse(getX(),getY(),w,h);
}

/**
 * @brief  Function to move the Ellipse
 *
 * @param newX
 * @param newY
 */
void ellipse::move(const int newX, const int newY)
{
    rect.setRect(newX,newY,rect.height(),rect.width());
}

/**
 * @brief Function to return the area of an ellipse.
 *
 * @return Area(Double) : Based on the formula Pi*(width/2)*(height/2)
 */
double ellipse::area()const
{
    double area;
    //rect.width();
    //rect.height();
    area = 3.14*(static_cast<double>(rect.width())/2)*(static_cast<double>(rect.height())/2);
    return area;
}

/**
 * @brief Function to return the Perimeter of an ellipse
 *
 * @return Perimeter: Based on pi/2* width^2 + height^2
 */
double ellipse::perimeter()const
{
    double perim;

    perim =2*3.14*sqrt((pow(static_cast<double>(rect.width()),2)+pow(static_cast<double>(rect.height()),2))/2);

    return perim;
}
}
