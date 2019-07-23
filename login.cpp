#include "login.h"
#include "ui_login.h"
#include "QMessageBox"

login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
}

login::~login()
{
    delete ui;
}

void login::on_pushButton_clicked()
{
    QString username = ui->lineEdit->text();
    QString password =ui->lineEdit_2->text();

    if (username=="admin" && password == "admin123")
    {
        QMessageBox::information(this,"Login","Administrator confirmed");
    }
}


void login::on_pushButton_2_clicked()
{
    contact = new contact(this);
    contact->show();
}
