#include "ellipse.h"

/**
 * @brief Function to set the ellipse based on rectangle
 *
 * @param rect : is a QTrect object
 * This function will set an ellipse based on the height and width of a rectangle.
 */
void ellipse::set_ellipse(const QRect& rect)
{
     this->rect=rect;
}

/**
 * @brief Function to Draw an ellipse.
 *
 *This function will be using QT painter and Shape Functions to draw the Ellipse.
 */
void ellipse::draw()
{
    getQpainter().setPen(getPen());
    getQpainter().setBrush(getBrush());
    getQpainter().save();

    getQpainter().drawEllipse(rect);
    getQpainter().restore();
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
