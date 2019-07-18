#ifndef SHAPES_H
#define SHAPES_H

#include "Shape.h"

class Line : public Shape
{
	public:
		Line(const QPoint& start = {}, const QPoint% end = {}, const QBrush &brush = {},
		const QPen &pen = {};
		
		~Line();
		
		void move(const int x, const int y;)
		
		// getters and setters for the start and the end of the points of the line
		QPoint getStart()const;			// returns the start point of the line
		
		QPoint getEnd()const;			// returns the end point of the line
		
		void setStart(const QPoint& start);			// sets the start point of the line
		
		void setEnd(const QPoint& end);				// sets the end point of the line
		
		// function to draw the line on Qt
		void draw(QPaintDevice* device)const override;
		
		// 
		double getArea()const override;			// returns the area if the line (in this case it will always be 0)
		
		double getPerimeter()const override;
	
	private:
		QPoint start;
		QPoint end;
		
}

#endif
