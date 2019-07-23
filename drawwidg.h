#ifndef DRAWWIDG_H
#define DRAWWIDG_H

#include <QWidget>
#include "shapes.h"
#include "vector.h"

using namespace CS1C;


class drawWidg : public QWidget
{
    Q_OBJECT
public:
    explicit drawWidg(QWidget *parent = nullptr);
    void drawShapes();
    void setShapeList(vector<shape*>);

signals:
protected:
    void paintEvent(QPaintEvent *);

public slots:
public:
    shape* shapePtr;
    QPainter* shp;
    vector<shape*> shapeList;
};

#endif // DRAWWIDG_H
