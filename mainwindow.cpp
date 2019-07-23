#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "contact.h"
#include "drawwidg.h"
#include "shape.h"
#include "text.h"
#include <QPainter>
#include <QtWidgets>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    dw = new drawWidg;
//    QGridLayout *mainLayout = new QGridLayout;
//    mainLayout->addWidget(dw, 110, 10, 1000, 500);
//    setLayout(mainLayout);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *)
{
//    QPainter painter(this);
//    painter.begin(this);
//    painter.drawLine(QPoint(50,60), QPoint(100,100));
//    painter.setBrush(Qt::BDiagPattern);
//    painter.drawRect(QRect(150,120,80,30));
//    QRect asd(10,10,10,10);
//    painter.drawText(200,200,"hello there help");
//    text* eqwe = new text;
//    eqwe->setSize(20);
//    eqwe->setCoords(200,200);
//    eqwe->setString("hello there help");
//    eqwe->draw();
//    dw = new drawWidg;
//    dw->setShape(eqwe);
//    dw->update();
}

void MainWindow::on_contactBtn_clicked()
{
    contact* c = new contact();
    c->show();
}

void MainWindow::on_pushButton_clicked()
{

}
