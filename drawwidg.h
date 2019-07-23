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
    void setShape(shape* currentShape);

signals:
protected:
    void paintEvent(QPaintEvent *);

public slots:
public:
    shape* shapePtr;
    vector<shape*> shapeList;
};

#endif // DRAWWIDG_H
