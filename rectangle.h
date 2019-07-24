#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shapes.h"

namespace Shapes {

class rectangle : public shape
{
public:
    rectangle(QPaintDevice* device = nullptr,int id = -1);    //defualt constructor
//    ~rectangle();

    void set_rect(const QRect& rect);
    void setWidth(int);
    void setHeight(int);

    void draw(QPainter &p);
    void move(int x2,int y2);
    double perimeter()const;
    double area()const;

private:
    QRect rect;
    int w;
    int h;
};
}
#endif
