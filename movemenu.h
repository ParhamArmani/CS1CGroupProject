#ifndef MOVEMENU_H
#define MOVEMENU_H

#include "vector.h"
#include <QDialog>
#include "shapes.h"

using namespace Shapes;
using namespace CS1C;

namespace Ui {
class moveMenu;
}

class moveMenu : public QDialog
{
    Q_OBJECT

public:
    explicit moveMenu(QWidget *parent = nullptr);
    ~moveMenu();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::moveMenu *ui;
    vector<shape*> shapeList;
};

#endif // MOVEMENU_H
