#ifndef SHAPES_H
#define SHAPES_H


#include <cmath>
#include <QBrush>
#include <QPoint>
#include <QPainter>
#include <QPen>
#include <QPaintEvent>

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

    virtual void draw() = 0;        //draws the shape
    virtual void move(const int newX, const int newY) = 0;        //updates the shapes
    virtual double perimeter()const = 0;   //finds the perimiter of the shape
    virtual double area()const = 0;        //finds the area of the shape

    void setPenColor(Qt::GlobalColor);      //changes the pen and text color
    void setPenStyle(Qt::PenStyle);         //changes the pen style
    void setPenWidth(int);
    void setPenCap(Qt::PenCapStyle);
    void setPenJoint(Qt::PenJoinStyle);
    void setBrushColor(Qt::GlobalColor);
    void setBrushStyle(Qt::BrushStyle);

    void setCoords(int, int);       //changes the shapes position
    int getX();
    int getY();

protected:
    QPainter& getQpainter();

private:
    QPainter paint;
    QPaintDevice* device;
    QPen pen;
    QBrush brush;
    shapeType s;
    int x1;
    int y1;
    int id;
};              //END SHAPE ABC

#endif // SHAPES_H
