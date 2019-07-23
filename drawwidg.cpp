#include "drawwidg.h"
#include "shape.h"
#include "rectangle.h"

drawWidg::drawWidg(QWidget *parent) : QWidget(parent)
{

}

void drawWidg::paintEvent(QPaintEvent * /* event */)
{
    rectangle r;
    r.setWidth(10);
    r.setHeight(10);
    r.setCoords(50,50);
    r.draw();
    this->setStyleSheet("background-color:white");
    this->show();
    QPainter painter(this);
    painter.begin(this);
    painter.drawLine(QPoint(50,60), QPoint(100,100));
    painter.setBrush(Qt::BDiagPattern);
    painter.drawRect(QRect(150,120,80,30));
    QRect asd(10,10,10,10);
    painter.drawText(200,200,"hello there help");
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
