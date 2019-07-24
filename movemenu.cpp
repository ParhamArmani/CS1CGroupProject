#include "movemenu.h"
#include "ui_movemenu.h"

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
