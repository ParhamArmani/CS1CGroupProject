#ifndef TEXT_H
#define TEXT_H

#include "shapes.h"

namespace Shapes {

class text : public shape
{
private:
    QString str;
    QFont font;
    int alignment;
    int pointSize;
    int w;
    int h;

public:
//    text();
    text(QPaintDevice* device = nullptr, int id = -1, shapeType s = shapeType::text, QString str = "Hello");
    ~text();

    void draw(QPainter &p);
    void move(const int newX, const int newY);
    double perimeter()const ;
    double area()const;

    void setAlignment(Qt::AlignmentFlag);
    void setSize(int);
    void setFont(QString);
    void setStyle(QFont::Style);
    void setWeight(QFont::Weight);
    void setWidth(int);
    void setHeight(int);
    void setString(QString);
};
}
#endif // TEXT_H
