#include "Line.h"

//Line::Line() : shape()
//{}

/**
 * @brief Construct a new Line:: Line object
 * 
 * @param device: is a parameter of the type QPainterDevice
 * @param id : is the parameter of the Type int
 * @param s : is the parameter of the type ShapeType
 */
Line::Line(QPaintDevice* device, int id, shapeType s)
    :shape(device, id, s)
{

}

/**
 * @brief Construct a new Line:: Line object
 * 
 * @param device :is a parameter of the type QPainterDevice
 * @param id :is the parameter of the Type int
 * @param s :is the parameter of the Type ShapeType
 * @param x :is the parameter of the Type int
 * @param y :is the parameter of the Type int
 */
Line::Line(QPaintDevice* device, int id, shapeType s, int x, int y)
    :shape(device, id, s)
{
    setCoords(x, y);
}

/**
 * @brief Destroy the Line:: Line object
 * 
 * 
 */
Line::~Line(){}

/**
 * @brief Function to draw the line. 
 * Pre: Recieves no parameters
 */
void Line::draw()
{
    getQpainter().drawLine(startX, startY, endX, endY);
}

/**
 * @brief Function to return the Area of the line (Default -1)
 * 
 * @return -1 :is a number of type Double since line doesn't have an area 
 */
double Line::area() const
{
    return -1;
}

/**
 * @brief Function to return the Perimeter of the line (Default -1)
 * 
 * @return -1 :is a number of type Double since line doesn't have an perimeter 
 */
double Line::perimeter() const
{
    return -1;
}

/**
 * @brief Function to move the line object to the new coordinate
 * 
 * @param x : is the x coorndinate of type int
 * @param y : is the y coorndinate of type int
 */
void Line::move(const int x, const int y)
{
    setCoords(x,y);
}
