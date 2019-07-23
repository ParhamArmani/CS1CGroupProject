#include "text.h"

//text::text() : shape()
//{}

/**
 * @brief Construct a new text::text object
 * 
 * @param device : is a parameter with the type of Qt Paint Device
 * @param id : is a parameter with the type of int
 * @param s :is a parameter with the type  of shapeType
 * @param txt : is a parameter with the type of Qt string
 */
text::text(QPaintDevice* device, int id, shapeType s, QString txt) : shape(device, id, s)
{
    str = txt;
}

/**
 * @brief Destroy the text::text object
 * 
 */
text::~text()
{

}

/**
 * @brief Fucntion to draw/show the text object.
 * Pre: Recieves nothing.
 */
void text::draw()
{
    QRect rect;
    rect.setX(getX());
    rect.setY(getY());
    getQpainter().drawText(rect, alignment, str);
}

/**
 * @brief Function to move the Object to the new coordinate
 * 
 * @param newX : is a parameter with the type int (New X coordinate)
 * @param newY : is a parameter with the type int (New Y Coordinate)
 */
void text::move(const int newX, const int newY)
{
    setCoords(newX, newY);
}

/**
 * @brief Function to Return the perimeter of the Text, (Zero)
 * 
 * @return Zero (Of type Double): The Perimenter of a text is Zero
 */
double text::perimeter()
{
    return 0;
}

/**
 * @brief Function to Return the Area of the Text, (Zero)
 * 
 * @return Zero (Of type Double): The Area of a text is Zero
 */
double text::area()
{
    return 0;
}

/**
 * @brief Function to Set Alignment Flag of the Qt Object.
 * 
 * @param Qt::AlignmentFlag: is a parameter of the type enum
 */
void text::setAlignment(Qt::AlignmentFlag)
{
    alignment = Qt::AlignmentFlag();
}

/**
 * @brief Function to set the size of the Text 
 * 
 * @param size : is a parameter that the text's size will be set.
 */
void text::setSize(int size)
{
    pointSize = size;
    font.setPointSize(size);
    getQpainter().setFont(font);
}

/**
 * @brief Function to set the Font of the Text
 * 
 * @param fontFamily : is a parameter of the type QString .
 */
void text::setFont(QString fontFamily)
{
    font.setFamily(fontFamily);
    getQpainter().setFont(font);
}

/**
 * @brief Function to set the Font of the Text.
 * @param QFont::Style  :is the parameter of the Type Enum QFont
 * 
 */
void text::setStyle(QFont::Style)
{
    font.setStyle(QFont::Style());
    getQpainter().setFont(font);
}

/**
 * @brief Function to set the weight of the Text
 * @param QF::Weight :is a parameter of type Enum QFont.
 */
void text::setWeight(QFont::Weight)
{
    font.setWeight(QFont::Weight());
    getQpainter().setFont(font);
}

/**
 * @brief Function to set the Width of the Text.
 * 
 * @param width: is a parameter of type int
 */
void text::setWidth(int width)
{
    w = width;
}

/**
 * @brief Function to set the Height of the Text.
 * 
 * @param height :is the Parameter of the type int
 */
void text::setHeight(int height)
{
    h = height;
}

/**
 * @brief Function to set the String of the text 
 * 
 * @param txt :is the Parameter of the Type QString.
 */
void text::setString(QString txt)
{
    str = txt;
}
