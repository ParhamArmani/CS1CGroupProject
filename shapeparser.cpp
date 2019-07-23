#include "shapeparser.h"

ShapeParser::ShapeParser()
{

}

ShapeParser::~ShapeParser()
{

}

CS1C::vector<shape*> ShapeParser::getShapeList() const
{
    return this->shapeList;
}

void ShapeParser::loadFile()
{
    QPaintDevice* device;

	string shapeProperty;
	string shapeValues;
	int id;
	shapeTypeFILE TEMPshapeType = NOSHAPE;

	load.open("shapes.txt");

	while (!load.eof())
	{
		char temp = load.peek();
		if (temp == '\n')
		{
			//skips whitespace (\n) in the first line
			load.ignore(1, '\n');
            cout << endl << "***ignored newline***" << endl;
		}

        //reads next line up to the colon, also ignores the following space
        getline(load, shapeProperty, ':');
		load.ignore(1, ' ');
        cout << endl << "[CONSOLE] Shape property: " << shapeProperty;

		//grabs whatever is past the colon, then assigns it to shapeValues
        getline(load, shapeValues, '\n');
        cout << endl << "[CONSOLE] Shape value(s): " << shapeValues << endl;

        //checks what was obtained from shapeProperty (anything before the colon)
		if (shapeProperty == "ShapeId")
		{
			//converts string to int type, then stored in id
			std::istringstream iss(shapeValues);
			iss >> id;
		}

		//designates the shape type to an enum, which is used with a switch statement later
		if (shapeProperty == "ShapeType")
		{
			if (shapeValues == "Line")				TEMPshapeType = LINE;
			else if (shapeValues == "Polyline")		TEMPshapeType = POLYLINE;
			else if (shapeValues == "Polygon")		TEMPshapeType = POLYGON;
			else if (shapeValues == "Rectangle")	TEMPshapeType = RECTANGLE;
			else if (shapeValues == "Square")		TEMPshapeType = SQUARE;
			else if (shapeValues == "Ellipse")		TEMPshapeType = ELLIPSE;
			else if (shapeValues == "Circle")		TEMPshapeType = CIRCLE;
			else if (shapeValues == "Text")			TEMPshapeType = TEXT;

			switch (TEMPshapeType)
			{
			case LINE:
                loadLine(device, id);
                break;
			case POLYLINE:
                cout << "[CONSOLE] Shape is a polyline" << endl;
				break;
			case POLYGON:
                cout << "[CONSOLE] Shape is a polygon" << endl;
				break;
			case RECTANGLE:
                cout << "[CONSOLE] Shape is a rectangle" << endl;
				break;
			case SQUARE:
                cout << "[CONSOLE] Shape is a square" << endl;
				break;
			case ELLIPSE:
                cout << "[CONSOLE] Shape is a ellipse" << endl;
				break;
			case CIRCLE:
                cout << "[CONSOLE] Shape is a circle" << endl;
				break;
			case TEXT:
                loadText(device, id);
			}
		}
	}
}

