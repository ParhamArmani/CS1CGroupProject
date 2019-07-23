#ifndef SHAPEPARSER_H
#define SHAPEPARSER_H

#include <string>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include "vector.h"
#include "shapes.h"
#include "text.h"

using std::string;
using std::cout;
using std::endl;
using std::getline;

class ShapeParser
{
public:
	ShapeParser();
	~ShapeParser();

	void loadFile();
    int calculateWidth(int x1, int x2);
    int calculateHeight(int y1, int y2);
    void loadText(QPaintDevice *device, int id);

private:
	//Line, Polyline, Polygon, Rectangle, Square[rectangle, l=w], Ellipse, Circle[ellipse, a=b], Text
	enum shapeTypeFILE { NOSHAPE, LINE = 1, POLYLINE, POLYGON, RECTANGLE, SQUARE, ELLIPSE, CIRCLE, TEXT };
};

#endif // SHAPES_H
