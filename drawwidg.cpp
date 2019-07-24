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
//using namespace Shapes;

drawWidg::drawWidg(QWidget *parent) : QWidget(parent)
{

}

void drawWidg::paintEvent(QPaintEvent * /* event */)
{
    QPainter painter(this);

    Line l(this);
    l.setCoords(20,90);
    l.setStart(20,90);
    l.setEnd(100,20);
//    l.setPenColor(Qt::blue);
//    l.setPenWidth(2);
//    l.setPenStyle(Qt::PenStyle::DashDotLine);
//    l.setPenCap(Qt::PenCapStyle::FlatCap);
//    l.setPenJoint(Qt::PenJoinStyle::MiterJoin);
    l.draw(painter);

    rectangle r(this);
    r.setCoords(20,200);
    r.setWidth(170);
    r.setHeight(100);
//    r.setPenColor(Qt::blue);
//    r.setPenWidth(0);
//    r.setPenStyle(Qt::PenStyle::DashDotLine);
//    r.setPenCap(Qt::PenCapStyle::RoundCap);
//    r.setPenJoint(Qt::PenJoinStyle::RoundJoin);
//    r.setBrushColor(Qt::red);
//    r.setBrushStyle(Qt::VerPattern);
    r.draw(painter);

    rectangle s(this);
    s.setCoords(250,150);
    s.setWidth(200);
    s.setHeight(200);
//    s.setPenColor(Qt::red);
//    s.setPenWidth(0);
//    s.setPenStyle(Qt::PenStyle::SolidLine);
//    s.setPenCap(Qt::PenCapStyle::RoundCap);
//    s.setPenJoint(Qt::PenJoinStyle::RoundJoin);
//    s.setBrushColor(Qt::blue);
//    s.setBrushStyle(Qt::HorPattern);
    s.draw(painter);

    ellipse e(this);
    e.setCoords(520,200);
    e.setWidth(170);
    e.setHeight(100);
//    e.setPenColor(Qt::black);
//    e.setPenWidth(12);
//    e.setPenStyle(Qt::PenStyle::SolidLine);
//    e.setPenCap(Qt::PenCapStyle::FlatCap);
//    e.setPenJoint(Qt::PenJoinStyle::MilterJoin);
//    e.setBrushColor(Qt::white);
//    e.setBrushStyle(Qt::NoBrush);
    e.draw(painter);

    ellipse c(this);
    c.setCoords(750,150);
    c.setWidth(200);
    c.setHeight(200);
//    c.setPenColor(Qt::black);
//    c.setPenWidth(12);
//    c.setPenStyle(Qt::PenStyle::SolidLine);
//    c.setPenCap(Qt::PenCapStyle::RoundCap);
//    c.setPenJoint(Qt::PenJoinStyle::MilterJoin);
//    c.setBrushColor(Qt::magenta);
//    c.setBrushStyle(Qt::SolidPattern);
    c.draw(painter);

    text t(this);
//    t.setSize(12);
    t.setString(QString("Class Project 2 - 2D Graphics Modeler"));
    t.setCoords(250,425);
    t.setWidth(500);
    t.setHeight(50);
//    t.setStyle(QFont::Style::StyleItalic);
//    t.setWeight(QFont::Weight::Bold);
//    t.setBrushColor(Qt::black);
//    t.setPenColor(Qt::black);
    t.draw(painter);



    for(int i = 0; i < shapeList.size(); i++)
        shapeList[i]->draw(painter);

}
void drawWidg::drawShapes()
{
//    QPainter asd;
//    asd.begin(this);
//    QRect f(60,60,30,40);
//    asd.drawRect(f);
    QPainter painter(this);
    rectangle r(this);
    r.setCoords(5,5);
    r.setWidth(50);
    r.setHeight(30);
    r.setPen(Qt::GlobalColor::blue, 5, Qt::PenStyle::SolidLine, Qt::PenCapStyle::RoundCap, Qt::PenJoinStyle::RoundJoin);
    r.draw(painter);
    for(int i = 0; i < shapeList.size(); i++)
        shapeList[i]->draw(painter);
}

void drawWidg::setShapeList(vector<shape *> old)
{
    shapeList = old;
}
