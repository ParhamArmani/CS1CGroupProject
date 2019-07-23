#include "rectangle.h"


/**
 * @brief Construct a new rectangle::rectangle object
 * 
 * @param device : is a parameter of QPaintDevice Type
 * @param id : is a parameter of int Type
 * @param s :is a parameter of ShapeType
 * @param x1 : is a parameter of int Type (X coordinate of the Shape)
 * @param y1 : is a parameter of int Type (Y coordinate of the shape)
 * @param w : is a parameter of int ( Width of the Shape)
 * @param h : is the parameter of int ( Height of the Shape)
 */
rectangle::rectangle(QPaintDevice* device, int id, shapeType s, int x1, int y1, int w, int h)
    :shape(device, id, s), w{w}, h{h}
{
    setCoords(x1, y1);
}

/**
 * @brief  Function to set the Rectangle 
 * 
 * @param rect : is the Parameter of Type QRect
 */
void rectangle::set_rect(const QRect& rect)
{
   this->rect=rect;

}

/**
 * @brief Function to set the Width of the Rectangle
 * 
 * @param width : is the parameter of the type Int ( Width of the Rectangle)
 */
void rectangle::setWidth(int width)
{
    w = width;
}

/**
 * @brief Function to set the Height of the Rectangle
 * 
 * @param height : is the parameter of type int (Height of the Rectangle)
 */
void rectangle::setHeight(int height)
{
    h = height;
}

/**
 * @brief Function to Draw the Rectangle Shape.
 * Requires no Parameter
 */
void rectangle::draw()
{
    getQpainter().setPen(getPen());
    getQpainter().setBrush(getBrush());
    getQpainter().save();
    getQpainter().drawRect(rect);
    getQpainter().restore();
}

/**
 * @brief  Function to move the shape
 * 
 * @param newX 
 * @param newY 
 */
void rectangle::move(const int newX, const int newY)
{
    rect.setRect(newX,newY,rect.height(),rect.width());
    setCoords(newX, newY);
}


/**
 * @brief Function return the Area of the rectangle
 * 
 * @return AREA  : area of the rectangle width * height
 */
double rectangle::area()const
{
    double area;
    rect.width();
    rect.height();
    area=static_cast<double>(rect.width())*(static_cast<double>(rect.height()));
    return area;
}

/**
 * @brief Function return the Perimeter of the rectangle
 * 
 * @return Perimeter : Perimeter of the rectangle 2(width + height)
 */
double rectangle::perimeter()const
{
    double perim;
    perim = (rect.width() * 2) + (rect.height()*2);
    perim = static_cast<double>(perim);

    return perim;
}
