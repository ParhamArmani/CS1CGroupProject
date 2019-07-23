#include "contact.h"
#include "ui_contact.h"

contact::contact(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::contact)
{
    ui->setupUi(this);
}

contact::~contact()
{
    delete ui;
}
