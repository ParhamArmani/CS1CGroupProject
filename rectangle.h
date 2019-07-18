#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shapes.h"

class rectangle : public shape
{
public:
    rectangle(QPaintDevice* device = nullptr,int id=-1): shape(device,id,shapeType::rectangle){}    //defualt constructor
    ~rectangle();

    void set_rect(const QRect& rect);
    void draw();
    void move(int x2,int y2);

    double perimeter();
    double area();

private:
    QRect rect;
//xywidthheight
};
class ellipse : public shape
{
public:
    ellipse(QPaintDevice* device = nullptr,int id=-1): shape(device,id,shapeType::rectangle){}    //defualt constructor
    ~ellipse();

    void set_ellipse(const QRect& rect);
    void draw();
    void move(int x2,int y2);

    double perimeter();
    double area();

private:
    QRect rect;

};
#endif



