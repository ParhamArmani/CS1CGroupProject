#ifndef SHAPES_H
#define SHAPES_H

#include <QPainter>

class shape     //BEGIN SHAPE ABC
{
private:
    QPainter object;
    QPen penInfo;
    QBrush brushInfo;
    void asd()
    {
//        penInfo.
        object.
    }
public:
    virtual ~shape();

    virtual void draw() = 0;
    virtual void move() = 0;
    virtual void perimiter() = 0;
    virtual void area() = 0;
};              //END SHAPE ABC


class rectangle : public shape
{
private:
    QRect rect;
public:
    rectangle();    //defualt constructor


};

class line : public shape
{

};

class polyline

#endif // SHAPES_H
