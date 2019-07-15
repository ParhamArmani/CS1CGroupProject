
#include "shapes.h"

shape::shape(QPaintDevice* device = nullptr, int i = -1, shapeType s = shapeType::noShape)
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
}
void shape::setPen(Qt::GlobalColor)
{
    QPen newPen;
    newPen.setColor(Qt::GlobalColor());
    paint.setPen(newPen);
}
void shape::setBrush(Qt::GlobalColor, Qt::BrushStyle)
{
    QBrush newBrush;
    newBrush.setColor(Qt::GlobalColor());
    newBrush.setStyle(Qt::BrushStyle());
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

}
void shape::setPenBrush(QBrush)
{

}
void shape::setPenStyle(QPen)
{

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
    QString* n = new QString();
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