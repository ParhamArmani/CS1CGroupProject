#ifndef SHAPES_H
#define SHAPES_H

#include <QPainter>

class shape     //BEGIN SHAPE ABC
{
private:
    QPainter object;
    QPen penInfo;
    QBrush brushInfo;
    shapeType shape;
    int x;
    int y;
    int h;
    int w;
    int id;
public:
    enum class ShapeType {noShape, line, polyline, polygon, rectangle, ellipse, text};

    shape(QPaintDevice* device = nullptr, int id = -1; shapeType shape = shapeType::noshape);
    virtual ~shape();

    ShapeType getShape() const;
    const QPen& getPen() const;
    const QBrush& getBrush() const;

    void setShape(shapeType shape);
    void setPen(Qt::GlobalColor, int width, Qt::PenStyle, Qt::PenCapStyle, Qt::PenJoinStyle);
    void setPen(Qt::GlobalColor);
    void setBrush(Qt::GlobalColor, Qt::BrushStyle);

    void drawRect(int, int);

    virtual void draw(const int translateX, const int translateY) = 0;        //draws the shape
    virtual void move(const int newX, const int newY) = 0;        //updates the shapes
    virtual double perimiter() = 0;   //finds the perimiter of the shape
    virtual double area() = 0;        //finds the area of the shape

    void setPenColor(QPen);         //
    void setPenBrush(QBrush);       //
    void setPenStyle(QPen);         //
    void setCoords(int, int);       //
    void setHeight(int);            //
    void setWidth(int);             //
};              //END SHAPE ABC


class rectangle : public shape
{
private:
    QRect rect;
    void asd()
    {
        rect.;
    }
public:
    rectangle();    //defualt constructor


};

class line : public shape
{
private:
    QLine line;

public:

};

class polyline : public shape
{
private:

public:
};

class polygon : public shape
{
private:

public:

};

class elipse : public shape
{
private:
    QRect rect;

public:

};

class text : public shape
{
private:
    QTextItem txt;
public:

};


#endif // SHAPES_H
