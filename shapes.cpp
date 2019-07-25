
#include "shapes.h"


namespace Shapes {

shape::shape(QPaintDevice* device, int id, shapeType s) : paintType(device), s{s}, id{id}
{
//    pen = Qt::SolidLine;
//    brush = Qt::NoBrush;
}

shape::~shape()
{

}

int shape::getId() const
{
    return id;
}

const QPen& shape::getPen() const
{
    return paintType.pen();
}

const QBrush& shape::getBrush() const
{
    return paintType.brush();
}

/**
 * @brief sets the shape
 * This function 
 * @param shape: Shape is a shapeType Element
 */
void shape::setShape(shapeType shape)
{
    s = shape;
}
/**
 * @brief : Function to set the Color, width, penStyle of the shape.
 * @param Qt::GlobalColor: color of the pen
 * @param width : width of the pen
 * @param Qt::PenStyle: style of the pen
 * @param Qt::PenCapStyle: Cap style of the penType.
 * @param Qt::PenJoinStyle: Join style of the pen
 */
void shape::setPen(Qt::GlobalColor c, int width, Qt::PenStyle s, Qt::PenCapStyle cs, Qt::PenJoinStyle js)
{
    penType.setColor(c);
    penType.setWidth(width);
    penType.setStyle(s);
    penType.setCapStyle(cs);
    penType.setJoinStyle(js);
    paintType.setPen(penType);
    return;
}

/**
 * @brief Function to set the Brush of the QT object.
 * @param Qt::GlobalColor: to set the global color of the qt object
 * @param Qt::BrushStyle: to set the BrushStyle of the qt object.
 */
void shape::setBrush(Qt::GlobalColor c, Qt::BrushStyle s)
{
    brushType.setColor(c);
    brushType.setStyle(s);
    paintType.setBrush(brushType);
    return;
}

/**
 * @brief Function to get or return the shape
 * 
 * @return shape::shapeType 
 */
shape::shapeType shape::getShape() const
{
    return s;
}


void shape::setId(int i)
{
    id = i;
}


/**
 * @brief Function to set the color of the pen of the QT device.
 * @param Qt::GlobalColor : global color of the Qt object.
 * 
 */
void shape::setPenColor(Qt::GlobalColor)
{
    penType.setColor(Qt::GlobalColor());
}

/**
 * @brief Function to set the pen style of the qt painter object.
 * @param Qt::PenStyle : the style of the pen of the qt painter object.
 *
 */
void shape::setPenStyle(Qt::PenStyle)
{
    penType.setStyle(Qt::PenStyle());
}

/**
 * @brief Function to set the width of the QT penType.
 *
 * @param w : the an integer which the width of the pen will be set to.
 */
void shape::setPenWidth(int w)
{
    penType.setWidth(w);
}

/**
 * @brief Set the Pen Cap of the QT object Shape.
 * @param Qt::PenCapStyle: is the Cap pen style of the qt painter object.
 */

void shape::setPenCap(Qt::PenCapStyle)
{
    penType.setCapStyle(Qt::PenCapStyle());
}

/**
 * @brief set the Pen joiint property of the QT Object
 * @param Qt::PenJoinStyle:
 */

void shape::setPenJoint(Qt::PenJoinStyle)
{
    penType.setJoinStyle(Qt::PenJoinStyle());
}

/**
 * @brief set the Brush Color property of the QT Object
 * @param Qt::GlobalColor: Color variable of the QT object.
 */
void shape::setBrushColor(Qt::GlobalColor)
{
    brushType.setColor(Qt::GlobalColor());
}

/**
 * @brief set the Brush Color property of the QT Object
 * @param Qt::GlobalColor: Color variable of the QT object.
 */
void shape::setBrushStyle(Qt::BrushStyle)
{
    brushType.setStyle(Qt::BrushStyle());
}
/**
 * @brief Function to set the coordinate the QT object.
 * 
 * @param x : is the length of the shape
 * @param y : is the width of the shape
 */
void shape::setCoords(int x, int y)
{
    x1 = x;
    y1 = y;
}

/**
 * @brief Function to return the X coordinate of the shape
 * 
 * @return int: return the X coordinate of the shape
 */
int shape::getX()
{
    return x1;
}

/**
 * @brief Function to return the Y coordinate of the shape
 * 
 * @return int: return the Y coordinate of the shape
 */
int shape::getY()
{
    return y1;
}

/**
 * @brief Function to return the QPainter Device of Object
 * 
 * @return QPainter& : An object of Qt
 */
QPainter& shape::getQpainter()
{
    return paintType;
}
}
