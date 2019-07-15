#ifndef SHAPES_H
#define SHAPES_H

#include <string>
#include <QPainter>
#include <QPen>
using std::string;
class shape     //BEGIN SHAPE ABC
{
public:
    enum shapeType {noShape, line, polyline, polygon, rectangle, ellipse, text};

    shape(QPaintDevice* device = nullptr, int id = -1, shapeType s = shapeType::noShape);
    virtual ~shape();

    shapeType getShape() const; //returns what type of shape it is
    const QPen& getPen() const; //returns a reference to the QPen
    const QBrush& getBrush() const; //returns a reference to the QBrush

    void setShape(shapeType shape);
    void setPen(Qt::GlobalColor, int width, Qt::PenStyle, Qt::PenCapStyle, Qt::PenJoinStyle);
    void setBrush(Qt::GlobalColor, Qt::BrushStyle);

    void drawRect(int, int);

    virtual void draw(const int translateX, const int translateY) = 0;        //draws the shape
    virtual void move(const int newX, const int newY) = 0;        //updates the shapes
    virtual double perimiter() = 0;   //finds the perimiter of the shape
    virtual double area() = 0;        //finds the area of the shape

    void setPenColor(Qt::GlobalColor);      //changes the pen and text color
    void setPenStyle(Qt::PenStyle);         //changes the pen style
    void setPenWidth(int);
    void setPenCap(Qt::PenCapStyle);
    void setPenJoint(Qt::PenJoinStyle);
    void setBrushColor(Qt::GlobalColor);
    void setBrushStyle(Qt::BrushStyle);

    void setTextAlignment();
    void setTextSize();
    void setTextFont();
    void setTextStyle();
    void setTextWeight();

    void setCoords(int, int);       //changes the shapes position

private:
    QPainter paint;
    QPaintDevice* device;
    QPen penInfo;
    QBrush brushInfo;
    shapeType s;
    int x1;
    int y1;
    int id;
    void asd()
    {
        paint.draw
    }
};              //END SHAPE ABC


class rectangle : public shape
{
private:
    QRect rect;
public:
    rectangle();    //defualt constructor

    void draw(const int translateX, const int translateY);
    void move(const int newX, const int newY);
    double perimiter();
    double area();

};

class line : public shape
{
private:
    QLine line;

public:
    void draw(const int translateX, const int translateY);
    void move(const int newX, const int newY);
    double perimiter();
    double area();

};

class polyline : public shape
{
private:

public:
    void draw(const int translateX, const int translateY);
    void move(const int newX, const int newY);
    double perimiter();
    double area();
};

class polygon : public shape
{
private:

public:
    void draw(const int translateX, const int translateY);
    void move(const int newX, const int newY);
    double perimiter();
    double area();

};

class elipse : public shape
{
private:
    QRect rect;

public:
    void draw(const int translateX, const int translateY);
    void move(const int newX, const int newY);
    double perimiter();
    double area();

};

class text : public shape
{
private:
    QString str;

public:
    text();
    text(string);

    void draw(const int translateX, const int translateY);
    void move(const int newX, const int newY);
    double perimiter();
    double area();

    void changeFont();
    void changeString();
    void changeColor();
    void changeAlignment();
    void changeSize();
    void changeStyle();
    void changeWeight();
};


#endif // SHAPES_H
