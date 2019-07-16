
#include "shapes.h"

shape::shape(QPaintDevice* device, int i, shapeType s)
{
    id = i;
}
const QPen& shape::getPen() const
{
    QPen p(paint.pen());
    return p;
}
const QBrush& shape::getBrush() const
{
    QBrush b(paint.brush());
    return b;
}
void shape::setShape(shapeType shape)
{
    s = shape;
}
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
void shape::setPen(Qt::GlobalColor)
{
    QPen newPen;
    newPen.setColor(Qt::GlobalColor());
    paint.setPen(newPen);
    pen = newPen;
}
void shape::setBrush(Qt::GlobalColor, Qt::BrushStyle)
{
    QBrush newBrush;
    newBrush.setColor(Qt::GlobalColor());
    newBrush.setStyle(Qt::BrushStyle());
    paint.setBrush(newBrush);
    brush = newBrush;
}

shape::shapeType shape::getShape() const
{
    return s;
}

void shape::setPenColor(Qt::GlobalColor)
{
    pen.setColor(Qt::GlobalColor());
    paint.setPen(pen);
}
void shape::setPenStyle(Qt::PenStyle)
{
    pen.setStyle(Qt::PenStyle());
    paint.setPen(pen);
}
void shape::setPenWidth(int w)
{
    pen.setWidth(w);
    paint.setPen(pen);
}
void shape::setPenCap(Qt::PenCapStyle)
{
    pen.setCapStyle(Qt::PenCapStyle());
    paint.setPen(pen);
}
void shape::setPenJoint(Qt::PenJoinStyle)
{
    pen.setJoinStyle(Qt::PenJoinStyle());
    paint.setPen(pen);
}
void shape::setBrushColor(Qt::GlobalColor)
{
    brush.setColor(Qt::GlobalColor());
    pen.setBrush(brush);
    paint.setBrush(brush);
}
void shape::setBrushStyle(Qt::BrushStyle)
{
    brush.setStyle(Qt::BrushStyle());
    pen.setBrush(brush);
    paint.setBrush(brush);
}
void shape::setCoords(int x, int y)
{
    x1 = x;
    y1 = y;
}
QPainter& shape::getQpainter()
{
    return paint;
}
