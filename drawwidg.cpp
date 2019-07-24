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
    text t(this);
    t.setSize(12);
    t.setString(QString("help"));
    t.setCoords(60,60);
    t.setStyle(QFont::Style::StyleItalic);
    t.setWeight(QFont::Weight::Bold);
    t.setBrushColor(Qt::black);
    t.setPenColor(Qt::black);
    t.draw();

    QPainter painter(this);
    QRect asd;
    asd.setX(0);
    asd.setY(0);
    asd.setHeight(5);
    asd.setWidth(5);
    painter.drawRect(asd);
//    text tx(this);

//    painter.begin(this);
//    painter.drawLine(QPoint(50,60), QPoint(100,100));
//    painter.setBrush(Qt::BDiagPattern);
//    painter.drawRect(QRect(150,120,80,30));

//    for(int i = 0; i < shapeList.size(); i++)
//        shapeList[i]->draw();

}
void drawWidg::drawShapes()
{
    for(int i = 0; i < shapeList.size(); i++)
        shapeList[i]->draw();
}

void drawWidg::setShapeList(vector<shape *> old)
{
    shapeList = old;
}
