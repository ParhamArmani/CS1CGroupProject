#ifndef LOGIN_H
#define LOGIN_H
#include "cont.h"
#include <QDialog>

namespace Ui {
class login;
}

class login : public QDialog
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    ~login();

    bool getBool() {return correctPswrd;}

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::login *ui;
    cont *contact;
    bool correctPswrd;
};

#endif // LOGIN_H
