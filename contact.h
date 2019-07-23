#ifndef CONTACT_H
#define CONTACT_H

#include <QDialog>

namespace Ui{
class contact;
}

class contact: public QDialog
{
    Q_OBJECT


public:
    explicit contact(QWidget *parent =nullptr);
    ~contact();

 private:
   Ui::contact *ui;
};
#endif
