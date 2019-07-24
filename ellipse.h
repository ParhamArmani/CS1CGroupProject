#ifndef ELLIPSE_H
#define ELLIPSE_H

#include "shapes.h"

namespace Shapes {

class ellipse : public shape
{
public:
    ellipse(QPaintDevice* device = nullptr,int id=-1): shape(device,id,shapeType::ellipse){}    //defualt constructor
    ~ellipse() {}

    void setHeight(int);
    void setWidth(int);

    void draw(QPainter &p);
    void move(int x2,int y2);
    double perimeter()const;
    double area()const;

private:
    QRect rect;
    int h;
    int w;

};
}
#endif // ELLIPSE_H
