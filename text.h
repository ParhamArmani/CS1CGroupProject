#ifndef TEXT_H
#define TEXT_H

#include "shapes.h"

class text : public shape
{
private:
    QString str;
    QFont font;
    int alignment;
    int w;
    int h;

public:
    text();
    text(QPaintDevice* device = nullptr, int id = -1, shapeType s = shapeType::text, QString str = "Hello");
    ~text();

    void draw();
    void move(const int newX, const int newY);
    double perimiter();
    double area();

    void setAlignment(Qt::AlignmentFlag);
    void setSize(int);
    void setFont(QString);
    void setStyle(QFont::Style);
    void setWeight(QFont::Weight());
    void setWidth(int);
    void setHeight(int);
};

#endif // TEXT_H
