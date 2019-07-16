
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
    QPen p(paint.pen());
    p.setColor(Qt::GlobalColor());
    paint.setPen(p);
    pen = p;
    get_qpainter().save();
}
void shape::setPenStyle(Qt::PenStyle)
{
    QPen p(paint.pen());
    p.setStyle(Qt::PenStyle());
    paint.setPen(p);
    pen = p;
}
void shape::setPenWidth(int w)
{
    QPen p(paint.pen());
    p.setWidth(w);
    paint.setPen(p);
    pen = p;
}
void shape::setPenCap(Qt::PenCapStyle)
{
    QPen p(paint.pen());
    p.setCapStyle(Qt::PenCapStyle());
    paint.setPen(p);
    pen = p;

}
void shape::setPenJoint(Qt::PenJoinStyle)
{
    QPen p(paint.pen());
    p.setJoinStyle(Qt::PenJoinStyle());
    paint.setPen(p);
    pen = p;
}
void shape::setBrushColor(Qt::GlobalColor)
{
    QPen p(paint.pen());
    QBrush b(p.brush());
    b.setColor(Qt::GlobalColor());
    p.setBrush(b);
    paint.setPen(p);
    pen = p;
}
void shape::setBrushStyle(Qt::BrushStyle)
{
//    QPen p(paint.pen());
    QBrush b(paint.brush());
    b.setStyle(Qt::BrushStyle());
//    p.setBrush(b);
    paint.setBrush(b);
//    paint.setPen(p);
    brush = b;
}
void shape::setCoords(int x, int y)
{
    x1 = x;
    y1 = y;
}


void shape::setTextSize()
{

}



text::text()
{

}

text::text(string txt)
{
    QString asd();
}

void text::draw(const int translateX, const int translateY)
{
    paint.
}

void text::move(const int newX, const int newY)
{
    setCoords(newX, newY);
}

double text::perimiter()
{
    return 0;
}

double text::area()
{
    return 0;
}
