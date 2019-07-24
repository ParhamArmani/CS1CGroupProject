#ifndef SHAPEPARSER_H
#define SHAPEPARSER_H

#include <string>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include "vector.h"
#include "shapes.h"
#include "Line.h"
#include "rectangle.h"
#include "text.h"

using std::string;
using std::cout;
using std::endl;
using std::getline;
using namespace Shapes;

class ShapeParser
{
public:
	ShapeParser();
	~ShapeParser();

    CS1C::vector<shape*> getShapeList() const;
	void loadFile();
    int calculateWidth(int x1, int x2);
    int calculateHeight(int y1, int y2);
    void loadLine(QPaintDevice *device, int id);
    void loadPolyLine(QPaintDevice *device, int id);
    void loadPolygon(QPaintDevice *device, int id);
    void loadRectangle(QPaintDevice *device, int id);
    void loadSquare(QPaintDevice *device, int id);
    void loadEllipse(QPaintDevice *device, int id);
    void loadCircle(QPaintDevice *device, int id);
    void loadText(QPaintDevice *device, int id);


protected:
	//Line, Polyline, Polygon, Rectangle, Square[rectangle, l=w], Ellipse, Circle[ellipse, a=b], Text
    enum shapeTypeFILE { NOSHAPE, LINE = 1, POLYLINE, POLYGON, RECTANGLE, SQUARE, ELLIPSE, CIRCLE, TEXT };
    CS1C::vector<shape*> shapeList;
    std::ifstream load;
};

#endif // SHAPES_H
