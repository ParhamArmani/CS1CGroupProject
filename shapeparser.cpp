#include "shapeparser.h"

ShapeParser::ShapeParser()
{

}

ShapeParser::~ShapeParser()
{

}

void ShapeParser::loadFile()
{
    CS1C::vector<shape*> shapeList;
    QPaintDevice* device;

    ifstream load;
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
                cout << "[CONSOLE] Shape is a line" << endl;
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
                cout << "[CONSOLE] Shape is a text" << endl;
                //text *tempText = new text(device, id, shape::shapeType::text, "");

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

                string tempTextColor = "";

                string tempTextAlignment = "";

                string tempTextPointSize_STRING = "";
                    int tempTextPointSize_INT = 0;

                string tempTextFontFamily = "";

                string tempTextFontStyle = "";

                string tempTextFontWeight = "";

                do
                {
                    //reads next line up to the colon, also ignores the following space
                    //finds the property that is pulled and then applies to the respective property of the object
                    getline(load, textProperty, ':');
                    load.ignore(1, ' ');

                /*************************
                 * DATA EXTRACTION TIIIME
                 *************************/
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
                    }

                    /**COLOR of the text**/
                    if(textProperty == "TextColor")
                    {
                        getline(load, tempTextColor, '\n');
                        cout << "[Shape Parser] Text: " << tempTextColor << endl;

                    }

                    /**ALIGNMENT of the text**/
                    if(textProperty == "TextAlignment")
                    {
                        getline(load, tempTextAlignment, '\n');
                        cout << "[Shape Parser] Text: " << tempTextAlignment << endl;

                    }

                    /**text POINT SIZE**/
                    if(textProperty == "TextPointSize")
                    {
                        getline(load, tempTextPointSize_STRING, '\n');
                        std::istringstream iss(tempTextPointSize_STRING);
                        iss >> tempTextPointSize_INT;
                        cout << "[Shape Parser] Text: " << tempTextPointSize_INT << endl;

                    }

                    /**text font STYLE**/
                    if(textProperty == "TextFontFamily")
                    {
                        getline(load, tempTextFontFamily, '\n');
                        cout << "[Shape Parser] Text: " << tempTextFontFamily << endl;

                    }

                    if(textProperty == "TextFontStyle")
                    {
                        getline(load, tempTextFontStyle, '\n');
                        cout << "[Shape Parser] Text: " << tempTextFontStyle << endl;

                    }


                    if(textProperty == "TextFontWeight")
                    {
                        getline(load, tempTextFontWeight, '\n');
                        cout << "[Shape Parser] Text: " << tempTextFontWeight << endl;

                    }

                /**************************
                 * DATA APPLICATION TIIIME
                 **************************/
                    /**

                    tempText->setWidth(tempWidth);
                    tempText->setHeight(tempHeight);
                    //actual text is set in object initialization
                    //???tempText->setColor(tempTextColor);
                    tempText->setAlignment(tempTextAlignment);
                    //???tempText->setPointSize(tempTextPointSize_STRING);
                    tempText->setFont(tempTextFontFamily);
                    tempText->setStyle(tempTextFontStyle);
                    tempText->setWeight();

                    **/
                }
                while(textProperty.compare("TextFontWeight") != 0);
                break;
			}
		}
	}
}

int ShapeParser::calculateWidth(int x1, int x2)
{
    return x2 - x1;
}

int ShapeParser::calculateHeight(int y1, int y2)
{
    return y1 - y2;
}


