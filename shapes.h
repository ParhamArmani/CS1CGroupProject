#ifndef SHAPES_H
#define SHAPES_H


#include <cmath>
#include <QBrush>
#include <QPoint>
#include <QPainter>
#include <QPen>
#include <QPaintEvent>

namespace Shapes {

class shape     //BEGIN SHAPE ABC
{
public:
    enum shapeType {noShape, line, polyline, polygon, rectangle, ellipse, text};

    shape(QPaintDevice* device = nullptr, int id = -1, shapeType s = shapeType::noShape);
    virtual ~shape();

    int getId() const;    //returns the id of the shape
    shapeType getShape() const; //returns what type of shape it is
    const QPen& getPen() const; //returns a reference to the QPen
    const QBrush& getBrush() const; //returns a reference to the QBrush

    void setShape(shapeType shape);
    void setPen(Qt::GlobalColor, int width, Qt::PenStyle, Qt::PenCapStyle, Qt::PenJoinStyle);
    void setBrush(Qt::GlobalColor, Qt::BrushStyle);

    void drawRect(int, int);

    virtual void draw(QPainter &p, QPaintDevice* device) = 0;        //draws the shape
    virtual void move(const int newX, const int newY) = 0;        //updates the shapes
    virtual double perimeter()const = 0;   //finds the perimiter of the shape
    virtual double area()const = 0;        //finds the area of the shape

    void setId(int);                        //sets the id
    void setPenColor(Qt::GlobalColor);      //changes the pen and text color
    void setPenStyle(Qt::PenStyle);         //changes the pen style
    void setPenWidth(int);                  //changes the pen width
    void setPenCap(Qt::PenCapStyle);        //chnges the pen cap
    void setPenJoint(Qt::PenJoinStyle);     //chnges the pen joint
    void setBrushColor(Qt::GlobalColor);    //changes the brush color
    void setBrushStyle(Qt::BrushStyle);     //changes the brush style

    void setCoords(int, int);       //changes the shapes position
    int getX();                     //gets the x value
    int getY();                     //gets the y value
    QPainter paint;

protected:
    QPainter& getQpainter();

private:

    QPaintDevice* device;
    QPen pen;
    QBrush brush;
    shapeType s;
    int x1;
    int y1;
    int id;
};              //END SHAPE ABC
}
#endif // SHAPES_H
