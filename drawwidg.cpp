#include "drawwidg.h"
#include "shape.h"
#include "rectangle.h"
#include "ellipse.h"
#include "Line.h"
#include "polyline.h"
#include "polygon.h"
#include "text.h"
#include "shapeparser.h"
#include "vector.h"

drawWidg::drawWidg(QWidget *parent) : QWidget(parent)
{

}

void drawWidg::paintEvent(QPaintEvent * /* event */)
{
    rectangle r;
    r.setWidth(10);
    r.setHeight(10);
    r.setCoords(50,50);
    r.setBrush(Qt::blue, Qt::BrushStyle::SolidPattern);
    r.setPen(Qt::black, 4, Qt::PenStyle::SolidLine, Qt::PenCapStyle::FlatCap, Qt::PenJoinStyle::RoundJoin);
    r.draw();
    QPainter painter(this);
    painter.begin(this);
    painter.drawLine(QPoint(50,60), QPoint(100,100));
    painter.setBrush(Qt::BDiagPattern);
    painter.drawRect(QRect(150,120,80,30));
//    text* eqwe = new text;
//    eqwe->setSize(20);
//    eqwe->setCoords(200,200);
//    eqwe->setString("hello there help");
//    eqwe->draw();
//    dw = new drawWidg;
//    dw->setShape(eqwe);
//    dw->update();
}
void drawWidg::setShape(shape* currentShape)
{
    shapePtr = currentShape;
}
