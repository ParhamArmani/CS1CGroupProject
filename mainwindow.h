#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "drawwidg.h"
#include "vector.h"
#include "shapes.h"
#include "text.h"

using namespace CS1C;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void on_contactBtn_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    drawWidg* dw;
    shape* s;
    vector<shape*> shapeList;
    bool access;
};

#endif // MAINWINDOW_H
