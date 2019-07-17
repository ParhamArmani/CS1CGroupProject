#include "text.h"

text::text()
{

}

text::text(QString txt)
{
    str = txt;
}

void text::draw()
{
    getQpainter().drawText(QRect(), alignment, str);
}

void text::move(const int newX, const int newY)
{
    setCoords(newX, newY);
}

double text::perimiter()
{
    return 0;
}

double text::area()
{
    return 0;
}

void text::setAlignment(Qt::AlignmentFlag)
{
    alignment = Qt::AlignmentFlag();
}
void text::setSize(int size)
{
    font.setPointSize(size);
    getQpainter().setFont(font);
}
void text::setFont(QString fontFamily)
{
    font.setFamily(fontFamily);
    getQpainter().setFont(font);
}
void text::setStyle(QFont::Style)
{
    font.setStyle(QFont::Style());
    getQpainter().setFont(font);
}
void text::setWeight(QFont::Weight())
{
    font.setWeight(QFont::Weight());
    getQpainter().setFont(font);
}