#include "Line.h"

Line::Line() = default;

void Line::draw(QPaintDevice* device)const
{
	auto paint = getPainter(device);
	paint -> drawLine(start, end);
}

double Line::getArea()const
{
	return -1;
	
}

double Line::getPerimeter()const
{
	return -1;
}

QPoint Line::getStart()const
{
	return start + getPos();	
} 

QPoint Line::getEnd()const
{
	return end + getPos();
}

void Line::move(const int x, const int y)
{
	Line.setLine(x, y);
}