void ShapeParser::loadLine(QPaintDevice *device, int id)
{
    cout << "[CONSOLE] Shape is a line" << endl;
    /*****************************
     * DATA INITIALIZATION TIIIME
     *****************************/
    string textProperty = "";

    string tempCoord = "";
        int tempX1 = 0;
        int tempY1 = 0;
        int tempX2 = 0;
        int tempY2 = 0;

    string tempPenColor = "";
    Qt::GlobalColor Q_PenColor;

    string tempPenWidth_STRING = "";
    int tempPenWidth_INT = 0;

    string tempPenStyle = "";
    Qt::PenStyle Q_PenStyle;

    string tempPenCapStyle = "";
    Qt::PenCapStyle Q_PenCapStyle;

    string tempPenJoinStyle = "";
    Qt::PenJoinStyle Q_PenJoinStyle;

    do
    {
        //reads next line up to the colon, also ignores the following space
        //finds the property that is pulled and then applies to the respective property of the object
        getline(load, textProperty, ':');
        load.ignore(1, ' ');


        /**coordinates and width/height calculations**/
        if(textProperty == "ShapeDimensions")
        {
            getline(load, tempCoord, ',');
            load.ignore(1, ' ');
            std::istringstream x1convert(tempCoord);
            x1convert >> tempX1;

            getline(load, tempCoord, ',');
            load.ignore(1, ' ');
            std::istringstream y1convert(tempCoord);
            y1convert >> tempY1;

            getline(load, tempCoord, ',');
            load.ignore(1, ' ');
            std::istringstream x2convert(tempCoord);
            x2convert >> tempX2;

            getline(load, tempCoord, '\n');
            std::istringstream y2convert(tempCoord);
            y2convert >> tempY2;

            cout << "[Shape Parser] Line: " << textProperty
                                << " | X1: " << tempX1
                                << " | Y1: " << tempY1
                                << " | X2: " << tempX2
                                << " | Y2: " << tempY2 << endl;
        }

        /**COLOR of the pen**/
        if(textProperty == "PenColor")
        {
            getline(load, tempPenColor, '\n');
            cout << "[Shape Parser] Line: " << tempPenColor << endl;

            if(tempPenColor == "white")        Q_PenColor = Qt::white;
            else if(tempPenColor == "black")   Q_PenColor = Qt::black;
            else if(tempPenColor == "red")     Q_PenColor = Qt::red;
            else if(tempPenColor == "green")   Q_PenColor = Qt::green;
            else if(tempPenColor == "blue")    Q_PenColor = Qt::blue;
            else if(tempPenColor == "cyan")    Q_PenColor = Qt::cyan;
            else if(tempPenColor == "magenta") Q_PenColor = Qt::magenta;
            else if(tempPenColor == "yellow")  Q_PenColor = Qt::yellow;
            else if(tempPenColor == "gray")    Q_PenColor = Qt::gray;
        }

        /**pen WIDTH**/
        if(textProperty == "PenWidth")
        {
            getline(load, tempPenWidth_STRING, '\n');
            std::istringstream penColorConvert(tempPenWidth_STRING);
            penColorConvert >> tempPenWidth_INT;
            cout << "[Shape Parser] Line: " << tempPenWidth_INT << endl;

        }

        /**pen STYLE**/
        if(textProperty == "PenStyle")
        {
            getline(load, tempPenStyle, '\n');
            cout << "[Shape Parser] Line: " << tempPenStyle << endl;
            if(tempPenStyle == "NoPen")                 Q_PenStyle = Qt::PenStyle::NoPen;
            else if(tempPenStyle == "SolidLine")        Q_PenStyle = Qt::PenStyle::SolidLine;
            else if(tempPenStyle == "DashLine")         Q_PenStyle = Qt::PenStyle::DashLine;
            else if(tempPenStyle == "DotLine")          Q_PenStyle = Qt::PenStyle::DotLine;
            else if(tempPenStyle == "DashDotLine")      Q_PenStyle = Qt::PenStyle::DashDotLine;
            else if(tempPenStyle == "DashDotDotLine")   Q_PenStyle = Qt::PenStyle::DashDotDotLine;
        }

        /**pen CAP STYLE**/
        if(textProperty == "PenCapStyle")
        {
            getline(load, tempPenCapStyle, '\n');
            cout << "[Shape Parser] Line: " << tempPenCapStyle << endl;
            if(tempPenCapStyle == "FlatCap")        Q_PenCapStyle = Qt::PenCapStyle::FlatCap;
            else if(tempPenCapStyle == "SquareCap") Q_PenCapStyle = Qt::PenCapStyle::SquareCap;
            else if(tempPenCapStyle == "RoundCap")  Q_PenCapStyle = Qt::PenCapStyle::RoundCap;
        }

        /**pen JOIN STYLE**/
        if(textProperty == "PenJoinStyle")
        {
            getline(load, tempPenJoinStyle, '\n');
            cout << "[Shape Parser] Line: " << tempPenJoinStyle << endl;
            if(tempPenJoinStyle == "MiterJoin")         Q_PenJoinStyle = Qt::PenJoinStyle::MiterJoin;
            else if(tempPenJoinStyle == "BevelJoin")    Q_PenJoinStyle = Qt::PenJoinStyle::BevelJoin;
            else if(tempPenJoinStyle == "RoundJoin")    Q_PenJoinStyle = Qt::PenJoinStyle::RoundJoin;
        }

    }

    while(textProperty.compare("PenJoinStyle") != 0);

    /**************************
     * DATA APPLICATION TIIIME
     **************************/
    Line *tempLine = new Line(device, id, shape::shapeType::line, tempX1, tempY1);

    tempLine->setPenColor(Q_PenColor);
    tempLine->setPenWidth(tempPenWidth_INT);
    tempLine->setPenStyle(Q_PenStyle);
    tempLine->setPenCap(Q_PenCapStyle);
    tempLine->setPenJoint(Q_PenJoinStyle);

    shapeList.push_back(tempLine);
}

