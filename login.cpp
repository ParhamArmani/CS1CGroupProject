#include "login.h"
#include "ui_login.h"
#include "QMessageBox"
#include "cont.h"

login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    correctPswrd = false;
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
        correctPswrd = true;
        this->close();
    }
}


void login::on_pushButton_2_clicked()
{
    contact = new cont(this);
    contact->show();
}
