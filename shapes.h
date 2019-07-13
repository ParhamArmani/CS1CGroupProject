#ifndef SHAPES_H
#define SHAPES_H

#include <string>
#include <QPainter>
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
    void setPen(Qt::GlobalColor);
    void setBrush(Qt::GlobalColor, Qt::BrushStyle);

    void drawRect(int, int);

    virtual void draw(const int translateX, const int translateY) = 0;        //draws the shape
    virtual void move(const int newX, const int newY) = 0;        //updates the shapes
    virtual double perimiter() = 0;   //finds the perimiter of the shape
    virtual double area() = 0;        //finds the area of the shape

    void setPenColor(QPen);         //changes the pen color
    void setPenBrush(QBrush);       //changes the pen brush
    void setPenStyle(QPen);         //changes the pen style
    void setCoords(int, int);       //changes the shapes position
    void setHeight(int);            //changes shape height
    void setWidth(int);             //changes shape width

private:
    QPainter paint;
    QPaintDevice* device;
    QPen penInfo;
    QBrush brushInfo;
    shapeType s;
    int x;
    int y;
    int h;
    int w;
    int id;
    void asd()
    {
        paint.drawText
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