void ShapeParser::loadText(QPaintDevice *device, int id)
{
    cout << "[CONSOLE] Shape is a text" << endl;
    /*****************************
     * DATA INITIALIZATION TIIIME
     *****************************/
    string textProperty = "";

    string tempCoord = "";
        int tempX1 = 0;
        int tempY1 = 0;
        int tempX2 = 0;
        int tempY2 = 0;
        int tempWidth = 0;
        int tempHeight = 0;

    string tempActualText = "";
    QString Q_ActualText;

    string tempTextColor = "";
    Qt::GlobalColor Q_TextColor;

    string tempTextAlignment = "";
    Qt::AlignmentFlag Q_TextAlignment;

    string tempTextPointSize_STRING = "";
        int tempTextPointSize_INT = 0;

    string tempTextFontFamily = "";
    QString Q_TextFontFamily;

    string tempTextFontStyle = "";
    QFont::Style Q_TextFontStyle;

    string tempTextFontWeight = "";
    QFont::Weight Q_TextFontWeight;

    /*************************
     * DATA EXTRACTION TIIIME
     *************************/
    do
    {
        //reads next line up to the colon, also ignores the following space
        //finds the property that is pulled and then applies to the respective property of the object
        getline(load, textProperty, ':');
        load.ignore(1, ' ');


        /**coordinates and width/height calculations**/
        if(textProperty == "ShapeDimensions")
        {
            getline(load, tempCoord, ',');
            load.ignore(1, ' ');
            std::istringstream x1convert(tempCoord);
            x1convert >> tempX1;

            getline(load, tempCoord, ',');
            load.ignore(1, ' ');
            std::istringstream y1convert(tempCoord);
            y1convert >> tempY1;

            getline(load, tempCoord, ',');
            load.ignore(1, ' ');
            std::istringstream x2convert(tempCoord);
            x2convert >> tempX2;

            getline(load, tempCoord, '\n');
            std::istringstream y2convert(tempCoord);
            y2convert >> tempY2;

            tempWidth = calculateWidth(tempX1, tempX2);
            tempHeight = calculateHeight(tempY1, tempY2);

            cout << "[Shape Parser] Text: " << textProperty
                                << " | X1: " << tempX1
                                << " | Y1: " << tempY1
                                << " | X2: " << tempX2
                                << " | Y2: " << tempY2
                                << " | Width: " << tempWidth
                                << " | Height: " << tempHeight << endl;
        }

        /**ACTUAL TEXT of the 'text' object**/
        if(textProperty == "TextString")
        {
            getline(load, tempActualText, '\n');
            cout << "[Shape Parser] Text: \'" << tempActualText << "\'" << endl;
            Q_ActualText = QString::fromStdString(tempActualText);
        }

        /**COLOR of the text**/
        if(textProperty == "TextColor")
        {
            getline(load, tempTextColor, '\n');
            cout << "[Shape Parser] Text: " << tempTextColor << endl;

            if(tempTextColor == "white")        Q_TextColor = Qt::white;
            else if(tempTextColor == "black")   Q_TextColor = Qt::black;
            else if(tempTextColor == "red")     Q_TextColor = Qt::red;
            else if(tempTextColor == "green")   Q_TextColor = Qt::green;
            else if(tempTextColor == "blue")    Q_TextColor = Qt::blue;
            else if(tempTextColor == "cyan")    Q_TextColor = Qt::cyan;
            else if(tempTextColor == "magenta") Q_TextColor = Qt::magenta;
            else if(tempTextColor == "yellow")  Q_TextColor = Qt::yellow;
            else if(tempTextColor == "gray")    Q_TextColor = Qt::gray;
        }

        /**ALIGNMENT of the text**/
        if(textProperty == "TextAlignment")
        {
            getline(load, tempTextAlignment, '\n');
            cout << "[Shape Parser] Text: " << tempTextAlignment << endl;
            if(tempTextAlignment == "AlignLeft")        Q_TextAlignment = Qt::AlignmentFlag::AlignLeft;
            else if(tempTextAlignment == "AlignRight")  Q_TextAlignment = Qt::AlignmentFlag::AlignRight;
            else if(tempTextAlignment == "AlignTop")    Q_TextAlignment = Qt::AlignmentFlag::AlignTop;
            else if(tempTextAlignment == "AlignBottom") Q_TextAlignment = Qt::AlignmentFlag::AlignCenter;
        }

        /**text POINT SIZE**/
        if(textProperty == "TextPointSize")
        {
            getline(load, tempTextPointSize_STRING, '\n');
            std::istringstream iss(tempTextPointSize_STRING);
            iss >> tempTextPointSize_INT;
            cout << "[Shape Parser] Text: " << tempTextPointSize_INT << endl;

        }

        /**text font FAMILY**/
        if(textProperty == "TextFontFamily")
        {
            getline(load, tempTextFontFamily, '\n');
            cout << "[Shape Parser] Text: " << tempTextFontFamily << endl;
            Q_TextFontFamily = QString::fromStdString(tempTextFontFamily);
        }

        /**text font STYLE**/
        if(textProperty == "TextFontStyle")
        {
            getline(load, tempTextFontStyle, '\n');
            cout << "[Shape Parser] Text: " << tempTextFontStyle << endl;
            if(tempTextFontStyle == "StyleNormal")          Q_TextFontStyle = QFont::StyleNormal;
            else if (tempTextFontStyle == "StyleItalic")    Q_TextFontStyle = QFont::StyleItalic;
            else if (tempTextFontStyle == "StyleOblique")   Q_TextFontStyle = QFont::StyleOblique;
        }

        /**text font WEIGHT**/
        if(textProperty == "TextFontWeight")
        {
            getline(load, tempTextFontWeight, '\n');
            cout << "[Shape Parser] Text: " << tempTextFontWeight << endl;
            if(tempTextFontWeight == "Thin")        Q_TextFontWeight = QFont::Thin;
            else if(tempTextFontWeight == "Light")  Q_TextFontWeight = QFont::Light;
            else if(tempTextFontWeight == "Normal") Q_TextFontWeight = QFont::Normal;
            else if(tempTextFontWeight == "Bold")   Q_TextFontWeight = QFont::Bold;
        }
    }

    while(textProperty.compare("TextFontWeight") != 0);

    /**************************
     * DATA APPLICATION TIIIME
     **************************/
    text *tempText = new text(device, id, shape::shapeType::text, Q_ActualText);

    tempText->setWidth(tempWidth);
    tempText->setHeight(tempHeight);
    tempText->setPenColor(Q_TextColor);
    tempText->setAlignment(Q_TextAlignment);
    tempText->setSize(tempTextPointSize_INT);
    tempText->setFont(Q_TextFontFamily);
    tempText->setStyle(Q_TextFontStyle);
    tempText->setWeight(Q_TextFontWeight);

    shapeList.push_back(tempText);
}

int ShapeParser::calculateWidth(int x1, int x2)
{
    return x2 - x1;
}

int ShapeParser::calculateHeight(int y1, int y2)
{
    return y1 - y2;
}


