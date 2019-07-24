#ifndef MOVEMENU_H
#define MOVEMENU_H

#include <QDialog>

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

private:
    Ui::moveMenu *ui;
};

#endif // MOVEMENU_H
