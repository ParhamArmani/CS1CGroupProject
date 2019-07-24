
#include "shapes.h"


namespace Shapes {

shape::shape(QPaintDevice* device, int id, shapeType s) : paint{device}, s{s}, id{id}
{
    pen = Qt::SolidLine;
    brush = Qt::NoBrush;
}

shape::~shape()
{

}

const QPen& shape::getPen() const
{
    return paint.pen();
}

const QBrush& shape::getBrush() const
{
    return paint.brush();
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
 * @param Qt::PenCapStyle: Cap style of the pen.
 * @param Qt::PenJoinStyle: Join style of the pen
 */
void shape::setPen(Qt::GlobalColor, int width, Qt::PenStyle, Qt::PenCapStyle, Qt::PenJoinStyle)
{
    QPen newPen;
    newPen.setColor(Qt::GlobalColor());
    newPen.setWidth(width);
    newPen.setStyle(Qt::PenStyle());
    newPen.setCapStyle(Qt::PenCapStyle());
    newPen.setJoinStyle(Qt::PenJoinStyle());
    paint.setPen(newPen);
    pen = newPen;
}

/**
 * @brief Function to set the Brush of the QT object.
 * @param Qt::GlobalColor: to set the global color of the qt object
 * @param Qt::BrushStyle: to set the BrushStyle of the qt object.
 */
void shape::setBrush(Qt::GlobalColor, Qt::BrushStyle)
{
    QBrush newBrush;
    newBrush.setColor(Qt::GlobalColor());
    newBrush.setStyle(Qt::BrushStyle());
    paint.setBrush(newBrush);
    brush = newBrush;
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

/**
 * @brief Function to set the color of the pen of the QT device.
 * @param Qt::GlobalColor : global color of the Qt object.
 * 
 */
void shape::setPenColor(Qt::GlobalColor)
{
    pen.setColor(Qt::GlobalColor());
    paint.setPen(pen);
}

/**
 * @brief Function to set the pen style of the qt painter object.
 * @param Qt::PenStyle : the style of the pen of the qt painter object.
 * 
 */
void shape::setPenStyle(Qt::PenStyle)
{
    pen.setStyle(Qt::PenStyle());
    paint.setPen(pen);
}

/**
 * @brief Function to set the width of the QT pen.
 * 
 * @param w : the an integer which the width of the pen will be set to.
 */
void shape::setPenWidth(int w)
{
    pen.setWidth(w);
    paint.setPen(pen);
}

/**
 * @brief Set the Pen Cap of the QT object Shape.
 * @param Qt::PenCapStyle: is the Cap pen style of the qt painter object.
 */

void shape::setPenCap(Qt::PenCapStyle)
{
    pen.setCapStyle(Qt::PenCapStyle());
    paint.setPen(pen);
}

/**
 * @brief set the Pen joiint property of the QT Object
 * @param Qt::PenJoinStyle: 
 */

void shape::setPenJoint(Qt::PenJoinStyle)
{
    pen.setJoinStyle(Qt::PenJoinStyle());
    paint.setPen(pen);
}

/**
 * @brief set the Brush Color property of the QT Object
 * @param Qt::GlobalColor: Color variable of the QT object.
 */
void shape::setBrushColor(Qt::GlobalColor)
{
    brush.setColor(Qt::GlobalColor());
    pen.setBrush(brush);
    paint.setBrush(brush);
}

/**
 * @brief set the Brush Color property of the QT Object
 * @param Qt::GlobalColor: Color variable of the QT object.
 */
void shape::setBrushStyle(Qt::BrushStyle)
{
    brush.setStyle(Qt::BrushStyle());
    pen.setBrush(brush);
    paint.setBrush(brush);
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
    return paint;
}
}
