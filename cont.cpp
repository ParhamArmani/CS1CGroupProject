#include "cont.h"
#include "ui_cont.h"

cont::cont(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::cont)
{
    ui->setupUi(this);
}

cont::~cont()
{
    delete ui;
}
