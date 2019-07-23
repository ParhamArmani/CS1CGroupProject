#ifndef CONT_H
#define CONT_H

#include <QDialog>

namespace Ui {
class cont;
}

class cont : public QDialog
{
    Q_OBJECT

public:
    explicit cont(QWidget *parent = nullptr);
    ~cont();

private:
    Ui::cont *ui;
};

#endif // CONT_H
