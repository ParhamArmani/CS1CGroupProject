#include "movemenu.h"
#include "ui_movemenu.h"
#include "drawwidg.h"

using std::cout;

moveMenu::moveMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::moveMenu)
{
    ui->setupUi(this);
}

moveMenu::~moveMenu()
{
    delete ui;
}

void moveMenu::on_pushButton_2_clicked()
{
    close();
}

void moveMenu::on_pushButton_clicked()
{
   int tempId;
    QString temp;
    temp = ui->idInput->text();
    tempId = temp.split(" ")[0].toInt();

    int i = 0;
    while(tempId != shapeList[i]->getId())
        i++;
}
