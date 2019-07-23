#ifndef DRAWWIDG_H
#define DRAWWIDG_H

#include <QWidget>
#include "shapes.h"


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
};

#endif // DRAWWIDG_H
