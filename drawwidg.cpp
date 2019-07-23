#include "drawwidg.h"

drawWidg::drawWidg(QWidget *parent) : QWidget(parent)
{

}

void drawWidg::paintEvent(QPaintEvent * /* event */)
{
    QPainter p(this);
    shapePtr->draw();
}
void drawWidg::setShape(shape* currentShape)
{
    shapePtr = currentShape;
}
