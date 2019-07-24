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
    l.setPenColor(Qt::blue);
    l.setPenWidth(2);
    l.setPenStyle(Qt::PenStyle::DashDotLine);
    l.setPenCap(Qt::PenCapStyle::FlatCap);
    l.setPenJoint(Qt::PenJoinStyle::MiterJoin);

    rectangle r(this);
    r.setCoords(20,200);
    r.setWidth(170);
    r.setHeight(100);
    r.setPenColor(Qt::blue);
    r.setPenWidth(0);
    r.setPenStyle(Qt::PenStyle::DashDotLine);
    r.setPenCap(Qt::PenCapStyle::RoundCap);
    r.setPenJoint(Qt::PenJoinStyle::RoundJoin);
    r.setBrushColor(Qt::red);
    r.setBrushStyle(Qt::VerPattern);
    r.draw(painter);

    rectangle s(this);
    s.setCoords(250,150);
    s.setWidth(200);
    s.setHeight(200);
    s.setPenColor(Qt::red);
    s.setPenWidth(0);
    s.setPenStyle(Qt::PenStyle::SolidLine);
    s.setPenCap(Qt::PenCapStyle::RoundCap);
    s.setPenJoint(Qt::PenJoinStyle::RoundJoin);
    s.setBrushColor(Qt::blue);
    s.setBrushStyle(Qt::HorPattern);
    s.draw(painter);

    ellipse e(this);
    e.setCoords(250,150);
    e.setWidth(200);
    e.setHeight(200);
    e.setPenColor(Qt::red);
    e.setPenWidth(0);
    e.setPenStyle(Qt::PenStyle::SolidLine);
    e.setPenCap(Qt::PenCapStyle::RoundCap);
    e.setPenJoint(Qt::PenJoinStyle::RoundJoin);
    e.setBrushColor(Qt::blue);
    e.setBrushStyle(Qt::HorPattern);
    e.draw(painter);

    text t(this);
    t.setSize(12);
    t.setString(QString("help"));
    t.setCoords(60,60);
    t.setStyle(QFont::Style::StyleItalic);
    t.setWeight(QFont::Weight::Bold);
    t.setBrushColor(Qt::black);
    t.setPenColor(Qt::black);
    t.draw(painter);



    drawShapes();
//    QPainter painter(this);
//    QRect asd;
//    asd.setX(0);
//    asd.setY(0);
//    asd.setHeight(5);
//    asd.setWidth(5);
//    painter.drawRect(asd);

//    painter.begin(this);
//    painter.drawLine(QPoint(50,60), QPoint(100,100));
//    painter.setBrush(Qt::BDiagPattern);
//    painter.drawRect(QRect(150,120,80,30));

//    for(int i = 0; i < shapeList.size(); i++)
//        shapeList[i]->draw();

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
