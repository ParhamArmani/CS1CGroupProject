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
    QRect t;
    t.setWidth(10);
    t.setWidth(10);
    QPainter painter(this);
    painter.begin(this);
    painter.drawLine(QPoint(50,60), QPoint(100,100));
    painter.setBrush(Qt::BDiagPattern);
    painter.drawRect(QRect(150,120,80,30));

    for(int i = 0; i < shapeList.size(); i++)
        shapeList[i]->draw();

//    text* eqwe = new text;
//    eqwe->setSize(20);
//    eqwe->setCoords(200,200);
//    eqwe->setString("hello there help");
//    eqwe->draw();
}
void drawWidg::setShape(shape* currentShape)
{
    shapePtr = currentShape;
}
void drawWidg::setShapeList(vector<shape *> old)
{
    shapeList = old;
}
