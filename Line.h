#ifndef LINE_H
#define LINE_H

#include "shapes.h"

namespace Shapes {

class Line : public shape
{
public:
    //Line();
    Line(QPaintDevice* device = nullptr, int id = -1);
//    Line(QPaintDevice* device = nullptr, int id = -1, shapeType s = shapeType::line, int x =0, int y=0);
    ~Line();

    void setEnd(int endX, int endY);
    void setStart(int startX, int startY);

    void move(const int x, const int y);
    void draw(QPainter &p);
    double area()const;
    double perimeter()const;

private:
    int startX;
    int startY;
    int endX;
    int endY;

};
}
#endif //LINE_H
