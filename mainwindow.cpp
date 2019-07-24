#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "drawwidg.h"
#include "shape.h"
#include "text.h"
#include <QPainter>
#include <QtWidgets>
#include "cont.h"
#include "login.h"
#include "movemenu.h"
#include "shapeparser.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    parser.loadFile();
//    shapeList = parser.getShapeList();
    ui->canvas->setGeometry(110, 10, 1000,500);
    QPalette pal = palette();
    pal.setColor(QPalette::Background, Qt::white);
    ui->canvas->setAutoFillBackground(true);
    ui->canvas->setPalette(pal);
    ui->canvas->setShapeList(shapeList);
    ui->canvas->drawShapes();
    ui->canvas->update();
    access = false;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_contactBtn_clicked()
{
    cont* c = new cont();
    c->show();
}

void MainWindow::on_pushButton_clicked()
{
    login* l = new login();
    l->show();
    access = l->getBool();
}

void MainWindow::on_moveBtn_clicked()
{
    if(access == true)
    {
        shapeList = ui->canvas->getShapeList();
        moveMenu* m = new moveMenu();
        m->show();
    }
    else {
        QMessageBox::information(this,"Error", "Admin access required");
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->canvas->update();
    ui->canvas->drawShapes();
}
