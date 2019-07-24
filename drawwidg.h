#ifndef DRAWWIDG_H
#define DRAWWIDG_H

#include <QWidget>
#include "shapes.h"
#include "vector.h"

using namespace Shapes;
using namespace CS1C;


class drawWidg : public QWidget
{
    Q_OBJECT
public:
    explicit drawWidg(QWidget *parent = 0);
    void drawShapes();
    void setShapeList(vector<shape*>);

signals:
protected:
    void paintEvent(QPaintEvent *) Q_DECL_OVERRIDE;

public slots:
public:
    shape* shapePtr;
    QPainter* shp;
    vector<shape*> shapeList;
};

#endif // DRAWWIDG_H
