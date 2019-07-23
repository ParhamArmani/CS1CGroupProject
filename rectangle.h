#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shapes.h"

class rectangle : public shape
{
public:
    rectangle(QPaintDevice* device = nullptr,int id = -1, shapeType s = shapeType::rectangle, int x1 = 0, int y1 = 0, int w = 1, int h = 1);    //defualt constructor
    ~rectangle();

    void set_rect(const QRect& rect);
    void setWidth(int);
    void setHeight(int);

    void draw();
    void move(int x2,int y2);
    double perimeter()const;
    double area()const;

private:
    QRect rect;
    int w;
    int h;
};



class ellipse : public shape
{
public:
    ellipse(QPaintDevice* device = nullptr,int id=-1): shape(device,id,shapeType::ellipse){}    //defualt constructor
    ~ellipse();

    void set_ellipse(const QRect& rect);

    void draw();
    void move(int x2,int y2);
    double perimeter() const;
    double area() const;

private:
    QRect rect;

};
#endif



