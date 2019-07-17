#ifndef TEXT_H
#define TEXT_H

#include "shapes.h"

class text : public shape
{
private:
    QString str;
    QFont font;
    int alignment;

public:
    text();
    text(QString);

    void draw();
    void move(const int newX, const int newY);
    double perimiter();
    double area();

    void setAlignment(Qt::AlignmentFlag);
    void setSize(int);
    void setFont(QString);
    void setStyle(QFont::Style);
    void setWeight(QFont::Weight());
};

#endif // TEXT_H