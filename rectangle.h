#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <string>
#include <cmath>
#include <QBrush>
#include <QPoint>
#include <QPen>
#include <QPainter>

class rectangle : public shape
{
public:
    rectangle(QPaintDevice* device = nullptr,int id=-1): shape(device,id,shapeType::rectangle){}    //defualt constructor
    ~rectangle() override{}

    void set_rect(const QRect& rect);
    void draw() override;
    void move(int x2,int y2);

    double perimeter();
    double area() override;

private:
    QRect rect;
//xywidthheight
};
class ellipse : public shape
{
public:
    ellipse(QPaintDevice* device = nullptr,int id=-1): shape(device,id,shapeType::rectangle){}    //defualt constructor
    ~ellipse() override{}

    void set_ellipse(const QRect& rect);
    void draw() override;
    void move(int x2,int y2) override;

    double perimeter();
    double area() override;

private:
    QRect rect;

};
#endif



