#ifndef ELLIPSE_H
#define ELLIPSE_H

#include "shapes.h"

class ellipse : public shape
{
public:
    ellipse(QPaintDevice* device = nullptr,int id=-1): shape(device,id,shapeType::ellipse){}    //defualt constructor
    ~ellipse();

    void set_ellipse(const QRect& rect);

    void draw();
    void move(int x2,int y2);
    double perimeter()const;
    double area()const;

private:
    QRect rect;

};

#endif // ELLIPSE_H
